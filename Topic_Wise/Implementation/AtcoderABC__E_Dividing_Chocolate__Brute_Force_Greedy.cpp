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

int h,w,k;
int v[11][1001];


int f(int mask){
    int sz=__builtin_popcount(mask)+1;
    vi vv[sz];
    for(int i=0;i<sz;i++)vv[i]=vi(w,0);
    for(int i=0;i<w;i++)vv[0][i]=v[0][i];
    
    int kk=0;
    for(int i=0;i<(h-1);i++){
        if((mask&(1LL<<i))==0){
            for(int ii=0;ii<w;ii++)vv[kk][ii]+=v[i+1][ii];
        }else{
            kk++;
            for(int ii=0;ii<w;ii++)vv[kk][ii]+=v[i+1][ii];
        }
    }

    int cuts=sz-1;
    int sum[sz]={0};
    for(int i=0;i<w;i++){
        int flg=0;
        for(int j=0;j<sz;j++){
            //sum[j]=(j?sum[j-1]:0)+vv[j][i];
            //cout<<j<<" "<<i<<" "<<sum[j]<<" "<<vv[j][i]<<"\n";
            sum[j]+=vv[j][i];
            if(sum[j]>k){
                flg=1;
            }
        }
        for(int j=0;j<sz && flg;j++){
            sum[j]=vv[j][i];
            if(sum[j]>k)return INF;
            
        }
        cuts+=flg;
    }
    
//    for(int i=0;i<sz;i++){
//        for(int j=0;j<w;j++){
//            cout<<vv[i][j]<<" ";
//        }
//        cout<<"\n";
//    }
//    cout<<cuts<<"\n\n\n";
    
    return cuts;
}

signed main(){
    //FASTER;
    cin>>h>>w>>k;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            char c;cin>>c;
            v[i][j]=(c=='1');
        }
    }
    int ans=INF;
    for(int i=0;i<(1LL<<(h-1));i++){//
        ans=min(ans,f(i));
    }
    cout<<ans;
}
