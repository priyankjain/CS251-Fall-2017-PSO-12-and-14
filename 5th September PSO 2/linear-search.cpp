//Linear Search
// Problem: Given an array, find the
// index of a  target. If not found, 
// return -1
// Time Complexity: O(n)
// Space Complexity: O(1)
// Advantages: Works for both sorted and
// unsorted array
// Disadvantage: Time complexity is
// relatively more

#include <vector>
#include <iostream>
using namespace std;

int LinearSearch(vector<int>& arr, int key) {
	int n = arr.size();
	for(int idx = 0; idx < n; idx++) {
		if(arr[idx] == key)
			return idx;
	}
	return -1;
}
int main() {
	vector<int> arr = {5, 3, 2, 0, 1};
	int key = 0;
	cout << "Key 0 found at index " << LinearSearch(arr, key)
	<< endl;
	return 0;
}
