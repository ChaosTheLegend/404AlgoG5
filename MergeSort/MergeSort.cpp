#include <iostream>

using namespace std;


int* merge(int* left, int* right, int leftSize, int rightSize){

    int resultSize = leftSize + rightSize;
    int* result = new int[resultSize];

    //i - индекс в левом массиве
    //j - индекс в правом массиве
    //k - индекс в результирующем массиве
    int i, j, k;

    i = j = k = 0;

    while(i < leftSize && j < rightSize){

        if(left[i] < right[j]){
            result[k] = left[i];
            i++;
        }
        else{
            result[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < leftSize){
        result[k] = left[i];
        i++;
        k++;
    }

    while(j < rightSize){
        result[k] = right[j];
        j++;
        k++;
    }

    return result;
}


int* mergeSort(int* arr, int size){

    if(size <= 1){
        return arr;
    }

    int mid = size / 2;

    int* left = new int[mid];
    int* right = new int[size - mid];

    for(int i = 0; i < mid; i++){
        left[i] = arr[i];
    }

    for(int i = mid; i < size; i++){
        right[i - mid] = arr[i];
    }

    left = mergeSort(left, mid);
    right = mergeSort(right, size - mid);

    return merge(left, right, mid, size - mid);
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

    int* sorted = mergeSort(arr, size);


    printArray(sorted, size);



}