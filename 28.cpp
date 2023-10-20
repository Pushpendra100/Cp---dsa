#include <bits/stdc++.h>
using namespace std;

int main() {

    /*
    https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-the-magical-candy-bags/?update=google&purpose=login&source=problem-page&fbclid=IwAR2kDiVkEaxu9dkCTCUhzXLuIccNn0Gz3dSfkaSUjlDE6Nb9UHMzt8HNDo4


    input
    1
    5 3
    2 1 7 4 2

    output
    14

    */

   int t;
   cin>>t;
   while (t--)
   {
    int n, k;
    cin>>n>>k;
    multiset<long long> bags;
    for (int i = 0; i < n; i++)
    {
        long long candy_ct;
        cin>>candy_ct;
        bags.insert(candy_ct);
    }
    // for this loop log(n)
    long long total_candies = 0;
    for (int i = 0; i < k; i++)
    {
        auto last_it = (--bags.end());
        long long candy_ct = *last_it;
        total_candies += candy_ct;
        bags.erase(last_it);  // --> O(1)
        bags.insert(candy_ct/2);  // --> O(log(n))
    }
    // for this loop k * log(n)
    cout<<total_candies<<"\n";
    
    
   }
   


    return 0;
}