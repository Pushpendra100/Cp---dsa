#include <bits/stdc++.h>
using namespace std;
// Large Exponentiation with ETF & Euler's Theorem


const int M = 1e9+7;








// if b <= 10^18
/*
    long long b = 10^18
    then log(10^18) bits ~ 18 * log(10) ~ 59
    and there are 64 bits in long long thus this code will work
*/
// int binExp(int a, long long b){
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

/*
we can't give value of b bigger than 10^18, we will indirectly give this

*consider, we need to calculate this and given M = 10^9+7
          32 
       64^
    50^ 

    here it is of form like a^(b^c)
    here b -> b^c


* a and b are coprime numbers if the common factor between them is only 1
    i.e. gcd(a, b) = 1

* ETF -> Euler Totient Function

    ETF value of N is count of k
        such that 1 <= k <= N and 
        k, N are coprime
    
    5 -> 1, 2, 3, 4 = 4   (5, 5 are not coprime because they have two common factors 1 and 5,   also gcd(5, 5)= 5)
    ETF is represented through phi
    Φ(5) = 4
    Φ(6) = 2  {1, 5}

                __
    Φ(n) = n * |  | (1 - (1/p))
        where p is all the distinct prime factors of n    ( 1 is neither prime nor composite)

    Φ(5) = 5 * (1 - 1/5) = 4
    Φ(6) = 6 * (1 - 1/2) * (1 - 1/3) = 2


* Euler Theorem

            b*modΦ(n)
    a^b ≅ a^          mod(n)                ≅ -> is called congruence

    a ≅ b mod(n) -> it means if we divide a with n then b will come as remainder

    that means                     b*modΦ(n)
    if we divide a^b with n then a^             will come as remainder

              (   b % Φ(n) )
    a^b % n = ( a^         ) % n


    Thus conclusion of Euler Theorem
               (   b % Φ(M) )
    a^b % M =  ( a^         ) % M                    where M is any number



    if n is prime   ( and in most cases M is prime)
    then
    Φ(n) = n(1 - (1/n))                         
        =  n - 1

    thus ETF value of prime no. is n-1

    Euler Theorem when M is prime
               (   b % (M - 1) )
    a^b % M =  ( a^            ) % M                where M is prime number

*/


int binExp(int a, long long b, int m){
    int ans = 1;
    while (b) 
    {
        if(b&1){ 
            ans = (ans * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b>>=1;
    }
    return ans;
}






int main() {

    // 50^64^32 % M
    // since M is prime 64^32 will have to do % with M-1
    // cout<<binExp(50, binExp(64, 32, M-1), M);
    // this is how we can handle very big values of b
    // all these above theory was to find out how we can integrate % M with the power so that we can make it small 
    // and with the help of euler's theorem we have find it out










    //Now let's do a question
    // https://leetcode.com/problems/super-pow/description/


    /*
    1337 is not a prime no.
    1337 = 7 * 191
    Φ(1337) = 1337*(1 - 1/7)*(1 - 1/191 ) = 6 * 190 = 1140


    b is given in form of an array

      b  
    a^     %  1337   

            b%1140  
    =   a^         %  1337


    now let's say b is [4, 3, 3, 8, 5, 2]
    then we can write complete no. as ( 4*10^5 + 3*10^4 + 3*10^3 + 8*10^2 + 5*10^1 + 2*10^0 ) % 1440
    and calculate modulo of each

    */

   /*
   Φ(1440) = 1440*(1 - 1/2)*(1 - 1/5)*(1 - 1/9) = 512
   */



    




    return 0;
}