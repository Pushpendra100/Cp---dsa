#include <bits/stdc++.h>
using namespace std;
// Sieve Algorithm: How to find Prime Numbers Optimally ?



/*
    1/      [2]    [3]    4/    [5]   6/    [7]    8/     9/    10/
    [11]    12/    [13]   14/   15/   16/   [17]   18/   [19]   20/
    21/     22/    [23]   24/   25/   26/   27/    28/   [29]   30/


    We have to find how many numbers are prime in this 

    So, sieve algorithm says, consider all these as prime numbers, in the starting only we will dismark 1 as we know it is not prime no.
    multiples of 2 will not be prime number
    as we move forward and the no. is not marked it means, no. before that does not divide this no. as in case of 3, thus this number is prime
    and now multiple of 3 will be cross out
    now we move to next number which is not crossed which is 5, thus 5 is prime
    and cross out all multiples of 5
    now we move to next number which is not crossed which is 7, thus 7 is prime
    and cross out all multiples of 7
    now we move to next number which is not crossed which is 11, thus 11 is prime
    and cross out all multiples of 11
    now we move to next number which is not crossed which is 13, thus 13 is prime
    and cross out all multiples of 13
    ...
    similarly go on
    and thus we will get all prime numbers upto 30

*/




const int N = 1e7+10;
// Q < 10^7  and N < 10^7
// in each query, a number N is given tell N is prime or not
// if we do this from previous classes TC: - 10^7 * (sqrt(10^7)) which is large time complexity and can't be done in 1s

vector<bool> isPrime(N,1);
// isPrime[i] - tells ith number is prime or not

    
int main() {

    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < N; i++)
    {
        if(isPrime[i] == true){
            for (int j = 2*i; j < N; j += i)
            {
                isPrime[j] = false;
            }
            
        }
    }
    // N * log(log(N))
    /*
     time complexity of this sieve loop
     for multiples of 2 = n/2
     for multiples of 3 = n/3
     for multiples of 4 = n/4
                            .
                            .
                            .
     = (n/2 + n/3 + n/4 + n/5 ...  + n/n)
     = n(1/2 + 1/3 + 1/4 ... + 1)
     = nlog(n)



     if I also consider the if condition of inside loop i.e. inside loop only runs for primes
     then = n/2 + n/3 + n/5 + n/7 + n/11 +.....
        ~ = n(log(log(n)))
    */



    // for (int i = 1; i < 100; i++)
    // {
    //     cout<<i<<" ";
    //     cout<<isPrime[i]<<endl;
    // }
    

    int q;
    cin>>q;
    /*
    5
    4
    17
    19
    21
    23
    */
    while (q--)
    {
        int num;
        cin>>num;
        if(isPrime[num]){
            cout<<"prime\n";
        }else{
            cout<<"not prime\n";
        }
    }
    // with sqrt method earlier its TC was :- Q * sqrt(n)
    //but now it is Q * O(1)
    
    

    return 0;
}