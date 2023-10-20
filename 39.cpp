#include <bits/stdc++.h>
using namespace std;
// Subset generation using recursion and backtracking
// https://leetcode.com/problems/subsets/description/


vector<vector<int>> subsets;

void generate(vector<int> &subset,  int i, vector<int> &nums){   // we don't want to pass by value other wise complexity will be very high

    if(i == nums.size()){   // base condition
        subsets.push_back(subset);
        return;
    }

    // ith element not in subset
    generate(subset, i+1, nums);
    
    // ith element in subset
    subset.push_back(nums[i]);
    generate(subset, i+1, nums);
    subset.pop_back();   // this is called backtracking
}         

/*
                                                     []
                            [1]                                               []                        ->1
                [1,2]                   [1]                      [2]                      []            ->2
        [1, 2, 3]       [1,2]     [1,3]         [1]       [2,3]        [2]          [3]         []      ->3


    thus there are n levels and thus total functions call = 2^n+1 ~ 2^n
    and time complexity of each function is O(1)


    // Thus total time complexity is O(2^n)

*/

int main() {

    // we know for n elements there are 2^n subsets


/*
input
3
1 2 3
*/

    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    vector<int> empty;
    generate(empty, 0, nums);
    for(auto &sub : subsets){
        for (auto &elem : sub)
        {
            cout<<elem<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}