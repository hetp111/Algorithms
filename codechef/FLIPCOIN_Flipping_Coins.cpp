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

//<3

vi tree(400000,0);
vi pending(400000,0);

void updateLz(int sc,int ec,int l,int r,int indx){
    if(pending[indx]%2){//baki hai to update karo
        tree[indx]=(ec-sc+1)-tree[indx];
        pending[indx]=0;
        if(sc!=ec){
            pending[2*indx+1]++;
            pending[2*indx+2]++;
        }
    }//fir continue:
    if(ec<l || sc>r)return;
    if(sc>=l && ec<=r){//overlap hai toh update node and pass lazy to child
        tree[indx]=(ec-sc+1)-tree[indx];//if not leaf or is a leaf, works for both
        if(sc!=ec){
            pending[2*indx+1]++;
            pending[2*indx+2]++;
        }
        return;
    }
    int mid=(sc+ec)/2;
    updateLz(sc,mid,l,r,indx*2+1);
    updateLz(mid+1,ec,l,r,indx*2+2);
    tree[indx]=tree[indx*2+1]+tree[indx*2+2];
}

int printlz(int sc,int ec,int l,int r,int indx){
    if(pending[indx]%2){//baki hai to update karo
        tree[indx]=(ec-sc+1)-tree[indx];
        pending[indx]=0;
        if(sc!=ec){
            pending[2*indx+1]++;
            pending[2*indx+2]++;
        }
    }//continue:
    if(ec<l || sc>r)return 0;
    if(sc>=l && ec<=r)return tree[indx];
    int mid=(sc+ec)/2;
    int a=printlz(sc,mid,l,r,indx*2+1);
    int b=printlz(mid+1,ec,l,r,indx*2+2);
    return a+b;
}

signed main(){
    FASTER;
    int n,q;cin>>n>>q;
    while(q--){
        int a,b,c;cin>>a>>b>>c;
        if(a==0){
            updateLz(0,n-1,b,c,0);
        }else{
            cout<<printlz(0,n-1,b,c,0)<<"\n";
        }
    }
}
