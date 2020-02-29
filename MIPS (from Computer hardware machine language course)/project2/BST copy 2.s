.data 
# Worked with Elyse Geimer
# recources used to geeks4geeks to see C code and other online recourses for ASM
# register used in functions after end, where we start implamenting
arrayList: .space 100 
sorted_list: .space 100

str0: .asciiz "Enter size of list (between 1 and 25): "
str1: .asciiz "Enter one list element: \n"
str2: .asciiz "Content of original list: "
str3: .asciiz "\nEnter a key to search for: "
str4: .asciiz "\nContent of sorted list: "
strYes: .asciiz "Key found!"
strNo: .asciiz "Key not found!"
.text 

#This is the main program.
#It first asks user to enter the size of a list.
#It then asks user to input the elements of the list, one at a time.
#It then calls printList to print out content of the list.
#It then calls inSort to perform insertion sort
#It then asks user to enter a search key and calls bSearch on the sorted list.
#It then prints out search result based on return value of bSearch
main: 
	addi $sp, $sp -8
	sw $ra, 0($sp)
	li $v0, 4 
	la $a0, str0 
	syscall 
	li $v0, 5	#read size of list from user
	syscall
	move $s0, $v0
	move $t0, $0
	la $s1, arrayList	#had to change because later I used arrayList instead
loop_in:
	li $v0, 4 
	la $a0, str1 
	syscall 
	sll $t1, $t0, 2
	add $t1, $t1, $s1
	li $v0, 5	#read elements from user
	syscall
	sw $v0, 0($t1)
	addi $t0, $t0, 1
	bne $t0, $s0, loop_in
	move $a0, $s1
	move $a1, $s0
	
	jal inSort	#Call inSort to perform insertion sort in original list
	
	sw $v0, 4($sp)
	li $v0, 4 
	la $a0, str2 
	syscall 
	la $a0, arrayList
	move $a1, $s0
	jal printList	#Print original list
	li $v0, 4 
	la $a0, str4 
	syscall 
	lw $a0, 4($sp)
	jal printList	#Print sorted list
	
	li $v0, 4 
	la $a0, str3 
	syscall 
	li $v0, 5	#read search key from user
	syscall
	move $a3, $v0
	lw $a0, 4($sp)
	jal BSTSearch	#call BSTSearch to perform binary search
	
	beq $v0, $0, notFound
	li $v0, 4 
	la $a0, strYes 
	syscall 
	j end
	
notFound:
	li $v0, 4 
	la $a0, strNo 
	syscall 
end:
	lw $ra, 0($sp)
	addi $sp, $sp 8
	li $v0, 10 
	syscall       
        
#printList takes in a list and its size as arguments. 
#It prints all the elements in one line.
printList:
        #Your implementation of printList here  
        #Note a0 is the sorted list     <------------------KEEP TRACK OF THIS--------------------
        #note t4 is to load imidiates directly
        #create a pointer of A which starts at A[0] in $t1
        move $t1, $a0
        #then we directly load 0 into $s0, to incrament in the future
        li $s0, 0
        
loop:
        #setless than and s0 which is equivalent to "i = 0".
        #doing slt, creates i < n in C, then stores 0 -> $t1 when it fails
        slt $t0, $s0, $a1
        beq $t0, $zero, break #breaks when $s0 <= 
        #n

        #li $t3, 4 #<------ this is for incrementing later

        # sets $a0 = $t1
        lw $a0, 0($t1)
        li $t4, 1
        lw $v0, 0($t4) #####################################
        syscall
        #then loads 32 into $a0
        li $t4, 32
        #t4 is 32 bits
        lw $a0, 0($t4)
        li $v0, 11      #recieved help for this one
        syscall         #what it does it that 32 puts a space and 11 prints the space
        
        addi $t1, $t1, 4 #add 4 to a0 which in C, increments 1 in the element. 4 bytes in each integer block
        addi $s0, $s0, 1 #this line the increments 1, i++ in C
        j loop #return to loop
        
