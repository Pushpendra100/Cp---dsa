#include <bits/stdc++.h>
using namespace std;

void print(unordered_map<int,string> &m){
    cout<<m.size()<<endl;
    for (auto &pr : m)
    {   
        cout<<pr.first<<" "<<pr.second<<"\n";
    }
}

int main() {

    // UNORDERED MAP
    //  differences between map and unordered map are :-
    //      1. inbuilt implementation - instead of tree unordered_map uses hash table
    //      2. Time complexity
    //      3. valid keys datatype

    // all functions are same 


    // unordered_map<int, string> m;
    // m[1] = "abc";   // O(1)
    // // insertion and access of memory both are of O(1)
    // m[5] = "cdc";
    // m[3] = "acd";
    // print(m);

    // m.find() and m.erase() --> O(1)

    // If there is nothing to take with order in the question, then always use
    // unordered_map because it will take less time to do any operation


    // In unordered_map, internally hash tables are used which hash the keys to store them
    // thus those data structuers that have hash function defined can only be used as key
    // thus we can't use pair, vector





    /*
    Given N strings and Q queries. In each query you are given a string
    print frequency of that string

    N <= 10^6
    |S| <= 100
    Q <= 10^6

    input
    8
    asj
    gfi
    abc 
    qef
    abc
    jkl
    asj
    abc
    2
    abc
    gfi

    */
   unordered_map<string, int> m;
   int n;
   cin>>n;
   for (int i = 0; i < n; i++)
   {
    string s;
    cin>>s;
    m[s]++;
   }
   int q;
   cin>>q;
   while(q--){
    string s;
    cin>>s;
    cout<<m[s]<<"\n";
   }
//    this while loop is 10^6 * O(1)
// if we have used map then it would be 10^6 * O(logN)









// MULTIMAP
// only difference between map and multimap is you can store duplicate keys 

multimap<int, int> mapp;




    return 0;
}