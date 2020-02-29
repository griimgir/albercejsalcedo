package nachos.threads;
import nachos.ag.BoatGrader;
import java.util.*;

public class Boat
{
    static BoatGrader bg;
    static int remaining_on_Oahu;
    static int adults_on_Oahu;
    static int children_on_Oahu;
    static int children_on_Molokai;
    static ArrayList<KThread> cO;
    static ArrayList<KThread> cM;
    static ArrayList<KThread> a;
    
    public static void selfTest()
    {
	BoatGrader b = new BoatGrader();
	
	System.out.println("\n ***Testing Boats with only 2 children***");
	begin(15, 15, b);

//	System.out.println("\n ***Testing Boats with 2 children, 1 adult***");
//  	begin(1, 2, b);

//  	System.out.println("\n ***Testing Boats with 3 children, 3 adults***");
//  	begin(3, 3, b);
    }

    public static void begin( int adults, int children, BoatGrader b )
    {
	// Store the externally generated autograder in a class
	// variable to be accessible by children.
	bg = b;

	// Instantiate global variables here
	
	// we want to initialize a value that will be known by people on Oahu
	//	once this value is zero, there is no one left to transport to Molokai
	remaining_on_Oahu = adults + children;
	adults_on_Oahu = adults;
	children_on_Oahu = children;
	children_on_Molokai = 0;
	
	// Create threads here. See section 3.4 of the Nachos for Java
	// Walkthrough linked from the projects page.

	Runnable r = new Runnable() {
	    public void run() {
                AdultItinerary();
            }
        };
        KThread t = new KThread(r);
        t.setName("Sample Boat Thread");
        t.fork();

    cO = new ArrayList<KThread>();
	    for (int i = 0; i < children; i++) {
		cO.add( new KThread(r) ); 
		cO.get(i).setName("child"); 
		cO.get(i).fork();
	    }
	a = new ArrayList<KThread>();
	    for (int i = 0; i < adults; i++) {
		a.add( new KThread(r) ); 
		a.get(i).setName("adult"); 
		a.get(i).fork();
	    }
	r.run();
    }

