#include <bits/stdc++.h>//Carefully Crafted by hetp111
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define MOD 98765431
#define PI acos(-1)
#define eps (1e-8)
#define INF (1e18)
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0)
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
//ifstream cinn("input.txt");ofstream coutt("output.txt");

int n,m;
vi adj[100001];
int vis[100001];
vi ans;

bool dfs(int cur,int par){
    vis[cur]=1;
    ans.push_back(cur);
    for(int child:adj[cur]){
        if(child==par)continue;
        if(vis[child]){
            ans.push_back(child);
            return 1;
        }
        if(!vis[child] && dfs(child,cur))return 1;
    }
    ans.pop_back();
    return 0;
}

signed main(){
    FASTER;
    cin>>n>>m;
    while(m--){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        
        ans=vi();
        if(dfs(i,-1)){
            int asd=0;
            while(ans[asd]!=ans.back())asd++;
            cout<<ans.size()-asd<<"\n";
            for(;asd<ans.size();asd++){
                cout<<ans[asd]<<" ";
            }
            return 0;
        }
    }
    
    cout<<"IMPOSSIBLE";
    
}
