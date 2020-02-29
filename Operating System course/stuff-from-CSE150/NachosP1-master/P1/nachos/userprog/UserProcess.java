package nachos.userprog;

import nachos.machine.*;
import nachos.threads.*;
import nachos.userprog.*;

import java.io.EOFException;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;

/**
 * Encapsulates the state of a user process that is not contained in its
 * user thread (or threads). This includes its address translation state, a
 * file table, and information about the program being executed.
 *
 * <p>
 * This class is extended by other classes to support additional functionality
 * (such as additional syscalls).
 *
 * @see	nachos.vm.VMProcess
 * @see	nachos.network.NetProcess
 */


public class UserProcess {
	/* 
    new data type: File Descriptor
    	organized with a data structure (array?) so that multiple processes can access "shared" files.

	 */	
	public class FileDesc{
		public FileDesc(){
		}
		private String file_name = ""; //name of file
		private OpenFile file = null; //file object, provided by Nachos
		private boolean unlinked = false; //set true when unlink/close is associated with this file
	}

	/**
	 * Allocate a new process.
	 */
	public UserProcess() {

		int numPhysPages = Machine.processor().getNumPhysPages();
		int ID = getpid();
		int ParentID = 0; //id of this child;s parent

		//updateProcesses(ID,this); //add to global list of processes

		pageTable = new TranslationEntry[numPhysPages];
		for (int i=0; i<numPhysPages; i++)
			pageTable[i] = new TranslationEntry(i,i, true,false,false,false);

		//	Processes = new HashMap<Integer, UserProcess>();
		//	
		//	
		//	
		//	    
		//	    
		FilesArray = new FileDesc[numFileDesc];
		//	
		//initialize array of files    
		for (int i = 0; i <numFileDesc; i++){
			FilesArray[i] = new FileDesc();
		}   
		//	//initiliaze STDIN/OUT    
		FilesArray[0].file_name = "STDIN";
		FilesArray[0].file = UserKernel.console.openForReading();
		//	    
		FilesArray[1].file_name = "STDOUT";
		FilesArray[1].file = UserKernel.console.openForWriting();
		//if there is no root process
		if(pProcess == null) {
			in = UserKernel.console.openForReading();
			out = UserKernel.console.openForWriting();
		}else {
			in = pProcess.in;
			out = pProcess.out;
		}

		Processes = new HashMap<Integer, UserProcess>();
		pProcess = null;

		/* assign proccess ID during proccess creation! */



	}

	/**
	 * Allocate and return a new process of the correct class. The class name
	 * is specified by the <tt>nachos.conf</tt> key
	 * <tt>Kernel.processClassName</tt>.
	 *
	 * @return	a new process of the correct class.
	 */
	public static UserProcess newUserProcess() {
		return (UserProcess)Lib.constructObject(Machine.getProcessClassName());
	}

	/**
	 * Execute the specified program with the specified arguments. Attempts to
	 * load the program, and then forks a thread to run it.
	 *
	 * @param	name	the name of the file containing the executable.
	 * @param	args	the arguments to pass to the executable.
	 * @return	<tt>true</tt> if the program was successfully executed.
	 */
	public boolean execute(String name, String[] args) {
		if (!load(name, args))
			return false;

		new UThread(this).setName(name).fork();

		return true;
	}

	/**
	 * Save the state of this process in preparation for a context switch.
	 * Called by <tt>UThread.saveState()</tt>.
	 */
	public void saveState() {
	}

	/**
	 * Restore the state of this process after a context switch. Called by
	 * <tt>UThread.restoreState()</tt>.
	 */
	public void restoreState() {
		Machine.processor().setPageTable(pageTable);
	}

	/**
	 * Read a null-terminated string from this process's virtual memory. Read
	 * at most <tt>maxLength + 1</tt> bytes from the specified address, search
	 * for the null terminator, and convert it to a <tt>java.lang.String</tt>,
	 * without including the null terminator. If no null terminator is found,
	 * returns <tt>null</tt>.
	 *
	 * @param	vaddr	the starting virtual address of the null-terminated
	 *			string.
	 * @param	maxLength	the maximum number of characters in the string,
	 *				not including the null terminator.
	 * @return	the string read, or <tt>null</tt> if no null terminator was
	 *		found.
	 */
	public String readVirtualMemoryString(int vaddr, int maxLength) {
		Lib.assertTrue(maxLength >= 0);

		byte[] bytes = new byte[maxLength+1];

		int bytesRead = readVirtualMemory(vaddr, bytes);

		for (int length=0; length<bytesRead; length++) {
			if (bytes[length] == 0)
				return new String(bytes, 0, length);
		}

		return null;
	}

