/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-26 19:25:33
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-10-14 14:52:24
 * @FilePath: /.leetcode/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AEn
 */
// #include<iostream>
// #include<string>
// #include<unordered_map>
// #include<unordered_set>
// #include <algorithm>

// #include <cctype>

// using namespace std;

// int main(){
//     int nums = 0;
//     cin >> nums;
//     unordered_set<string> hset;
//     unordered_map<string, int> hmap;
//     int k = nums;
//     while(k--){
//         hset.clear();
//         hmap.clear();
//         int ret = 0;
//         int count1 = 0, count2 = 0;
//         cin >> count1;
//         string str1="",str2="";
//         while (getline(cin,str1,' ')){
//             transform(str1.begin(),str1.end(),str1.begin(),::tolower);
//             hmap[str1]++;
//         }
//         cin >> count2;
//         while(getline(cin,str2,' ')){
//             transform(str2.begin(),str2.end(),str2.begin(),::tolower);
//             hset.insert(str2);
//         }
//         bool help(string &str1,string &str2){
//             if(str1==str2)return 
//         }
//         for(auto& p:hmap){
//             for(auto& hs:hset){
//                 int n = p.first.size();
//                 if (n== hs.size()){
//                     int i = 0;
//                     while(i<n){
//                         if(p.first[i]==hs[i]||hs[i]=='?'){
//                             ++i;
//                         }else break;
//                     }
//                     if(i==n){
//                         p.second = 0;
//                     }
//                 }
//             }
//             ret = max(ret, p.second);
//         }
//         cout << ret << endl;
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// #include<iostream>
// #include<vector>
// using namespace std;

// vector<int> nums, v = {2, 3, 5,7, 11, 13, 17, 19, 23, 29, 31, 37};
// void help(vector<int>&nums,vector<int>&v,int end){
//     for (int i = 0; i <end;++i){   
//         for (int j = 0; j <end; ++j){
//             for (int k = 0; k <end; ++k){
//                 int n1 = v[i],n2 = v[j], n3 = v[k];
//                 nums.push_back(n1 * n1 + n2 * n2 * n2 + n3 * n3 * n3 * n3);
//             }
//         }
//     }
// }

// int main(){
//     int n, tmp;
//     cin >> n;
//     vector<int> vmp;
//     while (n--){
//         cin >> tmp;
//         vmp.push_back(tmp);
//     }
    
//     sort(vmp.begin(), vmp.end());
//     auto itt=lower_bound(v.begin(), v.end(),sqrt(sqrt(vmp[vmp.size() - 1])));
//     help(nums, v, (int)(itt - v.begin())+1);
//     sort(nums.begin(), nums.end());

//     for(auto&t:vmp){
//         auto it = lower_bound(nums.begin(), nums.end(), t);
//         if(*it==t){
//             cout << (int)(it-nums.begin())+1 << endl;
//         }else{
//             cout << (int)(it-nums.begin()) << endl;
//         }  
//     }
//     return 0;
// }

// #include"stdio.h"
// #define MUL(a, b) a *b;

// using namespace std;

// int array_size(int a[10]){
//     return sizeof(a) / sizeof(a[0]);
// }

// int main()
// {
//     char x = 254;
//     printf("%d\n", x);

//     int sum = 0;
//     sum = MUL(1 + 1, 2 * 2) + MUL(3 + 3, 2 + 2);

//     printf("%d\n",sum);

//     printf("%d\n",25/4*3);
//     int a[10];
//     printf("%d\n",array_size(a));
//     return 0;
// }
// #include <stdio.h>
// #include <string.h>
// #include<iostream>
// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <arpa/inet.h>
// #include <stdio.h>
// #include <unistd.h>
// #include <errno.h>
// #include <fcntl.h>
// #include <stdlib.h>
// #include <cassert>
// //#include <sys/epoll.h>
// using namespace std;

// int main ()
// {
//    int len;
//    char* text = "POST /xmweb?host=mail.itcast.cn&_t=1542884567319\0 HTTP/1.1";
//    char *m_url;
//    m_url = strpbrk(text, " \t");
//    //cout << *m_url << endl;
//    *m_url++ ;
//    text = "POST\0/xmweb?host=mail.itcast.cn&_t=1542884567319 HTTP/1.1";
//    //cout << *m_url << endl;
//    //cout << text << endl;
//    char *method = text;
//    //cout << method << endl;
//    if (strcasecmp(method, "POST") == 0){
//     printf("%s\n", method);
//    }
//    //printf("%s\n", method);
//    m_url += strspn(m_url, " \t");
//    char *m_version = 0;
//    m_version = strpbrk(m_url, " \t");
//    *m_version++ ;
//    text = "POST\0/xmweb?host=mail.itcast.cn&_t=1542884567319 HTTP/1.1   ";
//    m_version += strspn(m_version, " \t");
//    //cout << m_version << endl;
//    m_url = "POST";
//    strcat(m_url, "judge.html");
//    cout<<m_url<<endl;
//    // len = strspn(str1, str2);

//    //printf("初始段匹配长度 %d\n", len );
   
//    return(0);
// }

// #include<iostream>

