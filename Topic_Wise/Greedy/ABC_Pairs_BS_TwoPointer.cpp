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

int n,k,zero,P,N;
vi pos,neg;

int nolesstheneq(int xy){
    int cnt=0;
    if(xy>0){
        //x>0
        for(int x:pos){
            //y>0
            int s=0,e=P-1,ans=-1;
            while(s<=e){
                int mid=(s+e)/2;
                if(x*pos[mid]>xy){
                    e=mid-1;
                }else{
                    s=mid+1;
                    ans=mid;
                }
            }
            if(ans!=-1)cnt+=ans+1-(x*x<=xy);
        }
        
        reverse(all(neg));
        //x<0
        for(int x:neg){
            //y<0
            
            int s=0,e=N-1,ans=-1;
            
            while(s<=e){
                int mid=(s+e)/2;
                if(x*neg[mid]>xy){
                    e=mid-1;
                }else{
                    s=mid+1;
                    ans=mid;
                }
            }
            if(ans!=-1)cnt+=ans+1-(x*x<=xy);
            
        }
        reverse(all(neg));
        
        cnt+=(zero*(zero-1)/2+N*P+(N+P)*zero)*2;
        
    }else if(xy<0){
        
        //x>0
        for(int x:pos){
            //y<0
            int s=0,e=N-1,ans=-1;
            while(s<=e){
                int mid=(s+e)/2;
                if(x*neg[mid]>xy){
                    e=mid-1;
                }else{
                    s=mid+1;
                    ans=mid;
                }
            }
            if(ans!=-1)cnt+=ans+1;
        }
        
        reverse(all(pos));
        //x<0
        for(int x:neg){
            //y>0
            int s=0,e=P-1,ans=-1;
            while(s<=e){
                int mid=(s+e)/2;
                if(x*pos[mid]>xy){
                    e=mid-1;
                }else{
                    s=mid+1;
                    ans=mid;
                }
            }
            if(ans!=-1)cnt+=ans+1;
        }
        reverse(all(pos));
    }else{
        cnt+=(P*N+zero*(P+N)+zero*(zero-1)/2)*2;
    }
    
    return cnt/2;
}

signed main(){
    FASTER;
    cin>>n>>k;
    while(n--){
        int in;cin>>in;
        if(in>0){
            pos.push_back(in);
        }else if(in<0){
            neg.push_back(in);
        }else zero++;
    }
    
    sort(all(pos));
    sort(all(neg));
    
    P=pos.size(),N=neg.size();
    
    int s=-INF,e=INF,ans;
    while(s<=e){
        int mid=(s+e)/2;
        if(nolesstheneq(mid)<k){
            s=mid+1;
            ans=mid+1;
        }else{
            e=mid-1;
        }
    }
    cout<<ans;
}