	/**
	 * Transfer data from this process's virtual memory to all of the specified
	 * array. Same as <tt>readVirtualMemory(vaddr, data, 0, data.length)</tt>.
	 *
	 * @param	vaddr	the first byte of virtual memory to read.
	 * @param	data	the array where the data will be stored.
	 * @return	the number of bytes successfully transferred.
	 */
	public int readVirtualMemory(int vaddr, byte[] data) {
		return readVirtualMemory(vaddr, data, 0, data.length);
	}

	/**
	 * Transfer data from this process's virtual memory to the specified array.
	 * This method handles address translation details. This method must
	 * <i>not</i> destroy the current process if an error occurs, but instead
	 * should return the number of bytes successfully copied (or zero if no
	 * data could be copied).
	 *
	 * @param	vaddr	the first byte of virtual memory to read.
	 * @param	data	the array where the data will be stored.
	 * @param	offset	the first byte to write in the array.
	 * @param	length	the number of bytes to transfer from virtual memory to
	 *			the array.
	 * @return	the number of bytes successfully transferred.
	 */
	public int readVirtualMemory(int vaddr, byte[] data, int offset,
			int length) {
		Lib.assertTrue(offset >= 0 && length >= 0 && offset+length <= data.length);

		byte[] memory = Machine.processor().getMemory();

		Processor processor = Machine.processor();

		// for now, just assume that virtual addresses equal physical addresses
		//if (vaddr < 0 || vaddr >= memory.length)
		//    return 0;

		int vpn = processor.pageFromAddress(vaddr);
		int addOffset = processor.offsetFromAddress(vaddr);

		if (vpn >= numPages) {
			return -1;
		}


		TranslationEntry tepage = null;
		tepage = pageTable[vpn];
		tepage.used = true;

		int ppn = tepage.ppn;
		int paddr = (ppn*pageSize) + addOffset;

		if (ppn < 0 || ppn >= processor.getNumPhysPages()) {
			Lib.debug(dbgProcess, "\t\t Physical page number invalid "+ppn);
			return 0;
		}


		int amount = Math.min(length, memory.length-paddr);
		System.arraycopy(memory, paddr, data, offset, amount);

		return amount;
	}

	/**
	 * Transfer all data from the specified array to this process's virtual
	 * memory.
	 * Same as <tt>writeVirtualMemory(vaddr, data, 0, data.length)</tt>.
	 *
	 * @paramvaddrthe first byte of virtual memory to write.
	 * @paramdatathe array containing the data to transfer.
	 * @returnthe number of bytes successfully transferred.
	 */

	/**
	 * Transfer data from the specified array to this process's virtual memory.
	 * This method handles address translation details. This method must
	 * <i>not</i> destroy the current process if an error occurs, but instead
	 * should return the number of bytes successfully copied (or zero if no
	 * data could be copied).
	 *
	 * @paramvaddrthe first byte of virtual memory to write.
	 * @paramdatathe array containing the data to transfer.
	 * @paramoffsetthe first byte to transfer from the array.
	 * @paramlengththe number of bytes to transfer from the array to
	 *virtual memory.
	 * @returnthe number of bytes successfully transferred.
	 */
	public int writeVirtualMemory(int vaddr, byte[] data, int offset,
			int length) {
		Lib.assertTrue(offset >= 0 && length >= 0 && offset+length <= data.length);

		byte[] memory = Machine.processor().getMemory();

		Processor processor = Machine.processor();

		// for now, just assume that virtual addresses equal physical addresses
		//if (vaddr < 0 || vaddr >= memory.length)
		//   return 0;


		int vpn = processor.pageFromAddress(vaddr);
		int addOffset = processor.offsetFromAddress(vaddr);

		if (vpn >= numPages) {
			return -1;
		}

		TranslationEntry tepage = null;
		tepage = pageTable[vpn];
		tepage.used = tepage.dirty = true;

		int ppn = tepage.ppn;
		int paddr = (ppn*pageSize) + addOffset;

		if (tepage.readOnly) {
			Lib.debug(dbgProcess, "\t\t Attempting to write to read-only page "+ppn);
			return -1;
		}
		if (ppn < 0 || ppn >= processor.getNumPhysPages()) {
			Lib.debug(dbgProcess, "\t\t Physical page number invalid "+ppn);
			return 0;
		}


		int amount = Math.min(length, memory.length-paddr);
		System.arraycopy(data, offset, memory, paddr, amount);

		return amount;
	}


