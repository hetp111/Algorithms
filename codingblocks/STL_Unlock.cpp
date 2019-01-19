#include <bits/stdc++.h>
using namespace std;
//https://hack.codingblocks.com/contests/c/511/1556
int main(){//;)
    int n,k;cin>>n>>k;
    vector<int> v(n);
    map<int,int> m;
    for(int i=0;i<n;i++){cin>>v[i];m[v[i]]=i;}
    int ii=0;
    for(int i=0;i<n && ii<k;i++){
        if(v[i]!=n-i){
            int a=v[i],b=v[m[n-i]];
            swap(v[i],v[m[n-i]]);ii++;
            m[a]=m[n-i];
            m[b]=i;
            //for(int ki:v)cout<<ki<<" ";cout<<"\n";
        }
    }
    for(int i:v)cout<<i<<" ";
}
