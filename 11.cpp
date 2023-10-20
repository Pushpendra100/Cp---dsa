#include <bits/stdc++.h>
using namespace std;

int main() {


    // some formulas 
    // 1. (a+b) % M = ((a % M) + (b % M)) % M
    // 2. (a*b) % M = ((a % M) * (b % M)) % M
    // 3. (a-b) % M = ((a % M) - (b % M) + M) % M
    // 4. (a/b) % M = ((a % M) * ((b^-1) % M)) % M
    // b^-1 is called multiplicative inverse








// Given a number N. Print its factorial.
// Constraints
// 1 <= N <= 100
//  print answer module M
//  where M = 47

// modulo is asked when we know we can calculate a large value but can't store it then question ask to return the modulo 
// this will return value less than 47

    // int n;
    // cin>>n;
    // long long fact = 1;
    // for (int i = 2; i <= n; i++)
    // {
    //     fact *= i;
    // }
    // cout<<fact<<endl;
    


// NOw here we will solve the problem
    int n;
    cin>>n;
    int M = 47;
    long long fact = 1;
    for (int i = 2; i <= n; i++)
    {
        fact = (fact * i) % M;
        // fact = (fact + i) % M;        // in case of addition we can do like this also
    }
    cout<<fact<<endl;
    
// let's say we need to calculate 5! = 1 * 2 * 3 * 4 * 5
// (1 * 2 * 3 * 4 * 5) % 47
// ((1 * 2 * 3 * 4) % 47 * (5 % 47)) % 47
// ((1 * 2 * 3 * 4) % 47 * 5 ) % 47
// ((((1 * 2 * 3) % 47 * (4 % 47))) % 47 * 5) % 47
// .
// .
// .
// ((1 % 47) * (2 % 47) * (3 % 47) * (4 % 47) * (5  % 47)) % 47

// similarly we can do this for addition
// ((1 % 47) + (2 % 47) + (3 % 47) + (4 % 47) + (5  % 47)) % 47



// Mostly M = 10^9 + 7
// there are two significance of this value of M
// 1. this is very close to integer maximum, thus we can store ans in int
// 2. Multiplicative inverse (MMI), 
//      10^9 + 7 is a prime number, and for M is prime, I can find mmi of every number from 1 to M
//      this can help us in finding MMI which will be used in (a/b)%M


    

    return 0;
}

