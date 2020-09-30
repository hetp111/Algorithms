#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define double long double
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
const int MOD=2000000011;
const int INF=1e12;
void io(string s="file"){freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}

int n,m;
pii S,F;
char v[1001][1001];
int vis[1001][1001];
int dis[1001][1001];

int dx[]={0,1,0,-1,1,-1,1,-1};
int dy[]={1,0,-1,0,1,-1,-1,1};

void bfs(int sx,int sy){
    vis[sx][sy]=(1<<8)-1;
    dis[sx][sy]=0;
    queue<pii> q;
    q.push(pii(sx,sy));
    while(!q.empty()){
        pii top=q.front();
        q.pop();
        if(top.first==F.first && top.second==F.second){
            cout<<dis[top.first][top.second]<<"\n";
            return;
        }
        for(int k=0; k<8; k++){
            
            for(int i=1;;i++){
                
                int tx=top.first+dx[k]*i;
                int ty=top.second+dy[k]*i;
                
                if(tx<n && ty<m && tx>=0 && ty>=0 && !(vis[tx][ty]&(1<<k))){
                    if(!vis[tx][ty]){
                        dis[tx][ty]=1+dis[top.first][top.second];
                        q.push(pii(tx,ty));
                    }
                    vis[tx][ty]|=(1<<k);
                }else break;
                
            }
            
        }
    }
    cout<<-1<<"\n";
}

void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
            vis[i][j]=0;
            if(v[i][j]=='S')S={i,j};
            if(v[i][j]=='F')F={i,j};
            if(v[i][j]=='X')vis[i][j]=(1<<8)-1;
        }
    }
    bfs(S.first,S.second);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}