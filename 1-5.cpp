#include <bits/stdc++.h>
using namespace std;

int main() {

    // increasing order of datatype from bottom to up
    // double
    // float
    // long long int
    // long int
    // int
    // characters


    // cout<< 3 * 7 /2; // * / operation goes from left to right

    // concept of overflow 

    // 10^-9 < int < 10^9
    // 10^-12 < long int < 10^12
    // 10^-18 < long long int < 10^18


// there are precision errors in double for very large no.

// for very large numbers store them in string like
// 4172348912748971328947289734872893478912748652689473479372847189735862384287418273874891385628348932


    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin , s);
        cout<<s<<endl;
    }


    return 0;
}