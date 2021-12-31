#include<iostream>
using namespace std;

//Problem : Print all pairs in a given array
// TC: O(N^2)
void printPairs(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            cout<<arr[i]<<" "<<arr[j];
            cout << endl;
        }
    }
}


int main(){
	//Array Containing 
	int arr[] = {-2,3,4,5,-12,6,2,3};
	int n = sizeof(arr)/sizeof(int);

	printSubarrays(arr,n);



	return 0;
}
