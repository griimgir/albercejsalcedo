package nachos.threads;

import java.util.Comparator;
import java.util.Iterator;
import java.util.TreeSet;

import nachos.machine.*;

/**
 * Uses the hardware timer to provide preemption, and to allow threads to sleep
 * until a certain time.
 */

class SortbyTime implements Comparator<KThread>{
	
	//comparing the threads, returns an int that determines what to do with threads
	public int compare(KThread newThread, KThread oldThread) {
		//checks the alarm_time() of current and next thread
		if(newThread.alarm_time > oldThread.alarm_time) {
			//if current thread is greater
			//return 1 to indicate a swap
			return 1;
		}
		else{         //(newThread.alarm_time() < oldThread.alarm_time()) {
			//if current thread is less
			//return -1 to indicate that
			return -1;
		}
	}
}


public class Alarm {
    /**
     * Allocate a new Alarm. Set the machine's timer interrupt handler to this
     * alarm's callback.
     *
     * <p><b>Note</b>: Nachos will not function correctly with more than one
     * alarm.
     */
	
    public Alarm() {
	Machine.timer().setInterruptHandler(new Runnable() {
		public void run() { timerInterrupt(); }
	    });
		waiting = new TreeSet<KThread>(new SortbyTime());
    }
    
    /**
     * The timer interrupt handler. This is called by the machine's timer
     * periodically (approximately every 500 clock ticks). Causes the current
     * thread to yield, forcing a context switch if there is another thread
     * that should be run.
     */
    public void timerInterrupt() {
    	
    	//created an iterator variable to traverse the tree
    	
    	Iterator<KThread> i = waiting.iterator();
    	//while there are still elements in the tree 
    	while(i.hasNext()) {
    		//check if this current thread's alarm time is less than or equal the current time
    		//that means the time is up
    		if(i.next().alarm_time <= Machine.timer().getTime()) {
    			//put thread in ready queue (KThread.ready())
    			i.next().ready();
    			//remove from treeset
    			i.remove();	
    		}else {
    			//if the alarm_time is greater
    			//leave the while loop
    			break;
    		}
    		
    	}
    	KThread.currentThread().yield();
    }

    /**
     * Put the current thread to sleep for at least <i>x</i> ticks,
     * waking it up in the timer interrupt handler. The thread must be
     * woken up (placed in the scheduler ready set) during the first timer
     * interrupt where
     *
     * <p><blockquote>
     * (current time) >= (WaitUntil called time)+(x)
     * </blockquote>
     *
     * @param	x	the minimum number of clock ticks to wait.
     *
     * @see	nachos.machine.Timer#getTime()
     */
    public void waitUntil(long x) {
	// for now, cheat just to get something working (busy waiting is bad)
	
    long wakeTime = Machine.timer().getTime() + x;
	
    
	//while (wakeTime > Machine.timer().getTime())
	//
	//
	//created a treeset of long, input is the Thread's alarm_time element
		KThread.currentThread().alarm_time = wakeTime;
		waiting.add(KThread.currentThread());
	//sortList(waiting);
		KThread.yield();
    
    }
    
 //   public void sortList(KThread thread) {
 //   	Iterator index = waiting.iterator();
 //   	while(index.next() != null) {
 //   		if(index > index.next()) {
 //   			
 //   		}
 //   	}
//   }

    //TreeSet<long> waiting;
    
   TreeSet<KThread> waiting;
   
   
}

