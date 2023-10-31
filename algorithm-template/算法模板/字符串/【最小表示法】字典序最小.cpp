#include <bits/stdc++.h>
using namespace std;

int n;
string s;

// 返回字符串最小表示法的起始位置
int getmin(){
    int i=0,j=1,k=0,t;
    while(i<n&&j<n&&k<n){
        t=s[(i+k)%n]-s[(j+k)%n];
        if(!t)k++;
        else{
            if(t>0)i+=k+1;
            else j+=k+1;
            if(i==j)j++;
            k=0;
        }
    }
    return i<j?i:j;
}

int main(){
    cin>>s; n = s.length();
    cout << getmin() << "\n";
}