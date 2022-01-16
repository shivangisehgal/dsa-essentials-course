#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<string, int> menu;
    //Insertion: O(LogN)
    menu["maggi"] = 15;
    menu["dosa"] = 100;
    menu["cold drink"] = 99;
    
    cout << menu["dosa"] << endl;
    
    string item;
    cin >> item;
    
    //Search: O(LogN)
    if(menu.count(item) == 0)
        cout << "Not present";
    else
    cout << item << " is present, its price is " << menu[item] << endl;
    
    //Upadte: O(LogN)
    //menu[item] = (1 + 0.1)*menu[item]; //10 perc increase
    
    //cout << "increased price of "<< item << " is: "<< menu[item] << endl;
    
    //Deletion: O(LogN)
    menu.erase(item);
    
    //Iterate/Search through entire hashtable (will be (lexicographicall/alphabetically) ordered based on keys) O(LogN)
    for(pair<string, int> menu_item: menu)
    {
        cout << menu_item.first << " - "<< menu_item.second << endl;
    } 
}