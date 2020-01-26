//https://cses.fi/problemset/task/1194/
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
char v[1000][1000];
int disA[1000][1000];
pii parA[1000][1000];
int disM[1000][1000];
pii st;
int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};

queue<pii> q;

bool okay(int i,int j){
    return (i<n && j<m && i>=0 && j>=0 && v[i][j]!='#');
}

string solve(int i,int j){
    string ans="";
    while(parA[i][j].first!=-1 && parA[i][j].second!=-1){
        int I=parA[i][j].first;
        int J=parA[i][j].second;
        if(I==i){
            if(J-j>0)ans+="L";
            else ans+="R";
        }else{
            if(I-i>0)ans+="U";
            else ans+="D";
        }
        i=I;
        j=J;
    }
    reverse(all(ans));
    return ans;
}


signed main(){
    FASTER;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
            disA[i][j]=disM[i][j]=INF;
            if(v[i][j]=='M'){
                q.push({i,j});
                disM[i][j]=0;
            }else if(v[i][j]=='A'){
                st={i,j};
                disA[i][j]=0;
                parA[i][j]={-1,-1};
            }
        }
    }
    //Monster
    while(!q.empty()){
        int R=q.front().first;
        int C=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int r=R+dr[i];
            int c=C+dc[i];
            if(okay(r,c) && disM[r][c]==INF){
                q.push({r,c});
                disM[r][c]=disM[R][C]+1;
            }
        }
    }
    //YOU
    q.push(st);
    while(!q.empty()){
        int R=q.front().first;
        int C=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int r=R+dr[i];
            int c=C+dc[i];
            if(okay(r,c) && disA[r][c]==INF){
                q.push({r,c});
                disA[r][c]=disA[R][C]+1;
                parA[r][c]={R,C};
            }
        }
    }
    
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        //cout<<disA[i][j]<<" "<<disM[i][j]<<"\n";
        if((i==0 || i==n-1 || j==0 || j==m-1)&&okay(i,j)&&(disA[i][j]<disM[i][j])){
            string path=solve(i,j);
            cout<<"YES\n"<<path.size()<<"\n"<<path;
            return 0;
        }
    }
    
    cout<<"NO";
    
}

