// Quick Sort
// Problem: Given an array, sort it
// Time Complexity: O(n log(n)) (Average Case), O(n^2) - Worst Case
// Space Complexity: O(1)

#include <vector>
#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
int partition(vector<int>& arr, int low, int high)
{
	int i = low - 1;
	int pivot = arr[high];
	int j = low;
	while(j < high) {
		if(arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
		j++;
	}
	swap(arr[i+1],arr[high]);
	return i+1;
}

void QuickSort(vector<int>& arr, int low, int high) {
	if(low < high) {
		int pivot_idx = partition(arr, low, high);
		QuickSort(arr, low, pivot_idx-1);
		QuickSort(arr, pivot_idx+1, high);
	}
}
int main() {
	std::vector<int> v = {5, 1, 3, 2, 0, -1};
	QuickSort(v, 0, v.size()-1);
	for(const int elem: v) {
		cout << elem << " ";
	}
	cout << endl;
	return 0;
}