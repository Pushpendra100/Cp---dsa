#include <bits/stdc++.h>
using namespace std;
// Upper bound and lower bound

/*
this works in log(n) complexity but condition is that data structure should be sorted i.e. array or vector should be sorted
otherwise it will work in O(n) complexity
must do sort *******************

lower bound => finds the element itself or the next element greater than it
upper bound => doesn't matter the element is present or not it will return the next greater element

lower and upper bound returns the address, for arrays it is pointer and for vectors, map and set it is iterator
*/

int main() {

    // int n;
    // cin>>n;
    // int a[n];
    // /*
    // 6
    // 4 
    // 5  
    // 5 
    // 25
    // 7 
    // 8 
    // */
    // for (int i = 0; i < n; i++)
    // {
    //     cin>>a[i];
    // }
    // sort(a, a+n);
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;

    // // int *ptr = lower_bound(a, a+n, 5);
    // // int *ptr = lower_bound(a, a+n, 6);
    // int *ptr = lower_bound(a, a+n, 26);
    // if(ptr == (a+n)){
    //     cout<<"Not found";
    //     return 0;
    // }
    // cout<<(*ptr)<<endl;



    // // int *ptr = upper_bound(a, a+n, 26);
    // // int *ptr = upper_bound(a, a+n, 5);
    // int *ptr = upper_bound(a, a+n, 6);
    // if(ptr == (a+n)){
    //     cout<<"Not found";
    //     return 0;
    // }
    // cout<<(*ptr)<<endl;











//  in vectors

    // int n;
    // cin>>n;
    // vector<int> a(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin>>a[i];
    // }
    // cout<<endl;
    // sort(a.begin(), a.end());
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;

    // auto it = upper_bound(a.begin(), a.end(), 5);
    // if(it == a.end()){
    //     cout<<"Not found";
    // }else{
    //     cout<<*it<<endl;
    // }
    









// in sets and maps

    int n;
    cin>>n;
    set<int> s;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        s.insert(x);
    }

    // if in case of sets and maps if you do like this 
    // auto it = lower_bound(s.begin(), s.end(), 5); //O(n)
    // then lower bound and upper bound will work in O(N)

    auto it = s.lower_bound(6); //O(log(n))
    auto it2 = m.upper_bound(6); //O(log(n)) 
    // in case of map it will see only keys  and will return the address 




/*
    Internal implementation of lower and upper bound
        - in case of arrays and vectors, binary search is used
        - in sets and maps, tree is used
*/

    
    

    

    return 0;
}