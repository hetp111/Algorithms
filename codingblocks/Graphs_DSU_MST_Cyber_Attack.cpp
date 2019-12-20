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

class edge{
public:
    int cost,v,u;
    
    bool operator<(const edge &e){
        return cost>e.cost;
    }
    
};

int findd(int n,int *par){
    if(n==par[n])return n;
    return par[n]=findd(par[n],par);
}

signed main(){
    FASTER;
    
    int n,m,s;cin>>n>>m>>s;
    vector<edge> edg(m);
    
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        edg[i]={c,a-1,b-1};
    }
    
    sort(all(edg));
    
    int par[n];
    int visEdg[m]={0};
    for(int i=0;i<n;i++)par[i]=i;
    
    for(int i=0;i<m;i++){
        int x=edg[i].u;
        int y=edg[i].v;
        
        if(findd(x,par)!=findd(y,par)){
            par[findd(x,par)]=findd(y,par);
            visEdg[i]=1;
        }
        
    }
    
    int ans=0,cst=0;
    for(int i=m-1;i>=0;i--){
        if(visEdg[i])continue;
        if(s-edg[i].cost>=0){
            s-=edg[i].cost;
            cst+=edg[i].cost;
            ans++;
        }else break;
    }
    cout<<ans<<" "<<cst;
}
