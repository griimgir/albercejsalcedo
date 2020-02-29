package nachos.threads;

import nachos.machine.*;
import java.util.LinkedList;

/**
 * A <i>communicator</i> allows threads to synchronously exchange 32-bit
 * messages. Multiple threads can be waiting to <i>speak</i>,
 * and multiple threads can be waiting to <i>listen</i>. But there should never
 * be a time when both a speaker and a listener are waiting, because the two
 * threads can be paired off at this point.
 */
public class Communicator {
    /**
     * Allocate a new communicator.
     */
    public Communicator() {


    
    }

    /*
     * Wait for a thread to listen through this communicator, and then transfer
     * <i>word</i> to the listener.
     *
     * <p>
     * Does not return until this thread is paired up with a listening thread.
     * Exactly one listener should receive <i>word</i>.
     *
     * @param	word	the integer to transfer.
     */


	/* !! I am working under the assumption that we do NOT use the wakeALL !! */

    public void speak(int word) {
	lokc.acquire();
	Wspeaker++;
	
	/* sleep if no room to speak */
	while(radioTower == true){
		speak.sleep();
	}

	/* Time to speak! */
	Lib.assertTrue(lokc.isHeldByCurrentThread());
	radioTower = true;
	this.message = word;

	/* wake listener */
	while(Wlistener == 0) {
	speak.sleep();
	}
	listen.wake(); //speaker goes to sleep, then is woken after listen finishes waking.

	Wspeaker--;
	lokc.release();
	
    }

    /**
     * Wait for a thread to speak through this communicator, and then return
     * the <i>word</i> that thread passed to <tt>speak()</tt>.
     *
     * @return	the integer transferred.
     */    
    public int listen() {
	/* message to be returned */
	int communicated;

	lokc.acquire();
	Wlistener++;

	while(radioTower == false /*|| Wspeaker != 0*/) {
		speak.wake();
		listen.sleep();
	}
	
	/* else there is a message in the radioTower! */
	Lib.assertTrue(lokc.isHeldByCurrentThread());
	communicated = message;
	radioTower = false;
	Wlistener--;
	speak.wake();
	lokc.release();	

	return communicated;
    }

    /* speaker tester*/
    private static class Speak implements Runnable {
    	Speak(Communicator g, int message){
    		this.g = g;
    		this.message = message;
    	}
    	
    	public void run() {
    		g.speak(message);
    		System.out.println("Speaking data:" + message);
    		message++;
    		g.speak(message);
    		System.out.println("Speaking data:" + message);
    		message++;
    		g.speak(message);
    		System.out.println("Speaking data:" + message);
    	}
    	
    	private Communicator g;
    	private int message;
    }
    
    /* listener tester */
    private static class Listen implements Runnable{
    	Listen(Communicator t){
    		this.t = t;
    	}
    	
    	public void run() {
    		Machine.halt();

    		message = t.listen();
    		System.out.println("Listened to first message: " + message);
    		message = t.listen();
    		System.out.println("Listened to second message: " + message);
    		message = t.listen();
    		System.out.println("Listened to third message: " + message);
    	}
    	
    	private Communicator t;
    	private int message;
    }
    
//    public static void selfTest() {
//    	/* open communicator for threads to communicate*/
//    	/* they will share the communicator! */
//    	Communicator phi = new Communicator();
//    	
//    	/* create thread to speak */
//    	KThread carrera = new KThread(new Speak(phi, 964));    	
//    	carrera.setName("Carrera");
//    	KThread cayman = new KThread(new Listen(phi));
//    	cayman.setName("Cayman");
//    	KThread panamera = new KThread(new Speak(phi, 993));
//    	panamera.setName("Panamera");
//    	
//    	carrera.fork();
//    	cayman.fork();
//    	panamera.fork();
//    	
//    	new Listen(phi).run();
//    }
    
    
	/* variables go here at the bottom, not in the constructor :x */
	private int message = 0; //this worked for single messages
	private int Wspeaker = 0; 
	private int Wlistener = 0;
	boolean radioTower = false;
	private Lock lokc = new Lock();
	private Condition speak = new Condition(lokc);
	private Condition listen = new Condition(lokc);
	//private LinkedList<KThread> speakerQueue;
	//private LinkedList<KThread> listenerQueue;
	private LinkedList<Integer> inbox = new LinkedList<Integer>(); //for multiple messages !
}
