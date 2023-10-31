#include <iostream>

using namespace std;

void quickSort(int* arr, int size){

    if(size <= 1){
        return;
    }

    int pivot = arr[size - 1];

    int i = 0;
    int j = size - 2;

    while (i <= j){

        if(arr[i] <= pivot){
            i++;
        }
        else{
            swap(arr[i], arr[j]);
            j--;
        }
    }

    swap(arr[i], arr[size - 1]);

    quickSort(arr, i);
    quickSort(arr + i + 1, size - i - 1);
}


void printArray(int* arr, int size){

    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(){
    int arr[] = {15, 8, 12, 4, 7, 6, 10, 9, 1, 3, 14, 2, 11, 5, 13};


    int size = sizeof(arr) / sizeof(int);

    printArray(arr, size);

    quickSort(arr, size);


    printArray(arr, size);
}