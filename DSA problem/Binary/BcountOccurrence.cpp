#include <iostream>
#include <vector>
using namespace std;

// Function to find the first occurrence of the target
int findFirstOccurrence(const vector<int>& arr, int target) {
    int start = 0, end = arr.size() - 1, result = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            result = mid;  // Record position
            end = mid - 1; // Move left
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return result;
}

// Function to find the last occurrence of the target
int findLastOccurrence(const vector<int>& arr, int target) {
    int start = 0, end = arr.size() - 1, result = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            result = mid;  // Record position
            start = mid + 1; // Move right
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return result;
}

// Function to count the occurrences of the target
int countOccurrences(const vector<int>& arr, int target) {
    int first = findFirstOccurrence(arr, target);
    if (first == -1) {
        return 0; // Target not found
    }
    int last = findLastOccurrence(arr, target);
    return last - first + 1;
}

int main() {
    vector<int> arr = {2, 4, 4, 4, 6, 7};
    int target = 4;

    int count = countOccurrences(arr, target);
    cout << "Occurrences of " << target << ": " << count << endl;

    return 0;
}