    static void AdultItinerary()
    {
	/* This is where you should put your solutions. Make calls
	   to the BoatGrader to show that it is synchronized. For
	   example:
	       bg.AdultRowToMolokai();
	   indicates that an adult has rowed the boat across to Molokai
	*/
	boolean complete_job = false;
	cM = new ArrayList<KThread>();
	System.out.println("\n ***Beginning Transfer of People***");
	    // first action will always be this, since at least 2 children will always be present
	System.out.println("\n ***First Action: 2 Children Row to Molokai***");
	    bg.ChildRowToMolokai();
		    //cO.get(children_on_Oahu-1).sleep();
		    cM.add( cO.get(children_on_Oahu-1) );
		    cO.remove(children_on_Oahu-1);
			children_on_Molokai++;
			children_on_Oahu--;
			remaining_on_Oahu--;
	    bg.ChildRideToMolokai();
		    //cO.get(children_on_Oahu-1).ready();
		    cM.add( cO.get(children_on_Oahu-1) );
		    cO.remove(children_on_Oahu-1);
			children_on_Molokai++;
			children_on_Oahu--;
			remaining_on_Oahu--;
	
	System.out.println("\n ***One child Rows back to Oahu to allow another person to get to Molokai");
	    bg.ChildRowToOahu();
		    //cM.get(children_on_Molokai-1).ready();
		    cO.add( cM.get(children_on_Molokai-1) );
		    cM.remove(children_on_Molokai-1);
			children_on_Molokai--;
			children_on_Oahu++;
			remaining_on_Oahu++;
	    
	    
	    // the following will accompany the boatgrader actions to synchronize with the actual threads
	    // i.e. a[ adults_on_Oahu - 1 ] / .finish()
	    // i.e. cO[ children_on_Oahu - 1 ] / .ready()
	    // i.e. cM[ children_on_Molokai -1 ] / .ready() / .sleep()
	    
		    // when Adult rows to Molokai ==> adult.finish()
		    // when Child rows to Molokai ==> child.sleep()
		    // when Child rides to Molokai ==> child.ready()
		    // when Child rows to Oahu ==> child.ready()
	    
	    
	    // loop the following until no people remain on Oahu
	while (!complete_job) {
	 
	    	if (adults_on_Oahu > 0) {
		System.out.println("\n ***An Adult is available and rows to Molokai*** \n ***We repeat the 2 Children management of boat***" );
			bg.AdultRowToMolokai();
				//a.get(adults_on_Oahu-1).finish();
				a.remove(adults_on_Oahu-1);
					adults_on_Oahu--;
					remaining_on_Oahu--;
			bg.ChildRowToOahu();
				//cM.get(children_on_Molokai-1).ready();
				//cM.get(children_on_Molokai-1).ready();
				cO.add( cM.get(children_on_Molokai-1) );
				cM.remove(children_on_Molokai-1);
					children_on_Molokai--;
					children_on_Oahu++;
					remaining_on_Oahu++;
			bg.ChildRowToMolokai();
				//cO.get(children_on_Oahu-1).sleep();
				cM.add( cO.get(children_on_Oahu-1) );
				cO.remove(children_on_Oahu-1);
					children_on_Molokai++;
					children_on_Oahu--;
					remaining_on_Oahu--;
	    	bg.ChildRideToMolokai();
				//cO.get(children_on_Oahu-1).ready();
				cM.add( cO.get(children_on_Oahu-1) );
				cO.remove(children_on_Oahu-1);
					children_on_Molokai++;
					children_on_Oahu--;
					remaining_on_Oahu--;
			bg.ChildRowToOahu();
				//cM.get(children_on_Molokai-1).ready();
				cO.add( cM.get(children_on_Molokai-1) );
				cM.remove(children_on_Molokai-1);
					children_on_Molokai--;
					children_on_Oahu++;
					remaining_on_Oahu++;
		}
		else if ((adults_on_Oahu == 0) && (remaining_on_Oahu > 1)) { 
		System.out.println("\n ***No Adult is available*** \n  ***We repeat the 2 Children management of boat***" );
			bg.ChildRowToMolokai();
				//cO.get(children_on_Oahu-1).sleep();
				cM.add( cO.get(children_on_Oahu-1) );
				cO.remove(children_on_Oahu-1);
					children_on_Molokai++;
					children_on_Oahu--;
					remaining_on_Oahu--;
	    	bg.ChildRideToMolokai();
				//cO.get(children_on_Oahu-1).ready();
				cM.add( cO.get(children_on_Oahu-1) );
				cO.remove(children_on_Oahu-1);
					children_on_Molokai++;
					children_on_Oahu--;
					remaining_on_Oahu--;
			bg.ChildRowToOahu();
				//cM.get(children_on_Molokai-1).ready();
				cO.add( cM.get(children_on_Molokai-1) );
				cM.remove(children_on_Molokai-1);
					children_on_Molokai--;
					children_on_Oahu++;
					remaining_on_Oahu++;
		}
		else { 
		System.out.println("\n ***No One is left on Oahu, Child returns to Molokai to Finish ");
			bg.ChildRowToMolokai();
				//cM.get(children_on_Molokai-1).ready();
				cO.add( cM.get(children_on_Molokai-1) );
				cM.remove(children_on_Molokai-1);
					children_on_Molokai++;
					children_on_Oahu--;
					remaining_on_Oahu--;
			
			complete_job = true;
		}
	}
	System.out.println("\n ***Finished Transfer of People");
    }

    static void ChildItinerary()
    {
    }

    static void SampleItinerary()
    {
	// Please note that this isn't a valid solution (you can't fit
	// all of them on the boat). Please also note that you may not
	// have a single thread calculate a solution and then just play
	// it back at the autograder -- you will be caught.
	System.out.println("\n ***Everyone piles on the boat and goes to Molokai***");
	bg.AdultRowToMolokai();
	bg.ChildRideToMolokai();
	bg.AdultRideToMolokai();
	bg.ChildRideToMolokai();
    }
    
}
