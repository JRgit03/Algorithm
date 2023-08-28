#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n;
int stk[N];
char op[N];

int main(){
    cin>>n;
    int tt1=0,tt2=0;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        stk[++tt1] = x;
    }    
    for(int i=0;i<n-1;i++){
        char c;cin>>c;
        op[++tt2] = c;
    }
    //cout << tt1 << " " << tt2 << "\n";
    while (tt2>0){
        char c = op[tt2--];
        int b = stk[tt1--] , a = stk[tt1--];
        //cout << c << " ";
        if(c=='+') stk[++tt1] = a+b;
        else if(c=='-')stk[++tt1] = a-b;
        else if(c=='*')stk[++tt1] = a*b;
        else if(c=='/'){
            if(!b){
                printf("ERROR: %d/0\n",a);return 0;
            }else{
                stk[++tt1] = a/b;
            }
        }
        //cout << tt1 << " " <<  stk[tt1] << "\n";
    }   
    printf("%d\n",stk[1]);
    return 0;
}
