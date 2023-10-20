#include <bits/stdc++.h>
using namespace std;
// Must Do Sieve Questions
// https://www.hackerearth.com/problem/algorithm/monk-and-divisor-conundrum-56e0eb99/


/*
    2 3 5 7 4 9 20

    let no. divisible by 4 = x
    let no. divisible by 5 = y
    and no. divisible by both 4 and 5 = z    
    then ans = x + y - z;



    2 3 5 7 4 9 20 4    
    we will use seive loop to store the count of multiples of the number in this loop
    and we are going to precompute this


    vector<int> given =   2 3 4 5 6 7 8 9 10 11 
    vector<int> count =   this vector will contain the count of multiples of a number in the array

    first loop will go from 2 to N
        set count = 0;
        then second loop will go for its multiples and increase the count of it
            if j in  given == 0
                then count[i]++;
        

    ex.  i = 2
            then j = 2
            then j = 4
            then j = 6
            ....
            .
            then j < N
        i = 3
            then j = 3
            then j = 6
            then j = 9
            .
            .
            then j < N
        i = 4
        .
        .
        .
        i < N

        this time complexity:- n/2 + n/3 + n/4 + n/5 + ..... 1
        = nlog(n)
        
        ans = ct[p] + ct[q] - ct[lcm(p, q)]

        a number divisible by both are one which are multiple of lcm(p, q)
*/







/*
input
6
2 3 5 7 4 9
2
4 5
3 7

output
2
3

*/





const int N = 2e5+10;

int multiples_ct[N];
int hsh[N];

int main() {

    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        hsh[x]++;
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j+=i )
        {
            multiples_ct[i] += hsh[j];
        }
        
    }
    
    
    int q;
    cin>>q;
    while (q--)
    {
        int p, q;
        cin>>p>>q;
        long long lcm = p*1LL*q / __gcd(p,q);
        long ans = multiples_ct[p] + multiples_ct[q];
        if(lcm<N) ans -= multiples_ct[lcm];
        cout<<ans<<"\n";
    }
    
    

    return 0;
}