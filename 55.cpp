#include <bits/stdc++.h>
using namespace std;
// Large Exponentiation using Binary Multiplication



// Whats happens if value of
// a <= 10^18 or 2^1024
// M <= 10^18







// if a<=10^18 then 
// const int M = 1e9+7;
// int binExp(int a, int b){
//     a%=M;
//     int ans = 1;
//     while (b) 
//     {
//         if(b&1){ 
//             ans = (ans * 1LL * a) % M;
//         }
//         a = (a * 1LL * a) % M;
//         b>>=1;
//     }
//     return ans;
// }




// if a<= 2^1024
// const int M = 1e9+7;
// int binExp(int a, int b){
//     a = binExp(2, 1024);
//     int ans = 1;
//     while (b) 
//     {
//         if(b&1){ 
//             ans = (ans * 1LL * a) % M;
//         }
//         a = (a * 1LL * a) % M;
//         b>>=1;
//     }
//     return ans;
// }






// if M <= 10^18
const long long M = 1e18+7;
int binExp(int a, int b){
    int ans = 1;
    while (b) 
    {
        if(b&1){ 
            // ans = (ans * 1LL * a) % M;
            ans = binMultiply(ans, a);
        }
        // a = (a * 1LL * a) % M;  // we can't directly multiply as 10^18 * 10^18 will overflow
        // so we will indirectly multiply 
        a = binMultiply(a,a);
        b>>=1;
    }
    return ans;
}
// time complexity :- log^2(n)




/*
 a * a  = a + a + ....... + a, sum of a is to be done a times
 we can say a+a < 10^18
            then take % M < 10^18
            then + a < 10^18
            then again take % M < 10^18
            the + a < 10^18
            .
            .
            .
            upto a times
thus like this at every step of adding we are able to take modulo which keeps the overall value less than 10^18


Now, we can do this in O(n) time by using for loop
But, we can do a * a in log(a) time

3 * (13)  -> binary of 13 is 1101
3 * (8+4+0+1) = 2*(2*2*3*1) + 2*(2*3*1) + 0*2*(3*1) + 3*1
this is same as binary exponetiation iterative

*/

long long binMultiply(long long a, long long b){
    int ans = 0;
    while (b) 
    {
        if(b&1){ 
            ans = (ans + a) % M;
        }
        a = (a + a) % M;  
        b>>=1;
    }
    return ans;
}
// this bin multiply can be used to multiply two very large number i.e. 10^18 * 10^18



int main() {


    return 0;
}