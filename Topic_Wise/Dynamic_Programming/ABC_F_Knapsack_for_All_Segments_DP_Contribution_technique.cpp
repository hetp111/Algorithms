#include <bits/stdc++.h>//Carefully Crafted by hetp111
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
//#define MOD (1000000007)
#define MOD (998244353)
#define PI acos(-1)
#define eps (1e-8)
#define INF (1e18)
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0)
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
//ifstream cinn("input.txt");ofstream coutt("output.txt");

int n,s,dp[3000][3000];//yep 3k chalega
vi v;

int f(int i,int sum){
    if(sum==s)return n-i+1;
    if(sum>s || i==n)return 0;
    int &ans=dp[i][sum];
    if(ans!=-1)return ans;
    ans=f(i+1,sum);
    ans=(ans+f(i+1,sum+v[i]))%MOD;
    return ans;
}


signed main(){
    FASTER;
    cin>>n>>s;
    memset(dp,-1,sizeof dp);
    v=vi(n);cin>>v;
    
    int ans=0;
    for(int i=0;i<n;i++)ans=(ans+f(i,0))%MOD;
    
    cout<<ans;
}