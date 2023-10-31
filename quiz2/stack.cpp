#include <iostream>

using namespace std;

int stack[100];
int front;

void push(int val){
    stack[front] = val;
    front++;
}

int main(){
}