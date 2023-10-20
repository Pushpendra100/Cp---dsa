#include <bits/stdc++.h>
using namespace std;
// Introduction to Dynamic Programming

const int N = 1e5+10;


// int fib(int n){
//     if(n==0) return 0;
//     if(n==1) return 1;
//     return fib(n-1) + fib(n-2);
// }
// // 2^n function calls thus O(2^n) time complexity - exponential time complexity















// int dp[N];
// //Top Down approach     (from big problem to small problem)

// int fib(int n){
//     if(n==0) return 0;
//     if(n==1) return 1;
//     if(dp[n] != -1) return dp[n];
//     //dp[n]!=-1 is called memoisation
//     return dp[n] = fib(n-1) + fib(n-2);
// }
// //Thus there are only n function calls
// // O(n)

// /*
// using dp
// O(x^y) exponential TC -> O(N) linear TC
// O(N!) factorial TC gets converted to -> O(2^N) exponential TC       == this happens using bit masking dp
// */

// int main() {
//     memset(dp, -1, sizeof(dp)); // we have filled complete dp array with -1 to get idea whether some value is filled or not
//     //memset works only for -1
//     int n;
//     cin>>n;
//     cout<<fib(n)<<endl;

//     return 0;
// }











int dp[N];

int main(){
    memset(dp, -1, sizeof(dp));
    int n;
    cin>>n;

    //BOTTOM UP Approach   (from small problem to big problem)
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <=n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout<<dp[n-1]+dp[n-2]<<endl;
    
}