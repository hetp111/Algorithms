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
int v[1001][1001];
int vis[1001][1001];
int vis2[1001][1001];
int group[1001][1001];
int ansOfGroup[1000001];
int groupNum=0;

bool ok(int i,int j){
    if(i>=n || i<0 || j>=m || j<0)return 0;
    return v[i][j];
}

int mx;

int dfs(int i,int j){
    
    if(vis[i][j])return 0;
    vis[i][j]=1;
    
    int ans=1;
    if(ok(i,j+1))ans+=dfs(i,j+1);
    if(ok(i,j-1))ans+=dfs(i,j-1);
    if(ok(i+1,j))ans+=dfs(i+1,j);
    if(ok(i-1,j))ans+=dfs(i-1,j);
    
    return ans;
}

void dfs2(int i,int j){
    
    if(vis2[i][j])return;
    vis2[i][j]=1;
    
    if(ok(i,j+1))dfs2(i,j+1);
    if(ok(i,j-1))dfs2(i,j-1);
    if(ok(i+1,j))dfs2(i+1,j);
    if(ok(i-1,j))dfs2(i-1,j);
    
    group[i][j]=groupNum;
    ansOfGroup[groupNum]=mx;
    
}


signed main(){
    FASTER;
    memset(group,-1,sizeof group);
    cin>>n>>m;
    int flg=1;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){cin>>v[i][j];flg=min(v[i][j],flg);}
    if(flg){
        cout<<n*m;
        return 0;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && v[i][j]){
                mx=dfs(i,j);
            }
            if(!vis2[i][j] && v[i][j]){
                dfs2(i,j);
                groupNum++;
            }
        }
    }
    
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==0){
                int a=-1,b=-1,c=-1,d=-1;
                if(i+1<n)a=group[i+1][j];
                if(i-1>=0)b=group[i-1][j];
                if(j+1<m)c=group[i][j+1];
                if(j-1>=0)d=group[i][j-1];
                set<int> tmp={a,b,c,d};
                if(tmp.find(-1)!=tmp.end())tmp.erase(tmp.find(-1));
                vi tmp2(all(tmp));
                int aanss=0;
                for(int asd:tmp2)aanss+=ansOfGroup[asd];
                ans=max(ans,aanss+1);///
            }
        }
    }
    
    cout<<ans;
    
}
