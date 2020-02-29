package nachos.threads;

import java.util.LinkedList;

import nachos.machine.*;

/**
 * An implementation of condition variables that disables interrupt()s for
 * synchronization.
 *
 * <p>
 * You must implement this.
 *
 * @see	nachos.threads.Condition
 */
public class Condition2 {
    /**
     * Allocate a new condition variable.
     *
     * @param	conditionLock	the lock associated with this condition
     *				variable. The current thread must hold this
     *				lock whenever it uses <tt>sleep()</tt>,
     *				<tt>wake()</tt>, or <tt>wakeAll()</tt>.
     */
    public Condition2(Lock conditionLock) {
	this.conditionLock = conditionLock;
	waitingThreads = new LinkedList<KThread>();
	//boolean condition; 	   
    }

    /**
     * Atomically release the associated lock and go to sleep on this condition
     * variable until another thread wakes it using <tt>wake()</tt>. The
     * current thread must hold the associated lock. The thread will
     * automatically reacquire the lock before <tt>sleep()</tt> returns.
     */
    public void sleep() {
	Lib.assertTrue(conditionLock.isHeldByCurrentThread());
	boolean intStatus = Machine.interrupt().disable();
	    
	condition = false; //condition variable, will be set to true during wake
	waitingThreads.add(KThread.currentThread()); //add thread to wait queue
	Machine.interrupt().restore(intStatus);
	conditionLock.release();
	    
    	//ConditionWaitQueue.waitForAccess(Kthread.currentThread()); //set to 'waiting for access'
	while(condition == false){
	intStatus = Machine.interrupt().disable();
	KThread.sleep(); //sleep until woken
    	}    
    	//WAKE!
	Machine.interrupt().restore(intStatus);
	conditionLock.acquire(); //get lock and proceed to do work
    }

    /**
     * Wake up at most one thread sleeping on this condition variable. The
     * current thread must hold the associated lock.
     */
    public void wake() {
	Lib.assertTrue(conditionLock.isHeldByCurrentThread());
	boolean intStatus = Machine.interrupt().disable();
	
	if(!waitingThreads.isEmpty()){    
		KThread thread = waitingThreads.getFirst();//grab a thread to receive access
		waitingThreads.removeFirst(); //take thread off wait queue
		condition = true;
		thread.ready();//move thread to ready state
	}
	Machine.interrupt().restore(intStatus);
    }

    /**
     * Wake up all threads sleeping on this condition variable. The current
     * thread must hold the associated lock.
     */
    public void wakeAll() {
	Lib.assertTrue(conditionLock.isHeldByCurrentThread());
	/* disable interrupts? */
	while(!waitingThreads.isEmpty()){
		wake();
	}
    }

    	private Lock conditionLock; //lock for locking purposes
	
	/*
	thread queue and linked list that stores threads, unsure why we need both, one is to modify
	the state of thread (waiting for access or ready) and the other just stores threads that are waiting. 
	It seems like thread queue stores threads, but there isn't an obvious way to add/remove threads, which is
	where the linked list comes in, to keep track of threads. This makes it seem like threadqueue is pointless?
	*/
	//private ThreadQueue ConditionWaitQueue;	
	private LinkedList<KThread> waitingThreads = new LinkedList<KThread>();
	/* enabling/disabling interrupts to protect changes to this linked list */
	private boolean condition; //not sure if need to intialize to true or false...
}
