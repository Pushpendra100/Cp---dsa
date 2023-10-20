#include <bits/stdc++.h>
using namespace std;

void increment(int *x){
    (*x)++;
}

int main() {

    // int x = 4;
    // cout<<&x<<endl;

    // // pointer stores the address
    // int *p_x;

    // p_x = &x;
    // cout<<p_x<<endl;
    // cout<<*p_x<<endl; // read * as value at 


    // *p_x = 5;
    // cout<<p_x<<endl;
    // cout<<x<<endl;

    // p_x+=1; // when we add 1 to the pointer, it adds that many bytes jiska ki woh pointer
    // // here in this case int 4 byte ka hai toh ab address mein 4 byte add kar lega yeh
    // cout<<p_x<<endl;



    int x = 4;
    int *p_x = &x;
    cout<<"Addr x: "<<&x<<endl;
    cout<<"Val p_x: "<<p_x<<endl;
    cout<<"Val *p_x: "<<*p_x<<endl;
    *p_x = 5;
    cout<<"x: "<<x<<endl;
    cout<<"p_x + 1: "<<p_x + 1<<endl;
    
    // in double pointer we store address of pointer
    int **p_p_x = &p_x;
    cout<<"Addr p_x: "<<&p_x<<endl;
    cout<<"Addr p_p_x: "<<p_p_x<<endl;
    cout<<"Val *p_p_x: "<<*p_p_x<<endl;
    cout<<"Val **p_p_x: "<<**p_p_x<<endl;

    **p_p_x = 7;
    cout<<x<<endl;



    int a[10];
    // a is itself a pointer
    cout<<a<<endl;
    cout<<&a[0]<<endl;
    cout<<a+1<<endl;
    cout<<&a[1]<<endl;


    int b = 10;
    cout<<b<<endl;
    increment(&b);
    cout<<b<<endl;




    return 0;
}