#include <bits/stdc++.h>
using namespace std;
// Modular Multiplicative Inverse : Modular Arithmetic for Division

/*
Modular Multiplicative Inverse

(a/b) % M = (a * b^-1) % M
          = ((a % M) * (b^-1 % M)) % M

    and (b^-1 % M) is called MMI of b


a * b = 1 then b is called MI (multiplicative inverse) of a

(a * b) % M = 1  then b is called MMI (Modular Multiplicative Inverse) of a
    and range of b is 1 <= b <= M-1

thus to find b 
    we will loop from 1 to M-1
    and check (a * b) % M = 1
    this will take time O(M)
thus we can find MMI of a with M in O(M) time

MMI is not defined for every a and M pair
MMI is defined only when a and M are coprime i.e. GCD(a, M) = 1


To find MMI in optimised time we will use Fermat's theorem

    a^(M-1) ≡ 1 mod(M)  
        where M is prime
        and a is not multiple of M

    i.e. if I divide a^(M-1) with M, we will get 1 as remainder

    ex. a = 2 and M = 3
        then a^2 = 4
        and 4%3 = 1

    
    Now multiplying both sides with a^-1
    a^(M-2) ≡ (a^-1) mod(M)
    which means  (a^(M-2) % M) = a^-1

    now we get a^-1 = (a^(M-2) % M)
    and we can calculate this using binExponentiation i.e. binExp(a, M-2)

    thus using binExp we can find a^-1 in log(N)

    So, final conclusion
    MMI of a = binExp(a, M-2, M);


    What if M is non prime
    then we can find MMI using extended Euclid's theorem 
    and this case is not that important for contest and interviews
*/

const int M = 1e9+7;

int binExp(int a, int b, int m){
    int result = 1;
    while (b>0)
    {
        if(b&1){
            result = (result * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b>>=1;
    }
    return result;
}


const int N = 1e6+10;
int fact[N];
int main() {

    // cout<<"MMI of 2 for M = 1e9+7 "<<binExp(2, M-2, M);



    /*
    Question
    There are N children and K toffees. K<N
    Count the number of ways to distribute toffee among N students such that each student gets one toffee
    N < 10^6, K < N < 10^6
    Q < 10^5

    We know its solution is NCK  % M where M is 10^9+7

    formula of nCr = n! / ((n-r)! * r!)
    */

   fact[0] = 1;
   for (int i = 1; i < N; i++)
   {
    fact[i] = ( fact[i-1] * 1LL *  i ) % M; 
   }
   // we are doing precomputation because if asked in question to do this for q queries
   int q;
   cin>>q;
   while (q--)
   {
    int n, k;
    cin>>n>>k;
    int ans = fact[n];
    int den = (fact[n-k] * 1LL * fact[k]) % M;
    ans = (ans * 1LL*  binExp(den, M-2, M))%M;
    cout<<ans<<endl;
   }
   

    return 0;
}