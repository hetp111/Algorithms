#include <bits/stdc++.h>
using namespace std;

//https://www.hackerrank.com/challenges/identify-smith-numbers/problem
//https://hack.codingblocks.com/contests/c/473/1103
//https://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/
int sum2(int n){
    int sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}

int sum1(int n){
    int nn=n,sum=0;
    for(int i=2;i<=sqrt(nn);i++){
        while(n%i==0){
            //cout<<n<<" "<<i<<"\n";
            sum+=sum2(i);
            n=n/i;
        }
    }
    if(n!=1)sum+=sum2(n);//n is prime? ;)
    return sum;
}

int main(){
    int n;cin>>n;
    int a=sum1(n);//sum of factor
    int b=sum2(n);//sum of digits
    if(a==b){//no need to check if n is prime
        cout<<1;
    }else{
        cout<<0;
    }
}
//https://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/
/*
#include <bits/stdc++.h>
using namespace std;

int sum2(int n){
    int sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}

int sum1(int n){
    // Print the number of 2s that divide n
    int sum=0,nn=n;
    while (n%2 == 0)
    {
        sum+=2;
        n=n/2;
    }

    // n must be odd at this point.  So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <sqrt(nn); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            sum+=sum2(i);
            n = n/i;
        }
    }
    if(n!=1)sum+=sum2(n);
    return sum;
}

int main(){
    int n;cin>>n;
    int a=sum1(n);//sum of factor
    int b=sum2(n);//sum of digits
    if(a==b){//no need to check if n is prime
        cout<<1;
    }else{
        cout<<0;
    }
}
*/
