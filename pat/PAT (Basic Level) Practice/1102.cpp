#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    string s[10005];
    long long num1[10005]={0},num2[10005]={0};
    for(int i=0;i<n;i++){
        cin>>s[i]>>num1[i]>>num2[i];
    }
    int max1=-1,max2=-1;
    string f1="",f2="";
    for(int i=0;i<n;i++){
        if(num2[i]>max1){
            max1=num2[i];
            f1 = s[i];
        }
        if(num1[i]*num2[i]>max2){
            max2=num1[i]*num2[i];
            f2 = s[i];
        }
    }
    cout << f1 << " " << max1 << "\n";
    cout << f2 << " " << max2 << "\n";
}