#include <bits/stdc++.h>
using namespace std;
// input
// 1
// 3 3
// 2 6 9
// 1 1
// 2 2
// 2 3

// output
// 3 
// 1
// 2



/*
    to find gcd of 1 to l-1 and r+1 to n

    constraints -
        1. subtask#1-
            2 <= T,N <= 100, 1 <= Q <= N, 1 <= A[i] <= 10^5
            1 <= L, R <= N and L <= R


        2. subtask#2 -
            2 <= T, N <= 10^5, 1 <= Q <= N, 1 <= A[i] <= 10^5
            1 <= L, R <= N and L <= R
            sum of N over all test cases will be less than or equal to 10^6
*/

// int main() {

//     int t;
//     cin>>t;
//     while(t--){
//         int n, q;
//         cin>>n>>q;
//         int a[n+10];
//         // in case of prefix pre-computation take 1 base input
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//         }
//         while (q--)
//         {
//             int l, r;
//             cin>>l>>r;
//             // __gcd(a, b) // this is inbuilt function to find gcd
//             // its complexity is log of a or b which is max out of a and b
//             int gc = 0;
//             for (int i = 1; i <= l-1; i++)
//             {
//                 gc = __gcd(gc, a[i]);
//             }
//             for (int i = r+1; i <=n ; i++)
//             {
//                 gc = __gcd(gc, a[i]);
//             }
//             cout<<gc<<endl;

//         }
//         // O(T * (N + Q*N)) = O(T*N + T*N*Q) = O(T*N*Q) = O(N^3)
//         // in subtask1 - 100^3 - thus it will complete subtask 1
//         // in subtask2 - sum of N over all test cases will be less than or equal to 10^6 - it actually is T*N = 10^6
//         // then also O(10^6 * Q) and Q is 10^5 thus 10^11 thus it is failing some test cases of subtask2

//     }

//     return 0;
// }

// now we will make two prefix arrays, one will be forward while another will be backward
// let's say a b c d e f is the array
// then forward array will have gcd stored like [a ab abc abcd abcde abcdef]
// and backward array will be like [abcdef bcdef cdef def ef f]

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        int a[n + 10];
        int forward[n + 10];
        int backward[n + 10];
        forward[0] = backward[n + 1] = 0;
        // gcd of any number with 0 is that number only
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            forward[i] = __gcd(forward[i - 1], a[i]);
        }
        for (int i = n; i >= 1; i--)
        {
            backward[i] = __gcd(backward[i + 1], a[i]);
        }
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            cout << __gcd(forward[l - 1], backward[r + 1]) << endl;
        }
    }
    // O(T * ( N + Q * logN)) = O(T * ( N + Q)) = O(T * N) = 10^6
    // logN is ignored for simplicity
    // and it is given T*N = 10^6
}