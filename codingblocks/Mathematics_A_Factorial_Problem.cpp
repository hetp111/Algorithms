#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//https://hack.codingblocks.com/contests/c/204/897
//;)
vector<pair<ll,ll> > pfk(ll k){
    vector<pair<ll,ll> > v;ll kk=k;
    for(ll i=2;i*i<=kk;i++){
        ll numoftimesi=0;
        while(k%i==0){
            numoftimesi++;
            k=k/i;
        }
        if(numoftimesi>0)
        v.push_back({i,numoftimesi});
    }
    if(k!=1)v.push_back({k,1});
    //for(asdf:v)cout<<asdf.first<<"-"<<asdf.second<<" ";
    return v;
}

ll findMinPowerOfK(vector<pair<ll,ll> > v,ll n){
    ll minn=100000000000;
    for(ll i=0;i<v.size();i++){
        ll num=v[i].first;
        ll nn=n;
        ll cnt=0;
        while(nn){
            nn=nn/num;
            cnt+=nn;
        }
        minn=min(cnt/v[i].second,minn);
    }
    return minn;
}

int main(){
    ll t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<pair<ll,ll> > primefactorOfK = pfk(k);
        ll ans=findMinPowerOfK(primefactorOfK,n);
        cout<<ans<<"\n";
    }
}
