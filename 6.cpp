#include <bits/stdc++.h>
using namespace std;

// ******************************************************
// main concepts learned *******************
// 2d array,
// max size of array in global and local scope 
// ******************************************************


// whenever variables are declared in global then const keyword is to be used
const int n = 1e7;
int a[n];



// locally size of array should be about 1e7 and globally it can go upto 1e7


int main() {

    // int a[5];


    // ******************************
    // 2d array

    // input
    // 3 4
    // 1 2 3 4
    // 5 6 7 8
    // 9 10 11 12

    // int n, m;
    // cin >> n >> m;
    // int a[n][m];

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cin >> a[i][j];
    //     }
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    // *******************************************
    // limits of array
    
    // int n = 1e7;
    // int a[n];
    // a[n-1] = 7;
    // cout<<a[n-1]; //******************Segmentation fault (core dumped)***********
    // we can't declare this big array of range of 1e7 inside main function

    // int n = 1e5;
    // int a[n];
    // a[n-1] = 7;
    // cout<<a[n-1];
    // this works

    a[n-1] = 7;
    cout<<a[n-1];
    // this is globally declared

    return 0;
}