//https://codeforces.com/contest/1176/problem/E

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
 
int n,m;
 
void solve(){
    cin>>n>>m;
    vi adj[n];
    int dis[n];fill(dis,dis+n,INF);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    
    queue<int> q;
    q.push(0);
    dis[0]=0;
    
    while(!q.empty()){
        int cur=q.front();q.pop();
        for(const int &ch:adj[cur])if(dis[ch]==INF){
            dis[ch]=(1+dis[cur])%2;
            q.push(ch);
        }
    }
    
    int b=0,w=0;
    for(int i=0;i<n;i++){
        b+=(dis[i]);
        w+=(1-dis[i]);
    }
    
    if(w<b){
        cout<<w<<"\n";
        for(int i=0;i<n;i++){
            if(!dis[i])cout<<i+1<<" ";
        }
    }else{
        cout<<b<<"\n";
        for(int i=0;i<n;i++){
            if(dis[i])cout<<i+1<<" ";
        }
    }
    
    
}
 
signed main(){
    FASTER;
    int t;cin>>t;
    while(t--)solve();
}