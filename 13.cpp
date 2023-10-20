#include <bits/stdc++.h>
using namespace std;
// Pre-computation using Prefix Sum in 1D/2D arrays



/*
    Given array a of N integers. Given Q queries and in each query given L and R print sum of
    array elements from index L to R(L,R included)

    Constraints
    1 <= N <= 10^5
    1 <= a[i] <= 10^9
    1 <= Q <= 10^5
    1 <= L, R <= N
*/

// const int N = 1e5+10;
// int a[N];

// int main() {

//     int n;
//     cin>>n;
//     // in these cases where l and r are given or constraints are given like 1<=l,
//     // then in these cases use 1 base arrays;
//     for (int i = 1; i <= n; i++)
//     {
//         cin>>a[i];
//     }

//     int q;
//     cin>>q;

//     while(q--){
//         int l,r;
//         cin>>l>>r;
//         long long sum = 0;
//         for (int i = l; i <= r; i++)
//         {
//             sum += a[i];
//         }
//         cout<<sum<<endl;
        
//     }
//     // we calculate time complexity acc to worst case
//     // O(N) + O(Q*N) = O(N^2) = 10^10 iterations
    

//     return 0;
// }


// const int N = 1e5+10;
// int a[N];
// declare array prefix sum
// int pf[N];

// int main(){
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//         pf[i] = pf[i-1] + a[i];
//         // here we don't need to handle pf[0] case otherwise we need to do if-else
//         // thus in cases of prefix use 1 base array
//     }

//     int q;
//     cin>>q;
//     while(q--){
//         int l,r;
//         cin>>l>>r;
//         cout<<pf[r] - pf[l-1]<<endl;
//     }
//     // O(N) + O(Q) = O(N) = 10^5
// }







/*
    Given 2d array a of N*N integers. Given Q queries and in each query given a, b, c and d, now print sum of rectangle represented
    by (a, b) as top left point and (c, d) as top bottom right point

    Constraints 
    1 <= N <= 10^3
    1 <= a[i][j] <= 10^9
    1 <= Q <= 10^5
    1 <= a, b, c, d <= N
*/
// const int N = 1e3 + 10;
// int arr[N][N];
// int main(){
//     int n;
//     cin>>n;
// // in prefix sum cases where two points are given take 1 base array
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j= 1; j <= n; j++)
//         {
//             cin>> arr[i][j];
//         }
        
//     }
//     int q;
//     cin>>q;
//     while(q--){
//         int a, b, c, d;
//         cin>>a>>b>>c>>d;
//         long long sum = 0;
//         for (int i = a; i <= c; i++)
//         {
//             for(int j = b; j<= d; j++){
//                 sum += arr[i][j];
//             }
//         }
//         cout<<sum<<endl;
        
//     }
//     // O(N^2) + O(Q*N^2) = 10^5 * 10^6 = 10^11 iterations
    
// }



const int N = 1e3+10;
int arr[N][N];
long long pf[N][N];

int main(){
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin>>arr[i][j];
            pf[i][j] = arr[i][j] + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];
        }
    }
    int q;
    cin>>q;
    while(q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout<<pf[c][d] - pf[a-1][d] - pf[c][b-1] + pf[a-1][b-1]<<endl;
    }
    // O(N^2) + O(Q) = 10^6 + 10^5 = 10^6
}