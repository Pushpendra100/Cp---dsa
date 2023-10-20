#include <bits/stdc++.h>
using namespace std;
// Nth Root of a Number using Binary Search

double eps = 1e-6; // this is how much we need accuracy

int main() {

    double x;
    int n;  // nth root
    cin>>x>>n;
    /*
    input
    2 2
    */
    double lo = 1, hi = x, mid;
    while (hi - lo > eps) // this will give accuracy of 5 digits after decimal as epsilon is 10^-6
    {
        mid=(hi+lo)/2;
        if(pow(mid, n) < x){
            lo = mid;
        }else{
            hi = mid;
        }
    }
    // TC: p*log(N*(10^d))
    // for pth root of number N
    // with d decimal accuracy
    cout<<setprecision(10)<<lo<<"\n"<<hi<<"\n";
    cout<<pow(x, 1.0/n)<<endl;

    return 0;
}