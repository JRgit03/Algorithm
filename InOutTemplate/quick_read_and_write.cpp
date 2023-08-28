#include<bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}

void print(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10^48);
}

int cnt[510];

int main(){
	int n = read();
	for(int i=0;i<n;i++){
		int x = read();
		cnt[x]++;
	}
	for(int i=0;i<=500;i++){
		if(cnt[i])print(i),printf(" "),print(cnt[i]),printf("\n");
	}
	return 0;
}