#include <bits/stdc++.h>
using namespace std;
//https://hack.codingblocks.com/contests/c/101/103
//STRING SORT
int main() {//;)
    int n;
    vector<string> s;
    cin>>n;
    for(int i=0;i<n;i++){
        string ss;
        cin>>ss;
        s.push_back(ss);
    }
    sort(s.begin(),s.end());

    for(int i=0;i+1<n;i++){
        int flg=0;
        string a=s[i];
        string b=s[i+1];
        for(int j=0;j<min(a.size(),b.size());j++){
            if(a[j]!=b[j]){
                break;
            }
            flg=1;
        }
        if(flg){
            swap(s[i],s[i+1]);
        }
    }
    for(string sss:s){
        cout<<sss<<"\n";
    }
}
