#include <bits/stdc++.h>
using namespace std;

/*
Array manipulation - 
starting with a 1-indexed array of zeroes and a list of opertaions, for each operation add a value to each the array element
between two given indices. Once all operations have been performed, return the max value in the array

constraints - 
3 <= n <= 10^7
1 <= m <= 2*10^5
1 <= a <= b <= n
0 <= k <= 10^9
*/

// sample input
// 5 3
// 1 2 100
// 2 5 100
// 3 4 100

// sample output
// 200

/*
after 1st update - 100 100 0 0 0
after 2nd update - 100 200 100 100 100
after 3rd update - 100 200 200 200 100
then maximum value - 200
*/


// const int N = 1e7+10;
// long long int arr[N];

// int main() {

//     int n,m;
//     cin>>n>>m;

//     while(m--){
//         int a, b, d;
//         cin >> a >> b >> d;
//         for (int i = a; i <= b; i++)
//         {
//             arr[i] += d;
//         }
//     }
//     long long mx = -1;
//     for (int i = 1; i <= n; i++)
//     {
//         if(mx < arr[i]) mx = arr[i];
//     }
//     cout<<mx<<endl;
//     // O(M*N + N) = O(M*N) = 10^12 iterations
    

//     return 0;
// }








// this will be solved using somewhat combination of 
// hashing and prefix

// see let's given operations are
// 2 -> 3  + 4
// 3 -> 5  + 2

/*
    1  2  3  4  5  6
    0  0  0  0  0  0

    0 +4  0 -4  0  0            --> if we take prefix sum of this we will get 0 4 4 0 0 0
    0 +4 +2 -4  0 -2
    -------------------
    0  4  6  2  2  0         now take prefix sum

    this we can do directly with the given array
*/



const int N = 1e7+10;
long long int arr[N];

int main() {
    int n,m;
    cin>>n>>m;
    while (m--)
    {
        int a, b, d;
        cin >> a >> b >> d;
        arr[a] += d;
        arr[b+1] -= d;
    }
    // now take prefix sum
    for (int i = 1; i <= N; i++)
    {
        arr[i] += arr[i-1]; 
    }

    long long mx = -1;
    for (int i = 1; i <= n; i++)
    {
        if(mx < arr[i]) mx = arr[i];
    }
    cout<<mx<<endl;
    // O(M + N) = 10^7 iterations
    
}