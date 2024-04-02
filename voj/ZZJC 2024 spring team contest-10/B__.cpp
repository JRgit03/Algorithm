#include <iostream>
using namespace std;
int a[80000+10][8];//这么大是为了存1到8的结果
int main()
{
  a[0][0]=1;
  int s=0;        //当前i的开始位置，此时i为1
  int end=0;      //当前i的结尾位置
  int n;
  cin>>n;
  for(int i=2;i<=n;i++)
  {
    int len=end;
    for(int j=s;j<=end;j++)
    {
      if((j-s)%2)//对应样例里面的从左插入
      {
        for(int t=0;t<i;t++)
        {
          len+=1;
          for(int k=0;k<t;k++)
            a[len][k]=a[j][k];
          a[len][t]=i;
          for(int k=t+1;k<i;k++)
            a[len][k]=a[j][k-1];
        }
      }
      else//对应从右插入
      {
        for(int t=i-1;t>=0;t--)
        {
          len+=1;
          for(int k=0;k<t;k++)
            a[len][k]=a[j][k];
          a[len][t]=i;
          for(int k=t+1;k<i;k++)
            a[len][k]=a[j][k-1];
        }
      }
    }
    s=end+1;//更新当前i的开始与结尾
    end=len;
  }
  for(int i=s;i<=end;i++)//输出答案
  {
    for(int j=0;j<n-1;j++)
    {
      cout<<a[i][j]<<" ";
    }
    cout<<a[i][n-1]<<endl;
  }
}