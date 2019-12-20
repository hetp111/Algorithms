
//bfs bipartite graph
//sexiness overload

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

bool bfs(vi *adj,int n){
    bool vis[n]={0};
    int color[n];
    memset(color,-1,sizeof(color));

    for(int bug=0;bug<n;bug++){

        if(!vis[bug]){
            queue<int> q;
            q.push(bug);
            while(!q.empty()){
                int parr=q.front();
                vis[parr]=1;
                q.pop();
                for(int child:adj[parr]){
                    if(color[child]==-1){
                        color[child]=1-color[parr];
                    }else if(color[child]==color[parr]){
                        return 1;
                    }
                }
            }
        }

    }
    return 0;
}

signed main(){
    FASTER;
    int t;cin>>t;
    for(int tt=1;tt<=t;tt++){
        int a,b;cin>>a>>b;
        vi adj[a];
        for(int i=0;i<b;i++){
            int x,y;cin>>x>>y;
            adj[x-1].push_back(y-1);
            adj[y-1].push_back(x-1);
        }

        int flg=bfs(adj,a);

        cout<<"Scenario #"<<tt<<":\n";
        if(flg){
            cout<<"Suspicious bugs found!\n";
        }else{
            cout<<"No suspicious bugs found!\n";
        }
    }
}
