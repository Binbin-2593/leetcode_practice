/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-06-11 21:25:55
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-06-11 22:03:26
 * @FilePath: /.leetcode/字符串/ACM模式/例2/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <algorithm>
#include<string>

using namespace std;

typedef unsigned long long ULL;

const int N = 100010, P = 131;

int n, m;
//char str[N];
string str(N);

ULL h[N], p[N];

ULL get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
    // scanf("%d%d", &n, &m);
    cin >> n >> m;
    //scanf("%s", str + 1);
    cin >> str;

    p[0] = 1;
    for (int i = 1; i <= n; i ++ ){
        h[i] = h[i - 1] * P + str[i-1];
        p[i] = p[i - 1] * P;
    }

    while (m -- ){
        int l1, r1, l2, r2;
        // scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        cin >> l1 >> r1 >> l2 >> r2;

        // if (get(l1, r1) == get(l2, r2)) puts("Yes");
        // else puts("No");
        if(get(l1, r1)==get(l2,r2)){
            cout << "Yes"<<endl;
        }else{
            cout << "No"<<endl;
        }
    }

    return 0;
}
//题解https://blog.csdn.net/qq_42581685/article/details/122767034
#include <iostream>
using namespace std;

typedef unsigned long long ULL;

const int N = 100005, P = 131;
ULL h[N], p[N];

int n, m;
char str[N];

int main() {
    scanf("%d%d%s", &n, &m, str);
    p[0] = 1;
    for (int i = 1; i <= n; i ++ ) {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i - 1];
    }
    int l1, r1, l2, r2;
    while (m -- ) {
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);

        ULL t1 = h[r1] - h[l1 - 1] * p[r1 - l1 + 1];
        ULL t2 = h[r2] - h[l2 - 1] * p[r2 - l2 + 1];

        if (t1 == t2) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

