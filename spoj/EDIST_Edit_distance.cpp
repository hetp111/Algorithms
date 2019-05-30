#include <bits/stdc++.h>//Carefully Crafted by hetp111
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){
    return out<<"("<<a.first<<", "<<a.second<<")";}
template<class A> ostream& operator<<(ostream& out, const vector<A> &a){
	out<<"[";for(auto it=a.begin();it!=a.end();it++){if(it!=a.begin())out<<",";out<<*it;}cout<<"]";
	return out;}
template<class A, class B> istream& operator>>(istream& in, pair<A,B> &a){in>>a.first>>a.second;return in;}
template<class A> istream& operator>>(istream& in, vector<A> &a){for(A &i:a)in>>i;return in;}

signed main(){
    FASTER;
    int t;cin>>t;
    while(t--){
        string a,b;cin>>a>>b;
        int n=a.size(),m=b.size();
        vector<vi> v(n+1,vi(m+1));
        for(int i=0;i<=m;i++)v[0][i]=i;
        for(int i=0;i<=n;i++)v[i][0]=i;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i-1]!=b[j-1]){//i-1 j-1 is current indx of string
                    int del=v[i-1][j];
                    int rep=v[i-1][j-1];
                    int in=v[i][j-1];
                    v[i][j]=min({del,rep,in})+1;
                }else v[i][j]=v[i-1][j-1];
            }
        }
        cout<<v[n][m]<<"\n";
    }
}
