#include <bits/stdc++.h>
using namespace std;
// How to GENERATE SUBSETS using Bit Masking

/*
Let's the given array be  2 3 7 8 9
                          0 1 2 3 4  

    subset [3, 8] --> bitmask = 01010

let an array be [2, 4, 5] -> no. of subsets 2^3 = 8  as _2_ * _2_ * _2_ = 8 as 2 options for each seat
    subsets -> [], [2], [4], [5], [2, 4], [2, 5], [4, 5], [2, 4, 5]

    thus, for 3 elements
   0 - 000 -> []
   1 - 001 -> [2]
   2 - 010 -> [4]
   3 - 011 -> [4,2]
   4 - 100 -> [5]
   5 - 101 -> [5, 2]
   6 - 110 -> [5, 4]
   7 - 111 -> [5, 4, 2]

   no. of subsets = 2^n = 1<<n 
   thus numbers from 0 to (2^n)-1 will represent the subsets 
   thus to generate the subsets we can loop from 0 to (2^n)-1
*/


vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    int subset_ct = (1<<n);
    vector<vector<int>> subsets;
    for (int mask = 0; mask < subset_ct; ++mask)
    {
        vector<int> subset;
        for (int i = 0; i < n; i++)
        {
            //always cover bit operations with () otherwise sometimes they can give some error and
            // you won't be able to find it, like (mask & (1<<i)) != 0 is correct while, mask & (1<<i) != 0 is incorrect
            if((mask & (1<<i)) != 0){  
                //ith bit is set
                subset.push_back(nums[i]);
            }
        }
        subsets.push_back(subset);
    }
    // O(2^n * n) = O(n * (2^n)) time complexity 
    return subsets;
    
}

int main() {

    /*
    input
    3 
    2 4 5
    */

    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    auto all_subsets = subsets(v);

    for (auto &subset : all_subsets)
    {
        for (int &elem : subset)
        {
            cout<<elem<<" ";
        }
        cout<<endl;
    }
    
   
     
    

    return 0;
}