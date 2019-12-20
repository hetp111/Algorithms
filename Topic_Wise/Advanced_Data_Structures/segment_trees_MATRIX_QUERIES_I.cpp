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

int r;

class matrix{
private:
    vector<vector<int>> v;
public:
    matrix(){
        vector<vector<int>> vv(2,vector<int>(2,0));v=vv;
    }
    void I(){
        for(int i=0;i<2;i++)v[i][i]=1;
    }
    void coutt(){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                cout<<v[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    void cinn(){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                cin>>v[i][j];
            }
        }
    }
    matrix operator*(const matrix &b){
        matrix c;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++)c.v[i][j]+=v[i][k]*b.v[k][j];
                c.v[i][j]=c.v[i][j]%r;
            }
        }
        return c;
    }
};

matrix IDENTITYMATRIX;

void makeTree(int s,int e,int indx,const vector<matrix> &v,vector<matrix> &tree){
    if(s==e){
        tree[indx]=v[e];
        return;
    }
    int mid=(s+e)/2;
    makeTree(s,mid,indx*2+1,v,tree);
    makeTree(mid+1,e,indx*2+2,v,tree);
    tree[indx]=tree[indx*2+1]*tree[indx*2+2];
    return;
}

matrix qqq(int s,int e,int SS,int EE,int indx,const vector<matrix> &tree){
    if(s<=SS && e>=EE){
        return tree[indx];
    }
    if(s>EE || e<SS)return IDENTITYMATRIX;

    int mid=(SS+EE)/2;
    matrix Lft = qqq(s,e,SS,mid,indx*2+1,tree);
    matrix rig = qqq(s,e,mid+1,EE,indx*2+2,tree);
    return Lft*rig;
}

signed main(){
    FASTER;
    IDENTITYMATRIX.I();
    int n,q;cin>>r>>n>>q;
    vector<matrix> v(n),tree(4*n);
    for(int t=0;t<n;t++){
        matrix m;m.cinn();
        v[t]=m;
    }

    makeTree(0,n-1,0,v,tree);

    while(q--){
        int l,r;cin>>l>>r;l--;r--;
        qqq(l,r,0,n-1,0,tree).coutt();
    }

}
