#include <bits/stdc++.h>
using namespace std;
// Basics of Factors and Divisors related problems

int main() {

    // int n;
    // cin>>n;
    // int ct = 0;
    // int sum = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     if(n % i==0){
    //         cout<<i<<endl;
    //         ct++;
    //         sum+=i;
    //     }
    // }
    // cout<<ct<<" "<<sum<<endl;
    //TC:- O(n)
    // this is very brute force method we need to optimize it



    /*
        SQRT Method
        1 * 24
        2 * 12
        3 * 8
        4 * 6
        6 * 4
        8 * 3
        12 * 2
        24 * 1
        Thus we can convert the loop from O(n) to O(sqrt(n))
    */

    // int n;
    // cin>>n;
    // int ct = 0;
    // int sum = 0;
    // for (int i = 1; i * i <= n; i++)
    // {
    //     if(n % i == 0){
    //         cout<<i<<" ";
    //         ct += 1;
    //         sum += i;
    //         if(n/i != i){
    //             cout<<n/i<<endl;
    //             ct+=1;
    //             sum += n/i;
    //         }
    //     }
    // }
    // cout<<endl;
    // cout<<ct<<" "<<sum<<endl;
    // O(sqrt(n))


    /*
    
    ********We need more faster method



    **Derivation of sum and count formulae

    so, prime factorization of a number x
    x = p1^n1 * p2^n2 * p3^n3        36 = 2^2 * 3^2
                                        = 2 * 2 * 3 * 3
                                        thus divisors will be subset of these prime numbers
        
    Now, i can take 0 p1 or 1 p1 or 2 p2 or.......n1 p1
    thus there are (n1+1) choices for p1

    Similarly (n1+1)(n2+1)(n3+1) = no. of divisors

    x = p1^n1 * p2^n2 * p3^n3 * ....
    then count of divisors = (n1 + 1)(n2 + 1)(n3 + 1)..
    ex. for 36 = 2^2 * 3^2 -> count of divisors = (2 + 1)(2 + 1) = 9




    Now for sum
    x = p1^n1 * p2^n2 * p3^n3
    these are the no. of choices = (n1+1)(n2+1)(n3+1)

    so now actually writing the possible no. in these no. of choices to find the sum
    (1 + p1 + p1^2 + p1^3 + ..... + p1^n1) *
    (1 + p2 + p2^2 + p3^3 + ..... + p3^n2) *
    (1 + p3 + p3^2 + p3^3 + ..... + p3^n3) = sum of all possible divisors

    ex. of 36 = 2^2 * 3^2
    sum of all divisors = (1 + 2 + 2^2)(1 + 3 + 3^2) = (7) (13) = 91
    it is gp

          p1^(n1+1) - 1     p2^(n2+1) - 1   p3^(n3 + 1) - 1
    sum = --------------- * ------------- * ---------------- * ...........
           p1 - 1             p2 - 1            p3 - 1

    for 36 = 2^2 * 3^2
    
    sum = (2^3 - 1 / 2 - 1)  * (3^3 - 1 / 3 - 1)
    sum = 7 * 13 = 91

    
    */
   
    return 0;
}