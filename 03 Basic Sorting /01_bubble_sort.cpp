// When you think of bubble sort, you can imagine the inputs being bubbles and rising up/going down depending on how dense they are.
//It goes through an entire array and compares each neighboring number. 
//It then swaps the numbers if needed and keeps doing this until the array is in ascending order.
//The algorithm gets its name as the bigger elements will “bubble” towards the rightmost position. 
//After each cycle, the largest element will be the last element in the unsorted part of the array. And our array size for comparison decreases by 1.

//TC: O(N^2)
//SC: O(1)


#include<iostream>
#include<ctime>
using namespace std;

bool compare(int a,int b){
	return a > b;
}

//Sort the elements in increasing order 
void bubble_sort(int a[],int n){

	for(int times=1;times<=n-1;times++){
		//repeated swapping
		for(int j=0; j <= n - times - 1; j++ ){
			if(compare(a[j],a[j+1])){
				swap(a[j],a[j+1]);
			}
		}

	}
}




int main(){
	int arr[] = {-2,3,4,-1,5,-12,6,1,3};
	int n = sizeof(arr)/sizeof(int);
	

	bubble_sort(arr,n);

	

	return 0;
}
