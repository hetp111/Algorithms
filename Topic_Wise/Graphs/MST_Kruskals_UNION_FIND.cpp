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

int findd(int n,int *par){
    if(n==par[n])return n;
    return par[n]=findd(par[n],par);
}

void unionn(int u,int v,int *par){
    int x=findd(u,par);
    int y=findd(v,par);
    par[x]=y;
}

signed main(){
    FASTER;
    int n,m;cin>>n>>m;
    vector<pair<int,pii>> ed(m);
    
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        ed[i]={c,{a-1,b-1}};
    }
    
    sort(all(ed));
    
    int par[n];
    for(int i=0;i<n;i++)par[i]=i;
    
    int cst=0;
    for(int i=0;i<m;i++){
        int u=ed[i].second.first;
        int v=ed[i].second.second;
        int c=ed[i].first;
        if(findd(v,par)!=findd(u,par)){
            unionn(v,u,par);
            cst+=c;
        }
    }
    cout<<cst;
    
}
