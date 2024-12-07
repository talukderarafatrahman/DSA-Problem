#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(const vector<int>& arr) {
    int start = 0, end = arr.size() - 1;

    while (start < end) {
        int mid = start + (end - start) / 2;

        // Check if the middle element is in the increasing part
        if (arr[mid] < arr[mid + 1]) {
            start = mid + 1;  // Move right
        } else {
            end = mid;  // Move left
        }
    }
    // At the end of the loop, `start` and `end` will point to the peak
    return start;
}

int main() {
    vector<int> arr = {1, 3, 8, 12, 4, 2};

    int peakIndex = findPeakElement(arr);
    cout << "Peak Element Index: " << peakIndex << endl;
    cout << "Peak Element: " << arr[peakIndex] << endl;

    return 0;
}
