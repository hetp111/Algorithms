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

void f(int r, int c, int m);
bool ok;
int t,n,k;

signed main(){
    FASTER;
    int T;cin>>T;
    for(t=1;t<=T;t++){
        cin>>n>>k;
		ok=0;
        f(1, 1, 0);
        if(ok==0)cout<<"Case #"<<t<<": "<<"IMPOSSIBLE\n";
    }
}

int grid[55][55];
bool rsafe[55][55];
bool csafe[55][55];

void f2(int r,int c,int m){
    for (int i = 1; i <= n && !ok; ++i){
        if (!rsafe[r][i] && !csafe[c][i]){
            rsafe[r][i] = csafe[c][i] = 1;
            if (r == c) m += i;
            grid[r][c] = i;
            f(r, c + 1, m);
            rsafe[r][i]=csafe[c][i]=0;
            if (r==c) m -= i;
            grid[r][c] = 0;
        }
    }
}

void f(int r, int c, int m) {
    if(!ok && c==n+1 && r==n && m == k){
        cout << "Case #" << t << ": " << "POSSIBLE\n";
        for(int i = 1; i <= n; ++i){
            for(int j=1;j<=n;++j)cout << grid[i][j] << " ";cout << "\n";
        }
        ok=1;
        return;
    }else if (r > n)return;
    else if (c > n)f(r + 1, 1, m);
    f2(r,c,m);
}

