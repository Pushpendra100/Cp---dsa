#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin>>n;
    vector<int> v(n);
    /*
    input
    6
    2 3 1 6 7 6
    */
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }



    // all these function are O(n) for vectors and arrays
    // but only count and find in case of sets and maps it is O(log(n))

    // min_element returns address
    int min = *min_element(v.begin()+3,v.end());
    cout<<min<<endl;

    int max = *max_element(v.begin(), v.end());
    cout<<max<<endl;

    // accumulate returns the sum of array or vector where we also need to pass the initial sum value 
    int sum = accumulate(v.begin(), v.end(), 0);
    cout<<sum<<endl;

    // count returns the count of a number 
    int ct = count(v.begin(), v.end(), 6);
    cout<<ct<<endl;

    // find returns the address of the number
    auto it = find(v.begin(), v.end(), 10);
    if(it != v.end()){
        cout<<*it<<endl;
    }else{
        cout<<"element not found"<<endl;
    }

    // reverse function 
    // reverse(v.begin(), v.end());
    reverse(v.begin()+2, v.end());
    for (auto &val : v)
    {
        cout<<val<<" ";
    }
    cout<<endl;


    string s = "akfjdaklfjdl";
    reverse(s.begin()+1, s.end());
    cout<<s<<endl;
    







    return 0;
}