	/**
	 * Transfer all data from the specified array to this process's virtual
	 * memory.
	 * Same as <tt>writeVirtualMemory(vaddr, data, 0, data.length)</tt>.
	 *
	 * @param	vaddr	the first byte of virtual memory to write.
	 * @param	data	the array containing the data to transfer.
	 * @return	the number of bytes successfully transferred.
	 */
	public int writeVirtualMemory(int vaddr, byte[] data) {
		return writeVirtualMemory(vaddr, data, 0, data.length);
	}

	/**
	 * Transfer data from the specified array to this process's virtual memory.
	 * This method handles address translation details. This method must
	 * <i>not</i> destroy the current process if an error occurs, but instead
	 * should return the number of bytes successfully copied (or zero if no
	 * data could be copied).
	 *
	 * @param	vaddr	the first byte of virtual memory to write.
	 * @param	data	the array containing the data to transfer.
	 * @param	offset	the first byte to transfer from the array.
	 * @param	length	the number of bytes to transfer from the array to
	 *			v
    /**
	 * Load the executable with the specified name into this process, and
	 * prepare to pass it the specified arguments. Opens the executable, reads
	 * its header information, and copies sections and arguments into this
	 * process's virtual memory.
	 *
	 * @param	name	the name of the file containing the executable.
	 * @param	args	the arguments to pass to the executable.
	 * @return	<tt>true</tt> if the executable was successfully loaded.
	 */
	private boolean load(String name, String[] args) {
		Lib.debug(dbgProcess, "UserProcess.load(\"" + name + "\")");

		OpenFile executable = ThreadedKernel.fileSystem.open(name, false);
		if (executable == null) {
			Lib.debug(dbgProcess, "\topen failed");
			return false;
		}

		try {
			coff = new Coff(executable);
		}
		catch (EOFException e) {
			executable.close();
			Lib.debug(dbgProcess, "\tcoff load failed");
			return false;
		}

		// make sure the sections are contiguous and start at page 0
		numPages = 0;
		for (int s=0; s<coff.getNumSections(); s++) {
			CoffSection section = coff.getSection(s);
			if (section.getFirstVPN() != numPages) {
				coff.close();
				Lib.debug(dbgProcess, "\tfragmented executable");
				return false;
			}
			numPages += section.getLength();
		}

		// make sure the argv array will fit in one page
		byte[][] argv = new byte[args.length][];
		int argsSize = 0;
		for (int i=0; i<args.length; i++) {
			argv[i] = args[i].getBytes();
			// 4 bytes for argv[] pointer; then string plus one for null byte
			argsSize += 4 + argv[i].length + 1;
		}
		if (argsSize > pageSize) {
			coff.close();
			Lib.debug(dbgProcess, "\targuments too long");
			return false;
		}

		// program counter initially points at the program entry point
		initialPC = coff.getEntryPoint();	

		// next comes the stack; stack pointer initially points to top of it
		numPages += stackPages;
		initialSP = numPages*pageSize;

		// and finally reserve 1 page for arguments
		numPages++;

		pageTable = new TranslationEntry[numPages];                                        
		for (int i = 0; i < numPages; i++) {                                               
			int ppn = UserKernel.getFreePage();                                           
			pageTable[i] =  new TranslationEntry(i, ppn, true, false, false, false);       
		}                                                                                  


		if (!loadSections())
			return false;

		// store arguments in last page
		int entryOffset = (numPages-1)*pageSize;
		int stringOffset = entryOffset + args.length*4;

		this.argc = args.length;
		this.argv = entryOffset;

		for (int i=0; i<argv.length; i++) {
			byte[] stringOffsetBytes = Lib.bytesFromInt(stringOffset);
			Lib.assertTrue(writeVirtualMemory(entryOffset,stringOffsetBytes) == 4);
			entryOffset += 4;
			Lib.assertTrue(writeVirtualMemory(stringOffset, argv[i]) ==
					argv[i].length);
			stringOffset += argv[i].length;
			Lib.assertTrue(writeVirtualMemory(stringOffset,new byte[] { 0 }) == 1);
			stringOffset += 1;
		}

		return true;
	}

