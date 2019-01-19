#include <bits/stdc++.h>
using namespace std;
//https://hack.codingblocks.com/contests/c/471/1629
int main(){//;)
    long long q,k;cin>>q>>k;
    vector<long long> v;
    for(long long i=0;i<q;i++){
        long long kk,x,y;
        cin>>kk;
        if(kk==1){
            cin>>x>>y;
            v.push_back(x*x+y*y);
        }else{
            cout<<v[k-1]<<"\n";
        }
        sort(v.begin(),v.end());
        if(v.size()>k){
            v.erase(v.begin()+k,v.end());//reduces time
        }
    }
}
