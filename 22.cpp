#include <bits/stdc++.h>
using namespace std;

// void printVec(vector<pair<int, int> &v){
void printVec(vector<int> &v){
    cout<<"size: "<<v.size()<<endl;
    for (int i = 0; i < v.size(); i++)
    {
        // cout<<v[i].first<<" "<<v[i].second<<"\n";
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main() {

    // // vector<pair<int, int>> v = {{1, 2}, {2, 3}, {4, 5}};
    // vector<pair<int, int>> v;
    // printVec(v);
    // int n;
    // cin>>n;
    // for (int i = 0; i < n; i++)
    // {
    //     int x, y;
    //     cin>>x>>y;
    //     v.push_back({x,y});
    //     // v.push_back(make_pair(x,y))
    // }
    // printVec(v);




    // array of vectors
    // int N;
    // cin>>N;
    // vector<int> v[N];
    // for (int i = 0; i < N; i++)
    // {
    //     int n;
    //     cin>>n;
    //     for (int j = 0; j < n; j++)
    //     {
    //         int x;
    //         cin>>x;
    //         v[i].push_back(x);
    //     }
    // }
    // for (int i = 0; i < N; i++)
    // {
    //     printVec(v[i]);
    // }




    int N;
    cin>>N;
    vector<vector<int>> v;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin>>n;
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
    for (int i = 0; i < N; i++)
    {
        printVec(v[i]);
    }
    
    
    

    return 0;
}