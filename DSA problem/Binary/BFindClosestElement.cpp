#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int findClosestElement(const vector<int>& arr, int target) {
    int start = 0, end = arr.size() - 1;
    int closest = arr[0];  // Assume the first element is the closest initially

    while (start <= end) {
        int mid = start + (end - start) / 2;

        // Update the closest element if the current element is closer
        if (abs(arr[mid] - target) < abs(closest - target) || 
           (abs(arr[mid] - target) == abs(closest - target) && arr[mid] < closest)) {
            closest = arr[mid];
        }

        // Adjust the search range
        if (arr[mid] < target) {
            start = mid + 1;  // Search right
        } else {
            end = mid - 1;  // Search left
        }
    }
    return closest;
}

int main() {
    vector<int> arr = {1, 3, 8, 10, 15};
    int target = 12;

    int closest = findClosestElement(arr, target);
    cout << "Closest Element: " << closest << endl;

    return 0;
}
