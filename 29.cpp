#include <bits/stdc++.h>
using namespace std;
// NESTING IN STL CONTAINERS

int main() {



    // // we can compare containers of stl:---



    // // compairing pairs
    // map<pair<int,int>,int> mp;

    // pair<int, int> p1, p2;
    // p1 = {1,2};
    // p2 = {2,3};
    // cout<<(p1<p2); //prints 1 //becuase 1 is less than 2
    // p1 = {2,2};
    // p2 = {2, 3};
    // cout<<(p1<p2); //prints 1 //becuase 2 is less than 3
    // cout<<endl;



    // // compairing sets
    // map<set<int>,int> ms;

    // set<int> s1 = {1, 2, 3};
    // set<int> s2 = {2, 3};
    // cout<<(s1<s2); //prints 1 //because first element is compared
    // s1 = {2, 4};
    // s2 = {2, 3};
    // cout<<(s1<s2); //prints 0 //because 4 is greater than 3
    // s1 = {2, 3};
    // s2 = {2, 3};
    // cout<<(s1==s2); //prints 1 //because both have same values
    // cout<<endl;


    // // compairing vectors
    // map<vector<int>,int> mv;

    // vector<int> v1 = {1, 2, 3};
    // vector<int> v2 = {2, 3};
    // cout<<(v1<v2); //prints 1 //because first element is compared
    // v1 = {2, 4};
    // v2 = {2, 3};
    // cout<<(v1<v2); //prints 0 //because 4 is greater than 3
    // v1 = {2, 3};
    // v2 = {2, 3};
    // cout<<(v1==v2); //prints 1 //because both have same values



    // Thus all those containers which can be compared can be put in the 
    // keys of map and anything can be put in the value







    // map<pair<string,string>, vector<int>> m;
    // // 3
    // // a b 4
    // // 1 2 3 4
    // // d f 3
    // // 2 3 4
    // // c d 2
    // // 1 2
    // int n;
    // cin>>n;
    // for (int i = 0; i < n; i++)
    // {
    //     string fn, ln;
    //     int ct;
    //     cin >> fn >> ln >> ct;
    //     for (int j = 0; j < ct; j++)
    //     {
    //         int x;
    //         cin>>x;
    //         m[{fn, ln}].push_back(x);
    //     }
    // }

    // for (auto &pr : m)
    // {
    //     auto &full_name = pr.first;
    //     auto &list = pr.second;

    //     cout<<full_name.first<<" "<<full_name.second<<" : ";
    //     cout<<" { ";
    //     for (auto &elem : list)
    //     {
    //         cout << elem<<" ";
    //     }
    //     cout<<"}";
    //     cout<<"\n";        
    // }
    
    

// similarly we can keep pair in sets also but not in unordered sets
    // set<pair<int,int>> st;








/*
    you have to print marks in decreasing order and then if the marks are same
    then name should be lexographical order

    constraints are
    1 <= N <= 10^5
    1 <= |Length of the name| <= 100
    1 <= Marks <= 100



    input-
    4
    Eva 78
    Bob 99
    Alice 78
    Alice 78

    output-
    Bob 99
    Alice 78
    Alice 78
    Eva 78
*/



    // map<int, multiset<string>> marks_map;
    // int n;
    // cin>>n;
    // for (int i = 0; i < n; i++)
    // {
    //     int x;
    //     string name;
    //     cin>>name>>x;

    //     marks_map[x].insert(name);
    // }

    // auto cur_it = --marks_map.end();
    // while(true){
    //     auto &students = (*cur_it).second;
    //     int marks = (*cur_it).first;
    //     for (auto &student : students)
    //     {
    //         cout<<student<<" "<<marks<<"\n";
    //     }
    //     if(cur_it == marks_map.begin()) break;
    //     cur_it--;
    // }




    // we can do this in another way  -- by taking negative keys to reverse the order



    map<int, multiset<string>> marks_map;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        string name;
        cin>>name>>x;

        marks_map[-1*x].insert(name);
    }

    for (auto &marks_students_pr : marks_map)
    {
        auto &students = marks_students_pr.second;
        int marks = marks_students_pr.first;
        for (auto &student : students)
        {
            cout<<student<<" "<<-1*marks<<endl;
        }
        
    }
    
 

    return 0;
}