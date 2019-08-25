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

//sexy

map<pii,vector<pii>> adj;
map<pii,int> disFromA;
map<pii,bool> vis;

void bfs(pii src){
    vis.clear();
    disFromA.clear();

    queue<pii> q;
    q.push(src);
    vis[src]=1;

    while(!q.empty()){
        pii par=q.front();
        q.pop();
        for(pii child:adj[par]){
            if(!vis[child]){
                vis[child]=1;
                disFromA[child]=1+disFromA[par];
                q.push(child);
            }
        }
    }

}

signed main(){
    FASTER;

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(i-1>=0 && j+2<8)adj[{i,j}].push_back({i-1,j+2});
            if(i+1<8 && j+2<8)adj[{i,j}].push_back({i+1,j+2});

            if(i+2<8 && j-1>=0)adj[{i,j}].push_back({i+2,j-1});
            if(i+2<8 && j+1<8)adj[{i,j}].push_back({i+2,j+1});

            if(i+1<8 && j-2>=0)adj[{i,j}].push_back({i+1,j-2});
            if(i-1>=0 && j-2>=0)adj[{i,j}].push_back({i-1,j-2});

            if(i-2>=0 && j+1<8)adj[{i,j}].push_back({i-2,j+1});
            if(i-2>=0 && j-1>=0)adj[{i,j}].push_back({i-2,j-1});
        }

    }

    int t;cin>>t;
    while(t--){
        pii a,b;
        string s1,s2;cin>>s1>>s2;
        a={8-(s1[1]-'0'),s1[0]-'a'};
        b={8-(s2[1]-'0'),s2[0]-'a'};
        bfs(a);
        cout<<disFromA[b]<<"\n";
    }
}
