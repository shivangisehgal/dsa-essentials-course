M1 : Linear Search - TC : O(N), SC: O(1)
M2 : Modified Binary Search - TC : O(logN), SC : O(1)


class Solution {
public:
    int search(vector<int>& a, int target) {
        int low = 0, high = a.size() - 1; 
        while(low <= high) {
            int mid = (low + high) >> 1; 
            if(a[mid] == target) return mid; 
            
            // the left side is sorted
            if(a[low] <= a[mid]) {
                //figure out if element lies in this half, ie, a[low] <= target <= a[mid]
                if(target >= a[low] && target <= a[mid]) {
                    high = mid - 1; 
                }
                else {
                    low = mid + 1; 
                }
            }
            //right half is sorted
            else {
                 //figure out if element lies this half half, ie, a[mid] <= target <= a[high]
                if(target >= a[mid] && target <= a[high]) {
                    low = mid + 1; 
                }
                else {
                    high = mid - 1; 
                }
            }
        } 
        return -1; 
    }
};
