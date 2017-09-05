// Merge Sort
// Problem: Given an array, sort it
// Time Complexity: O(n log(n))
// Space Complexity: O(n)

#include <vector>
#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void merge(vector<int>& arr, int low, int mid, int high) {
	int l_size = mid - low + 1;
	int r_size = high - mid;
	int L[mid - low + 1];
	int R[high-mid];
	for(int i=0; i<l_size; i++)
		L[i] = arr[i+low];
	for(int i=0; i<r_size; i++)
		R[i] = arr[i+mid+1];
	int i = 0, j = 0, k=low;
	while(i < l_size && j < r_size) {
		if(L[i] < R[j]) {
			arr[k++] = L[i++];
		}
		else {
			arr[k++] = R[j++];
		}
	}
	while(i < l_size) {
		arr[k++] = L[i++];
	}
	while(j < r_size) {
		arr[k++] = R[j++];
	}
}
void MergeSort(vector<int>& arr, int low, int high) {
	if(low < high) {
		int mid = low + (high - low)/2; // mid = (low+high)/2;
		MergeSort(arr, low, mid);
		MergeSort(arr, mid+1, high);
		merge(arr, low, mid, high);
	}
}
int main() {
	std::vector<int> v = {5, 1, 3, 2, 0, -1};
	MergeSort(v, 0, v.size()-1);
	for(const int elem: v) {
		cout << elem << " ";
	}
	cout << endl;
	return 0;
}