// using namespace std;
// int MaxZhishu(int n){
//     int x = 2,ret=0;
//     while(n){
//         if(n%x){
//             ++x;
//         }else{
//             ret = n;
//             n /= x;
//             if(n==1){
//                 return ret;
//             }
//         }
//     }
//     return 0;
// }
// int main(){
//    int n = 45;
//    cout << MaxZhishu(n) << endl;
//    return 0;
// }

// #include <iostream>
// #include<vector>
// #include<string>

// using namespace std;

// void calNext(const string &needle, vector<int> &next) {
//         for (int j = 1, t = -1; j < needle.length(); ++j) { 
//             //j对应后缀,t对应前缀
//             //t是一个前缀和
//             while (t > -1 && needle[t+1] != needle[j]) {
//                 t = next[t]; // 如果下一位不同，往前回溯 
//             }
//             if (needle[t+1] == needle[j]) {
//                 ++t; //如果下一位相同，更新相同的最大前后缀长
//             }
//             next[j] = t;//处理初始边界 
//         }
//     }

//     int main(){
//         string s = "aabaaf";
//         vector<int> v(s.size(), -1);
//         calNext(s, v);
//         for(char&c:s){
//             cout << c << " ";
//         }
//         cout << endl;
//         for (auto &i : v){
//             cout << i << " ";
//         }
//         cout<< endl;
//         return 0;
//     }
#include<iostream>

using namespace std;

// class CBase{
// public:
//     CBase() { cout << "This is CBaseconstruction" << endl; }
//     ~CBase() { cout << "This is CBasedestruction" << endl; }
//     virtual void f1()
//     {
//         cout << "f1 function of CBase" << endl;
//     }
//     void f2(){
//         cout << "f2 function of CBase" << endl;
//     }
// };

// class CSub:public CBase{
// public:
//     CSub() { cout << "This is CSub construction" << endl; }
//     ~CSub() {cout << "This is CSub destruction" << endl; }
//     virtual void f1(){
//         cout << "f1 function of CSub" << endl;
//     }
//     void f2(){
//         cout << "f2 function of CSub" << endl;
//     }
// };
// int main(){
//     CBase *p1 = new CBase;
//     CBase *p2 = new CSub;
//     CSub obj1;
//     p2->f1();
//     p2->f2();
//     delete p1;
//     delete p2;
//     cout << "end" << endl;
//     return 0;
// }
// char *c[]= {"ENTER", "NEW","POINT", "FIRST"};
// char **cp[] = {c + 3, c + 2, c+ 1,c};
// char ***cpp = cp;
// int main(void){
// printf("%s",**++cpp);
// printf("%s",*--*++cpp+3);
// printf("%s",*cpp[-2]+3);
// printf("%s\n",cpp[-1][-1]+1);
// return 0;}

// string getText(vector<string>& texts) {
//     int n = texts.size()/3;
// 	int last = texts.size() - n * 3;
	
// 	string res;
	
// 	for(int i=0; i<n; i++){
// 		string str[3] = {texts[i], texts[i+1], texts[i+2]};
// 		while(true){
// 			int total_len = str[0].length()/3 + str[1].length()/3 + str[2].length()/3;
// 			if(total_len > M){  // 超出
// 				int max_id = 0;
// 				if(str[1].length() > str[max_id].length()) max_id = 1;
// 				if(str[2].length() > str[max_id].length()) max_id = 2;
// 				str[max_id] = str[max_id].substr(0, str[max_id].length()-3);
// 			}
// 			else break;
// 		}
// 		res = str[0] + " " + str[1] + " " + str[2] + ";";
// 	}
	
// 	//cout << "111" << endl;
// 	if(last != 0){
// 		vector<string> str(last);
// 		while(true){
// 			//cout << "last = " << last << endl;
// 			int total_len = 0;
// 			for(int i=0; i<last; i++){
// 				//cout << texts[n * 3 + i].length() << endl;
// 				total_len += texts[n * 3 + i].length()/3;
// 				str[i] = texts[n * 3 + i];	
// 				//cout << "total_len:" << total_len << endl;		
// 			}
			
// 			if(total_len > M){
// 				int max_id = 0;
// 				for(int i=1; i<last; i++){
// 					if(str[i].length() > str[max_id].length()) max_id = i;
// 				}
// 				str[max_id] = str[max_id].substr(0, str[max_id].length()-3);
// 			}
// 			else break;
// 		}
// 		for(int i=0; i<last; i++){
//             if(i==last-1){
//                 res += (str[i]);
//             }else{
//                 res += (str[i]+" ");
//             }
			     
// 		}
// 	}
//     return res;
// }


// #include<iostream>

// using namespace std;

// union myun  
// {  
//      struct { int x; int y; int z; }u;  
//      int k;  
// }a;  
// int main()  
// {  
//      a.u.x =4;  
//      a.u.y =5;  
//      a.u.z =6;  
//      a.k = 0;  
//      printf("%d %d %d\n",a.u.x,a.u.y,a.u.z);  
//      return 0;  
// }
#include<stdio.h>
 
//联合体
union u1  
{
    char a;   
    int b;
    short c;
}U2;
 
//主函数
int main(){
    U2.a='a';
    printf("%d%c\n",U2.b,U2.c);//输出aa
    U2.a='b';
    printf("%c%c\n",U2.b,U2.c);//输出bb
    // U2.b=0x4241;
    U2.b=8;
    printf("%d%d\n",U2.a,U2.c);//输出AA
    return 0;
}

