#include <bits/stdc++.h>
using namespace std;

void printHello(){
    cout<<"Hello world";
}

int sum(int a, int b) {
    int result = a+b;
    return result;
}

int digit_sum(int n) {
    int digit_sum = 0;
    while(n){
        digit_sum += n%10;
        n = n / 10;
    }
    return digit_sum;
}


// void increment(int n){
//     n++;
// }
// this is pass by value 


void increment(int &n, int n1){
    n++;
    n1++;
}
// here n is pass by reference while n1 is pass by value



// void swap(int &a, int &b){
//     int temp = a;
//     a = b;
//     b = temp;
// }


void func(string &s){
    s = "new";
}

// we can declare parameter of 1d array without size but we need to give second size if more than 1d arrays 
void func2(int a[]){
    a[0] = 5;
}
void func3(int a[][4]){
    cout<<"ehllo";
}





const int N = 1e5+10;
const int N2 = 1e3+10;
int arr1[N];
int arr2[N2][N2];

void func4(){
    arr1[0] = 2;
    arr2[0][0] = 6;
}

int main() {

    // printHello();
    // cout<<sum(2,3);

    // int a,b;
    // cin>>a>>b;
    // cout<< digit_sum(a) + digit_sum(b);





    int a = 3;
    int b = 5;
    // cout<<a<<" "<<b<<endl;
    // increment(a,b);
    // cout<<a<<" "<<b<<endl;

    // cout<<a<<" "<<b<<endl;
    // swap(a,b);
    // cout<<a<<" "<<b<<endl;



    // There are some cool inbuild functions in c++
    swap(a,b);
    cout<<a<<" "<<b<<endl;
    cout<<max(a,b)<<endl;
    cout<<min(a,b)<<endl;

    string s = "abcd";
    func(s);
    cout<<s<<endl;


//  this case of pass by value and pass by reference goes on with all data structures except arrays
//  arrays are pssed by reference only
    int arr[10];
    arr[0] = 7;
    cout<<arr[0]<<endl;
    func2(arr);
    cout<<arr[0]<<endl;


// this passing of array in the function and then using it is so cumber some for competitive programmers instead in case of cp
// you can declare the array in global scope only so that you can pass the array in the function directly without passing it in argument



    return 0;
    // in today' compiler return 0 is now optional as a special case for main function
}