#include <bits/stdc++.h>
using namespace std;
// All Sieve Concepts in ONE Medium Hard Question
// https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/hacker-with-prime-bebe28ac/


/*
    2 22 7 10

    16 -> 2^4 -> 2 * 2 and we have to remove 2^2 and yes we can do this by dividing this number with 2 twice by taking it from the array => YES
    429 -> 3 * 11 * 13 here we need to remove any one prime but none of them is present in the array => NO
    42 -> 2 * 3 * 7 here we can remove any one of 2 or 7 by using the array => YES


    for a number which is approx 10^6 -> there can't be more than 10 distinct prime factors
    because 2, 3, 5, 7, 11, 13, 17, 19 there multiplication will itself exceed the value of 10^6


    now, I will only write distinct prime factors of the number
    429 -> 3, 11, 13
    now take any two by using for loop
        3 * 11 -> 429/3*11 -> this number itself or a number in array whose power is this number, if exist then YES
        11 * 13
        3 * 13
    this will take n^2 time


    Again understaning with another example
    2, 22, 7, 10

    60 -> 2, 2, 3, 5

    2 * 2   -> 60/(2*2) -> 15 we dont't have 15 in array nor 15 is power of some number => NO
    2 * 3   -> 60/(2*3) -> 10 we have 10 in array  => YES
    2 * 5   -> 60/(2*5) -> 6  => NO
    3 * 5   -> 60/(3*5) -> 4 => 4 is power of 2 => YES


*/


/*
input
4 3
2 22 7 10
16
429
42

output
YES
NO
YES
*/



// seive method is for iterating over multiples or powers

const int N = 2e6+10;
int hp[N];
int canRemove[N]; // canRemove[i] -> if i can be removed = 1 or else = 0
int hsh[N];

vector<int> distinctPF(int x){
    vector<int> ans;
    while (x>1)
    {
        int pf = hp[x];
        while (x%pf == 0) x/=pf;
        ans.push_back(pf);
    }
    return ans; 
}

int main() {

    for (int i = 2; i < N; i++)
    {
        if(hp[i]==0){
            for (int j = i; j < N; j+=i)
            {
                hp[j] = i;  
            }
        }
    }
    

    int n,q;
    cin>>n>>q; 
    for (int i = 0; i < n; i++)
    {   
        int x;
        cin>>x;
        hsh[x] = 1;
    }
    for (int i = 2; i < N; i++)
    {
        if(hsh[i]){
            for (long long j = i; j < N; j *= i)
            {
                canRemove[j] = 1;
            }
        }
    }
    
    while (q--)
    {
        int x;
        cin>>x;
        vector<int> pf = distinctPF(x);
        bool isPossible = false;
        for (int i = 0; i < pf.size(); i++)
        {
            for (int j = i; j < pf.size(); j++)
            {
                int product = pf[i] * pf[j];
                if(i==j && x%product != 0) continue;
                int toRemove = x / product;
                if(canRemove[toRemove] == 1 || toRemove == 1){
                    isPossible = true;
                    break;
                }
            }
            if(isPossible) break;
        }
        cout<<(isPossible?"YES\n":"NO\n");
        
    }
    
    

    

    return 0;
}