//https://www.spoj.com/problems/ROHAAN/
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

void solve(int TTT){
    int n,v[50][50]={0};cin>>n;
    //for(int i=0;i<50;i++)for(int j=0;j<50;j++)if(i!=j)v[i][j]=1e12;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
            }
        }
    }
    
    int q,asd=0;cin>>q;
    while(q--){
        int a,b;cin>>a>>b;
        asd+=v[a-1][b-1];
    }
    cout<<"Case #"<<TTT<<": "<<asd<<"\n";
    
}

signed main(){
    FASTER;
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        solve(i);
    }
}

