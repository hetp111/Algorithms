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

vi subsets(const vi &v){
    vi ans;
    int n=v.size();
    for(int i=0;i<(1<<n);i++){
        int sum=0,j=0,I=i;
        while(I){
            if(I&1)sum+=v[j];
            j++;
            I>>=1;
        }
        ans.push_back(sum);
    }
    return ans;
}

signed main(){
    FASTER;
    int n,a,b;cin>>n>>a>>b;
    int n1=n/2,n2=n-n1;
    vi v1(n1),v2(n2),sv1,sv2;cin>>v1>>v2;
    sv1=subsets(v1);
    sv2=subsets(v2);
    sort(all(sv2));
    int ans=0;
    for(int num:sv1)ans+=(upper_bound(all(sv2),b-num)-lower_bound(all(sv2),a-num));
    cout<<ans<<"\n";
}
