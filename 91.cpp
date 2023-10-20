#include <bits/stdc++.h>
using namespace std;
// https://atcoder.jp/contests/dp/tasks
// Frog 1 & 2: Atcoder 1D DP Questions

/*
approach to dp questions
- first try to write using brute force approach using recursion in top down manner  
*/








// *************** Frog 1 ***********************************


/*
1       2       3       4       5       6
we have to get min. cost to reach stone 6
let min cost to reach 4 is m4 and for 5 it is m5
then m6 = min(m4 + |h6 - h4|, m5 + |h6 - h5|)

*/

/*
input
4
10 30 40 20
output
30
*/



// const int N = 1e5+10;
// int h[N];

// // int func(int i){
// //     if(i==0) return 0;
// //     int cost = INT_MAX;

// //     //way1
// //     cost = min(cost, func(i-1) + abs(h[i] - h[i-1]));
// //     //way2
// //     if(i>1)
// //         cost = min(cost, func(i-2) + abs(h[i] - h[i-2]));
// //     return cost;
// // }
// // brute force approach of recursion


// // now dp

// int dp[N];
// int func(int i){
//     if(i==0) return 0;
//     if(dp[i] != -1) return dp[i];
//     int cost = INT_MAX;

//     //way1
//     cost = min(cost, func(i-1) + abs(h[i] - h[i-1]));
//     //way2
//     if(i>1)
//         cost = min(cost, func(i-2) + abs(h[i] - h[i-2]));
//     return dp[i] = cost;
// }
// // TC:- O(N)


// int main() {
//     memset(dp, -1, sizeof(dp));
//     int n;
//     cin>>n;
//     for (int i = 0; i < n; i++)
//     {
//         cin>>h[i];
//     }
//     cout<<func(n-1)<<endl;  

//     return 0;
// }














// *************** Frog 2 ***********************************



/*
input
3 1
10 20 10
output
20
*/



const int N = 1e5+10;
int k;
int h[N];
int dp[N];

int func(int i){
    if(i==0) return 0;
    if(dp[i] != -1) return dp[i];
    int cost = INT_MAX;

    for (int j = 1; j <= k; j++)
    {   
        if(i-j>=0)
            cost = min(cost, func(i-j) + abs(h[i]-h[i-j]));
    }
    return dp[i] = cost;
}
//O(N*K) time complexity


int main() {
    memset(dp, -1, sizeof(dp));
    int n;
    cin>>n>>k;
    for (int i = 0; i < n; i++)
    {
        cin>>h[i];
    }
    cout<<func(n-1)<<endl;  

    return 0;
}
