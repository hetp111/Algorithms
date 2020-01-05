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

signed main(){
    FASTER;
    int n,k;cin>>n>>k;
    vi dp(n);cin>>dp;
    
    int ans=0;
    
    for(int i=k;i<n;i+=k){
        int m1=i-k,m2=-1;
        
        for(int j=i-k+1;j<i;j++){
            if(dp[j]>dp[m1]){
                m1=j;
            }
        }
        
        if(k!=1)m2=(((i-k)==m1)?(i-k+1):(i-k));
        
        for(int j=i-k;j<i && k!=1;j++){
            if(dp[j]>dp[m2] && j!=m1){
                m2=j;
            }
        }
        
        for(int j=i;j<i+k && j<n;j++){
            if(dp[j]<0)dp[j]=dp[m1];
            else if(j-m1!=k)dp[j]+=dp[m1];
            else dp[j]+=dp[m2];
            ans=max(ans,dp[j]);
        }
    }
    
    cout<<ans;
}