#include <bits/stdc++.h>
using namespace std;

// int main() {

// // PAIR ***************
//     pair<int, string> p;

//     // p = make_pair(2, "abc");
//     // cin>>p.first>>p.second;
//     p = {2, "abc"};

//     pair<int, string> p1 = p; //pass by value
//     p1.first = 3;
//     pair<int, string> &p2 = p; //pass by reference
//     p2.second = "cba";
//     cout<<p.first<<" "<<p.second<<endl;

//     pair<int, int> p_array[3];
//     p_array[0] = {1, 2};
//     p_array[1] = {2, 3};
//     p_array[2] = {3, 4};
//     swap(p_array[0], p_array[2]); //thus using pair in arrays is that we can have the relation also moving in same way as if there were two arrays a and b 
//     // but now both are joined in pair
//     for (int i = 0; i < 3; i++)
//     {
//         cout<<p_array[i].first<<" "<<p_array[i].second<<"\n";
//     }
    


//     return 0;
// }





void printVec(vector<string> &v){
    cout<<"size: "<<v.size()<<endl;
    for (int i = 0; i < v.size(); i++)
    {
        // v.size() -> O(1) time complexity
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){


    // VECTORS*******************

    // vector<int> v;
    // int n;
    // cin>>n;
    // for (int i = 0; i < n; i++)
    // {
    //     int x;
    //     cin >> x;
    //     v.push_back(x);     // push_back puts element in last of vector and takes O(1)
    // }
    // printVec(v);
    

    // if vector is declared 
    // - locally = 10^5 is limit for vector
    // - globally = 10^7 is limit for vector
    // on online platforms
    // actually this limit is on continous memory allocation



    // vector<int> v(10);  //fill vector of size 10 with 0's
    // v.push_back(7);
    // printVec(v);

    // vector<int> v(10,3); //we can predefined vector with some value 
    // v.push_back(7);
    // printVec(v);

    // v.pop_back();  //it will remove last value 
    // // push_back and pop_back() are of time complexity O(1  )
    // printVec(v);

    // vector<int> v(10,3);
    // vector<int> v2 = v; // its time complexity is O(N), thus it is expensive operation
    // //v2 is complete separate vector from v but its copy
    // // it is not possible in array, array mein pointers copy hotein hain

    // // vector is automatic pass by value only like int and strings but array is always pass by reference
    // // thus when you are passing a vector in a function make sure to pass it through reference 
    // // otherwise the funciton will make new vector and will copy argument in it which will be O(N) time complexity
    // // thats why if array is a and vector is b, we get directly address using a but for vector we need to do b.begin()
    // v2.push_back(5);
    // printVec(v);
    // printVec(v2);






    vector<string> v;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        v.push_back(s);
    }
    printVec(v);
    


    return 0;
}