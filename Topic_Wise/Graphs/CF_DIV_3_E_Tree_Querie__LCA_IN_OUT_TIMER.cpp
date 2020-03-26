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


//LCA kind of, nice one.

int n,m;
vi adj[200005];
int depth[200005],par[200005];

int v[200005],tin[200005],tout[200005],cnt;

void dfsFindD(int cur,int ppar){
    depth[cur]=1+depth[ppar];
    tin[cur]=++cnt;
    for(int ch:adj[cur]){
        if(ch==ppar)continue;
        dfsFindD(ch,cur);
        par[ch]=cur;
    }
    tout[cur]=cnt;
}

signed main(){
    FASTER;
    cin>>n>>m;
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfsFindD(1,0);
    par[1]=1;
    while(m--){
        int k;cin>>k;
        int id,mx=-1;
        for(int i=1;i<=k;i++){
            cin>>v[i];
            v[i]=par[v[i]];
            if(mx<depth[v[i]]){
                mx=depth[v[i]];
                id=v[i];
            }
        }
        bool yes=1;
        for(int i=1;i<=k&&yes;i++){
            yes&=(tin[v[i]]<=tin[id] && tout[v[i]]>=tout[id]);
        }
        cout<<(yes?"YES":"NO")<<"\n";
    }
    
}