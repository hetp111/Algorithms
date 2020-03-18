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

int n,v[500],dp[500][500],dp2[500][500];

int f(int i,int j){
    if(i==j)return v[i];
    int &ans=dp[i][j];
    if(ans!=-INF)return ans;
    
    ans=-1;
    
    for(int k=i;k<j;k++){
        if(f(i,k)!=-1 && f(i,k)==f(k+1,j)){
            ans=1+f(i,k);
            break;
        }
    }
    
    return ans;
}

int ff(int i,int j){
    if(i==j)return 1;
    int &ans=dp2[i][j];
    if(ans!=-INF)return ans;
    ans=(f(i,j)!=-1?1:(j-i+1));
    for(int k=i;k<j;k++)ans=min(ans,ff(i,k)+ff(k+1,j));
    return ans;
}

signed main(){
    FASTER;
    for(int i=0;i<500;i++){
        for(int j=0;j<500;j++){
            dp[i][j]=-INF;
            dp2[i][j]=-INF;
        }
    }
    cin>>n;
    for(int i=0;i<n;i++)cin>>v[i];
    cout<<ff(0,n-1);
}