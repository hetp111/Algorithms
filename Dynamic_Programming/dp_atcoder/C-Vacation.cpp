#include <bits/stdc++.h>
using namespace std;
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;

int main(){
    int n;
    cin>>n;
    int a[n][3];
    int dp[n][3];
    for(int i=0;i<n;i++)for(int j=0;j<3;j++)cin>>a[i][j];

    dp[0][0]=a[0][0];
    dp[0][1]=a[0][1];
    dp[0][2]=a[0][2];

    for(int i=1;i<n;i++){
        dp[i][0]=a[i][0]+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=a[i][1]+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=a[i][2]+max(dp[i-1][1],dp[i-1][0]);
    }
    cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
}
