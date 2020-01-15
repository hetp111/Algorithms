//https://codeforces.com/contest/277/problem/A

//n+m..!

#include <bits/stdc++.h>//Carefully Crafted by hetp111
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define MOD (1e9+7)
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
vi adj[101];
int par[201];

int findd(int n){
    if(n==par[n])return n;
    return par[n]=findd(par[n]);
}

void unionn(int a,int b){
    par[findd(a)]=findd(b);
}

signed main() {
    FASTER;
    cin>>n>>m;
    
    for(int i=1;i<=n+m;i++)par[i]=i;
    bool ze=1;
    for(int i=1;i<=n;i++){
        int in;cin>>in;
        ze=ze&&in==0;
        while(in--){
            int len;cin>>len;
            adj[i].push_back(len);
            unionn(i,n+len);
        }
    }
    
    unordered_set<int> st;
    for(int i=1;i<=n;i++)st.insert(findd(i));
    cout<<(!ze?(st.size()-1):n);
    
}