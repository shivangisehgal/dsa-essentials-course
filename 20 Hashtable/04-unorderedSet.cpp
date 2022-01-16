#include <iostream>
#include<unordered_set>
using namespace std;

int main()
{
    unordered_set<int> s{1,3,4,7,10,9,2};
    
    int key;
    cin >> key;
    
    //Insert: O(1)
    s.insert(111);
    
    //Delete: O(1)
    s.erase(9);
    
    //Search: O(1)
    if(s.find(key) != s.end())
    cout << key << " is present." << endl;
    else
    cout << key << " is not present." << endl;
    
    for(auto x : s)
        cout << x << " ";
    return 0;
}
