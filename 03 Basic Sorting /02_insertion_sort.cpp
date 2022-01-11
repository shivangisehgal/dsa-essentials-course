// Insertion sort is a sorting algorithm, which sorts the array by shifting the elements one at at time.
// We have a sorted sublist and an unsorted sublist. It iterates the input elements by growing the sorted list at each iteration. 
// If it is the first element, it is already sorted.
// Pick the next element.
// Compare with all the elements in sorted sub-list.
// Shift all the the elements in sorted sub-list that is greater than the value to be sorted.
// Insert the value.
// Repeat until all the elements are in the sorted sublist.


//TC: O(N^2)
//SC: O(1)

#include<iostream>
using namespace std;

//Sort the elements in increasing order 
void insertion_sort(int a[],int n){

	for(int i=1; i<=n-1; i++){

		int current = a[i];

		int prev = i - 1; 
		//loop to find the right index where the element current should be inserted
		while(prev>=0 and a[prev] > current){
			a[prev + 1] = a[prev];
			prev = prev - 1;
		}

		a[prev+1] = current; 
	}


}


int main(){
	int arr[] = {-2,3,4,-1,5,-12,6,1,3};
	int n = sizeof(arr)/sizeof(int);
	insertion_sort(arr,n);

	for(auto x : arr){
		cout << x  <<",";
	}

	return 0;
}
