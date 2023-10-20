#include <bits/stdc++.h>
using namespace std;
// LAMBDA FUNCTION, ALL_OF, ANY_OF AND NONE_OF FUNCTIONS

bool is_positive(int x){
    return x>0;
}

int main() {


    // lambda function
    // cout<<[](int x, int y){return x+y;}(3, 4)<<endl;
    // auto sum = [](int x, int y){return x+y;};
    // cout<<sum(2,3)<<endl;



    // all_of function returns true only if all of the elements return true otherwise false
    // // vector<int> v = {2, 3, 4};
    // vector<int> v = {2, -1, 4};
    // // cout<<all_of(v.begin(),v.end(), is_positive);
    // cout<<all_of(v.begin(),v.end(), [](int x){ return x > 0;}); // all elements positive


    // any_of function returns true if any one element returns true, if all elements return false then only it will return false
    // // vector<int> v = {-2, -3, 4};
    // vector<int> v = {-2, -3, -4};
    // cout<<any_of(v.begin(),v.end(), [](int x){ return x > 0;});  // any one positive


    // none_of function returns true only when all elements return false
    // // vector<int> v = {2 ,3 , 4}; //0
    // vector<int> v = {-2 ,-3 , -4}; //1
    // cout<<none_of(v.begin(), v.end(), [](int x){return x>0;});  // none of positive



//  similarly we can do this for arrays as well




    // // vector<int> v = {2, 3, 4}; //0
    // vector<int> v = {2, 4};  //1
    // cout<<all_of(v.begin(),v.end(), [](int x){ return x % 2 == 0;}); // all elements even


    // // vector<int> v = {2, 3, 4}; //1
    // vector<int> v = {3, 5};  //0
    // cout<<any_of(v.begin(),v.end(), [](int x){ return x % 2 == 0;});  // any one element even

    // vector<int> v = {2, 3, 4}; //0
    // vector<int> v = {3, 5};  //1
    // cout<<none_of(v.begin(),v.end(), [](int x){ return x % 2 == 0;});  // none of element even


 


    return 0;
}