	/**
	 * Allocates memory for this process, and loads the COFF sections into
	 * memory. If this returns successfully, the process will definitely be
	 * run (this is the last step in process initialization that can fail).
	 *
	 * @return	<tt>true</tt> if the sections were successfully loaded.
	 */
	protected boolean loadSections() {
		if (numPages > Machine.processor().getNumPhysPages()) {
			coff.close();
			Lib.debug(dbgProcess, "\tinsufficient physical memory");
			return false;
		}

		// load sections
		for (int s=0; s<coff.getNumSections(); s++) {
			CoffSection section = coff.getSection(s);

			Lib.debug(dbgProcess, "\tinitializing " + section.getName()
			+ " section (" + section.getLength() + " pages)");

			for (int i=0; i<section.getLength(); i++) {
				int vpn = section.getFirstVPN()+i;



				// for now, just assume virtual addresses=physical addresses
				//section.loadPage(i, vpn);

				TranslationEntry tepage = pageTable[vpn];
				tepage.readOnly = section.isReadOnly();
				int ppn = tepage.ppn;

				section.loadPage(i, ppn);
			}
		}

		return true;
	}

	/**
	 * Release any resources allocated by <tt>loadSections()</tt>.
	 */
	protected void unloadSections() {
		for(int i = 0; i < numPages; i++){
			UserKernel.addFreePage(pageTable[i].ppn);
			pageTable[i].valid = false;
		}
	}    

	/**
	 * Initialize the processor's registers in preparation for running the
	 * program loaded into this process. Set the PC register to point at the
	 * start function, set the stack pointer register to point at the top of
	 * the stack, set the A0 and A1 registers to argc and argv, respectively,
	 * and initialize all other registers to 0.
	 */
	public void initRegisters() {
		Processor processor = Machine.processor();

		// by default, everything's 0
		for (int i=0; i<processor.numUserRegisters; i++)
			processor.writeRegister(i, 0);

		// initialize PC and SP according
		processor.writeRegister(Processor.regPC, initialPC);
		processor.writeRegister(Processor.regSP, initialSP);

		// initialize the first two argument registers to argc and argv
		processor.writeRegister(Processor.regA0, argc);
		processor.writeRegister(Processor.regA1, argv);
	}

	/**
	 * Handle the halt() system call. 
	 */
	private int handleHalt() {

		Machine.halt();

		Lib.assertNotReached("Machine.halt() did not halt machine!");
		return 0;
	}

	private int handleCreat(int addr){
		String name = readVirtualMemoryString(addr, 256);

		// size error, too long or failed to read
		//	if (transfer_amount > 256 || transfer_amount < 0){
		//		System.out.println("uh oh!");
		//		return -1; //not sure what to return
		//	}
		//	
		//	boolean SUCCESS = false; //boolean for succesful file creation/open
		int Index = 0; //index of file that is created/opened
		//loop until an empty file    

		OpenFile checkFile = UserKernel.fileSystem.open(name, true);

		if (checkFile == null){
			return -1;
		}

		else {
			for (Index = 0; Index < 16; Index++){
				//if(FilesArray[Index].file_name == name || FilesArray[Index].file == null){
				if(FilesArray[Index].file == null){
					FilesArray[Index].file_name = name;
					FilesArray[Index].file = checkFile;
					return Index;
				}
			}

			return -1;
		}
		//	for(; Index < numFileDesc; Index++){
		/* 
		add the 'or' statement to cover the case of a file already exists with that name
			because although open() handles that, it would never reach that point because the 
			loop previously only looked for 'null' files.
		 */
		//		if(FilesArray[Index].file_name == name){
		//open function provided by nachos
		//			FilesArray[Index].file = UserKernel.fileSystem.open(FilesArray[Index].file_name, true);
		//			FilesArray[Index].file_name = name;
		//			SUCCESS = true;
		//			break; //break out of for loop on successful file open/creation
		//		}
		//	}
		//	if(!SUCCESS){ //failed to find a file to open/create
		//		return -1;
		//	}

		//	return Index; //return opened file in array
	}

