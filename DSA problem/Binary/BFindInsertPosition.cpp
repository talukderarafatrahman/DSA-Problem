#include <iostream>
#include <vector>
using namespace std;

int findInsertPosition(const vector<int>& arr, int target) {
    int start = 0, end = arr.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            return mid;  // Target found at this position
        } else if (arr[mid] < target) {
            start = mid + 1;  // Move right to search for the insert position
        } else {
            end = mid - 1;  // Move left
        }
    }
    // At the end of the loop, `start` is the insert position
    return start;
}

int main() {
    vector<int> arr = {1, 3, 5, 6};
    int target = 4;

    int insertPos = findInsertPosition(arr, target);
    cout << "Insert Position: " << insertPos << endl;

    return 0;
}
