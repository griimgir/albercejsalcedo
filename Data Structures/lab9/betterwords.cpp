#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

char getLetter(string str){
    // cout << str.at(0);
    return str.at(0);
    //cout << str.at(0) << endl;
}

// //searches reveresed words
// bool search(string* words, int size, string reversed){
// for (int i = 0; i < size; i++) {
//     if (reversed == array[i]){
//         return true;
//     }
// }
// return false;
// }

int main(int argc, const char * argv[]){
    string word;
    vector<string> words;
    //int size = words.size();
    int matched = 0;
    int beta = 0;

    ifstream in("words.txt");

//inject each word in 'in' and injects it into 'word' which then
//inserts 'word' into the array of 'words'
int count = 0;
while (in >> word) {
    words.push_back(word);
    count++;
}

//time start
auto start = high_resolution_clock::now();

//Catalogs every word into smaller arrays with the same first char in the word
vector<string> a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, weirdshit;
// string gl;
char firstLetter;
for(int index = 0; index < words.size(); index++){
    //cout << words[index] << endl;
    firstLetter = getLetter(words[index]);
    //cout << gl << endl;
    if(firstLetter == 'A'){
        a.push_back(words[index]);
    }
    if(firstLetter == 'B'){
        b.push_back(words[index]);
    }
    if(firstLetter == 'C'){
        c.push_back(words[index]);
    }
    if(firstLetter == 'D'){
        d.push_back(words[index]);
    }
    if(firstLetter == 'E'){
        e.push_back(words[index]);
    }
    if(firstLetter == 'F'){
        f.push_back(words[index]);
    }
    if(firstLetter == 'G'){
        g.push_back(words[index]);
    }
    if(firstLetter == 'H'){
        h.push_back(words[index]);
    }
    if(firstLetter == 'I'){
        i.push_back(words[index]);
    }
    if(firstLetter == 'J'){
        j.push_back(words[index]);
    }
    if(firstLetter == 'K'){
        k.push_back(words[index]);
    }
    if(firstLetter == 'L'){
        l.push_back(words[index]);
    }
    if(firstLetter == 'M'){
        m.push_back(words[index]);
    }
    if(firstLetter == 'N'){
        n.push_back(words[index]);
    }
    if(firstLetter == 'O'){
        o.push_back(words[index]);
    }
    if(firstLetter == 'P'){
        p.push_back(words[index]);
    }
    if(firstLetter == 'Q'){
        q.push_back(words[index]);
    }
    if(firstLetter == 'R'){
        r.push_back(words[index]);
    }
    if(firstLetter == 'S'){
        s.push_back(words[index]);
    }
    if(firstLetter == 'T'){
        t.push_back(words[index]);
    }
    if(firstLetter == 'U'){
        u.push_back(words[index]);
    }
    if(firstLetter == 'V'){
        v.push_back(words[index]);
    }
    if(firstLetter == 'W'){
        w.push_back(words[index]);
    }
    if(firstLetter == 'X'){
        x.push_back(words[index]);
    }
    if(firstLetter == 'Y'){
        y.push_back(words[index]);
    }
    if(firstLetter == 'Z'){
        z.push_back(words[index]);
    }
    else{
        weirdshit.push_back(words[index]);
        beta++;
    }
}

//reverses words in list. rw = reverse word
for (int index = 0; index < words.size(); index++){
    string rw = words[index];
    reverse(rw.begin(), rw.end());
    // cout << rw << endl;
    if (getLetter(rw) == 'A'){
        for (int jindex = 0; jindex < a.size(); jindex++){
            if (rw == a[jindex]){
                matched++;
            }
            else{
                continue;
            }
        }
    }
    if (getLetter(rw) == 'B'){
        for (int jindex = 0; jindex < b.size(); jindex++){
            if (rw == b[jindex]){
                matched++;
            }
            else{
                continue;
            }
        }
    }
    if (getLetter(rw) == 'C'){
        for (int jindex = 0; jindex < c.size(); jindex++){
            if (rw == c[jindex]){
                matched++;
            }
            else{
                continue;
            }
        }
    }
    if (getLetter(rw) == 'D'){
        for (int jindex = 0; jindex < d.size(); jindex++){
            if (rw == d[jindex]){
                matched++;
            }
            else{
                continue;
            }
        }
    }
    if (getLetter(rw) == 'E'){
        for (int jindex = 0; jindex < e.size(); jindex++){
            if (rw == e[jindex]){
                matched++;
            }
            else{
                continue;
            }
        }
    }
    if (getLetter(rw) == 'F'){
        for (int jindex = 0; jindex < f.size(); jindex++){
            if (rw == f[jindex]){
                matched++;
            }
            else{
                continue;
            }
        }
    }
    if (getLetter(rw) == 'G'){
        for (int jindex = 0; jindex < g.size(); jindex++){
            if (rw == g[jindex]){
                matched++;
            }
            else{
                continue;
            }
        }
    }
    if (getLetter(rw) == 'H'){
        for (int jindex = 0; jindex < h.size(); jindex++){
            if (rw == h[jindex]){
                matched++;
            }
            else{
                continue;
            }
        }
    }
    if (getLetter(rw) == 'I'){
        for (int jindex = 0; jindex < i.size(); jindex++){
            if (rw == i[jindex]){
                matched++;
            }
            else{
                continue;
            }
        }
    }
    if (getLetter(rw) == 'J'){
        for (int jindex = 0; jindex < j.size(); jindex++){
            if (rw == j[jindex]){
                matched++;
            }
            else{
                continue;
            }
        }
    }
    if (getLetter(rw) == 'K'){
        for (int jindex = 0; jindex < k.size(); jindex++){
            if (rw == k[jindex]){
                matched++;
            }
            else{
                continue;
            }
        }
    }
    if (getLetter(rw) == 'L'){
        for (int jindex = 0; jindex < l.size(); jindex++){
            if (rw == l[jindex]){
                matched++;
            }
            else{
                continue;
            }
        }
    }
    if (getLetter(rw) == 'M'){
        for (int jindex = 0; jindex < m.size(); jindex++){
            if (rw == m[jindex]){
                matched++;
            }
            else{
                continue;
            }
        }
    }
    if (getLetter(rw) == 'N'){
        for (int jindex = 0; jindex < n.size(); jindex++){
            if (rw == n[jindex]){
                matched++;
            }
            else{
                continue;
            }
        }
    }
    if (getLetter(rw) == 'O'){
        for (int jindex = 0; jindex < o.size(); jindex++){
            if (rw == o[jindex]){
                matched++;
            }
            else{
                continue;
            }
        }
    }
    if (getLetter(rw) == 'P'){
        for (int jindex = 0; jindex < p.size(); jindex++){
            if (rw == p[jindex]){
                matched++;
            }
            else{
                continue;
            }
        }
    }
    if (getLetter(rw) == 'Q'){
        for (int jindex = 0; jindex < q.size(); jindex++){
            if (rw == q[jindex]){
                matched++;
            }
            else{
                continue;
            }
        }
    }
    if (getLetter(rw) == 'R'){
        for (int jindex = 0; jindex < r.size(); jindex++){
            if (rw == r[jindex]){
                matched++;
            }
            else{
                continue;
            }
        }
    }
    if (getLetter(rw) == 'S'){
        for (int jindex = 0; jindex < s.size(); jindex++){
            if (rw == s[jindex]){
                matched++;
            }
            else{
                continue;
            }
        }
    }
    if (getLetter(rw) == 'T'){
        for (int jindex = 0; jindex < t.size(); jindex++){
            if (rw == t[jindex]){
                matched++;
            }
            else{
                continue;
            }
        }
    }
    if (getLetter(rw) == 'U'){
        for (int jindex = 0; jindex < u.size(); jindex++){
            if (rw == u[jindex]){
                matched++;
            }
            else{
                continue;
            }
        }
    }
    if (getLetter(rw) == 'V'){
        for (int jindex = 0; jindex < v.size(); jindex++){
            if (rw == v[jindex]){
                matched++;
            }
            else{
                continue;
            }
        }
    }
    if (getLetter(rw) == 'W'){
        for (int jindex = 0; jindex < w.size(); jindex++){
            if (rw == w[jindex]){
                matched++;
            }
            else{
                continue;
            }
        }
    }
    if (getLetter(rw) == 'X'){
        for (int jindex = 0; jindex < x.size(); jindex++){
            if (rw == x[jindex]){
                matched++;
            }
            else{
                continue;
            }
        }
    }
    if (getLetter(rw) == 'Y'){
        for (int jindex = 0; jindex < y.size(); jindex++){
            if (rw == y[jindex]){
                matched++;
            }
            else{
                continue;
            }
        }
    }
    if (getLetter(rw) == 'Z'){
        for (int jindex = 0; jindex < z.size(); jindex++){
            if (rw == z[jindex]){
                matched++;
            }
            else{
                continue;
            }
        }
    }
    else {
        for (int jindex = 0; jindex < weirdshit.size(); jindex++){
            if (rw == weirdshit[jindex]){
                matched++;
            }
            else{
                continue;
            }
        }
    }
}

auto stop = high_resolution_clock::now();

auto duration = duration_cast<milliseconds>(stop - start);

cout << "Number of words: ";
cout << count << endl;
cout << "Number of Non-letter words: ";
cout << beta << endl;
cout << "Total matched found: ";
cout << matched << endl;

cout << "" << endl;
cout << "Time duration in ms: ";
cout << duration.count() << endl;
cout << "Time duration estimated in seconds: ";
cout << int(duration.count() / 1000) << endl;
cout << "Time duration estimated in minutes: ";
cout << int((duration.count() / 1000)/60) << endl;
return 0;





}









    // int counter = 0;
    // char c = '';
    // while (in >> word) {
    //     words[count] = word;
    //     c = words[count].at(0);
    //     count++;
    // }
