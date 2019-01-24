#include <bits/stdc++.h>
using namespace std;
//https://hack.codingblocks.com/contests/c/473/66
//;)
main(){
    int t;cin>>t;
    vector<string> ans;
    while(t--){
        string s1,s2,s="";
        cin>>s1>>s2;
        for(int i=0;i<s1.size();i++){
            if(s1[i]==s2[i]){
                s+="0";
            }else{
                s+="1";
            }
        }
        ans.push_back(s);
    }
    for(string a:ans){
        cout<<a<<"\n";
    }
}
