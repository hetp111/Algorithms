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

int tree[4*(200005)];
int lz[4*(200005)];
int n,q;
int v[200005];

void update(int s,int e,int indx,int S,int E,int val){
    if(e<S || s>E)return;
    
    if(lz[indx]!=0){
        tree[indx]+=lz[indx];
        if(s!=e){
            lz[indx*2+1]+=lz[indx];
            lz[indx*2+2]+=lz[indx];
        }
        lz[indx]=0;
    }
    
    if(e<=E && s>=S){
        tree[indx]+=val;
        if(s!=e){
            lz[indx*2+1]+=val;
            lz[indx*2+2]+=val;
        }
        return;
    }
    
    int mid=(s+e)/2;
    update(s,mid,indx*2+1,S,E,val);
    update(mid+1,e,indx*2+2,S,E,val);
    tree[indx]=tree[indx*2+1]+tree[indx*2+2];
}

int query(int s,int e,int indx,int S,int E){
    if(e<S || s>E)return 0;
    
    if(lz[indx]!=0){
        tree[indx]+=lz[indx];
        if(s!=e){
            lz[indx*2+1]+=lz[indx];
            lz[indx*2+2]+=lz[indx];
        }
        lz[indx]=0;
    }
    
    if(e<=E && s>=S)return tree[indx];
    int mid=(s+e)/2;
    return query(s,mid,indx*2+1,S,E)+query(mid+1,e,indx*2+2,S,E);
}

signed main(){
    FASTER;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>v[i];
        update(0,n-1,0,i,i,v[i]);
        update(0,n-1,0,i+1,i+1,-v[i]);
    }
    
    while(q--){
        int c;cin>>c;
        if(c==1){
            int a,b,u;cin>>a>>b>>u;a--,b--;
            update(0,n-1,0,a,a,u);
            update(0,n-1,0,b+1,b+1,-u);
        }else{
            int id;cin>>id;id--;
            cout<<query(0,n-1,0,0,id)<<"\n";
        }
    }
}