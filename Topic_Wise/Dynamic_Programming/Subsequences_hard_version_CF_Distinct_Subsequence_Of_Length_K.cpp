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
#define PI acos(-1)
#define eps (1e-8)
#define INF (1e18)
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0)
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
//ifstream cinn("input.txt");ofstream coutt("output.txt");
 
//i believe i can flyyyyyy 
//sexy problem
 
int dp[105][105];
int last[26];
string s;
int n,k;
 
signed main(){
    FASTER;
    cin>>n>>k>>s;
    memset(last,-1,sizeof last);
    
    for(int i=0;i<=n;i++)dp[0][i]=0;
    for(int i=0;i<=n;i++)dp[i][0]=1;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i][j]=(dp[i-1][j]+dp[i-1][j-1]);
            if(last[s[i-1]-'a']!=-1){
                dp[i][j]-=dp[last[s[i-1]-'a']-1][j-1];
            }
        }
        last[s[i-1]-'a']=i;
    }
    
    int ans=0;
    for(int i=n;i>=0;i--){
        int cur=dp[n][i];
        if(k>=cur){
            ans+=(n-i)*cur;
            k-=cur;
        }else{
            ans+=(n-i)*k;
            k=0;
            break;
        }
    }
    cout<<(k==0?ans:-1);
}