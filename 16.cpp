#include <bits/stdc++.h>
using namespace std;


/*

A string is given and there are many queries given and in a query
l and r are given, take those letters in the range and if you can make 
palindrome after rearranging them then print yes

constraints
1 <= t <= 10
1 <= N,Q <= 100000
1 <= L, R <= N
'a' <= S[i] <= 'z' for 1 <= i <= N



example :-

s = abccde
    1,2 -> a, b - No
    3,4 -> c, c - Yes (cc)
    3,5 -> c, c, d - Yes (cdc)
    4,4 -> c - Yes (single letter is always a palindrome)



some more depth in palindrome
    abcdcba odd length 
    then we can have only d which have odd no. of occurence

    abccba even length
    then every element has even no. of occurence

    - final verdict - 
    in a palindrome at max only one element can have odd no. of occurence
*/

// INPUT
// 2
// 5 5
// abcec
// 1 2
// 2 5
// 3 5
// 1 5
// 1 4 
// 5 5
// aabbc
// 1 2
// 2 5
// 3 5
// 1 5
// 1 4

// OUTPUT
// NO
// NO
// YES
// NO
// NO
// YES
// NO
// YES
// YES
// YES




// int main() {
//     int t;
//     cin>>t;
//     while(t--){
//         int n, q;
//         cin>>n>>q;
//         string s;
//         cin>>s;
//         while(q--){
//             int l,r;
//             cin>>l>>r;
//             int hsh[26];
//             for (int i = 0; i < 26; i++)
//             {
//                 hsh[i] = 0;
//             }
//             l--, r--; //making it index
//             for (int i = l ; i <= r; i++)
//             {
//                 hsh[s[i]-'a']++;
//             }
//             int oddCt = 0;
//             for (int i = 0; i < 26; i++)
//             {
//                 if(hsh[i] % 2 != 0) oddCt++;
//             }
//             if(oddCt > 1) cout<<"NO\n";
//             else cout<<"YES\n";
//         }
//         // input of string is O(N)
//         // O(T * N + Q * (26 + N + 26))
//         // O(T*Q*N) = 10 * 10^5 * 10^5 = 10^11
//     }
//     return 0;
// }



// optimization
// let the given string be abaccde
// a b a c c d e
// a -> 1 0 1 0 0 0 0
//      1 1 2 2 2 2 2    prefix sum of a
// thus no. of a count from index = 1 to index = 6 is 2 - 1 = 1
// b -> 0 1 0 0 0 0 0
//      0 1 1 1 1 1 1    prefix sum of b
// similarly we can do this for all characters
// thus we will have 26 arrays of n size

const int N = 1e5+10;   
int hsh[26][N];
int main(){
    int t;
    cin>>t;
    while(t--){
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < N; j++)
            {
                hsh[i][j] = 0;
            }
            
        }
        
        int n, q;
        cin >> n >> q;
        string s;
        cin>>s;
        for (int i = 0; i < n; i++)
        {
            hsh[ s[i] - 'a'][i + 1]++;
            // + 1 because we want to make it prefix sum array thus making it base 1
        }
        for (int i = 0; i < 26; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                hsh[i][j] += hsh[i][j-1];
            }
        }
        // now we have prefix sum array stored
        while(q--){
            int l, r;
            cin>>l>>r;
            int oddCt = 0;
            for (int i = 0; i < 26; i++)
            {
                int charCt = hsh[i][r] - hsh[i][l-1];
                if(charCt % 2 != 0) oddCt++;
            }
            if(oddCt > 1) cout<<"NO\n";
            else cout<<"YES\n";
        }
        // O(T*(26*N + N + N + 26 + Q*26))
        // O(T*(N + Q)) 
        // O(T * N) = 10 * 10^5
        
    }
}