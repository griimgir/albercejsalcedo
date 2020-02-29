#include <iostream>
#include "TimeSupport.h"
#include "RandomSupport.h"
#include "Array.h"
#include "LinkedList.h"

using namespace std;

int main(int argc, const char * argv[]) {

    // Control variables
    int N = 10000;
    bool back = true;
    
    
    cout << "N = " << N << endl;
    if (back){
        cout << "Inserting at the end." << endl;
    }
    else {
        cout << "Inserting at the beginning." << endl;
    }
    
    cout << endl;

    cout << "Linked List Experiment" << endl;

    LinkedList myLinkedList;

    // Complete linked list experiment
    //timestamp btime = current_time();
    //timestamp etime = current_time();

    timestamp btime = current_time();

    myLinkedList = LinkedList();
    if(back){
        while(back){
            for(int i = 0; i < N; i++){
                myLinkedList.append(i);
                cout << myLinkedList.valueAt(i) << endl;;
            }
            break;
        }
    }  
    else{
        for(int i = 0; i < N; i++){
            myLinkedList.insertAt(0,i);
        }
    }
    timestamp etime = current_time();
    long calcdiff = time_diff(btime, etime);  
    cout << "It took time: " << calcdiff << "ms" << endl;



    cout << endl << "Array Experiment" << endl;
    ResizableArray myArray;

   // Complete array experiment

    timestamp arrayB = current_time();
    if(back){
        for(int i = 0; i < N; i++){
            myArray.append(i);
        }
    }
        else{
            for(int i = 0; i < N; i++){
                myArray.insertAt(0, i);
            }
        }


    timestamp arrayE = current_time();
    long calcAdiff = time_diff(arrayB, arrayE);
    cout << "It took time: " << calcAdiff << "ms" << endl;

    return 0;
}














//#include <iostream>
//#include "TimeSupport.h"
//#include "TimeSupport.h"
//#include "Array.h"
//#include "LinkedList.h"
//
//using namespace std;
//
//int main(int argc, const char * argv[]) {
//
//    cout << "Linked List Stuff" << endl;
//
//    LinkedList myLinkedList;
//
//    myLinkedList.append(5);
//    myLinkedList.append(7);
//    myLinkedList.append(3);
//
//    myLinkedList.print();
//
//    cout << myLinkedList.valueAt(2) << endl;
//
//
//    cout << endl << "Array Stuff" << endl;
//
//    ResizableArray myArray;
//
//    myArray.append(5);
//    myArray.append(7);
//    myArray.append(3);
//
//    myArray.print();
//
//    cout << myArray.valueAt(2) << endl;
//
//    return 0;
//}