break:
        li $v0, 4
        la $a0, arrayList   
        jr $ra
        
#inSort takes in a list and it size as arguments. 
#It performs INSERTION sort in ascending order and returns a new sorted list
#You may use the pre-defined sorted_list to store the result
inSort:
        #Your implementation of inSort here
        li $t1, 1 #sets t1 = 1
        li $t2, 0 #set a new t2 = 0, this is for t1 -> t2 later. Transfering
        la $t8, arrayList #transfers array position in arrayList
        
        la $t9, sorted_list #loads address of sorted_list to $t9, its job is to copy the array

copy:
        bgt $t1, $a1, reset #greater than, go to reset
        lw $t5, ($t8)   #loads arrayList to t5
        sw $t5, ($t9)   #stores the arraylist to sorted
        addi $t8, $t8, 4 #increments +1 in C which is 4 bytes since its type int
        addi $t9, $t9, 4 #increments +1 in C which is 4 bytes since its type int
        addi $t1, $t1, 1 #incrememnt t1++ or i++ in C
        j copy
        
        
reset:
        la $t9, sorted_list

sort:       
        bge $t2, $a1, end2 #exits to end if a1 is less than t2
        move $t3, $t2
        
whileLoop:
        mul $t5, $t3, 4 
        add $t0, $t9, $t5 # stores A[i * 4]
        
        ble $t3, 0, terminate # if t3 < 0 loop will terminate
        
        lw $t7, 0($t0) # t7 is the a position in the arrayList
        lw $t6, -4($t0)# t6 is position - 1, hence the -4
        bge $t7, $t6, terminate #if arrarList[i] > arrList[j-i] it will terminate
        lw $t4, 0($t0) # t4 position in arrayList
        sw $t6, 0($t0) 
        sw $t4, -4($t0) # $t4 is position - 1, hence the -4
        
        subi $t3, $t3, 1
        j whileLoop
        
terminate:      #ends while loop
        addi $t2, $t2, 1 #increment t2 by 1: t2++
        j sort

end2:
        la $v0, sorted_list
        jr $ra  

#BSTSearch takes in a list, its size, and a search key as arguments.
#It performs binary search RECURSIVELY to look for the search key.
#It will return a 1 if the key is found, or a 0 otherwise.
#Note: you MUST NOT use iterative approach in this function.
BSTSearch:
        #sw $s0, $s1 ->$sp
        #sw $s0, 0($s1)
        # a0 is the sorted list
        # a3 is the value being searched for
        # a1 is the size
        
        addi $sp, $sp, -4
        sw $ra, 0($sp) #grabs the address of this pointer and stores it to ra
        
        bne $s3, $zero, jumpAddy
        add $s0, $zero, $zero #beggining of the array
        addi $s3, $zero, 1
        
jumpAddy:
        bgt $s0, $a1, reset2 #terminates when lowerbound < upperbound
        addi $t3, $zero, 4
        add $t1, $a1, $s0 # adds: start + end
        sra $t1, $t1, 1 # function in c: (start + end)/2 this function is used any of my recursion labs in CSE100
        mul $t3, $t3, $t1 #t3 * 4
        add $t0, $t3, $a0 
        lw $t2, 0($t0) 
        beq $t2, $a3, captured #if found, terminates and jumps to captured
        
        bgt $t2, $a3, Blow # if the middle is less than the key than we traverse through the BST 

Bup:
        addi $s0, $t1, 1
        j BSTSearch #recurse the BST
        
Blow:
        addi $a1, $t1, -1 
        j BSTSearch     #recurse the BST
        
captured:
        addi $v0, $zero, 1 #terminates loop and returns 1 to indicate it is found
        j return

reset2:     #returns 0 to indicate it was not found
        add $v0, $zero, $zero      
           
return:
        sw $ra, 0($sp)
        addi $sp, $sp, 4 #cleans the stack. house keeping
        jr $ra           #cleans pointers
