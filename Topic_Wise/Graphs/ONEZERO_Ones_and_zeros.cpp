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

//sexy

int mod(string s,int n){
    int p=1,ans=0,dig;
    for(int i=s.size()-1;i>=0;i--){
        dig=(s[i]-'0')*p;
        ans=(ans+dig)%n;
        p=(p*10)%n;
    }
    return ans;
}

string solve(int n){
    queue<string> q;
    unordered_map<int,bool> vis;

    q.push("1");

    while(!q.empty()){
        string s=q.front();
        q.pop();
        int rem=mod(s,n);

        if(rem==0){
            return s;
        }else if(!vis[rem]){
            vis[rem]=1;
            q.push(s+"0");
            q.push(s+"1");
        }
    }
}

signed main(){
    FASTER;
    int t,n;cin>>t;
    while(t--){
        cin>>n;
        cout<<solve(n)<<"\n";
    }
}
