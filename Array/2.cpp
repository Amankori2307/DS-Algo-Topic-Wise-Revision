/*
    Find the maximum and minimum element in an array


    Write a C function to return minimum and maximum in an array. Your program should make the minimum number 
    of comparisons. 
*/


#include<iostream>
#include <climits>
using namespace std;

struct Pair{
    int min;
    int max;
};

// Linear Search
Pair finMinAndMaxInArr(int arr[], int n){
    int minNo = INT_MAX, maxNo = INT_MIN;
    for(int i=0; i<n; i++){
        minNo = min(minNo, arr[i]);
        maxNo = max(maxNo, arr[i]);
    }
    return {minNo, maxNo};
}

// Tournament Method
Pair finMinAndMaxInArr2(int arr[], int low, int high){
    cout << "low: " << low << ", high: " << high << "\n";
    Pair ans;
    if(low == high){
        ans.min = arr[low];
        ans.max = arr[high];
        return ans;
    };
    if(high == low+1){
        ans.min = min(arr[high], arr[low]);
        ans.max = max(arr[high], arr[low]);
        return ans;
    }
    int mid = (low + high)/2;
    Pair left = finMinAndMaxInArr2(arr, low, mid);
    Pair right = finMinAndMaxInArr2(arr, mid, high);
    ans.min  = min(left.min, right.min);
    ans.max  = max(left.max, right.max);
    return ans;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    // Pair minAndMax = finMinAndMaxInArr(arr, n);
    // cout << minAndMax.min << " " << minAndMax.max;
    Pair minAndMax = finMinAndMaxInArr2(arr, 0, n-1);
    cout << minAndMax.min << " " << minAndMax.max;
    
    return 0;
}