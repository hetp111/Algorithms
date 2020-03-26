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

//O(n+m)

int n,m,s;
vi adj[5001],adji[5001];

vi order;
vi compressed[5001];
bool vis[5001];
int comp[5001];

void dfs1(int cur){
    vis[cur]=1;
    for(int ch:adj[cur]){
        if(vis[ch])continue;
        dfs1(ch);
    }
    order.push_back(cur);
}

void dfs2(int cur,const int &cmpNo){
    comp[cur]=cmpNo;
    for(int ch:adji[cur]){
        if(comp[ch])continue;
        dfs2(ch,cmpNo);
    }
}

void dfs3(int cur){
    vis[cur]=1;
    for(int ch:compressed[cur]){
        if(vis[ch])continue;
        dfs3(ch);
    }
}

signed main(){
    FASTER;
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adji[b].push_back(a);
    }
    
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        dfs1(i);
    }
    reverse(all(order));
    
    int cmpNo=1;
    for(int i:order){
        if(comp[i])continue;
        dfs2(i,cmpNo);
        cmpNo++;
    }
    
    int inDegree[cmpNo]={0};
    for(int i=1;i<=n;i++){
        for(int ch:adj[i]){
            if(comp[i]==comp[ch])continue;
            compressed[comp[i]].push_back(comp[ch]);
            inDegree[comp[ch]]++;
        }
    }
    
    memset(vis,0,sizeof vis);//for compressed graph
    dfs3(comp[s]);
    int ans=0;
    for(int i=1;i<cmpNo;i++){
        if(vis[i] || inDegree[i])continue;
        ans++;
    }
    cout<<ans;
}