	private int handleOpen(int addr){

		String name = readVirtualMemoryString(addr, 256);

		// size error, too long or failed to read
		//      if (transfer_amount > 256 || transfer_amount < 0){
		//              System.out.println("uh oh!");
		//              return -1; //not sure what to return
		//      }
		//      
		//        boolean SUCCESS = false; //boolean for succesful file creation/open
		int Index = 0; //index of file that is created/opened
		//loop until an empty file    

		OpenFile checkFile = UserKernel.fileSystem.open(name, false);

		if (checkFile == null){
			return -1;
		}

		else {
			for (Index = 0; Index < 16; Index++){
				if(FilesArray[Index].file_name == name || FilesArray[Index].file == null){
					FilesArray[Index].file_name = name;
					FilesArray[Index].file = checkFile;
					return Index;
				}
			}

			return -1;
		}
	}
	//	String name = readVirtualMemoryString(addr, 256);

	// size error, too long or failed to read
	//	if (transfer_amount > 256 || transfer_amount < 0){
	//		System.out.println("uh oh!");
	//		return -1; //not sure what to return
	//	}

	//open file, add to file descriptor structure
	///	boolean SUCCESS = false;
	///	int Index = 0;
	///	for(; Index < numFileDesc; Index++){
	//		if(FilesArray[Index].file_name == name){
	//			FilesArray[Index].file = UserKernel.fileSystem.open(name, true);
	//			FilesArray[Index].file_name = name;
	//			SUCCESS = true;
	///			break;
	//		}
	//	}
	///	if(!SUCCESS){
	///		return -1;
	//	}

	//	return Index;
	//  }

	private int handleRead(int Index, int bufa_addr, int limit){

		if(Index < 0 || Index > numFileDesc || FilesArray[Index].file == null){
			return -1;	
		}

		FileDesc temp_file = FilesArray[Index];
		byte[] read_buffer = new byte[limit];
		int bread = temp_file.file.read(read_buffer, 0,limit);

		if(bread > limit){
			return -1;
		}

		writeVirtualMemory(bufa_addr, read_buffer, 0, limit); 
		if(bread < 0){
			return -1;
		}

		return bread;  
	}

	private int handleWrite(int Index, int bufftuff, int limit){

		if(Index < 0 || Index > numFileDesc || FilesArray[Index].file == null){
			return -1;	
		}

		FileDesc temp_file = FilesArray[Index];
		byte[] buffreader = new byte[limit];
		readVirtualMemory(bufftuff, buffreader, 0, limit);

		int bread = temp_file.file.write(buffreader, 0, limit);
		if(bread < 0 || bread < limit){
			return -1;
		}

		return bread;  
	}

	private int handleClose(int Index){

		if(Index < 0 || Index > numFileDesc || FilesArray[Index].file == null){
			return -1;	
		}

		FileDesc toClose = FilesArray[Index];
		int bread = 0; 
		//	FilesArray[Index].file.close();
		//	FilesArray[Index].file_name = "";

		toClose.file.close();


		if(FilesArray[Index].unlinked == true){
			if(UserKernel.fileSystem.remove(toClose.file_name)){
				bread = 0; 
			}
			else{
				bread = -1;
			}
		}


		toClose.file_name = "";

		return bread;


	}

	private int handleUnlink(int Name){

		String filename;
		filename = readVirtualMemoryString(Name, 256);

		int fileFinder = 0;

		for(int i = 0; i < numFileDesc; i++){
			if(FilesArray[i].file_name == filename){
				fileFinder = 1;	
				FilesArray[i].unlinked = true;
			}

		}

		if(fileFinder == 0){
			if(UserKernel.fileSystem.remove(filename)){
				return 0; 
			}
			else{
				return -1;
			}

		}
		return 0;

	}

