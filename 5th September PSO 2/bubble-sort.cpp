// Bubble Sort
// Problem: Given an array, sort it
// Idea: At each step, bubble out the maximum element from the sorted part
// to the unsorted part. Here sorted part comes after unsorted part,
// unlike selection or insertion sort.
// Time Complexity: O(n^2)
// Space Complexity: O(1)

#include <vector>
#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void BubbleSort(vector<int>& arr) {
	for(int i=arr.size()-1; i>0; i--) {
		for(int j=0; j<i; j++) {
			if(arr[j] > arr[j+1]) {
				swap(arr[j+1], arr[j]);
			}
		}
	}
}
int main() {
	std::vector<int> v = {5, 1, 3, 2, 0};
	BubbleSort(v);
	for(const int elem: v) {
		cout << elem << " ";
	}
	cout << endl;
	return 0;
}