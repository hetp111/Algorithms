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
    int n;cin>>n;
    vi v(n),abc,fed;cin>>v;
    for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
            for(int c=0;c<n;c++){
                abc.push_back(v[a]*v[b]+v[c]);
                if(v[c]!=0)fed.push_back((v[a]+v[b])*v[c]);
            }
        }
    }
    sort(all(fed));
    int cnt=0;
    for(int s1:abc)cnt+=(upper_bound(all(fed),s1)-lower_bound(all(fed),s1));
    cout<<cnt;
}