	private int handleExec(int name_vaddr, int argc_m, int argv_m){
		String name = readVirtualMemoryString(name_vaddr, 256); 
		byte [] argumentsbeforeTrans = new byte[4]; //argv has address of arguments that need to be translated, this will store temp 
		String [] argumentstoString = new String[argc_m]; //arguments after they have been translated from virtual mem.

		for(int x = 0; x < argc_m; x++){
			/* copy each element from argv into temp array, argv points at the beginning of the array, so 
			use offset included within readVirtualMemory?*/
			int argsize = readVirtualMemory(argv_m+x*4, argumentsbeforeTrans); //4bytes = 32 bits = 1 int!
			if(argsize < 1){
				return -1;
			}

			int argumentAddr = Lib.bytesToInt(argumentsbeforeTrans,0); 
			argumentstoString[x] = readVirtualMemoryString(argumentAddr, 256); //store each argmument into new array
			if(argsize < 1){
				return -1;
			}

		}
		/* Create a child to do exec, assign parent's ID to child, update parent's (this) list of children, exectute.*/
		UserProcess child = UserProcess.newUserProcess();
		child.ParentID = this.ID;
		this.CID.add(child.ID); 
		boolean SUCCESS = child.execute(name, argumentstoString);
		if(!SUCCESS){
			//failed to exec!
			return -1;
		}
		return child.ID;
	}

	private int handleJoin(int cid, int status_addr){

		boolean found = false; //set to true when child is found

		/*Go through children list, look for child*/
		Iterator<Integer> currID = this.CID.iterator();
		while(currID.hasNext()){
			int curr_ID = currID.next();
			if(curr_ID == cid){
				/*it exists, remove child*/
				currID.remove();
				found = true;
				break;
			}
		}

		if(!found){
			return -1;
		}

		UserProcess child = getProcess(cid);
		if(child == null){
			return -1; //child does not exist (exited)	  
		}

		child.thread.join();
		dupdateProcesses(cid);

		byte [] ByteIntConversion = new byte[4];
		ByteIntConversion = Lib.bytesFromInt(child.processExit);
		writeVirtualMemory(status_addr, ByteIntConversion);

		if(child.processExit != 0){
			return 0;	  
		}

		else{
			return 1;	  
		}




	}

	private void handleExit(int STATUS){

		for (int i = 0; i < numFileDesc; i++){
			handleClose(i);	  
		}

		// remove children
		Iterator<Integer> currID = this.CID.iterator();
		while(currID.hasNext()){
			int curr_ID = currID.next();
			currID.remove();
			UserProcess childprocess = getProcess(curr_ID);
			childprocess.ParentID = 901;
		}


		this.processExit = STATUS;

		if(this.pid == 901){
			Kernel.kernel.terminate();	  
		}

		else{
			KThread.currentThread().finish();	
		}

		//	this.unloadSections();

	}

	private static final int
	syscallHalt = 0,
	syscallExit = 1,
	syscallExec = 2,
	syscallJoin = 3,
	syscallCreate = 4,
	syscallOpen = 5,
	syscallRead = 6,
	syscallWrite = 7,
	syscallClose = 8,
	syscallUnlink = 9;

