#include <stdlib.h> 
#include <iostream>
#include "TimeSupport.h"
using namespace std;

int main(){

cout << "Welcome to Math Skills!" << endl;

    int qn = 0, x = 0, answer = 0;
    int totalQuestions = 10;
    for(int i = 0; i < totalQuestions; i++){
    timestamp start = current_time();
        int a = rand() % 10;
        int b = rand() % 10;
        cout << i + 1 << ". " << a << " + " << b << " = ";
        cin >> x;
        answer = a + b;
        if(answer != x){
            cout<< "That's incorrect" << endl;
        }
    timestamp end = current_time();
    long duration = time_diff(start, end);
    int seconds = duration / 1000;
    cout << "It took you " << seconds << " seconds" << endl;
    }   
    return 0;
}