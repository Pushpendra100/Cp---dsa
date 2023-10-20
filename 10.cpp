#include <bits/stdc++.h>
using namespace std;



// int main() {

//     int x;
//     int sum = 0;
//     sum = x+x;
//     // all of these are constant time operations

//     return 0;
// }
// number of iterations in code = 3
// time complexity is O(3)





// int main(){
//     int x;
//     int sum = 0;
//     sum = x+x;
//     int n;
//     cin>>n;
//     for (int i = 0; i < n; i++)
//     {
//         int y;
//         y = 5;
//         y++;
//     }
//     return 0;
// }
// O(5) + O(3*n), since value of n is very big, overall complexity -> O(n)

// O(n) + O(n) = O(n)
// O(k*n) where k<<n, = O(n)
// O(3), O(4), O(5) -> O(1) 


// no. of iterations run in online platforms is around 10^7 in 1sec




// N < 100000
// a[i] < 100000

// int main() {

//     int n;
//     cin>>n;
//     int a[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin>>a[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cin>>a[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             /* code */
//         }
        
//     }
    

// }
// O(1) + O(1) + O(1) + O(n) + O(n) = O(n)






// int main() {

//     int n;
//     cin>>n;
//     int a[n];

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             /* code */
//         }
        
//     }
    

// }
// O(1) + O(1) + O(1) + O(n^2) = O(n^2)
// and we have n < 10^5 and this is n^2 which will be 10^10 iterations and we know there are 10^7 iterations in 1sec
// thus it will exceed time limit



// int main() {
//     int n;
//     cin>>n;
//     int ct = 0;
//     while(n>0){
//         n = n/2;
//         ct++;
//     }
// }
// O(1) + O(1) + O(ct) = 

// we calculate time complexity by considering the worst case
// N<10^5
// 10 - 5 - 2 - 1 - 0 ---> these are three steps (last step is not counted)
// it means if i divide N with 2 a times then i will get 1, i.e. 1 = N/2^a
// 2^a = N now applying log
// log2(2^a) = log2(N)
// a = log2(N)
// O(1) + O(1) + O(log(n)) = O(log(n))  
// this is very favourable time complexity









// int main(){
//     int n;
//     cin>>n;
//     int ct = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < i; j++)
//         {
//             ct++;
//         }
        
//     }
    
// }
// inner loop
// when i = 0 then j = 0
// when i = 1 then j = 1
// when i = 2 then j = 2
// .
// .
// .
// when i = n - 1 then j = n-1
// now total iterations is n-1 times, conisder to be n
//  then sum of n numbers is
// n(n+1)/2
// O(n^2/2 + n/2)
// O(n^2/2) + O(n/2)
// this O(n) can be ignored infront of n^2
// O(n^2) - this is the complexity

















/*
given t test cases and an array of size N. Print sum of array in each test case.
constraints:
1 <= T <= 1000
1 <= N <= 1000
1 <= a[i] <= 1000
*/

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin>>x;
            sum+=x;
        }
        cout<<sum<<endl;
        
    }
}
// O(T*N), since T and N are same 10^3
// O(N^2) - 10^6 this will pass online coding platforms










/*
given t test cases and an array of size N. Print sum of array in each test case.
constraints:
1 <= T <= 100000
1 <= N <= 100000
1 <= a[i] <= 1000
Sum of N over all test cases is < 10^7
*/

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin>>x;
            sum+=x;
        }
        cout<<sum<<endl;
        
    }
}
// since it is given that sum of N over all test cases is 10^7 this means
// O(10^7) --> this will pass the online platforms
