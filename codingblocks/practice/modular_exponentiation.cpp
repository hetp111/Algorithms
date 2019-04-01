#include <bits/stdc++.h>
using namespace std;
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
//https://hack.codingblocks.com/practice/p/387/743
ll f(ll a, ll b, ll c){
    ll rel=1;
    while(b){
        if(b&1)rel=(rel*a)%c;
        a=(a*a)%c;
        b=b>>1;
    }
    return rel%c;
}

int main(){
    FASTER;
    ll a,b,c;cin>>a>>b>>c;
    cout<<f(a,b,c);//(a^b)%c
}
