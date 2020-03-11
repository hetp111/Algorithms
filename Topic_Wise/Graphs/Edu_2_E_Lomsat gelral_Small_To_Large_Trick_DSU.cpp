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

//https://codeforces.com/blog/entry/67696

int n;
vi adj[100001];
int color[100001];
int res[100001];
int sz[100001];

int cnt[100001];
int ans[100001];
vi vec[100001];

int dfs(int cur,int par,int keep){
    int Max = -1, bigchild = -1;
	for(int ch:adj[cur])if(ch!=par){
        if(sz[ch]>Max){
            Max=sz[ch];
            bigchild=ch;
        }
	}
	
	for(int ch:adj[cur])if(ch!=par && ch!=bigchild){
        dfs(ch,cur,0);
	}
	
	int mx=0;
	if(bigchild!=-1){
        mx=dfs(bigchild,cur,1);
        swap(vec[cur],vec[bigchild]);
	}
	
	vec[cur].push_back(cur);
	ans[cnt[color[cur]]] -= color[cur];
	cnt[color[cur]]++;
	ans[cnt[color[cur]]] += color[cur];
	mx=max(mx,cnt[color[cur]]);
	for(auto u : adj[cur]) {
		if(u != par && u != bigchild) {
			for(auto x : vec[u]) {
				ans[cnt[color[x]]] -= color[x];
				cnt[color[x]]++;
				ans[cnt[color[x]]] += color[x];
				mx=max(mx,cnt[color[x]]);
				vec[cur].push_back(x);
			}
		}
	}
	
	res[cur] = ans[mx];
	if(keep == 0) {
		for(auto u : vec[cur]) {
			ans[cnt[color[u]]] -= color[u];
			cnt[color[u]]--;
			ans[cnt[color[u]]] += color[u];
		}
	}
	return mx;
}

void dfsSz(int cur,int par){
    sz[cur]=1;
    for(int ch:adj[cur])if(ch!=par){
        dfsSz(ch,cur);
        sz[cur]+=sz[ch];
    }
}

signed main(){
    FASTER;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>color[i];
    for(int i=1;i<=n-1;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfsSz(1,-1);
    dfs(1,-1,1);
    for(int i=1;i<=n;i++)cout<<res[i]<<" ";
}