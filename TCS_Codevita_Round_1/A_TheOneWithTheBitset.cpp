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

vi makebitscore(const vi &v){
    vi bitscore;
    for(int i:v){
        int mn=INT_MAX,mx=INT_MIN;
        while(i){
            mn=min(mn,i%10);
            mx=max(mx,i%10);
            i/=10;
        }
        if(mn==INT_MAX)mn=0;
        if(mx==INT_MIN)mx=0;
        int asd=0;
        int anss=mn*7+mx*11;
        asd=(anss%10)+((anss/10)%10)*10;
        bitscore.push_back(asd);
    }
    //cout<<bitscore<<"\n";
    return bitscore;
}

signed main(){
    FASTER;
    int n;cin>>n;
    vi v(n);cin>>v;
    vi bitscore=makebitscore(v);
    map<int,int> kitnapair;
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+2;j<n;j+=2){
            int n1,n2;
            n1=(bitscore[i]-bitscore[i]%10)/10;
            n2=(bitscore[j]-bitscore[j]%10)/10;
            if(n1==n2 && kitnapair[n1]!=2){
                cnt++;
                //cout<<i<<" "<<j<<"\n";
                kitnapair[n1]++;         
            }
        }
    }
    cout<<cnt<<"";
}