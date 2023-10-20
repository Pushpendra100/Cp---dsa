#include <bits/stdc++.h>
using namespace std;
// Knapsack 2 Atcoder Tutorial With Code: Dynamic Programming
// https://atcoder.jp/contests/dp/tasks/dp_e

/*
in the previous question TC:-  O(105^100005)

but now W <= 10^9 
which will make our TC:- O(10^11) thus we can't work with previous methodolgy

actually we have thought of,  N items selected sum less than wt  and maximize value 

now we are saying, N items selected sum = value and find minimum weight to get that value
    given 1≤vi​≤10^3

w - 2  3  4
v - 5  6  11

for value 1 we can't chose anything
for value 11 we can chose weight 4 or we can chose weight 2 and 3, here min weight is 4

then we have to find weight less than or equal to given weight
*/


int val[105];
long long wt[105];

//max value can be after complete addition 10^3 * 10^2 = 10^5
long long dp[105][100005];

// this func is returning min weight for this value_left
long long func(int ind, int value_left){
    if(value_left==0) return 0;
    if(ind < 0) return 1e15; //we can't make it if ind<0
    if(dp[ind][value_left] != -1) return dp[ind][value_left];
    // don't choose
    long long ans = func(ind - 1, value_left);
    // choose
    if(value_left - val[ind]>= 0)
    ans = min(ans, func(ind - 1, value_left - val[ind]) + wt[ind]);
    return dp[ind][value_left] = ans;
}
// TC:- O(105*100005)


int main() {
    memset(dp, -1, sizeof(dp));
    int n;
    long long w;
    cin>>n>>w;
    for (int i = 0; i < n; i++)
    {
        cin>>wt[i]>>val[i];
    }
    int max_value = 1e5+5;
    for (int i = max_value; i >= 0; i--)
    {
        if(func(n-1, i)<=w){
            cout<<i<<endl;
            break;
        }
    }
    

    return 0;
}