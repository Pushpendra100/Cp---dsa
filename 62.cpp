#include <bits/stdc++.h>
using namespace std;
// https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/name-count/

const int M = 1e9+7;
const int N = 1e5+10;
int fact[N];

int binExp(int a, int b, int m){
    int result = 1;
    while(b>0){
        if(b&1){
            result = (result* 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b>>=1;
    }
    return result;
}

// K symbols, and make N size password, K > N
// the no. of ways to choose n symbols from k and then to arrange then, we can arrange them in n!
// kCn * n! is the ans



int main() {

    int t;
    cin>>t;
    fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = (fact[i-1] * 1LL * i) % M;
    }
    
    while (t--)
    {
     int n, k;
     cin>>n>>k;
     int ans = fact[n];
     ans = (ans * 1LL * fact[k]) % M;
     int den = (fact[k-n] * 1LL * fact[n]) % M;
     ans  = (ans * 1LL * binExp(den, M-2, M)) % M;
     cout<<ans<<endl;
    }
    // O(N + (T * log(M)))   this log(M) is given by binExp function


    //Final Conclusion of whole Modulo thing

    /*
     (a * b )
     (------) % M 
     (c * d )

     then to calculate this
     first do num part
        num = ( (a %M) * 1LL* (b % M) ) % M
        denom = ( (c %M) * 1LL * (d % M) ) % M

        now to bring final ans we need to inverse the denom

        final_ans = ( num * 1LL * binExp(denom, M-2, M) ) % M;

        also, keep in mind, to get inverse u can use binExp only when M is a prime no.
    
    */



    return 0;
}