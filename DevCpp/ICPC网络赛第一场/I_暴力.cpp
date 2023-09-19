#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10 , Mod = 998244353;
int n;
string s;
int f[N][70][2][2][2]; // f[i,j,s1,s2,s3] 前i-1个字符考虑完成且第i个字符为j 大写-小写-数字


// num 0 ~ 9 upper 10 ~ 35 lower 36 ~ 61
int get(char c){
	if(c >= '0' && c <= '9') return int(c - '0');
	if(c >= 'A' && c <= 'Z') return int(c - 'A' + 10);
	if(c >= 'a' && c <= 'z') return int(c - 'a' + 36);
	return -1; 	
}

void init(){
	char c = s[1]; int j = get(c);
	if(c >= '0' && c <= '9') {
		f[1][j][0][0][1] = 1;
	}else if(c >= 'A' && c <= 'Z') {
		f[1][j][1][0][0] = 1;
	}else if(c >= 'a' && c <= 'z') {
		f[1][j][0][1][0] = f[1][j-26][1][0][0] = 1;
	}else{
		for(int j=0;j<=61;j++) f[1][j][j>=10&&j<=35][j>=36&&j<=61][j>=0&&j<=9] = 1;
	}
}

int main(){
	cin>>n>>s; s = "?" + s;
	init();
	for(int i=2;i<=n;i++){
		char c = s[i]; int cur = get(c);
		if(c >= '0' && c <= '9') { // 数字
			for(int j=0;j<=61;j++){
				for(int s1=0;s1<=1;s1++){
					for(int s2=0;s2<=1;s2++){
						for(int s3=0;s3<=1;s3++){
							if(cur != j){
								f[i][cur][s1][s2][s3|1] += f[i-1][j][s1][s2][s3];
							}
						}
					}
				}
			}
		}else if(c >= 'A' && c <= 'Z') { // 大写字母
			for(int j=0;j<=61;j++){
				for(int s1=0;s1<=1;s1++){
					for(int s2=0;s2<=1;s2++){
						for(int s3=0;s3<=1;s3++){
							if(cur != j){
								f[i][cur][s1|1][s2][s3] += f[i-1][j][s1][s2][s3];
							}
						}
					}
				}
			}
		}else if(c >= 'a' && c <= 'z') { // 小写字母
			for(int j=0;j<=61;j++){
				for(int s1=0;s1<=1;s1++){
					for(int s2=0;s2<=1;s2++){
						for(int s3=0;s3<=1;s3++){
							if(cur != j){
								f[i][cur][s1][s2|1][s3] += f[i-1][j][s1][s2][s3];
							}
						}
					}
				}
			}
			c = toupper(c); cur = get(c);
			for(int j=0;j<=61;j++){
				for(int s1=0;s1<=1;s1++){
					for(int s2=0;s2<=1;s2++){
						for(int s3=0;s3<=1;s3++){
							if(cur != j){
								f[i][cur][s1|1][s2][s3] += f[i-1][j][s1][s2][s3];
							}
						}
					}
				}
			}
		}else { // ?
			for(int cur=0;cur<=61;cur++){ //当前
				for(int j=0;j<=61;j++){ //上一个
					for(int s1=0;s1<=1;s1++){
						for(int s2=0;s2<=1;s2++){
							for(int s3=0;s3<=1;s3++){
								if(cur != j){
									f[i][cur][s1|(cur>=10&&c<=35)][s2|(cur>=36&&cur<=61)][s3|(cur>=0&&cur<=9)] += f[i-1][j][s1][s2][s3];
								}
								//f[i][cur][s1|(cur>=10&&c<=35)][s2|(cur>=36&&cur<=61)][s3|(cur>=0&&cur<=9)] += f[i-1][j][s1][s2][s3];
							}
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for(int j=0;j<=61;j++) ans += f[n][j][1][1][1];
	cout << ans << "\n";
	return 0;
}
