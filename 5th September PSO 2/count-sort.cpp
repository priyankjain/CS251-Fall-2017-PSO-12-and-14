// Count Sort
// Problem: Given an array of digits, sort it
// Time Complexity: O(n) 
// Space Complexity: O(10) = Constant

#include <vector>
#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void CountSort(vector<int>& arr) {
	int count[10];
	for(int i=0; i<10; i++)
		count[i] = 0;
	for(const int elem: arr) {
		count[elem]++;
	}
	for(int i=1; i<10; i++) {
		count[i] += count[i-1];
	}
	vector<int> result(arr.begin(), arr.end());
	for(const int elem: arr) {
		result[count[elem]-1] = elem;
		count[elem]--;
	}
	arr = result;
}
int main() {
	std::vector<int> v = {5, 1, 3, 2, 0, 0, 1, 0, 2, 3, 4, 5, 8};
	CountSort(v);
	for(const int elem: v) {
		cout << elem << " ";
	}
	cout << endl;
	return 0;
}