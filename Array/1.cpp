/*
    Reverse the array

    odd 3/2 = 1
    even 4/2 = 2
*/ 
#include<iostream>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Itterative Approach
void reverseArr(int arr[], int n){
    for(int i = 0; i<n/2; i++){
        swap(arr[i], arr[n-i-1]);
    }
}

// Recursive Approach
void reverseArrRecursive(int arr[], int start, int end){
    if(start >= end) return;

    swap(arr[start], arr[end]);
    reverseArrRecursive(arr, start+1, end-1);
}

void printArr(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    // reverseArr(arr, n);
    // printArr(arr, n);

    
    reverseArrRecursive(arr, 0, n-1);
    printArr(arr, n);
}