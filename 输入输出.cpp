/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-14 15:00:27
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-09-05 21:00:13
 * @FilePath: /.leetcode/输入输出.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include <vector>
#include<queue>
using namespace std;

int main(){
    //输入
    int n;
    cin>>n;
    vector<int> nums(n),ans(n);
    for(int i = 0; i < n; i++){
        int num;
        cin>>num;//cin>> 遇到（空格、回车）等不可见字符，一次读取结束，下次从这些字符后开始读
        nums[i] = num;
    }
    //输出ans
    int j = 0;
    for (; j < n - 1; ++j){
        cout << ans[j] << " ";
    }
    cout << ans[n - 1] << endl;
    return 0;
}
#include<stdio.h>

int main(){
    //方式是读一行——>处理——>输出，循环进行，当读函数读取EOF跳出
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF){
            int t=0;
        for(int i=m; i<=n; i++){
            int a=i/100;
            int b=i%100/10;
            int c=i%10;
            
            if(i==a*a*a+b*b*b+c*c*c && t==0){
                printf("%d ",i);
                t++;
            }
            else if(i==a*a*a+b*b*b+c*c*c && t==1){
                printf("%d ",i);
            }
        }
        if(t!=0){ printf("\n"); }
        if(t==0){ printf("no\n"); }
    }
    return 0;
}


int a;//读入一行数据，数据用逗号隔开，对每个数据做响应操作
while(cin>>a){
    cout << a; // OR vec.push_back(a);
    cin.get(); //读取掉数据之间的逗号，get()一次获取一个字符
}

//当读到逗号需要操作：
while(cin>>a){
	//对数据操作。如：cout<<a;
	if(cin.get()==','){
		//操作
	}
}

//读取字符串
string raw_data("3, 4, 5, 76"), tmp;
vector<string> data;
stringstream input(raw_data);//定义一个字符串流绑定到源string
//用getline识别标志符，读取一段数据
while (getline(input, tmp, ',')){
    data.push_back(tmp);
} 





//万能头文件
#include <bits/stdc++.h>


//cin>>使用
/*
1.每句cin从目前流中第一个有效字符开始读，遇到," "、"\n"停止；
2.已经读取过的内容从流中消失
3.cin.get();消除流中不想用的字符
4.第一行为string，第二行为int：
    string str;
    int n;
    cin>>str>>n;
*/
// getline使用(常用读取整行)
/*
 istream& getline ( istream &is , string &str , char delim );
    在流中读取内容，遇到delim停止；无第三参数，默认"\n"

1、当getline与whlie一起使用的时候，即while(getline(cin,str))是一个死循环，只有当按Ctrl+z或键入EOF才会结束。
2、当使用getline的时候，如果前面用cin输入东西，则必须输入cin.get()吃掉回车符"\n"
        string str,s[100];int n;int i=0;
        cin >> n;cin.get();
        for(int i = 0; i < n; i++){
            getline(cin,str);
            s[i] = str;
        }
3.循环读：读一行——>处理——>输出一行
    string str;
    while (getline(cin, str)){
        cout << String_Sorting(str) << endl;
    }
4.输入为多行一组类型
    while(scanf("%lld.%lld.%lld.%lld",&a,&b,&c,&d)!=EOF){    while条件中为读每组第一行的语句，循环体中来读接下来的行
        cin>>num;
        //....
        cout<<a<<"."<<b<<"."<<c<<"."<<d<<endl;
    }
 */

//cout<<使用
/*
1.可直接输出一个字符串：cout<<str<<endl;
*/
//读取一行空格隔开的数字
/*
input： 3 2 5 4 6 5 8 7
        8
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> nums;
    int x，y;
    while (ss >> x)
        nums.push_back(x);

    cin>>y;
*/