#include <iostream>
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string,int> m;

    pair<string,int> p=make_pair("babbar", 3);
    m.insert(p);

    pair<string,int> p2("love",2);
    m.insert(p2);

    m["mera"]=1;

    m["mera"]=2;

    //search
    cout<< m["mera"] << endl; //if accessed in this way and such key doesnt exist it will create a new one
    cout<< m.at("babbar") << endl; //it will give an error if entry doesnt exist

    //to check if it exists
    cout<< m.count("bro") << endl;

    //erase
    m.erase("love");

    for(auto i:m){
        cout<< i.first << " " << i.second << endl;
    }
    
    //iterator
    unordered_map<string,int> :: iterator it =m.begin();

    while(it!=m.end()){
        cout<< it->first << " " << it->second << endl;
        it++;
    }
    //in normal map data is stored in the order of data given
}































