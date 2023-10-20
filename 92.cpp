#include <bits/stdc++.h>
using namespace std;
// Longest Increasing Subsequence (LIS)
// https://atcoder.jp/contests/dp/tasks
// https://leetcode.com/problems/longest-increasing-subsequence/description/

/*
10 9 2 5 3 7 101 18
subarray is continous part of array i.e. 2 5 3
subsequence only keeps the order same in how they appear in array i.e. 9 3 7 18

longest increasing subsequence -> 2 5 7 101 = 4
                               -> 2 3 7 18 = 4
*/

const int N = 25e2+10;  
vector<int> a(N);
int dp[N];

int lis(int i){
    if(dp[i] != -1) return dp[i];
    int ans = 1; // this includes the number itself and then using for loop we check for all elements left to it
    for (int j = 0; j < i; j++)
    {
        if(a[i]>a[j]){
            ans = max(ans, lis(j) + 1);
        }
    }
    return dp[i] = ans;
}
// due to dp O(N) and each func call has O(N) tc
// thus O(N^2)



int main() {
    memset(dp, -1, sizeof(dp));
    int n;
    cin>>n;
    for (int i = 0; i <n; i++)
    {
        cin>>a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, lis(i));
    }
    cout<<ans<<endl;
    

    return 0;
}