#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool search(string* array, int size, string key){
    for (int i = 0; i < size; i++) {
        if (key == array[i]){
            return true;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    
    const int N = 500000;
    
    ifstream in("words.txt");
    
    string word;
    
    string* words = new string[N];

    int count = 0;
    
    while (in >> word) {
        words[count] = word;
        count++;
    }
    
    cout << "Total: " << count << endl << endl;
    
    cout << "| Matching Progress:                      |\n|";
    int matched = 0;
    
    for (int i = 0; i < N; i++){
        string curr = words[i];
        reverse(curr.begin(), curr.end());
        
        if (search(words, N, curr)){
            //cout << words[i] << " = " << curr << endl;
            matched ++;
        }
        if (i % (N/40) == 0) cout << "-";
    }
    cout << "|" << endl;
    
    
    cout << "Matched: " << matched << endl;
    return 0;
}
