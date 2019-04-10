#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

/*
Algorithm:

[1] While there is more input continue to [2] otherwise go to [6]
[2] Scan in the next character
[3] Determine whether it is a bracket, operand, or operator
[4a] If it is an operand, print it to the output
[4b] If it is a left bracket, push onto stack
[4c] If it is a right bracket,
  while( left bracket is not  encountered on the stack  )
         keep popping the stack and printing into the output
Pop the left bracket also from the stack  but doesn't print it.
[4d] If it's an operator - check for precedence if the top of the stack is an operator and it has higher precedence than current operator then pop the stack and print onto output, continue until condition is false. Then push in the current operator into stack.
[5] Go back to [1]
[6] exit

*/
int prio(char c){
    if(c=='+')return 1;
    if(c=='-')return 2;
    if(c=='*')return 3;
    if(c=='/')return 4;
    if(c=='^')return 5;
}

int issym(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')return 1;
    return 0;
}

int main(){
    FASTER;
    int t;cin>>t;
    while(t--){
        stack<char> stk;
        string ans="",s;
        cin>>s;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]==')'){//bracket
                    if(s[i]=='(')stk.push(s[i]);
                    else{
                        while(stk.top()!='('){
                            ans+=stk.top();
                            stk.pop();
                        }
                        stk.pop();
                    }
            }else if(!issym(s[i])){//oprand
                ans+=s[i];
            }else{//operator
                while(prio(stk.top())>s[i]){
                    ans+=stk.top();
                    stk.pop();
                }
                stk.push(s[i]);
            }
        }
        cout<<ans<<"\n";
    }

}
