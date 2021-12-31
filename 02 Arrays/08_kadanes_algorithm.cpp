#include<iostream>
using namespace std;
//Kadane'a Algorithm : O(N)
int maximum_subarray_sum(int arr[],int n){

	int cs = 0;
	int largest = 0;
	int maxelement = INT_MIN;

	for(int i=0;i<n;i++){
		cs = cs + arr[i];
		if(cs < 0){
			cs = 0;
		}
		largest = max(largest, cs);
		
		maxelement = max(maxelement, arr[i]); //needed in all-negative-numbers case
	}
	
	if(maxelement < 0) //check for all negative numbers
	return maxelement;
	
	return largest;
}


int main(){
	//Array Containing 
	int arr[] = {-2,3,4,-1,5,-12,6,1,3};
	int n = sizeof(arr)/sizeof(int);

	cout<< maximum_subarray_sum(arr,n) <<endl;

	return 0;
}
