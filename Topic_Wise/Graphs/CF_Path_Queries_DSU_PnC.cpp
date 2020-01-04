//https://codeforces.com/contest/1213/problem/G
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
 
int n,m,cnt;
vector<pair<int,pii>> edg;
vii mm;
int ans[200001];
int dsu[200001];
int sz[200001];
 
int findd(int n){
    if(dsu[n]==n)return n;
    return dsu[n]=findd(dsu[n]);
}
 
void unionn(int p1,int p2){
    if(sz[p1]<sz[p2])swap(p1,p2);
    cnt+=sz[p1]*sz[p2];
    sz[p1]+=sz[p2];
    dsu[p2]=p1;
}
 
signed main(){
    FASTER;
    cin>>n>>m;
    for(int i=0;i<n-1;i++){
        int a,b,c;cin>>a>>b>>c;
        dsu[i]=i;
        sz[i]=1;
        edg.push_back({c,{a-1,b-1}});
    }
    dsu[n-1]=n-1;
    sz[n-1]=1;
    
    sort(all(edg));
    for(int i=0;i<m;i++){
        int in;cin>>in;
        mm.push_back({in,i});
    }
    sort(all(mm));
    
    
    int indx=0;
    for(const pii &i:mm){
        while(indx<n-1 && edg[indx].first<=i.first){
            int u = findd(edg[indx].second.first);
            int v = findd(edg[indx].second.second);
            unionn(u,v);
            indx++;
        }
        ans[i.second]=cnt;
    }
    
    for(int i=0;i<m;i++){
        cout<<ans[i]<<" ";
    }
    
}