#include <bits/stdc++.h>
using namespace std;
// Prime Check & Prime Factorisation


int main() {

/*
 n is a prime if its divisors are only 1 and n
 n --> 1, n
*/

    // bool is_prime = true;
    // int n;
    // cin>>n;
    // for (int i = 2; i < n; i++)
    // {
    //     if(n % i == 0){
    //         is_prime = false;
    //         break;
    //     }
    // }
    // // O(n)
    // cout<<is_prime<<endl;

    // this is brute force method









      /*
        SQRT Method
        1 * 24      1 * 36 
        2 * 12      2 * 18 
        3 * 8       3 * 12
        4 * 6       4 * 9
        6 * 4       6 * 6
        8 * 3       9 * 4
        12 * 2      12 * 3
        24 * 1      18 * 2
                    36 * 1

        Thus we can convert the loop from O(n) to O(sqrt(n))

        if a number is divided by 2 then it is fact then it is also divided by 18
        also if a number is not divided by 2 then it is also not divided by 18

        thus we can check upto sqrt(n)
    */


    // int n;
    // cin>>n;
    // if(n ==1){
    //     cout<<0<<endl;
    //     return 0;
    // }
    // bool is_prime = true;
    // for (int i = 2; i * i <= n; i++)
    // {
    //     if(n % i == 0){
    //         is_prime = false;
    //         break;
    //     }
    // }
    // // O(n)
    // cout<<is_prime<<endl;












    /*
    Finding Prime Factorisation

    ## in any number the smallest divisor other than 1 is a prime number
        ex. for 36 = 2 is prime
                25 = 5 is a prime
                91 = 7 is a prime

    ## 36 --2--> 18 --2--> 9 --3--> 3 --3--> 1
    */

//    int n;
//    cin>>n;
//    vector<int> prime_factors;
//    for (int i = 2; i <= n; i++)
//    {
//     while (n%i ==0)
//     {
//         prime_factors.push_back(i);
//         n /= i;
//     }
//    }
//    // O(n)
//    for (int &prime : prime_factors)
//    {
//     cout<<prime<<" ";
//    }
   

   /*
   for a composite number
   atleast one prime factor will lie from [2, sqrt(n)]
   */
   

    int n;
    cin>>n;
    vector<int> prime_factors;
    for (int i = 2; i*i <= n; i++)
    {
        while (n%i ==0)
        {
            prime_factors.push_back(i);
            n /= i;
        }
    }
    if(n > 1){
        prime_factors.push_back(n);
    }
    // TC:- O(sqrt(n))
    for (int &prime : prime_factors)
    {
        cout<<prime<<" ";
    }











    return 0;
}