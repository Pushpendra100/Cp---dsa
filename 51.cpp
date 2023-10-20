#include <bits/stdc++.h>
using namespace std;
// What is Bit Masking with example Question
// https://codeforces.com/blog/entry/73558

/*
Bit + Mask

###
Let's assume we have 4 fruits
0 - Apple
1 - Orange
2 - Banana
3 - Lichi

and we have 3 people and fruits they have are
1 - [2, 3]
2 - [0, 1, 2]
3 - [1, 3]

We have to find common fruits between two people
thus intersection of 1 and 2 person is 2

************** For 2 sorted arrays, their intersection can be find out in O(N) time using two pointer approach

We want to reduce this O(N) time for intersection cases
thus instead of storing fruits in arrays and no. of fruits are less, we will make a binary which has 2 and 3 bit set

So, 1 - 2, 3  ->   1100 - 12
    2 - 0, 1, 2 -> 0111 -  7
    3 - 1, 3 -> 1010    - 10

    this is bit mask, that we are making a mask of bits to represent something
    thus to know which fruits does the person has, can be represented through a number

Now, for telling intersection of person 1 and 2, we can simply do 12 & 7 = 1100 & 0111 = 0100 -> thus only fruit with index 2 is common
     to find union of person 1 and 2, 12 | 7 = 1100 | 0111 = 1111

But, there is a limit as for int - 31 bits
                            unsigned int - 32 bits
                            long long - 63 bits
                            unsigned long long - 64 bits
    
    thus if my fruits are more than 32 then we can't use unsigned bit, then we need to use unsigned long long    
    but if exceed 64 then we can't bit masking
    This is bit masking limit


*/


void printBinary(int num){
    for (int i = 31; i >= 0; i--)
    {   
        cout<< ((num>>i) & 1);       
    }                                      
    cout<<endl;                            
}

int main() {

    /*
        Workers work on days [1, 30]

        input
        5
        4 
        1 4 7 9
        6
        2 9 1 7 25 29
        7
        1 23 4 7 9 11 29
        10
        2 28 8 7 9 10 30 21 18 19
        4
        1 11 29 7

        We have to return two workers whose common days of working are maximum

    */

    // int n;
    // cin>>n;
    // vector<int> days[n];
    // for (int i = 0; i < n; i++)
    // {
    //     int no_of_working_days;
    //     cin>>no_of_working_days;
    //     for (int j = 0; j < no_of_working_days; j++)
    //     {   
    //         int day;
    //         cin>>day;
    //         days[i].push_back(day);
    //     }
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i+1; j < n; j++)
    //     {
    //         // days[i], days[j]  
    //         // the two vectors with max intersection will be the answer
    //         // O(N) = O(30) - vector can have 30 days in it, thus intersection time complexity is O(30)
    //     }
    // }
    // // O(N^2 *30) this is the complete time complexity







    // so instead of storing a vector of days we can store bit mask of working days
    int n;
    cin>>n;
    vector<int> masks(n, 0);
    for (int i = 0; i < n; i++)
    {
        int no_of_working_days;
        cin>>no_of_working_days;
        int mask = 0;
        for (int j = 0; j < no_of_working_days; j++)
        {   
            int day;
            cin>>day;
            mask = (mask | (1<<day));
        }
        masks[i] = mask;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<masks[i]<<endl;
    //     printBinary(masks[i]);
    // }
    
    int max_days = 0;
    int person1 = -1;
    int person2 = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int intersection = (masks[i] & masks[j]);  //O(1)
            int common_days = __builtin_popcount(intersection); //O(1)
            if(common_days>max_days){
                max_days = common_days;
                person1 = i;
                person2= j;
            }
            
            // max_days = max(max_days, common_days);
            // cout<<i<<" "<<j<<" "<<common_days<<endl;
        }
    }
    // O(N^2 * 1) = O(N^2)
    cout<<person1<<" "<<person2<<" "<<max_days<<endl;
    

    return 0;
}