/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-06-11 21:21:15
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-06-11 21:22:15
 * @FilePath: /.leetcode/字符串/ACM模式/例1/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<bits/stdc++.h>
using namespace std;
int mod=13331,k=26;  //利用mod防止数字溢出，k表示在26进制下的哈希值 
string a,b;
int sum=0;
long long a1[100];   //记录a字串的哈希值 
long long b1[100];   //记录b字串的哈希值 
 
//计算前缀的哈希值
long long hash1(string s,int len)  
{
 	long long ans1=0;
	 for(int i=0;i<len;i++){
 	 	ans1=(ans1*k%mod+(s[i]-'0'))%mod;
	 }
	 return ans1;
}
 
//计算后缀的哈希值 
long long hash2(string s,int len,int length) 
{
 	long long ans2=0;
	 for(int i=length-len;i<length;i++)
 	{
 	 	ans2=(ans2*k%mod+(s[i]-'0'))%mod;
	 }
	 return ans2;
}
 
int main()
{
	cin>>a>>b;//string也可以直接用cin读取
	int len1=a.length();
	int len2=b.length();
	//最终答案一定不会超过两字串较小长度的那一个长度 
	int minl=min(len1,len2);
	//sum记录下最终的答案 
    int sum=0;
    //sum1 表示a的前缀与b的后缀最长相等的个数 
    //sum2 表示b的前缀与a的后缀最长相等的个数 
    int sum1=0,sum2=0;  
	//计算a的前缀和b的后缀。
	for(int i=1;i<=minl;i++)
	{
	a1[i]=hash1(a,i);
	b1[i]=hash2(b,i,len2);
	if(a1[i]==b1[i]) sum1=i;
    }
    //计算a的后缀和b的前缀 
    for(int i=1;i<=minl;i++)
	{
	b1[i]=hash1(b,i);
	a1[i]=hash2(a,i,len1);
	if(a1[i]==b1[i]) sum2=i;
    }
    //输出sum1，sum2的最大的那一个 
    sum=max(sum1,sum2);
    cout<<sum<<endl;
}

