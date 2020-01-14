//https://codeforces.com/contest/1272/problem/E Multi source BFS

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

int n;
vi adj[200001];
int dis[200001];
int ans[200001];
vi even,odd;

signed main() {
    FASTER;
    cin>>n;
    for(int i=1;i<=n;i++){
        int in;cin>>in;
        if(in&1)odd.push_back(i);
        else even.push_back(i);
        if(i+in<=n)adj[i+in].push_back(i);
        if(i-in>=1)adj[i-in].push_back(i);
    }
    
    fill(ans,ans+200001,-1);
    queue<int> q;
    
    //
    
    fill(dis,dis+200001,INF);
    for(int ev:even){
        dis[ev]=0;
        q.push(ev);
    }
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int ch:adj[cur])if(dis[ch]==INF){
            dis[ch]=1+dis[cur];
            q.push(ch);
        }
    }
    for(int od:odd)if(dis[od]!=INF)ans[od]=dis[od];
    
    //
    
    fill(dis,dis+200001,INF);
    for(int od:odd){
        dis[od]=0;
        q.push(od);
    }
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int ch:adj[cur])if(dis[ch]==INF){
            dis[ch]=1+dis[cur];
            q.push(ch);
        }
    }
    for(int ev:even)if(dis[ev]!=INF)ans[ev]=dis[ev];
    
    //
    
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
}