// Counting sort is a sorting algorithm that sorts the elements of an array by counting the number of occurrences of each unique element in the array. 
// The count is stored in an auxiliary array and the sorting is done by mapping the count as an index of the auxiliary array.

// TC: O(N + K)
// SC: O(N + K)
// Where K is the range of input

#include<iostream>
#include<vector>
using namespace std;



void counting_sort(int a[],int n){
	//Largest Element
	int largest = -1;

	for(int i=0;i<n;i++){
		largest = max(largest,a[i]);
	}

	//create a count array/vector
	vector<int> freq(largest+1,0);

	//Update the freq array 
	for(int i=0;i<n;i++){
		freq[a[i]]++;
	}

	//Put back the elements from freq into original array

	int j = 0;
	for(int i=0; i<=largest; i++){

		while(freq[i]>0){
			a[j] = i;
			freq[i]--;
			j++;
		}
	}
	return;

}



int main(){

	int arr[] = {88, 97, 10, 12, 15, 1, 5, 6, 12, 5, 8};
	int n = sizeof(arr) / sizeof(int);
	counting_sort(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}


	return 0;
}
