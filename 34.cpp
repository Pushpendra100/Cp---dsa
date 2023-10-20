#include <bits/stdc++.h>
using namespace std;

bool should_i_swap1(pair<int,int> a, pair<int, int> b){
    if(a>b) return true;
    return false;
}

bool should_i_swap(pair<int,int> a, pair<int, int> b){
    if(a.first != b.first){
        if(a.first > b.first) return true;
        return false;    
    }else{
        if(a.second < b.second) return true;
        return false;
    }
}

bool comp(pair<int,int> a, pair<int, int> b){
    if(a.first != b.first){
        if(a.first > b.first) return false;
        return true;    
    }else{
        if(a.second < b.second) return false;
        return true;
    }
}

// short trick of comp function
// jo order mein chahiye wo hi order mein return kar do
// bas agar return a.first < b.first hai
//  if agar yeh true hai toh swap nahi hoga but agar yeh false hai toh swap ho jayega

bool comp_short(pair<int,int> a, pair<int, int> b){
    if(a.first != b.first){
        return a.first < b.first;           
    }

    return a.second > b.second;
}

// comp function for decreasing order of array
bool comp_short1(int a, int b){
    return a > b;
}

int main() {

    int n;
    cin>>n;
    vector<pair<int,int>> a(n);
    /*
    input
    6
    4 3
    5 5 
    5 3
    25 6
    7 9
    8 5
    */
    for (int i = 0; i < n; i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i+1; j < n; j++)
    //     {
    //         if(should_i_swap(a[i], a[j])){   // this is the logic ki swap karna hai ya nahi yahi comparator function hai
    //             swap(a[i], a[j]);
    //         }
    //     }
        
    // }




    // sort(a.begin(), a.end());
    // sort(a.begin(), a.end(), should_i_swap);
    //but the behaviour of comparator function is some what opposite
    // if you want to swap then return false else return true

    // sort(a.begin(), a.end(), comp);
    // sort(a.begin(), a.end(), comp_short);
    sort(a.begin(), a.end(), greater<pair<int,int>>()); /// in built function for decreasing order


    
    for (int i = 0; i < n; i++)
    {
        cout<<a[i].first<<" "<<a[i].second<<"\n";
    }
   

    return 0;
}