#include <bits/stdc++.h>
using namespace std;
// Advanced Binary Search with Predicate Function
// https://www.spoj.com/problems/EKO/

/*
Predicate function - which returns true or false
monotonic predicate function are :-  (ek point ke baad kewal true aaye ya phir kewal false aaye)
    - TTTTTTFFFFFFFFF
    - FFFFFFFFFTTTTT
    - TTTTTTTTT
    - FFFFFFFFFFF

using binary search we can find ki pehla true kab aaya ya phir pehla false kab aaya

*/
/*
    func(h){
        if wood>=M then returns true
        else false
    }
    so for h = 0  -> T
           h = x  -> T
           h = x+  -> T
           h = x+  -> T
           h = x+  -> T
    for some h     -> F
    then           -> F
                   -> F



    thus we have to find last T
*/















const int N = 1e6+10;
int n; 
long long m; //required amount of wood
long long trees[N];

bool isWoodSufficient(int h){
    long long wood = 0;
    for (int i = 0; i < n; i++)
    {
        if(trees[i] >= h){
            wood += trees[i] - h;
        }
    }
    return wood>=m;
}



int main() {

    /*
    input
    4 7 
    20 15 10 17
    */

    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        cin>>trees[i];
    }
    
    long long lo = 0, hi= 1e9, mid;
    // T T T T F F F F F we need to find last true
    while (hi-lo>1)
    {
        mid = (hi+lo)/2;
        if(isWoodSufficient(mid)){  // isWoodSufficient will take N time
            lo = mid; //as mid is itself true
        }else{
            hi = mid -1;    // as mid is itself false
        }
    }
    // this while loop will take log(H)
    if(isWoodSufficient(hi)){
        cout<<hi<<endl;  // first we will check with hi as we have to return max height, i.e. last true
    }else{
        cout<<lo<<endl;    // there is no case ki aapko wood na mile isliye answer nahi hoga yeh toh possible hi nahi hai
    }

    //TC: O(Nlog(H))  H is max height
    

    return 0;
}