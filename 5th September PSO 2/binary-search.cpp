// Binary Search
// Problem: Given a sorted array, find the index of a given target.
// Return -1 if not found
// Time Complexity: O(log n)
// Space Complexity: O(1)
// Advantage: Fast in time
// Disadvantage: Requires array to be sorted. Pre-processing of sorting
// should be done if not sorted.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int BinarySearch(vector<int>& arr, int key) {
	int low = 0, high = arr.size()-1;
	while(low <= high) {
		int mid = (low + high)/2;
		if(arr[mid] == key)
			return mid;
		else if(arr[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}
int main() {
	vector<int> arr = {5, 3, 2, 0, 1};
	sort(arr.begin(), arr.end());
	int key = 0;
	cout << "Key 0 found at index " << BinarySearch(arr, key)
	<< endl;
	return 0;
}
