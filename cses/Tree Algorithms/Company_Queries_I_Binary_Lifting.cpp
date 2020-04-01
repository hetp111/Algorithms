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
 
vi adj[200005];
int dp[200005][25];//i,j 2^j th parent of i
int n,q;
 
void dfs(int cur,int par){
    dp[cur][0]=par;
    for(int ch:adj[cur]){
        if(ch==par)continue;
        dfs(ch,cur);
    }
}
 
int ff(int k){
    int cnt=0;
    while(k)k/=2,cnt++;
    return cnt-1;
}
 
int f(int cur,int k){
    if(k==0 || cur==-1)return cur;
    return f(dp[cur][ff(k)],k-(1LL<<ff(k)));
}
 
signed main(){ 
    FASTER;
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        int a;cin>>a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    memset(dp,-1,sizeof dp);
    dfs(1,-1);
    
    for(int j=1;j<25;j++){
        for(int i=2;i<=n;i++){
            if(dp[i][j-1]!=-1)dp[i][j]=dp[dp[i][j-1]][j-1];
        }
    }
    
    while(q--){
        int x,k;cin>>x>>k;
        cout<<f(x,k)<<"\n";
    }
}