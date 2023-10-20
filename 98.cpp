#include <bits/stdc++.h>
using namespace std;
// SUBSET SUM & PARTITION PROBLEM : Dynamic Programming 
// https://leetcode.com/problems/partition-equal-subset-sum/description/

/*
1       5       11      5
to make sum = 6 of a subset

we can select one element or not

func(index, sum)  
index -> upto which index we have to take elements to make sum 


                                func(3, 6)
                    func(2, 1)                 func(2, 6)

*/

const int N = 1e5+10;
int dp[205][20005];

bool func(int i, int sum, vector<int> &nums){
    if(sum == 0) return true;
    if(i<0) return false;
    if(dp[i][sum]!=-1) return dp[i][sum];
    // not consider ith index
    bool isPossible = func(i-1, sum, nums);
    // consider ith index
    if(sum-nums[i]>=0)
    isPossible |= func(i-1, sum - nums[i], nums);
    return dp[i][sum] = isPossible;
}


bool canPartition(vector<int>& nums) {
    memset(dp, -1, sizeof(dp));
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum%2 != 0) return false;
    sum = sum/2;
    return func(nums.size() - 1, sum, nums);
}



int main() {

    

    return 0;
}