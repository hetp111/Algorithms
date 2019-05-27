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

int mergg(int s,int mid,int e,vi &v,vi &v2){
    int i=s,j=mid+1,k=s;
    int inv=0;
    while(i<=mid && j<=e){
        if(v[i]>v[j]){
            inv+=(mid+1-i);
            v2[k++]=v[j++];
        }else{
            v2[k++]=v[i++];
        }
    }
    while(j<=e){
        v2[k++]=v[j++];
    }
    while(i<=mid){
        v2[k++]=v[i++];
    }
    for(int i=s;i<=e;i++)v[i]=v2[i];
    return inv;
}

int mergsort(int s,int e,vi &v,vi &v2){
    if(s>=e)return 0;
    int mid=(s+e)/2;
    int inv=mergsort(s,mid,v,v2);
    inv+=mergsort(mid+1,e,v,v2);
    inv+=mergg(s,mid,e,v,v2);
    return inv;
}

signed main(){
    FASTER;
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vi v(n),v2(n);cin>>v;
        cout<<mergsort(0,n-1,v,v2)<<"\n";
    }
}
