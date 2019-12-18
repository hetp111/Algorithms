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

//https://www.hackerrank.com/challenges/the-quickest-way-up/problem

void solve(){
    vi adj[101];
    int board[101]={0};
    for(int i=1;i<=100;i++)board[i]=i;
    
    int n;cin>>n;
    while(n--){
        int a,b;cin>>a>>b;
        board[a]=b;
    }
    int m;cin>>m;
    while(m--){
        int a,b;cin>>a>>b;
        board[a]=b;
    }
    
    for(int i=1;i<100;i++){
        for(int j=1;j<=6;j++){
            if(i+j>100)continue;
            adj[i].push_back(board[i+j]);
        }
    }
    
    deque<int> q;
    int vis[101]={0};
    int dis[101]={0};
    q.push_back(1);
    vis[1]=1;
    while(!q.empty()){
        int cur = q.front();
        q.pop_front();
        for(const int &child:adj[cur]){
            if(vis[child])continue;
            vis[child]=1;
            dis[child]=1+dis[cur];
            q.push_back(child);
        }
    }
    cout<<(dis[100]==0?-1:dis[100])<<"\n";
}

signed main(){
    FASTER;
    int q;cin>>q;
    while(q--){
        solve();
    }
}
