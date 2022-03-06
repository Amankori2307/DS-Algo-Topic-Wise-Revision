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

int kthSamllestElement(){

}


quick

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << kthSamllestElement << endl;
    return 0;
}