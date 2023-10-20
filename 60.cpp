#include <bits/stdc++.h>
using namespace std;
// These Sieve Variations will help you Solve many Number Theory Questions

// const int N = 1e7 + 10;
// vector<bool> isPrime(N, 1);
// vector<int> lp(N,0), hp(N, 0);

const int N = 1e5 + 10;
vector<int> divisors[N];

int main() {

//     isPrime[0] = isPrime[1] = false;
//     for (int i = 2; i < N; i++)
//     {
//         if(isPrime[i] == true){
//             lp[i] = hp[i] = i;  // for a prime number higesht prime and lowest prime is itself the number
//             for (int j = 2*i; j < N; j += i)
//             {
//                 isPrime[j] = false;
//                 hp[j] = i;
//                 if(lp[j] == 0){
//                     lp[j] = i;
//                 }
//             }
            
//         }
//     }
//     // for (int i = 1; i < 100; i++)
//     // {
//     //     cout<<lp[i]<<" "<<hp[i]<<endl;
//     // }
    

// //Prime factorisation
//     /*
//     for finding prime factorisation we need to have a factor of the number which we have 
//     like lp and hp, anyone we can use
//     and then n/=prime_factor
//     then if further the number is not divisble then for that number we will gets it hp
//     and then again start dividing it till further it stops
//     */

//    int num;
//    cin>>num;
// //    vector<int> prime_factors;
//     map<int, int> prime_factors;

//    while (num > 1)
//    {
//     int prime_factor = hp[num];
//     while(num % prime_factor == 0){
//         num /= prime_factor;
//         // prime_factors.push_back(prime_factor);
//         prime_factors[prime_factor]++ ;
//     }
//    }
//    // TC approx is log(n)
//    // just we need to precompute here then if there large no. of queries given then it will be very helpful


// //    for (int &factor : prime_factors)
// //    {
// //     cout<<factor<<" ";
// //    }
//    for (auto &factor : prime_factors)
//    {
//     cout<<factor.first<<" "<<factor.second<<endl;
//    }
   
   




















// Storing all divisors
//for this case take N = 10^5 + 7

    int sum[N];      
    for (int i = 1; i < N; i++)
    {
        for (int j =i; j < N; j += i) //this loop is moving on all multiples of i
        {
           divisors[j].push_back(i);
           sum[j]+= i;
        }
    }
    // TC:- N(log(N))         //done in previous class

    for(int i = 1; i<10; i++){
        for(int &div: divisors[i]){
            cout<<div<<" ";
        }
        cout<<" sum "<<sum[i];
        cout<<endl;
    }

















    return 0;
}