	/**
	 * Handle a syscall exception. Called by <tt>handleException()</tt>. The
	 * <i>syscall</i> argument identifies which syscall the user executed:
	 *
	 * <table>
	 * <tr><td>syscall#</td><td>syscall prototype</td></tr>
	 * <tr><td>0</td><td><tt>void halt();</tt></td></tr>
	 * <tr><td>1</td><td><tt>void exit(int status);</tt></td></tr>
	 * <tr><td>2</td><td><tt>int  exec(char *name, int argc, char **argv);
	 * 								</tt></td></tr>
	 * <tr><td>3</td><td><tt>int  join(int pid, int *status);</tt></td></tr>
	 * <tr><td>4</td><td><tt>int  creat(char *name);</tt></td></tr>
	 * <tr><td>5</td><td><tt>int  open(char *name);</tt></td></tr>
	 * <tr><td>6</td><td><tt>int  read(int fd, char *buffer, int size);
	 *								</tt></td></tr>
	 * <tr><td>7</td><td><tt>int  write(int fd, char *buffer, int size);
	 *								</tt></td></tr>
	 * <tr><td>8</td><td><tt>int  close(int fd);</tt></td></tr>
	 * <tr><td>9</td><td><tt>int  unlink(char *name);</tt></td></tr>
	 * </table>
	 * 
	 * @param	syscall	the syscall number.
	 * @param	a0	the first syscall argument.
	 * @param	a1	the second syscall argument.
	 * @param	a2	the third syscall argument.
	 * @param	a3	the fourth syscall argument.
	 * @return	the value to be returned to the user.
	 */
	public int handleSyscall (int syscall, int a0, int a1, int a2, int a3) {

		switch (syscall) {

		case syscallHalt:{
			return handleHalt();
		}
		case syscallCreate:{	
			return handleCreat(a0);	
		}	
		case syscallOpen:{
			return handleOpen(a0);	
		}
		case syscallRead:{
			return handleRead(a0, a1, a2);	
		}
		case syscallWrite:{
			return handleWrite(a0, a1, a2);	
		}
		case syscallClose:{
			return handleClose(a0);	
		}
		case syscallUnlink:{
			return handleUnlink(a0);	
		}
		case syscallExec:{
			return handleExec(a0, a1, a2);
		}
		case syscallJoin:{
			return handleJoin(a0, a1);	
		}
		case syscallExit:{
			handleExit(a0);
			return 0;
		}

		default:{
			Lib.debug(dbgProcess, "Unknown syscall " + syscall);
			Lib.assertNotReached("Unknown system call!");
		}

		}
		return 0;
	}

	/**
	 * Handle a user exception. Called by
	 * <tt>UserKernel.exceptionHandler()</tt>. The
	 * <i>cause</i> argument identifies which exception occurred; see the
	 * <tt>Processor.exceptionZZZ</tt> constants.
	 *
	 * @param	cause	the user exception that occurred.
	 */
	public void handleException(int cause) {
		Processor processor = Machine.processor();

		switch (cause) {
		case Processor.exceptionSyscall:
			int result = handleSyscall(processor.readRegister(Processor.regV0),
					processor.readRegister(Processor.regA0),
					processor.readRegister(Processor.regA1),
					processor.readRegister(Processor.regA2),
					processor.readRegister(Processor.regA3)
					);
			processor.writeRegister(Processor.regV0, result);
			processor.advancePC();
			break;				       

		default:
			Lib.debug(dbgProcess, "Unexpected exception: " +
					Processor.exceptionNames[cause]);
			Lib.assertNotReached("Unexpected exception");
		}
	}



	public UserProcess getProcess(int id){
		return Processes.get(id);	
	}

	public UserProcess updateProcesses(int proc_id, UserProcess proc){
		UserProcess inserted;                            
		Machine.interrupt().disable();                             
		inserted = Processes.put(proc_id, proc);          
		Machine.interrupt().enabled();                            
		return inserted;      
	}

	public UserProcess dupdateProcesses(int proc_id){
		UserProcess deleted;                            
		Machine.interrupt().disable();                             
		deleted = Processes.remove(proc_id);          
		Machine.interrupt().enabled();                            
		return deleted;      
	}

	private LinkedList <Integer> CID = new LinkedList<Integer>();

	protected int pid = 900;

	public int getpid(){
		//Machine.interrupt.disable();
		return ++pid;
		//Machine.interrupt.enanbled();
	}


	protected final int numFileDesc = 16; //our chosen size for amount of files a process can have open

	protected int ID;
	protected int ParentID;


	private UserProcess pProcess;
	private OpenFile in;
	private OpenFile out;

	private HashMap<Integer, UserProcess> Processes; 

	UThread thread;

	protected FileDesc[] FilesArray;

	/** The program being run by this process. */
	protected Coff coff;

	/** This process's page table. */
	protected TranslationEntry[] pageTable;
	/** The number of contiguous pages occupied by the program. */
	protected int numPages;

	/** The number of pages in the program's stack. */
	protected final int stackPages = 8;

	private int initialPC, initialSP;
	private int argc, argv;

	private int processExit;

	private static final int pageSize = Processor.pageSize;
	private static final char dbgProcess = 'a';

}
