//https://codeforces.com/contest/1288/problem/E

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

int n,m;
int bit[600001];
int v[300001];
int pos[300001];
int mn[300001];
int mx[300001];

void update(int indx,int up){
    while(indx<=600000){
        bit[indx]+=up;
        indx+=(indx&(-indx));
    }
}

int query(int indx){
    int sum=0;
    while(indx>0){
        sum+=bit[indx];
        indx-=(indx&(-indx));
    }
    return sum;
}

signed main(){
    FASTER;
    cin>>n>>m;
    for(int i=1;i<=n;i++)mn[i]=mx[i]=i;
    for(int i=1;i<=m;i++){
        cin>>v[i];
        mn[v[i]]=1;
    }
    
    for(int i=1;i<=n;i++)update(i,1);
    for(int i=1;i<=n;i++)pos[i]=n-i+1;
    
    for(int i=1;i<=m;i++){
        mx[v[i]]=max(mx[v[i]],query(600000)-query(pos[v[i]]-1));
        update(pos[v[i]],-1);
        pos[v[i]]=i+n;
        update(pos[v[i]],1);
    }
    
    for(int i=1;i<=n;i++)mx[i]=max(mx[i],query(600000)-query(pos[i]-1));
    
    for(int i=1;i<=n;i++)cout<<mn[i]<<" "<<mx[i]<<"\n";
    
}