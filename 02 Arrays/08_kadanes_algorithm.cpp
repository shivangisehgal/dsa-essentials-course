// Approach/Intuition 1 :
//" Either add a[i] or start a new subarray with a[i] "
// currsum = max(currsum + a[i], a[i])
// maxsubarray = max(maxsubarray, currsum)


// Approach/Intuition 2 :
// " Whenever we get a negative prefix sum, it'll have 0 contribution and we'll take a[i]. Kind of like sliding window. "
//If we have at least one non-negative number in the array, our maximum subarray sum can never be negative. 
// (Negative numbers in a subarray are allowed, 
// because, think of it, the subarray would still have a positive contribution (ex: [2, -1, 6] = if we're at 6 then currsum = (1) + 6, so there is still an addition of a positive number to a current element.
// to the currsum. Thus, subarray with maxsum = [2, -1, 6]
// however, if the ex. was [2, -4, 6] => if we're at 6 then currsum = (-2) + 6 X 
// So when we reached -4, the currsum would be -2 < 0, thus -4 will have no contribution and till now subarray [2] will have max sum.
// Moving on to 6, curr = 0 + 6 = 6, now subarray with maxsum = [6]

#include<iostream>
using namespace std;
//Kadane'a Algorithm : O(N)
int maximum_subarray_sum(int arr[],int n){

	int cs = 0;
	int largest = 0;
	int maxelement = INT_MIN;

	for(int i=0;i<n;i++){
		cs = cs + arr[i];
		//If the addition of a[i] results in negative sum, 
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
