#include <bits/stdc++.h>//Carefully Crafted by hetp111
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define pii pair<int,int>
#define prec(n) fixed<<setprecision(n)
#define MOD 1000000007
#define eps 1e-8
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){
    return out<<"("<<a.first<<","<<a.second<<")";}
template<class A> ostream& operator<<(ostream& out, const vector<A> &a){
	out<<"";for(auto it=a.begin();it!=a.end();it++){if(it!=a.begin())out<<" ";out<<*it;}out<<"";
	return out;}
template<class A, class B> istream& operator>>(istream& in, pair<A,B> &a){in>>a.first>>a.second;return in;}
template<class A> istream& operator>>(istream& in, vector<A> &a){for(A &i:a)in>>i;return in;}
//ifstream cinn("input.txt");ofstream coutt("output.txt");

//sparse table

signed main(){
    FASTER;
    int n,q;cin>>n;
    vi v(n);cin>>v;
    int dpt=((int)log2(n))+1;
    vector<vi> table(dpt,vi(n,0));
    table[0]=v;

    for(int i=1;i<dpt;i++){
        for(int j=0;j<=(n-(1<<i));j++){
            int a,b;
            a=j;
            b=j+(1<<(i-1));
            table[i][j]=min(table[i-1][a],table[i-1][b]);
        }
        //cout<<table[i]<<"\n";
    }

    cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        int len=r-l+1;
        int row=(int)log2(len);
        int a=table[row][l];
        int b=table[row][r-((1<<row)-1)];
        cout<<min(a,b)<<"\n";
    }

}
