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

void ispal(string &s){//ifPal s=s+1, if then 9999->10001
    int n=s.size();
    int l=0,r=n-1;
    while(l<r){
        if(s[l]==s[r]){
            l++;r--;
        }else{
            return;
        }
    }
    if(s[0]=='9'){
        int i=n-1;
        while(s[i]=='9'){
            i--;
        }
        if(i<0){
            string ss(n+1,'0');
            ss[0]='1';
            ss[n]='1';
            s=ss;
        }else{
            s[i]++;
        }
    }else{
        int i=n-1;
        while(s[i]=='9'){
            i--;
        }
        s[i]++;
    }
}

signed main(){
    FASTER;
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        ispal(s);
        int n=s.size();
        int l=0,r=n-1;
        while(l<r){
            if(s[l]-'0'<s[r]-'0'){
                if(s[r-1]!='9')s[r-1]+=1;
                else{
                    int i=r-1;
                    while(s[i]=='9'){
                        s[i]='0';
                        i--;
                    }
                    s[i]+=1;
                }
            }
            s[r]=s[l];
            l++;r--;
        }
        cout<<s<<"\n";
    }
}
