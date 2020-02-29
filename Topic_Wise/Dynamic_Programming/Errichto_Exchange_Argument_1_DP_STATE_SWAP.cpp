//https://atcoder.jp/contests/cf17-final/tasks/cf17_final_d
//https://youtu.be/7hFWrKa6yRM?list=PLl0KD3g-oDOHpWRyyGBUJ9jmul0lUOD80&t=1190
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

vii v;
int n,dp[5000][5001];

int f(int i,int k){// f(i,j) min price when j items taken and i items included
    if(k<0)return INF;
    if(i==-1){
        if(k>0)return INF;
        return 0;
    }
    
    int &ans=dp[i][k];
    if(ans!=-1)return ans;
    
    ans=INF;
    int picheka=f(i-1,k-1);
    if(picheka<=v[i].first)ans=min(ans,picheka+v[i].second);
    ans=min(ans,f(i-1,k));
    
    return ans;
}

signed main(){
    FASTER;
    memset(dp,-1,sizeof dp);
    cin>>n;
    v=vii(n);cin>>v;
    sort(all(v),[](const pii &a,const pii &b){return a.first+a.second<b.first+b.second;});
    
    for(int i=n;i>=0;i--){
        if(f(n-1,i)!=INF){
            cout<<i;
            return 0;
        }
    }
}
