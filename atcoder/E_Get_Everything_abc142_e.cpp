//bitmask + dp
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
#define eps 1e-8
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
//ifstream cinn("input.txt");ofstream coutt("output.txt");
 
int n,m,total=0;
vector<vi> v;
vi cost,treasurbit;
 
int dp[1005][5000];
 
int f(int i,int selected){
    if(i==m){
        if(selected==total)return 0;
        return 1e18;
    }
    
    if(dp[i][selected]!=-1)return dp[i][selected];
    
    int a=f(i+1,selected);
    int b=f(i+1,selected|treasurbit[i])+cost[i];
    
    return dp[i][selected]=min(a,b);
    
}
 
signed main(){
    FASTER;
    cin>>n>>m;
    v.resize(m);
    cost.resize(m);
    treasurbit.resize(m,0);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        total|=(1<<i);
    }
    
    for(int i=0;i<m;i++){
        int a;
        cin>>cost[i]>>a;
        while(a--){
            int in;cin>>in;
            treasurbit[i]|=(1<<(in-1));
        }
    }
    
    int anss=f(0,0);
    
    if(anss!=1e18){
        cout<<anss;
    }else cout<<-1;
}
