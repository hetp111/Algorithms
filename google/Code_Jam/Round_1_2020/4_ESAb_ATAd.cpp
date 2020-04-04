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

string ans;
int i,j,r,c,d;
char l;

void complement(string& s){
    for(int i=0;i<s.size();i++){
        if(s[i]=='0')s[i]='1';
        else s[i]='0';
    }
}


void doo(){
    cout<<j+1<<endl;cin>>ans[j];
    cout<<d-j<<endl;cin>>ans[d-1-j];
    if(ans[j]==ans[d-1-j])c=j;
    else r=j;
    j++;
}

void doo2(){
    if(c!=-1){
        cout << c+1 << endl;
        cin >> l;
        if(ans[c]!=l)complement(ans);
    }
    else{
        cout <<1<<endl;
        cin>>l;
    }
    if(r!=-1){
        cout << r+1 << endl;
        cin >> l;
        if(ans[r]!=l)reverse(all(ans));
    }
    else{
        cout <<1<<endl;
        cin>>l;
    }
}

signed main(){
    FASTER;
    int t;cin>>t>>d;
    for(int T=0;T<t;T++){
        
        ans=string(d,'X');
        for(i=1,j=0,r=-1,c=-1;j<d/2;i+=2){
            if(i>10 && i%10==1){
                doo2();
            }
            else{
                doo();
            }
        }
        cout<<ans<<endl;
        char fine;cin>>fine;
        if(fine=='N'){
            exit(0);
        }
    }
}
