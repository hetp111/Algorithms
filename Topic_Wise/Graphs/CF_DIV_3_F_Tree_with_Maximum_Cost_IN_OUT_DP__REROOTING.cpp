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

int n,a[200005];
vi adj[200005];

int dp[200005],sum[200005],SUM,ans;

void dfs(int cur,int par){
    dp[cur]=0;
    sum[cur]=a[cur];
    for(int ch:adj[cur]){
        if(ch==par)continue;
        dfs(ch,cur);
        sum[cur]+=sum[ch];
        dp[cur]+=dp[ch]+sum[ch];
    }
}

void dfs2(int cur,int par,int uper){
    ans=max(ans,dp[cur]+uper);
    for(int ch:adj[cur]){
        if(ch==par)continue;
        dfs2(ch,cur,(dp[cur]-dp[ch]+uper)+(SUM-sum[ch])-sum[ch]);
    }
}

signed main(){
    FASTER;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        SUM+=a[i];
    }
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1);
    dfs2(1,-1,0);
    cout<<ans;
}
