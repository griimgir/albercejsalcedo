#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

long ascii = 97;

int transform(char x){
    return ((int)x - 32) % ascii;
}

bool search(string* array, int size, string key){
    for (int i = 0; i < size; i++) {
        if (key == array[i]){
            return true;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    
    //const int N = 500000;
    
    ifstream in("words.txt");
    
    string word;
    
    //string* words = new string[N];

    vector<string> words;

    int count = 0;
    
    while (in >> word) {
        words.push_back(word);
        count++;
    }

vector<string> a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, weirdshit;

    for( int i = 0; i < words.size(); i++){
        vector<int> array1 = transform(words[i].at(0));
    }
    
    cout << "Total: " << count << endl << endl;
    
    cout << "| Matching Progress:                      |\n|";
    int matched = 0;
    //int ascii = 97;
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
