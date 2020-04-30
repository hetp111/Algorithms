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
//ifstream cinn("input.txt");ofstream coutt("output.txt");

int n,m;
int prime[10000001],cnt[10000001],f[10000001];

signed main(){
    FASTER;
    cin>>n;
    for(int i=0;i<n;i++){
        int in;cin>>in;
        cnt[in]++;
    }
    memset(prime,1,sizeof prime);
    prime[1]=0;
    for(int i=2;i<=10000000;i++){
        if(prime[i]){
            f[i]+=cnt[i];
            for(int j=2*i;j<=10000000;j+=i){
                prime[j]=0;
                f[i]+=cnt[j];
            }
        }
        f[i]+=f[i-1];
    }
    
    cin>>m;
    while(m--){
        int l,r;cin>>l>>r;
        l=min(l,10000000LL);
        r=min(r,10000000LL);
        cout<<f[r]-f[l-1]<<"\n";
    }
}