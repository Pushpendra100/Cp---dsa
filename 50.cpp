#include <bits/stdc++.h>
using namespace std;
// Power of XOR Operator 


// Swapping of two numbers using XOR
// int main() {

//     int a = 4, b = 6;

//     /*
//     1 0 --> 1
//     0 1 --> 1
//     0 0 --> 0
//     1 1 --> 0

//     --> XOR of two numbers is 0 ( x ^ x == 0 )
//             101
//             101 ^
//             ----
//             000
//     --> XOR of a number with 0 is the number itself ( x^0 == x)
//             101
//             000 ^
//             ------
//             101
//     --> XOR is associative thus order does not matter
//             x^y^z == y^z^x == z^y^x
//     */

//    a = a ^ b;
//    b = b ^ a;
//    a = a ^ b;

//    /*
//    b = b ^ ( a ^ b )
//    b = b ^ b ^ a
//    b = 0 ^ a
//    b = a

//    and 

//    a = a ^ b;
//    a = ( a ^ b) ^ a;  //b->a due to second step
//    a = a ^ a ^ b;
//    a = 0 ^ b;
//    a = b;

//    */

//   cout<<a<<" "<<b<<endl;

//     return 0;
// }





/*
Given array of n integers. All integers are present in event count except one.
Find that one integer which has odd count in O(N) time complexity and O(1) space;

N<10^5
a[i]<10^5


input
9
2 4 6 7 7 4 2 2 2

*/

int main(){

    /*
        c ^ a ^ b ^ c ^ b -->  c ^ a ^ c ^ b ^ b --> c ^ a ^ c ^ 0 --> a ^ c ^ c --> a
        thus no. which are present in even count, there xor would be cancelled
        in last only that element will be left which is present in odd count
    */

   int n;
   cin>>n;
   int x;
   int ans = 0; // xor of any number with 0 is that number itself
   for (int i = 0; i < n; i++)
   {
    cin>>x;
    ans ^= x;
   }
   cout<<ans<<endl;
   

}