#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;

int main(){
    int n,m;cin>>n>>m;
    
    vector<string> vec[m+1];
    
    for(int i=1;i<=m;i++){
        int k;cin>>k;
        for(int j=0;j<k;j++){
            string s;cin>>s;
            vec[i].push_back(s);
        }
    }

    string A,B;cin>>A>>B;
    
    map<string,double> mpa,mpb;

    for(int i=1;i<=m;i++){
        bool f1=false,f2=false;
        vector<string> male,female;
        int k = (int)vec[i].size(); double add = 1.0 / k;
        for(int j=0;j<k;j++){
            string x = vec[i][j];
            if(x[0]=='-') female.push_back(x);
            else male.push_back(x);
            if(x==A) f1 = true;
            if(x==B) f2 = true;
        }

        if(f1){
            if(A[0]=='-'){
                for(auto x : male) mpa[x] += add;
            }else{
                for(auto x : female) mpa[x] += add;
            }
        }
        if(f2){
            if(B[0]=='-'){
                for(auto x : male) mpb[x] += add;
            }else{
                for(auto x : female) mpb[x] += add;
            }
        }
    }

    double maxa = -1 , maxb = -1;
    vector<string> v1,v2;

    for(auto [ob , val] : mpa){
        //cout << ob << " " << val << "\n";
        if(val > maxa){
            //cout << val << " " << maxa << " ?" << "\n";
            maxa = val;
            v1.clear();
            v1.push_back(ob);
        }else if(fabs(val - maxa) <= eps){
            v1.push_back(ob);
        }
    }

    for(auto [ob , val] : mpb){
        //cout << ob << " " << val << "\n";
        if(val > maxb){
            //cout << val << " " << maxb << " ?" << "\n";
            maxb = val;
            v2.clear();
            v2.push_back(ob);
        }else if(fabs(val - maxb) <= eps){
            v2.push_back(ob);
        }
    }

    double AB = mpa[B];
    //cout << AB << "\n";

    if((fabs(AB - maxa) <= eps) && (fabs(AB - maxb) <= eps)){
        cout << A << " " << B << "\n";
        return 0;
    }

    if(maxa == -1 && maxb == -1){  //两人未出现在照片内 测试点3坑点
        cout << A << " " << B << "\n";
        return 0;
    }

    sort(v1.begin(),v1.end(),[](const string a,const string b){
        return abs(stoi(a)) < abs(stoi(b));
    });
    for(auto x : v1)
        cout << A << " " << x << "\n";

     sort(v2.begin(),v2.end(),[](const string a,const string b){
        return  abs(stoi(a)) < abs(stoi(b));
    });
    for(auto x : v2)
        cout << B << " " << x << "\n";

    return 0;
}
