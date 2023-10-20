#include <bits/stdc++.h>
using namespace std;
// Pre-computation Techniques and Hashing


const int M = 1e9+7;



// int main() {

//     /*
//     Given T test cases and in each test case a number N. Print its factorial for each test case % M
//     where M = 10^9 + 7.

//     Constraints
//     1 <= T <=  10^5
//     1 <= N <=  10^5
//     */

//    int t;
//    cin>>t;
//    while(t--){
//     int n;
//     cin>>n;
//     long long fact = 1;
//     for (int i = 2; i <= n; i++)
//     {
//         fact = (fact*i)%M;
//     }
//     cout<<fact<<endl;
//    }
//     // O(T*N) = O(N^2) = 10^10 iterations, this code will not run in 1 sec and thus it will give tle error
// // but we can store some values jo pehle ek bar compute ho chuka hai usko bar bar compute kyun karein.


//     return 0;
// }





// const int N = 1e5 + 10;
// long long fact[N];

// int main() {
//     fact[0] = fact[1] = 1;
//     for (int i = 2; i < N; i++)
//     {
//         fact[i] = fact[i-1] * i;
//     }
    
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         cout<<fact[n]<<endl;
//     }
// //    O(N) + O(T) = O(N) = 10^5 iterations
// }






/*
    Given array a of N integers. Given Q queries and in each query given a number X, print count of that number 
    in array.

    Constraints 
    1 <= N <= 10^5
    1 <= a[i] <= 10^7
    1 <= Q <= 10^5
*/

// int main() {
//     int n;
//     cin>>n;
//     int a[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin>>a[i];
//     }
//     int q;
//     cin>>q;
//     while(q--){
//         int x;
//         cin>>x;

//         int ct = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if(a[i]==x) ct++;
//         }
//         cout<<ct<<endl;
//     }
//     // O(N) + O(Q*N) = O(N) + O(N^2) = O(N^2) = 10^10, thus this code will not run in 1sec
// }


// since  1 <= N <= 10^5
// thus we can declare a hash array
const int N = 1e7 + 10;
int hsh[N];
// all global arrays are already 0 initialised

int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        hsh[a[i]]++;
    }
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        cout<<hsh[x]<<endl;
    }
    // O(N) + O(T) = O(N) = 10^5 iterations
}



// How to hash negative numbers
// 1. stl way -  we can use map and unordered map
// 2.    [-4, 2 ,1 -3, -4, -6]
//          add 6 to every element
//      [2, 8, 9, 3, 2, 0]
// now we can create a hash of this array
// now if we want to find count of -4 then 
// -4 + 6 = 2, we will do hsh[2] and this will be the count