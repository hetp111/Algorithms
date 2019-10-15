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

void findXY(int a,int b,int &x,int &y){
    if(a==0){x=0;y=__gcd(a,b)/b;return;}
    int x1,y1;
    findXY(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
}

signed main(){
    FASTER;
    int n;cin>>n;
    int x,y;
    findXY(n,MOD,x,y);
    cout<<(x+MOD)%MOD<<"\n";
}

