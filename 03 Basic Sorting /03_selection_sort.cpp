// The algorithm maintains two subarrays in a given array.
// 1) The subarray which is already sorted. 
// 2) Remaining subarray which is unsorted.
// In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray. 

// TC: O(N^2)
// SC: O(1)

#include<iostream>
using namespace std;

//Sort the elements in increasing order 
void selection_sort(int a[],int n){

	for(int pos = 0; pos <= n-2; pos++){

		int current = a[pos];
		int min_position = pos;

		//find out the element 
		for(int j=pos; j<n; j++){

			if(a[j] < a[min_position]){
				min_position = j;
			}

		}
		//swap outside the loop
		swap(a[min_position],a[pos]);
	}


}


int main(){
	int arr[] = {-2,3,4,-1,5,-12,6,1,3};
	int n = sizeof(arr)/sizeof(int);
	selection_sort(arr,n);

	for(auto x : arr){
		cout << x  <<",";
	}

	return 0;
}
