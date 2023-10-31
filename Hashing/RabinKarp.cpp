#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int base = 31;
int mod = 1e9 + 7;

int getHash(string s){

    int result = 0;
    int length = s.length();

    for(int i = length -1; i >= 0; i++){
        int charHash = s[i] - 'a' + 1;
        result *= base;
        result += charHash;
        result %= mod;
    }

    return result;
}

int simplePower(int a, int b){

        int result = 1;

        for(int i = 0; i < b; i++){
            result *= a;
        }

        return result;
}

int getNextHash(int prevHash, char newChar, int length){

    int result = prevHash/base;
    int newCharHash = newChar - 'a' + 1;
    int power = simplePower(base, length - 1) * newCharHash;
    result += power;

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

    int textHash = getHash(text.substr(0, pattern.length()));


    for(int i = 0; i < text.length() - pattern.length()+1; i++){
        if(patternHash == textHash){
            result.push_back(i);
        }

        textHash = getNextHash(textHash, text[i + pattern.length()], pattern.length());
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

    vector<int> result = rabinKarp(text, pattern);

    printVector(result);
}