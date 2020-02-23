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

int n,m;
char v[255][255];
int dis[255][255];
//map<pii,vector<pii>> adj;
vector<pii> adj[255][255];

bool f(int x){//kya ye max dis=mid possible hai ?
    int mi1 = INF, ma1 = -INF, mi2 = INF, ma2 = -INF;
    int mi1x,mi1y;
    int mi2x,mi2y;
    int ma1x,ma1y;
    int ma2x,ma2y;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        if(dis[i][j]<=x)continue;
        if(i+j<mi1){
            mi1=i+j;
            mi1x=i;
            mi1y=j;
        }
        if(i+j>ma1){
            ma1=i+j;
            ma1x=i;
            ma1y=j;
        }
        if(i-j<mi2){
            mi2=i-j;
            mi2x=i;
            mi2y=j;
        }
        if(i-j>ma2){
            ma2=i-j;
            ma2x=i;
            ma2y=j;
        }
    }
    
    if(mi1==INF && mi2==INF && ma1==-INF && ma2==-INF)return 1;
    
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        
        if(
           abs(mi1x-i)+abs(mi1y-j)<=x &&
           abs(mi2x-i)+abs(mi2y-j)<=x &&
           abs(ma1x-i)+abs(ma1y-j)<=x &&
           abs(ma2x-i)+abs(ma2y-j)<=x
           ) return 1;
        
    }
    
    return 0;
}


signed main(){
    FASTER;
    int t;cin>>t;
    for(int T=1;T<=t;T++){
        cin>>n>>m;
        
        queue<pii> q;
        
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
            cin>>v[i][j];
            if(v[i][j]=='1'){
                q.push({i,j});
                dis[i][j]=0;
            }else dis[i][j]=INF;
            
            if(i+1<=n)adj[i][j].push_back({i+1,j});
            if(i-1>=1)adj[i][j].push_back({i-1,j});
            if(j+1<=m)adj[i][j].push_back({i,j+1});
            if(j-1>=1)adj[i][j].push_back({i,j-1});
        }
        
        while(!q.empty()){
            pii cur=q.front();
            q.pop();
            for(auto ch:adj[cur.first][cur.second])if(dis[ch.first][ch.second]==INF){
                dis[ch.first][ch.second]=1+dis[cur.first][cur.second];
                q.push(ch);
            }
        }
        
        int s=0,e=n-1+m-1,ans=e;
        while(s<=e){
            int mid=(s+e)/2;
            if(f(mid)){//kya ye max dis=mid possible hai ?
                ans=mid;
                e=mid-1;
            }else s=mid+1;
        }
        
        cout<<"Case #"<<T<<": "<<ans<<"\n";
    }
}