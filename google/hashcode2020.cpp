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
ifstream cinn("input.txt");ofstream coutt("output.txt");


struct library{
    int N,T,M,indx;
    vi ids;
};

int B,L,D;
int score[100005];
library lib[100005];

signed main(){
    FASTER;
    cinn>>B>>L>>D;
    for(int i=0;i<B;i++)cinn>>score[i];
    
    for(int i=0;i<L;i++){
        cinn>>lib[i].N>>lib[i].T>>lib[i].M;
        lib[i].ids=vi(lib[i].N);
        lib[i].indx=i;
        for(int j=0;j<lib[i].N;j++){
            cinn>>lib[i].ids[j];
        }
        sort(all(lib[i].ids),[](const int &a,const int &b){
                return score[a]>score[b];
        });
    }
    
    sort(lib,lib+L,[](const library &a,const library &b){
         return a.T*b.M*b.N<b.T*a.M*a.N;
    });
    
    vii libsTaken;
    int i=0,days=0,DD=D;
    while(DD-lib[i].T>=0 && i<L){
        DD-=lib[i].T;
        days+=lib[i].T;
        libsTaken.push_back({i,days});
        i++;
    }
    
    //int ans=0;
    i=0;for(i=0;i<libsTaken.size() && libsTaken[i].second<=D;i++);
    
    coutt<<i<<"\n";
    for(i=0;i<libsTaken.size() && libsTaken[i].second<=D;i++){
        int kitne=min((D-libsTaken[i].second)*lib[libsTaken[i].first].M,lib[libsTaken[i].first].N);
        coutt<<lib[libsTaken[i].first].indx<<" "<<kitne<<"\n";
        for(int j=0;j<kitne;j++){
            coutt<<lib[libsTaken[i].first].ids[j]<<" ";
            //ans+=score[lib[libsTaken[i].first].ids[j]];
        }
        coutt<<"\n";
    }
    
}
