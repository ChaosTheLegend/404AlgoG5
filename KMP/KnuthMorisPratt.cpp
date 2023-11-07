#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


vector<int> KnuthMorisPratt(string text, string pattern){
    //You have been warned
    //This is a very complicated algorithm
    int textLength = text.length();
    int patternLength = pattern.length();

    vector<int> result;

    int lsp[patternLength];

    //part 1 calculate the longest suffix prefix

    lsp[0] = 0;

    for (int i = 1; i < patternLength; ++i) {
        int len = lsp[i - 1];

        if(pattern[i] == pattern[len]) {
            lsp[i] = len + 1;
            continue;
        }

        while(len > 0 && pattern[i] != pattern[len]) {
            len = lsp[len - 1];
        }

        if(pattern[i] == pattern[len]) {
            len++;
        }

        lsp[i] = len;
    }

    //part 2 find the pattern in the text

    int j = 0;

    for (int i = 0; i < textLength; ++i) {
        if(text[i] == pattern[j]) {
            j++;

            if(j == patternLength) {
                result.push_back(i - patternLength + 1);
                j = lsp[j - 1];
            }

            continue;
        }


        while(j > 0 && text[i] != pattern[j]) {
            j = lsp[j - 1];
        }


    }

    return result;
}


void printVector(vector<int> v){
    for(int i : v){
        cout << i << " ";
    }
}

int main(){

    string text = "Abandon all hope all ye who enter here";

    string pattern;

    getline(cin, pattern);

    vector<int> result = KnuthMorisPratt(text, pattern);

    printVector(result);
}