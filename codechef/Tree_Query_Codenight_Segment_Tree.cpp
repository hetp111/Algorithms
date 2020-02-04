#include <bits/stdc++.h>//Carefully Crafted by hetp111
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define MOD (1000000007)
//#define MOD (998244353)
#define PI acos(-1)
#define eps (1e-8)
#define INF (1e18)
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0)
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
//ifstream cinn("input.txt");ofstream coutt("output.txt");

int n,cntr;
vi adj[100000];
int val[100000];
int indxOf[100000];
int szSub[100000];

int tree[4*100000];

int dfs(int cur,int par){
    indxOf[cur]=cntr++;
    for(int ch:adj[cur])if(ch!=par){
        szSub[cur]+=dfs(ch,cur)+1;
    }
    return szSub[cur];
}

void update(int s,int e,int idx,int SE,int val){
    if(s>SE || e<SE)return;
    if(s==e){
        tree[idx]=val;
        return;
    }
    int mid=(s+e)/2;
    update(s,mid,idx*2+1,SE,val);
    update(mid+1,e,idx*2+2,SE,val);
    tree[idx]=tree[idx*2+1]+tree[idx*2+2];
}

int query(int s,int e,int idx,int S,int E){
    if(s>E || e<S)return 0;
    if(s>=S && e<=E)return tree[idx];
    int mid=(s+e)/2;
    return query(s,mid,idx*2+1,S,E)+query(mid+1,e,idx*2+2,S,E);
}

signed main(){
    FASTER;
    cin>>n;
    for(int i=0;i<n;i++)cin>>val[i];
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    dfs(0,-1);
    
    for(int i=0;i<n;i++){
        update(0,n-1,0,indxOf[i],val[i]*val[i]);
    }
    
    int q;cin>>q;
    while(q--){
        int c;cin>>c;
        if(c==2){
            int idx;cin>>idx;idx--;
            cout<<query(0,n-1,0,indxOf[idx],indxOf[idx]+szSub[idx])<<"\n";
        }else{
            int idx,inc;cin>>idx>>inc;idx--;
            update(0,n-1,0,indxOf[idx],inc*inc);
        }
    }
}