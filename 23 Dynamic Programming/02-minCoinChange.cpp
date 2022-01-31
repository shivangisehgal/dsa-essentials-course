//We can create a dynamic programming array.

//Consider an array of coins {1, 4, 9, 10}, we can choose any coin multiple times.
//minimum number of coins required to get an amount of Rs 0 = 0
//The dp array would store the minimum number of coins required (which are given in the coins array) to get an amount of Rs 'index'

//minimum number of coins required to get an amount of Rs 6 = 
// = minimum(1 + minimum number of coins required to get an amount of Rs 5, 1 + minimum number of coins required to get an amount of Rs 2)
//=> dp[6] = min(1 + dp[5], 1 + dp[2])

//similarly, minimum number of coins required to get an amount of Rs 12 = 
//= minimum(1 + minimum number of coins required to get an amount of Rs 11, 1 + minimum number of coins required to get an amount of Rs 8, 1 + minimum number of coins required to get an amount of Rs 3, 1 + minimum number of coins required to get an amount of Rs 2)
//=> dp[12] = min(1 + dp[11], 1 + dp[8], 1 + dp[3], 1 + dp[2])

//TODO: ADD TC, SC

#include <bits/stdc++.h>
using namespace std;

int minCoinsToGetTarget(int target, vector<int>& coins)
{
    vector<int> dp(target + 1);
    dp[0] = 0;
    
    for(int i = 1; i <= target; i++)
    {
        //to find: dp[i]
        dp[i] = INT_MAX;
        
        for(auto coin : coins)
        {
            if(i >= coin and dp[i - coin] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i - coin]);
        }
        
    }
    
    return dp[target] == INT_MAX ? -1 : dp[target];
}

int main()
{
    
    vector<int> coins = {1, 5, 7, 10};
    
    cout << minCoinsToGetTarget(9, coins);
    return 0;
}
