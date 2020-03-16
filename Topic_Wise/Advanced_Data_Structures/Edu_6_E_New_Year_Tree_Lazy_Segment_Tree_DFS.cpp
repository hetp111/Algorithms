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

int n,m;
int col[400005];
vi adj[400005];

int in[400005];
int sz[400005];
int cnt=1;

void dfs(int cur,int par){
    sz[cur]=1;
    in[cur]=cnt++;
    for(int ch:adj[cur]){
        if(ch==par)continue;
        dfs(ch,cur);
        sz[cur]+=sz[ch];
    }
}

///segtree

int tree[4*400005];
int lz[4*400005];

void push(int s,int e,int indx){
    if(lz[indx]){
        tree[indx]=lz[indx];
        if(s!=e)lz[2*indx]=lz[2*indx+1]=lz[indx];
        lz[indx]=0;
    }
}

void update(int s,int e,int indx,int S,int E,int col){
    push(s,e,indx);
    if(e<S || s>E)return;
    if(s>=S && e<=E){
        tree[indx]=(1LL<<col);
        if(s!=e)lz[2*indx]=lz[2*indx+1]=(1LL<<col);
        return;
    }
    int mid=(s+e)/2;
    update(s,mid,indx*2,S,E,col);
    update(mid+1,e,indx*2+1,S,E,col);
    tree[indx]=tree[indx*2]|tree[indx*2+1];
}

int query(int s,int e,int indx,int S,int E){
    push(s,e,indx);
    if(e<S || s>E)return 0;
    if(s>=S && e<=E)return tree[indx];
    int mid=(s+e)/2;
    return query(s,mid,indx*2,S,E)|query(mid+1,e,indx*2+1,S,E);
}

/////


signed main(){
    FASTER;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>col[i];
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1);
    
    for(int i=1;i<=n;i++){
        update(1,n,1,in[i],in[i],col[i]);
    }
    
    while(m--){
        int c;cin>>c;
        if(c==1){
            int a,b;cin>>a>>b;
            update(1,n,1,in[a],in[a]+sz[a]-1,b);
        }else{
            int a;cin>>a;
            int qq=query(1,n,1,in[a],in[a]+sz[a]-1);
            int cntt=0;
            while(qq){
                cntt+=qq&1;
                qq/=2;
            }
            cout<<cntt<<"\n";
        }
    }
}