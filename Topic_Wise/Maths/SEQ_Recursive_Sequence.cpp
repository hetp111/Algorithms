#include <bits/stdc++.h>//Carefully Crafted by hetp111
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define MOD 1000000000
#define PI acos(-1)
#define eps (1e-8)
#define INF (1e18)
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0)
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
//ifstream cinn("input.txt");ofstream coutt("output.txt");

vvi mul(const vvi &a,const vvi &b){
    int r=a.size();
    int c=a[0].size();
    //int r1=b.size();
    int c2=b[0].size();
    
    vvi cc(r,vi(c2,0));
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c2;j++){
            for(int k=0;k<c;k++){
                cc[i][j]=(cc[i][j]%MOD+((a[i][k]%MOD)*(b[k][j]%MOD))%MOD)%MOD;
            }
        }
    }
    
    return cc;
}

vvi poww(const vvi &T,int n){
    if(n==0){
        vvi v(T.size(),vi(T[0].size(),0));//r==c
        for(int i=0;i<T.size();i++)v[i][i]=1;
        return v;
    }
    vvi ans=poww(T,n/2);
    ans=mul(ans,ans);
    if(n&1)ans=mul(ans,T);
    return ans;
}

signed main(){
    FASTER;
    int t;cin>>t;
    while(t--){
        int k;cin>>k;
        vi b(k),c(k);cin>>b>>c;
        int n;cin>>n;n--;
        
        if(n<=k-1){
            cout<<b[n]%MOD<<"\n";
            continue;
        }
        vvi T(k,vi(k,0));
        for(int i=0;i<k;i++)T[0][i]=c[i]%MOD;
        for(int i=1;i<k;i++)T[i][i-1]=1;
        
        T=poww(T,n-k+1);
        vvi Ak(k,vi(1));
        for(int i=0;i<k;i++)Ak[i][0]=b[k-i-1]%MOD;
        
        cout<<mul(T,Ak)[0][0]<<"\n";
        
    }
}