#include<iostream>
using namespace std;

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int pivotIndex(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low-1);
    for(int j=low; j<=high-1; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[++i], arr[high]);
    return i;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = pivotIndex(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int n=0;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    quickSort(arr, 0, n-1);
    printArray(arr, n);
    return 0;
}