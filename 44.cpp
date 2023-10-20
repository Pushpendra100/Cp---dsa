#include <bits/stdc++.h>
using namespace std;
// Advanced Binary Search with Predicate Function
// https://www.spoj.com/problems/AGGRCOW/


/*
    | - 3 - 5 - 8 - 12 - 20 - |
    we have to maximize the minimum distance between cows
        c1 c2  c3                m.d = 0     -> T
        c1 c2  c3                m.d = 1     -> T
        c1 c2  c3                m.d = 2     -> T
        c1     c2   c3           m.d = 3     -> T
        c1     c2   c3           m.d = 4     -> T
        c1     c2        c3      m.d = 5     -> T
        c1          c2   c3      m.d = 6     -> T
        c1          c2   c3      m.d = 7     -> T
        c1          c2   c3      m.d = 8     -> T     --> we need to find last true
        c1          c2           m.d = 9     -> F
        c1          c2           m.d = 10     -> F


    this is monotonic predicate function thus binary search
*/

/*
input
1   
5 3
1
2
8
4
9
*/



const int N = 1e5+10;
int n, cows;
int positions[N];

bool canPlaceCows(int minDist){
    int lastPos = -1;
    int cows_ct = cows; // we can't change global variable thus we make cow_ct
    for (int i = 0; i < n; i++)  // when we are using this loop we are assuming that the positions array is sorted so that when we move to next element more distance is increased than the previous one i.e. next no.is greater
    {
        if(positions[i] - lastPos >= minDist || lastPos == -1){
            cows_ct--;
            lastPos = positions[i];
        }
        if(cows_ct == 0) break;
    }

    return cows_ct == 0;
}

int main() {

    int t;
    cin>>t; 
    while (t--)
    {
        cin>>n>>cows;
        for (int i = 0; i < n; i++)
        {
            cin>>positions[i];
        }
        sort(positions, positions+n);  // nlog(n)
        // TTTTTFFFF
        int lo = 0, hi = 1e9, mid;
        while (hi-lo>1)
        {
            mid = (lo+hi)/2;
            if(canPlaceCows(mid)){ //canPlaceCows - O(n)
                lo = mid;
            }else{
                hi = mid-1;
            }
        } // nlog(10^9)
        //since we need max value first check hi
        if(canPlaceCows(hi)){
            cout<<hi<<endl;
        }else{
            cout<<lo<<endl;
        }
        
        //nlog(10^9) + nlog(n)
        
    }
    

    

    return 0;
}