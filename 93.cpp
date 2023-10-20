#include <bits/stdc++.h>
using namespace std;
// Coin Change 1 & 2 : Leetcode DP Questions 
// https://leetcode.com/problems/coin-change/description/
// https://leetcode.com/problems/coin-change-ii/description/


//************************* Coin Change ********************************************




// int func(int amount, vector<int> &coins){
//     if(amount == 0) return 0;
//     int ans = INT_MAX;
//     for (int coin : coins)
//     {   
//         if(amount - coin >=0)
//             ans = min( ans + 0LL, func(amount - coin, coins) + 1LL );
//     }
//     return ans;
// }
// exponential time complexity





// int dp[10010];

// int func(int amount, vector<int> &coins){
//     if(amount == 0) return 0;
//     if(dp[amount] != -1) return dp[amount];

//     int ans = INT_MAX;
//     for (int coin : coins)
//     {   
//         if(amount - coin >=0)
//             ans = min( ans + 0LL, func(amount - coin, coins) + 1LL );
//     }
//     return dp[amount] = ans;
// }

// int coinChange(vector<int>& coins, int amount) {
//     memset(dp, -1, sizeof(dp));
//     int ans = func(amount, coins);
//     return ans == INT_MAX? -1: ans;
// }


// int main() {

//     vector<int> coins = {2};
//     cout<<coinChange(coins, 3);

//     return 0;
// }

















// ************************* Coin Change 2 ********************************************



/*
we are solving issue of 1 1 1 2 and 1 2 1 1 by having using coins in order
using all 1 first and then using all 2 i.e. using all coins in order

*/


int dp[310][10010];

// no. of ways to make amount by using coins upto n index
int func(int ind, int amount, vector<int> &coins){
    if(amount == 0) return 1;
    if(ind < 0) return 0;
    if(dp[ind][amount] != -1) return dp[ind][amount];

    int ways = 0;
    for (int coin_amount = 0; coin_amount <= amount; coin_amount += coins[ind])
    {   
        ways += func(ind - 1, amount - coin_amount, coins);
    }
    return dp[ind][amount] = ways;
}

int coinChange(int amount, vector<int>& coins) {
    memset(dp, -1, sizeof(dp));
    return func(coins.size()-1, amount, coins);
}


int main() {

    vector<int> coins = {2};
    int amount = 3;
    cout<<coinChange(3, coins);

    return 0;
}
