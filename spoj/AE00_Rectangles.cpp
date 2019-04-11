#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

//O(n*sqrt(n))

int f(int n){
    int cnt=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0)cnt++;
    }
    return cnt;
}

int main(){
    FASTER;
    int n,cur=1,lst=1;cin>>n;
    for(int i=2;i<=n;i++){
        cur=lst+f(i);
        lst=cur;
    }
    cout<<cur;
}


/*
O(sqrt(n))

https://codegeeksblog.wordpress.com/2013/06/01/spoj-ae00-rectangles/
https://oeis.org/A094820

int main()
{
    int n,i,ans=0;
    scanf("%d",&n);
    for(i=1;i<=((int)sqrt(n));i++)
        ans+=(n/i-i+1);
    printf("%d",ans);
    return 0;
}

*/
