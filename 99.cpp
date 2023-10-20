#include <bits/stdc++.h>
using namespace std;
// Longest Common Subsequence: Dynamic Programming
/*
String DP Problems
- Longest common subsequence
- Longest common substring
- Edit distance
*/

/*
func(i, j) 
    max(
        func(i-1, j),
        func(i, j-1),
        func(i-1, j-1) + if(i==j) then 1 else 0
    )
*/

int dp[1005][1005];

// first string is seen upto i index and second string is seen upto j index, then longest subsequence is returned by this function
int lcs(int i, int j, string &s1, string &s2){
    if(i<0 || j<0) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    // remvove 1 char from s1
    int ans = lcs(i-1, j, s1, s2);
    // remvove 1 char from s2
    ans = max(ans,lcs(i, j-1, s1, s2));
    // remvove 1 char from s1 and s2
    ans = max(ans, lcs(i-1, j-1, s1, s2) + (s1[i] == s2[j]));

    return dp[i][j] = ans;
}
//O(N^2) because i and j are changing in dp thus i*j ---> these many time function calls





int longestCommonSubsequence(string text1, string text2) {
    memset(dp, -1, sizeof(dp));
    return lcs(text1.size()-1, text2.size()-1, text1, text2);
}




int main() {

    

    return 0;
}