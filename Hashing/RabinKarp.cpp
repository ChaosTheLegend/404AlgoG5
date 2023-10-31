#include <iostream>
#include <string>
#include <vector>


using namespace std;

int base = 31;
int mod = 1e9 + 7;

int getHash(string& s){

    int result = 0;

    for(char c : s){
        result += c - 'a' + 1;
        result *= base;
        result %= mod;
    }

    return result;
}

bool nativeCompare(string s1, string s2){

    unsigned int length = s1.length();

    for(int i = 0; i < length; i++){
        if(s1[i] != s2[i]){
            return false;
        }
    }

    return true;
}

vector<int> rabinKarp(string& text, string& pattern){

    vector<int> result;

    int patternHash = getHash(pattern);
    unsigned int patternLength = pattern.length();

    for(int i = 0; i <= text.length() - pattern.length(); i++){

        string sub = text.substr(i, patternLength);

        int subHash = getHash(sub);

        if(subHash == patternHash){
            if(nativeCompare(pattern, sub)) result.push_back(i);
        }
    }

    return result;
}


void printVector(vector<int>& v){

    for(int i : v){
        cout << i << " ";
    }
    cout << endl;
}


int main(){

    string text, pattern;

    cin >> text >> pattern;

    cout << text << " # " << pattern << endl;

    vector<int> result = rabinKarp(text, pattern);

    printVector(result);
}