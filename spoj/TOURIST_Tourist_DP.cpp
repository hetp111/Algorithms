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

int n,m;
int dp[101][101][101];//x1y1x2
char v[101][101];

bool outofbound(int i,int j,int k){
    return (i>n || j>m || k>n || (i+j-k)>m) || (v[i][j]=='#' || v[k][i+j-k]=='#');
}

int f(int x1,int y1,int x2){
    if(outofbound(x1,y1,x2))return INT_MIN;
    if(dp[x1][y1][x2]!=-1)return dp[x1][y1][x2];
    
    if(x1==n && y1==m)return v[n][m]=='*';//x2==n is obvious if x1=n and y1=m
    
    int ans=INT_MIN;
    
    int w=0;
    w+=(v[x1][y1]=='*');
    w+=(x1!=x2 && v[x2][x1+y1-x2]=='*');
    ans=max(ans,w+f(x1+1,y1+0,x2+1));
    ans=max(ans,w+f(x1+0,y1+1,x2+1));
    ans=max(ans,w+f(x1+1,y1+0,x2+0));
    ans=max(ans,w+f(x1+0,y1+1,x2+0));
    
    return dp[x1][y1][x2]=ans;
}

void solve(){
    memset(dp,-1,sizeof dp);
    cin>>n>>m;
    swap(n,m);//chutya
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>v[i][j];
        }
    }
    
    cout<<f(1,1,1)<<"\n";
    
}

signed main(){
    FASTER;
    int t;cin>>t;
    while(t--)solve();
}

