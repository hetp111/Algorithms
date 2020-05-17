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
#define MOD2 (998244353)
#define MOD3 (1000000009)
#define PI acos(-1)
#define eps (1e-8)
#define INF (1e18)
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0)
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
ifstream cinn("input.txt");ofstream coutt("output.txt");

string s;
int n;
pii has[1000000];
vi chk;

int eleven[1000001][2];
int three[1000001][2];
int five[1000001][2];
int seven[1000001][2];

pii gimme(int l,int r){
    if(l==0)return has[r];
    
    int h=(has[r].first-(has[l-1].first*three[r-l+1][0])%MOD+MOD)%MOD;
    h=(h*seven[l][1])%MOD;
    
    int h1=(has[r].second-(has[l-1].second*five[r-l+1][0])%MOD2+MOD2)%MOD2;
    h1=(h1*eleven[l][1])%MOD2;
    
    return {h,h1};
}

bool f(int mid){
    int s=1,e=n-2;
    if(s>e)return 0;
    pii hhh=has[chk[mid]];
    for(int i=s;i+(chk[mid]+1)-1<=e;i++){
        if(hhh==gimme(i,i+(chk[mid]+1)-1)){
            return 1;
        }
    }
    return 0;
}

int poww(int a,int b,int m){
    if(b==0)return 1;
    int x=poww(a,b/2,m);
    x=(x*x)%m;
    if(b&1)x=(x*a)%m;
    return x;
}

signed main(){
    FASTER;
    
    three[0][0]=seven[0][0]=eleven[0][0]=five[0][0]=1;
    three[0][1]=seven[0][1]=eleven[0][1]=five[0][1]=1;
    
    int i3=poww(3,MOD-2,MOD),i7=poww(7,MOD-2,MOD),i5=poww(5,MOD2-2,MOD2),i11=poww(11,MOD2-2,MOD2);
    
    for(int i=1;i<=1e6;i++){
        three[i][0]=three[i-1][0]*3%MOD;
        seven[i][0]=seven[i-1][0]*7%MOD;
        five[i][0]=five[i-1][0]*5%MOD2;
        eleven[i][0]=eleven[i-1][0]*11%MOD2;
        
        three[i][1]=three[i-1][1]*i3%MOD;
        seven[i][1]=seven[i-1][1]*i7%MOD;
        five[i][1]=five[i-1][1]*i5%MOD2;
        eleven[i][1]=eleven[i-1][1]*i11%MOD2;
    }
    
    
    cin>>s;
    n=s.size();
    int le1=0,le2=0;
    for(int i=0;i<n;i++){
        int c=s[i]-'a'+1;
        le1=((le1*3)%MOD + (c*seven[i][0])%MOD)%MOD;
        le2=((le2*5)%MOD2 + (c*eleven[i][0])%MOD2)%MOD2;
        has[i]={le1,le2};
    }
    
    for(int i=0;i<n-1;i++){
        if(gimme(0,i)==gimme(n-i-1,n-1)){
            chk.push_back(i);
        }
    }
    
    int s=0,e=(int)chk.size()-1,ans=-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(f(mid)){
            s=mid+1;
            ans=chk[mid]+1;
        }else e=mid-1;
    }
    
    if(ans!=-1)cout<<::s.substr(0,ans);
    else cout<<"Just a legend";
}