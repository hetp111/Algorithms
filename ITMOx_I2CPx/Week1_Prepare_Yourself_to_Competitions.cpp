//#include <bits/stdc++.h> het-
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ifstream inf("input.txt");
    ofstream ouf("output.txt");
    int n;vector<int> p;vector<int> t;int ans=0;
    inf>>n;
    int TT=0,PP=0;
    for(int i=0;i<n;i++){
        int tmp;inf>>tmp;
        p.push_back(tmp);
    }
    for(int i=0;i<n;i++){
        int tmp;inf>>tmp;
        t.push_back(tmp);
    }
    vector<int> difff;
    for(int i=0;i<n;i++){
        difff.push_back(p[i]-t[i]);
        if(p[i]>t[i]){
            ans+=p[i];
            PP++;
        }else{
            ans+=t[i];
            TT++;
        }
    }
    sort(difff.begin(),difff.end());
    if(PP==n){
        ans+=(-difff[0]);
    }else if(TT==n){
        ans+=(difff[difff.size()-1]);
    }
    ouf<<ans;
    return 0;
}
