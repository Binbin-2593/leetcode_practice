/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-26 19:25:33
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-09-01 23:09:21
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
#include<iostream>
#include<vector>
using namespace std;

vector<int> nums, v = {2, 3, 5,7, 11, 13, 17, 19, 23, 29, 31, 37};
void help(vector<int>&nums,vector<int>&v,int end){
    for (int i = 0; i <end;++i){   
        for (int j = 0; j <end; ++j){
            for (int k = 0; k <end; ++k){
                int n1 = v[i],n2 = v[j], n3 = v[k];
                nums.push_back(n1 * n1 + n2 * n2 * n2 + n3 * n3 * n3 * n3);
            }
        }
    }
}

int main(){
    int n, tmp;
    cin >> n;
    vector<int> vmp;
    while (n--){
        cin >> tmp;
        vmp.push_back(tmp);
    }
    
    sort(vmp.begin(), vmp.end());
    auto itt=lower_bound(v.begin(), v.end(),sqrt(sqrt(vmp[vmp.size() - 1])));
    help(nums, v, (int)(itt - v.begin())+1);
    sort(nums.begin(), nums.end());

    for(auto&t:vmp){
        auto it = lower_bound(nums.begin(), nums.end(), t);
        if(*it==t){
            cout << (int)(it-nums.begin())+1 << endl;
        }else{
            cout << (int)(it-nums.begin()) << endl;
        }  
    }
    return 0;
}