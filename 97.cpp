#include <bits/stdc++.h>
using namespace std;
// Unbound knapsack
// ROD CUTTING: Dynamic Programming
// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

/*
func(len) --> len is the length which can be cut
*/

int dp[1005];

// maximum value which can be obtained if we have this length of rod
int func(int len, vector<int> &prices){
    if(len == 0) return 0;
    if(dp[len]!= -1) return dp[len];
    int ans = 0;
    for(int len_to_cut = 1; len_to_cut <= prices.size(); len_to_cut++){
        if(len - len_to_cut>=0){
            ans = max(ans, func(len - len_to_cut, prices) + prices[len_to_cut - 1]);
        }
    }
    return dp[len] = ans;
}
// N times function call due to dp
// and each function call has a for loop of N size
//O(N^2)



int cutRod(int price[], int n){
    memset(dp, -1, sizeof(dp));
    vector<int> prices(price, price+n);
    return func(n, prices);
}



int main() {



    return 0;
}