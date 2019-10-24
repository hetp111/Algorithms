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
#define eps (1e-8)
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
//ifstream cinn("input.txt");ofstream coutt("output.txt");
 
 
const int N=7;
 
int vis[N][N];
char Path[N*N-1];
char Input[N*N-1];
int cnt=0,steps=0;
 
bool outOfBound(int i,int j){
    return (i>=N || j>=N || j<0 || i<0);
}
 
bool chk(){
    for(int i=0;i<N*N-1;i++){
        if(Input[i]=='?')continue;
        if(Input[i]!=Path[i])return 0;
    }
    return 1;
}
 
void f(int i,int j){
    if(outOfBound(i,j))return;
    
    if(i==N-1 && j==0){
        if(steps==N*N-1 && chk())cnt++;
        return;
    }
    
    bool t=vis[i][j] ||
            (((i-1>=0 && vis[i-1][j]) && (i+1<N && vis[i+1][j])) && (j+1<N && j-1>=0 && !vis[i][j+1] && !vis[i][j-1])) ||
            (((j-1>=0 && vis[i][j-1]) && (j+1<N && vis[i][j+1])) && (i+1<N && i-1>=0 && !vis[i+1][j] && !vis[i-1][j])) ||
            ((j==N-1 || j==0) && (i+1<N && i-1>=0 && !vis[i+1][j] && !vis[i-1][j])) ||
            ((i==N-1 || i==0) && (j+1<N && j-1>=0 && !vis[i][j+1] && !vis[i][j-1]))
            ;
    if(t)return;
    
    vis[i][j]=1;
    
    Path[steps]='D';
    steps++;
    f(i+1,j);
    steps--;
    
    Path[steps]='U';
    steps++;
    f(i-1,j);
    steps--;
    
    Path[steps]='R';
    steps++;
    f(i,j+1);
    steps--;
    
    Path[steps]='L';
    steps++;
    f(i,j-1);
    steps--;
    
    vis[i][j]=0;
}
 
 
signed main(){
    FASTER;
    for(int i=0;i<N*N-1;i++)cin>>Input[i];
    f(0,0);
    cout<<cnt;
}
