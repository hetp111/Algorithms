//https://www.spoj.com/problems/TOPOSORT/

#include <bits/stdc++.h>//Carefully Crafted by hetp111
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define MOD 1000000007
#define PI acos(-1)
#define eps (1e-8)
#define INF (1e18)
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0)
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
//ifstream cinn("input.txt");ofstream coutt("output.txt");

int n,m,err=0;

void dfs(int cur,const vi *adj,int *vis,vi &ans){
    vis[cur]=1;
    for(int child:adj[cur]){
        if(vis[child])continue;
        dfs(child,adj,vis,ans);
    }
    ans.push_back(cur+1);
}

bool cycle(int cur,const vi *adj,int *color){
    color[cur]=1;
    for(int u:adj[cur]) {
        if(color[u]==0 && cycle(u,adj,color))return true;
        if(color[u]==1)return true;
    }
    color[cur]=2;
    return false;
}

signed main(){
    FASTER;
    cin>>n>>m;
    vi adj[n];
    
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a-1].push_back(b-1);
    }
    
    for(int i=0;i<n;i++){
        sort(all(adj[i]));
        reverse(all(adj[i]));
    }
    
    int vis[n]={0};
    int color[n]={0};
    vi ans;
    
    for(int v=0;v<n;v++){
        if(color[v]==0&&cycle(v,adj,color))err=1;
    }
    
    for(int i=n-1;i>=0 && !err;i--){
        if(vis[i])continue;
        dfs(i,adj,vis,ans);
    }
    
    reverse(all(ans));
    
    if(!err)cout<<ans;
    else cout<<"Sandro fails.";
}
