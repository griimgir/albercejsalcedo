#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

void getLetter(string str){
    cout << str.at(0) << endl;
}

 int main(int argc, const char * argv[]){




    string rw = "Hello";
    reverse(rw.begin(), rw.end());
    cout << rw << endl;
//     const int N = 500000;
    
//     ifstream in("words.txt");
    
//     string word;
    
//     string* words = new string[N];

//     int count = 0;
    
//     while (in >> word) {
//         words[count] = word;
//         count++;
       
//     }

//     cout << words[300] << endl;
//      return 0;
// }

/*
    string word;
    vector<string> words, test;

    ifstream in("words.txt");

int count = 0;
while (in >> word) {
    words.push_back(word);
    count++;
}

for(int i = 10; i < 50; i++){
    cout << words[i] << endl;
    getLetter(words[i]);
}

test.push_back("hello");
test.push_back("it works");
test.push_back("yes");
test.push_back("it");
test.push_back("does");
for(int i = 0; i < 5; i++){
cout << test[i] << endl;
}
*/


// for(int i = 0; i < words.size(); i++){
//     cout << words[i] << endl;
// } 

return 0;
}












// #include <iostream>
// using namespace std;
// int x, y;
// int *px, *py;
// int f () {
// int s = *px + *py;
// cout << s << endl;
// return s;
// }
// int main() {
// x = y = 2;
// px = &x;
// py = &y;
// x = y = f();
// cout << f() << endl;
// }
