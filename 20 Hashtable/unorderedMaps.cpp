#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    unordered_map<string, int> menu;
    //Insertion: O(1)
    menu["maggi"] = 15;
    menu["dosa"] = 100;
    menu["cold drink"] = 99;
    
    cout << menu["dosa"] << endl;
    
    string item;
    cin >> item;
    
    //Search: O(1)
    if(menu.count(item) == 0)
        cout << "Not present";
    else
    cout << item << " is present, its price is " << menu[item] << endl;
    
    //Upadte: O(1)
    menu[item] = (1 + 0.1)*menu[item]; //10 perc increase
    
    cout << "increased price of "<< item << " is: "<< menu[item] << endl;
    
    //Deletion: O(1)
    menu.erase(item);
    
    //Iterate/Search through entire hashtable (will be Random order) O(1)
    for(pair<string, int> menu_item: menu)
    {
        cout << menu_item.first << " - "<< menu_item.second << endl;
    } 
}