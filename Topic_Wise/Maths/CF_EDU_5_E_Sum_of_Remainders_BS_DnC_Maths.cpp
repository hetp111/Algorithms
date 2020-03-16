#include <bits/stdc++.h>//Carefully Crafted by hetp111
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define MOD (1000000007)
//#define MOD (998244353)
#define PI acos(-1)
#define eps (1e-8)
#define INF (1e18)
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0)
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
//ifstream cinn("input.txt");ofstream coutt("output.txt");


//https://codeforces.com/blog/entry/68972#comment-533763
//https://discordapp.com/channels/326795829664808960/326795829664808960/689023813861507072


const int i2 = (MOD+1)/2;

int sum(int a,int b){
    a%=MOD;
    b%=MOD;
    return (((b*(b+1)%MOD)*i2)%MOD - ((a*(a+1)%MOD)*i2)%MOD + a + MOD)%MOD;
}

void solve(int l,int r,int n,int &ans){
    if(n/l==n/r){
        ans= (ans + ((n/l)%MOD*sum(l,r))%MOD)%MOD;
    }else{
        int mid=(l+r)/2;
        solve(l,mid,n,ans);
        solve(mid+1,r,n,ans);
    }
}

int f(int n,int m){// n/1*1 + n/2*2 ... n/m*n m<=n
    int ans=0;
    solve(1,m,n,ans);
    return ans;
}

signed main(){
    FASTER;
    int n,m;cin>>n>>m;
    cout<<(((n%MOD)*(m%MOD))%MOD-f(n,min(m,n))+MOD)%MOD;
}
