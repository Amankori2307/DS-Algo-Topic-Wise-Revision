/*
    Find the "Kth" max and min element of an array 

    Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth 
    smallest element in the given array. It is given that all array elements are distinct.

    Expected Time Complexity: O(n)
    Expected Auxiliary Space: O(log(n))
    Constraints:
    1 <= N <= 105
    1 <= arr[i] <= 105
    1 <= K <= N


    Quick Sort

    Like Merge Sort, QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions 
    the given array around the picked pivot. There are many different versions of quickSort that pick pivot in 
    different ways. 
    - Always pick first element as pivot.
    - Always pick last element as pivot (implemented below)
    - Pick a random element as pivot.
    - Pick median as pivot.
    The key process in quickSort is partition(). Target of partitions is, given an array and an element x of array 
    as pivot, put x at its correct position in sorted array and put all smaller elements (smaller than x) before x, 
    and put all greater elements (greater than x) after x. All this should be done in linear time.
*/ 


#include<iostream>
using namespace std;

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high){
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

int kthSamllestElement(int arr[], int low, int high, int k){
    if(low <= high){
        int pi = partition(arr, low, high);
        if(pi == k-1) return arr[pi];

        if(pi > k-1){  // if kth smallest element lies in the left array
            int l = kthSamllestElement(arr, low, pi-1, k);
            if(l != -1 ) return l;

        } else { // if kth smallest element liest in the right array
            int r = kthSamllestElement(arr, pi+1, high, k);
            if(r != -1) return r;
        }         
    }
    return -1;
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] <<  " ";
    }
    cout << "\n";
}
int main(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << kthSamllestElement(arr, 0, n-1, k) << endl;
    return 0;
}