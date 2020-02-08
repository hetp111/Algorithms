//https://codeforces.com/contest/1296/problem/F
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

vi adj[5001];
int u[5001],v[5001];
int ew[5001];
int a[5001],b[5001],c[5001];
int n;

bool dfs(int s,int e,int par,int val){
    if(s==e)return 1;
    for(int edg:adj[s]){
        int ch=u[edg]^v[edg]^s;
        if(ch==par)continue;
        if(dfs(ch,e,s,val)){
            ew[edg]=max(ew[edg],val);
            return 1;
        }
    }
    return 0;
}

int dfs2(int s,int e,int par){
    if(s==e)return 1e18;
    for(int edg:adj[s]){
        int ch=v[edg]^u[edg]^s;
        if(ch==par)continue;
        int poss=dfs2(ch,e,s);
        if(poss)return min(poss,ew[edg]);
    }
    return 0;
}

signed main(){
    FASTER;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>u[i]>>v[i];
        adj[u[i]].push_back(i);
        adj[v[i]].push_back(i);
    }
    fill(ew+1,ew+n,1);
    
    int q;cin>>q;
    for(int i=1;i<=q;i++){
        cin>>a[i]>>b[i]>>c[i];
        dfs(a[i],b[i],-1,c[i]);
    }
    
    for(int i=1;i<=q;i++){
        if(dfs2(a[i],b[i],-1)!=c[i]){
            cout<<-1<<" ";
            return 0;
        }
    }
    
    for(int i=1;i<n;i++)cout<<ew[i]<<" ";
}