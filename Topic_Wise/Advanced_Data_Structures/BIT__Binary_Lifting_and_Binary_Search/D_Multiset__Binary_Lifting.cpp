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
#define MOD2 (998244353)
#define MOD3 (1000000009)
#define PI acos(-1)
#define eps (1e-8)
#define INF (1e18)
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0)
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
ifstream cinn("input.txt");ofstream coutt("output.txt");
int poww(int a,int b,int m=MOD){if(b==0)return 1;int x=poww(a,b/2,m);x=x*x%m;if(b&1)x=x*a%m;return x;}

int tree[1000001];

void update(int i,int c){
    while(i<1000001){
        tree[i]+=c;
        i+=i&(-i);
    }
}

int gett(int i){
    int sum=0;
    while(i>0){
        sum+=tree[i];
        i-=i&(-i);
    }
    return sum;
}

signed main(){
    FASTER;
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
        int tmp;cin>>tmp;
        update(tmp,1);
    }
    while(q--){
        int in;cin>>in;
        if(in>0){
            update(in,1);
        }else{
            in*=-1;
            
            int cur=0,pre=0;
            for(int i=19;i>=0;i--){
                if(cur+(1LL<<i)<1000001 && tree[cur+(1LL<<i)]+pre<in){
                    cur+=(1LL<<i);
                    pre+=tree[cur];
                }
            }
            update(cur+1,-1);
        }
    }
    
    for(int i=1;i<=1e6;i++){
        if(gett(i)){
            cout<<i;
            return 0;
        }
    }
    cout<<0;
}