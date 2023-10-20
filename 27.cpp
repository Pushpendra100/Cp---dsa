#include <bits/stdc++.h>
using namespace std;

void print(multiset<string> &s){
    for (auto &value : s)
    {
        cout<<value<<"\n";
    }
    // for (auto it = s.begin(); it != s.end(); it++)
    // {
    //     cout<<*it<<"\n";
    // }
    
    
}

int main() {

    // set<string> s;

    // // it stores both in sorted and unique keys
    // // it is just like you are taking keys of map only, internally set uses red black tree

    // s.insert("abc");    // logN - both insertion and value access is of logN time complexity
    // s.insert("xyz");    
    // s.insert("def");    
    // s.insert("def");
    // auto it = s.find("abc"); // log(n)
    // //if exist then return the address otherwise return s.end()
    // // after using find don't directly use the value of it, first use a if statement to avoid a segmentation fault

    // if(it != s.end()){
    //     cout<<(*it);
    // }
    // cout<<"\n";
    // s.erase("xyz"); // log(n)
    // s.erase(it);
    // print(s);



    /*
    Given N strings, print unique strings in lexographical order
    N <= 10^5
    |s| <= 100000
    */

    // set<string> s;
    // int n;
    // cin>>n;
    // for (int i = 0; i < n; i++)
    // {
    //     string str;
    //     cin>>str;
    //     s.insert(str);
    // }
    // for (auto &value : s)
    // {
    //     cout<<value<<"\n";
    // }

    // same for sets internally they use red black tree








    // UNORDERED SET
    // // same as unordered_map unordered_set uses hash table thus it can't hold copmlex data structure like pair and vector in it
    // // because their inbuilt hash functions are not defined
    // unordered_set<string> s;
    // s.insert("abc");    // O(1) --> now all actions are O(1)
    // s.insert("xyz");    
    // s.insert("def");    
    // s.insert("def");    
    // // thus if order is not mattering then we will use unordered set, it will also decrease time
    // print(s);



    /*
    Given N strings and Q queries.
    In each query you are give a string print yes if string is present else print no

    N <= 10^6
    |S| <= 100
    Q <= 10^6


    input
    8
    abc
    def
    abc
    ghj
    jkl
    ghj
    ghj
    abc
    3
    abc
    ghj
    acd



    */
    

    // unordered_set<string> us;
    // int n;
    // cin>>n;
    // for (int i = 0; i < n; i++)
    // {
    //     string str;
    //     cin>>str;
    //     us.insert(str);
    // }
    // int q;
    // cin>>q;
    // while (q--)
    // {
    //     string str;
    //     cin>>str;
    //     if(us.find(str)==us.end()){
    //         cout<<"NO\n";
    //     }else{
    //         cout<<"YES\n";
    //     }
    // }
    
    









//  MULTISET
// this also uses red black tree thus all operations are in log(n) and you can put any data type inside it
// in this you can have duplicates but in sorted fashion
    multiset<string> s;

    s.insert("abc");    // O(log(n)) --> now all actions are O(log(n))
    s.insert("xyz");    
    s.insert("def");    
    s.insert("def");    
    s.insert("def");    
    s.insert("jhl");    
    s.insert("jhl");    
    s.insert("kll");    

    print(s);

    auto it = s.find("def"); // it will return address of first instance
    if(it != s.end()){
        s.erase(it);    
    }
    cout<<"\n";
    // two things can be passed in erase
    // 1. address -> then only that is erased  --> O(1)
    // 2. if value passed -> then all those values are deleted --> O(log(n))

    print(s);
    cout<<"\n";
    s.erase("jhl");
    print(s);
    cout<<"\n";


    return 0;
}