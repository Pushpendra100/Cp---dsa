#include <bits/stdc++.h>
using namespace std;

int main() {

    // vector<int> v = {2, 3, 5, 6, 7};
    //     // vector<int>::iterator it = v.begin();
    //     // cout<<*(it+1)<<"\n";    // +1 in iterator only works when it is continous memory allocation

    // for (auto it = v.begin(); it != v.end(); it++)
    // {
    //     cout<<*it<<"\n";
    // }
    // // ***************************
    // // map and set are not continous
    // // thus it+1 will not work
    // // but it++ will work because it will take it to next element but in case of it+1 it moving to next address
    // // ****************************


    vector<pair<int,int>> v_p = {{1, 2}, {2, 3}, {3, 4}};
    vector<pair<int,int>>:: iterator it; // declare iterator with the same datatype jo uske container ka hai

    for ( it = v_p.begin(); it != v_p.end(); it++)
    {
        cout<<(*it).first<<" "<<(*it).second<<"\n";
    }

    for ( it = v_p.begin(); it != v_p.end(); it++)
    {
        cout<<it->first<<" "<<it->second<<"\n";
        // we can also use this syntax when iterator is pointing to a pair
    }
    


    return 0;
}