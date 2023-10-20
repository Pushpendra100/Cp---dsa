#include <bits/stdc++.h>
using namespace std;
// Implement Upper Bound & Lower Bound with Binary Search




int lower_bound(vector<int> &v, int element){
    int lo = 0, hi = v.size() -1;
    int mid;
    while (hi-lo>1)
    {
        int mid = (hi+lo)/2;
        if(v[mid]< element){
            lo = mid+1;
        }else{
            hi = mid;
        }
    }
    if(v[lo]>=element){
        return lo;
    }
    if(v[hi]>= element){
        return hi;
    }
    return -1;
    
}

int upper_bound(vector<int> &v, int element){
    int lo = 0, hi = v.size() -1;
    int mid;
    while (hi-lo>1)
    {
        int mid = (hi+lo)/2;
        if(v[mid]<= element){
            lo = mid+1;
        }else{
            hi = mid;
        }
    }
    if(v[lo]>element){
        return lo;
    }
    if(v[hi]> element){
        return hi;
    }
    return -1;
    
}







int main() {

    /*
    input
    6 
    2 4 8 12 17 26
    18
    */

    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    int element;
    cin>>element;
    int lb = lower_bound(v,element);
    int ub = upper_bound(v,element);
    cout<<lb<<" "<<(lb!=-1?v[lb]:-1)<<endl;
    cout<<ub<<" "<<(ub!=-1?v[ub]:-1)<<endl;

    // similarly we can also pass the starting iterator as well as ending iterator in the lower and upper bound function
    

    return 0;
}