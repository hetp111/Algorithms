//https://www.codechef.com/viewsolution/38190700  Modular GCD

#include <bits/stdc++.h>
using namespace std;
//#define int int64_t /////////////////////////////////
#define double long double
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
const long long MOD=1e9+7; ///////////////////////
const long long INF=1e12; //////////////////////
void io(string s="file"){freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}



__int128 gcd(__int128 a,__int128 b){
    if(a==0)return b;
    return gcd(b%a,a);
}

__int128 poww(__int128 a,__int128 b,__int128 m){
    if(b==0)return 1;
    __int128 ans=poww(a,b/2,m);
    ans=ans*ans%m;
    if(b&1)ans=ans*a%m;
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        long long a,b,n;cin>>a>>b>>n;
        if(a==b){
            cout<<(long long)((poww(a,n,MOD)+poww(b,n,MOD))%MOD)<<"\n";
            continue;
        }
        cout<<(long long)(gcd((poww(a,n,a-b)+poww(b,n,a-b))%(a-b),a-b)%MOD)<<"\n";
    }
    
    
}
