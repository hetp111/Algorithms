//Carefully crafted by hetp111
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

//https://www.spoj.com/problems/ACODE/

signed main(){
    FASTER;
    string s;cin>>s;
    int dp[100000];
    while(s!="0"){
        int n=s.size();
        dp[0]=1;
        for(int i=1;i<n;i++){
            int numm=((s[i-1]-'0')*10+(s[i]-'0'));
            if(numm>=10 && numm<=26 && s[i]!='0'){
                if(i-2>=0)
                dp[i]=dp[i-1]+dp[i-2];
                else dp[i]=2;
            }else{
                dp[i]=dp[i-1];
            }
            if(s[i]=='0'){
                if(i-2>0)
                dp[i]=dp[i-2];
                else dp[i]=1;
            }
        }
        cout<<dp[n-1]<<"\n";
        cin>>s;
    }
}
