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
#define eps 1e-8
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
//ifstream cinn("input.txt");ofstream coutt("output.txt");

int x[200001],n,ans;//x is count of children plus (parent=1);
bool vis[200001];
vii adj[200001];

int dfs(int par){
    vis[par]=1;
    x[par]=1;
    for(const pii &child:adj[par]){
        if(vis[child.first])continue;
        x[par]+=dfs(child.first);
        ans+=2*min(x[child.first],n-x[child.first])*child.second;
    }
    return x[par];
}

signed main(){
    FASTER;
    int T;cin>>T;
    for(int t=1;t<=T;t++){
        memset(x,0,sizeof x);
        memset(vis,0,sizeof vis);
        for(vii &i:adj)i.clear();
        ans=0;
        cin>>n;
        for(int i=0;i<n-1;i++){
            int a,b,c;cin>>a>>b>>c;
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        dfs(1);
        cout<<"Case #"<<t<<": "<<ans<<"\n";
    }
}
