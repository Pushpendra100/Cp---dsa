#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> v = {2, 3, 5, 6, 7};
    // another way of printing a vector
    // for(int value : v){
    //     // here also vector values are passed by value
    //     cout<<value<<" ";
    // }
    // for(int &value : v){
    //     // thus use &, do pass by reference
    //     cout<<value<<" ";
    // }



    vector<pair<int, int>> v_p = {{1, 2}, {2, 3}};
    // for (pair<int, int> &value : v_p)
    // {
    //     cout<<value.first<<" "<<value.second<<"\n";
    // }
    


    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout<<*it<<" ";
    }
    for (auto  &value : v_p)
    {
        cout<<value.first<<" "<<value.second<<"\n";
    }
    
    
    



    return 0;
}