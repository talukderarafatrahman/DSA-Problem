#include <iostream>
#include <vector>
using namespace std;

int findFirstOccurrence(const vector<int>& arr, int target) {
    int start = 0, end = arr.size() - 1, result = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            result = mid;  
            end = mid - 1;  
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return result;
}


int findLastOccurrence(const vector<int>& arr, int target) {
    int start = 0, end = arr.size() - 1, result = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            result = mid;  
            start = mid + 1; 
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return result;
}


pair<int, int> findFirstAndLastPosition(const vector<int>& arr, int target) {
    int first = findFirstOccurrence(arr, target);
    int last = findLastOccurrence(arr, target);
    return {first, last};
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4};
    int target = 2;

    pair<int, int> result = findFirstAndLastPosition(arr, target);
    cout << "First Occurrence: " << result.first << ", Last Occurrence: " << result.second << endl;

    return 0;
}
