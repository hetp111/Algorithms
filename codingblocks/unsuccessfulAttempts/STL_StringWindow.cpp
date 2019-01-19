#include <bits/stdc++.h>
using namespace std;
//https://hack.codingblocks.com/contests/c/380/1665
bool cksubstr(string s, string s2){
    int k=0;
    if(s[0]!=s2[0] || s[s.size()-1]!=s2[s2.size()-1])return 0;
    for(int i=0;i<s.size();i++){
        if(s[i]==s2[k]){
            k++;
        }
    }
    if(k==s2.size())return 1;
    return 0;
}
int main(){//;)
    string s1,s2;set<pair<int,string>> anss;
    getline(cin,s1);int n1=s1.size();
    getline(cin,s2);int n2=s2.size();
    for(int i=0;i<=n1;i++){
        string s="";
        for(int j=i;j<n1;j++){
            s+=s1[j];
            if(cksubstr(s,s2)){
                pair<int,string> pp=make_pair(s.size(),s);
                anss.insert(pp);
            }
        }
    }
    if(!anss.empty())
    cout<<(anss.begin())->second;
    else
    cout<<"No string";
}
