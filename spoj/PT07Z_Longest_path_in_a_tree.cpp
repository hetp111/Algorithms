
//https://cs.stackexchange.com/questions/11263/longest-path-in-an-undirected-tree-with-only-one-traversal

#include <bits/stdc++.h>//Carefully Crafted by hetp111
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define pii pair<int,int>
#define prec(n) fixed<<setprecision(n)
#define MOD 1000000007
#define eps 1e-8
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){
    return out<<"("<<a.first<<","<<a.second<<")";}
template<class A> ostream& operator<<(ostream& out, const vector<A> &a){
	out<<"";for(auto it=a.begin();it!=a.end();it++){if(it!=a.begin())out<<" ";out<<*it;}out<<"";
	return out;}
template<class A, class B> istream& operator>>(istream& in, pair<A,B> &a){in>>a.first>>a.second;return in;}
template<class A> istream& operator>>(istream& in, vector<A> &a){for(A &i:a)in>>i;return in;}
//ifstream cinn("input.txt");ofstream coutt("output.txt");

int disFromi[10000];
int vis[10000];
vi adj[10000];

void dfs(int src){
    vis[src]=1;
    for(int child:adj[src]){
        if(vis[child])continue;
        disFromi[child]=1+disFromi[src];
        dfs(child);
    }
}

signed main(){
    FASTER;
    int n;cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y;cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }

    dfs(0);
    int id=-1,mxDis=0;
    for(int i=0;i<n;i++){
        if(mxDis<disFromi[i]){
            id=i;
            mxDis=disFromi[i];
        }
    }

    memset(vis,0,sizeof(vis));
    memset(disFromi,0,sizeof(disFromi));

    dfs(id);

    cout<<*max_element(disFromi,disFromi+n);
}
