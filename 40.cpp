#include <bits/stdc++.h>
using namespace std;
// BINARY SEARCH

/*
monotonic functions - which maintains a given order
e.g. 1 2 3 4 5 6 this is ascending thus monotonic
    6 5 4 3  this is descending thus monotonic
    1 2 6 5 4 this is non monotonic

    We can apply binary search on monotonic functions

    we can apply bs on y = x^2
    we can apply bs on FFFFTTTTT (this is called predicate functions)( this is also monotonic, ek bar T return kiya phir T hi deta ja raha hai)
    we can apply bs on TTTTTFFFF
*/



/*  lets no. to be searched be 5
    0 1 2 3 4 5
    2 3 4 5 6 7  -> given sorted array

    search space = 0 - 5, mid = (0+5)/2 = 2
    a[2]<5, thus
    search space = 3 - 5, mid = (3+5)/2 = 4
    a[4]>5, thus
    search space = 3 - 3, mid = 3
    a[3]== 5, thus
    ans = 3
    if a[3]!=5, thus
    we can say that no. is not present

*/

int main() {

    int n;
    cin>>n;
    vector<int> v(n);
    /*
    input
    6 
    2 3 4 5 6 7
    7
    */
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    
    int to_find;
    cin>>to_find;
    int lo = 0, hi = n-1;  // search space = n
    int mid;
    while (hi-lo>1)   // in every while loop we are decreasing search space by half
    {
        int mid = (hi+lo)/2;
        if(v[mid]<to_find){
            lo = mid+1;
        }else{
            hi= mid;
        }
    }
    // thus time complexity is O(log2(n))
    if(v[lo]==to_find){
        cout<<lo<<endl;
    }else if(v[hi]==to_find){
        cout<<hi<<endl;
    }else{
        cout<<"Not found"<<endl;
    }

    
    

    return 0;
}