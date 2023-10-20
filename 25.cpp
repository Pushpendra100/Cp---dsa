#include <bits/stdc++.h>
using namespace std;

void print(map<int,string> &m){
    cout<<m.size()<<endl;
    for (auto &pr : m)
    {   
    // accessing value of map is also O(logN) 
    // as we are accessing each value in map in one iteration of loop it is O(logN) and there are N iterations
        cout<<pr.first<<" "<<pr.second<<"\n";
    }
    // thus this loop is N(logN)
}

int main() {

        // MAP
        // map is not continous
        // thus we can't do it+1, but instead we can do it++ where it is iterator
        // map stores key in sorted fashion and only unique keys exists
        // map internally works using red black trees

        // map<int, string> m;
        // m[1] = "abc";   // this operation is O(logN) time where N is the current size of map
        // m[5] = "cdc";
        // m[3] = "acd";
        // m.insert({4, "afg"}); //map stores a pair
        // m.insert(make_pair(4, "afg"));

        // // map<int, string>::iterator it;
        // // for (it = m.begin(); it != m.end(); it++)
        // // {
        // //     cout<<(*it).first<<" "<<(*it).second<<"\n";
        // // }

        // print(m);




        // map<int, int> m;
        // m[1] = 2; //this operation is O(logN)
        // m[6]; // this is same as above and its also O(logN)
        // // writing this above line only will insert value 0 or empty string
        // // accessing each value of map is also logN
        // print(m);
        // // 2
        // // 1 2
        // // 6 0
        // m[1] = 4;   
        // print(m);


        map<int, string> m;
        m[1] = "abc";  
        m[5] = "cdc";
        m[3] = "acd";

        // auto it = m.find(3); //its time complexity is also O(logN)
        // //it returns the address 
        // // or if the key does not exist in the map it will return m.end()
        // if(it == m.end()){
        //     cout<<"NO value";
        // }else{
        //     cout<<(*it).first<<" "<<(*it).second;
        // }


        // m.erase(3); // O(logN)
        // // it takes either value or the address as input
        // print(m);


        // // auto it = m.find(3);
        // auto it = m.find(7);
        // // m.erase(it);
        // // if you give some value in erase which does not exist or address is out of map
        // // then it will give segmentation fault
        // // thus we will use it with a check
        // if(it != m.end()){
        //     m.erase(it);
        // }
        // print(m);



        // m.clear(); // it completely clears the map
        // print(m);



        // more in insertion
        // time of insertion also depends on the key
        // map<string, string> mpp;

        // mpp["abcd"] = "abb";
        // // because keys are stored in sorted fashion, it means key comparision also takes place
        // // thus that time will also be accountable
        // // s.size() * logN    where s is the key






        /*
            Given N strings, print unique strings in lexographical order with their frequency
            N <= 10^5
            |S| <= 100

            8
            asj
            gfi
            abc 
            qef
            abc
            jkl
            asj
            abc
        */

        map<string, int> mpp;
        //hame string unique rakhni hai isliy inhe keys liya hai
        int n;
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin>>s;
            // mpp[s] = mpp[s] + 1;
        //  | here mpp[s] is initialise to zero
        //            | so here 0 comes initially
        //  then 1 is added
            mpp[s]++;
        }
        for(auto &pr:mpp){
            cout<<pr.first<<" "<<pr.second<<"\n";
        }
        





    return 0;
}