#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>arr, int tar){
    int st=0, end=arr.size()-1;
    while (st<=end)
    {
       int mid = (st+end)/2;
       if(tar>arr[mid]){
        st=mid+1;
       }
       else if(tar < arr[mid]){
        end=mid-1;
       }
       else
         return mid;
    }
    return -1;
}

int main() {
    int n, target;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array in sorted order:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the target value to search for: ";
    cin >> target;

    int result = binarySearch(arr, target);
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}