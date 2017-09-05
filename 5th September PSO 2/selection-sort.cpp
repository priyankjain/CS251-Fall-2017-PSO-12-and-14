// Selection Sort
// Problem: Given an array, sort it
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
void SelectionSort(vector<int>& arr) {
	for (int i=0; i<arr.size()-1; i++) {
		int min_idx = i;
		for(int j=i+1; j<arr.size(); j++)
			if(arr[j] < arr[min_idx])
				min_idx = j;
		if(min_idx != i)
			swap(arr[i], arr[min_idx]);
	}
}
int main() {
	std::vector<int> v = {5, 1, 3, 2, 0};
	SelectionSort(v);
	for(const int elem: v) {
		cout << elem << " ";
	}
	cout << endl;
	return 0;
}