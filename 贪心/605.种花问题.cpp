/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start

//这种下标i加过大（>1）的数难处理越界问题

// class Solution {
// public:
//     bool canPlaceFlowers(vector<int>& flowerbed, int n) {
//         int k=flowerbed.size(),m=0;
//         if(flowerbed[0]==0&&flowerbed[1]==0)
//             ++m;
//         if(flowerbed[k-1]==0&&flowerbed[k-2]==0)
//             ++m;

//         for (int i = 0; i < k-3; )
//         {
//             if (flowerbed[i]==1&&flowerbed[i+1]==0&&flowerbed[i+2]==0&&flowerbed[i+3]==0){
//                 ++m;
//                 flowerbed[i + 2] = 1;
//                 i = i + 2;
//             }
//             else
//                 ++i;
//             // else if(i>1&&flowerbed[i-2]==1){}
//         }
//     return m>=n;
//     }
// };

class Solution{
public:
    bool canPlaceFlowers(vector<int> &flowerbed,int n){
        for (int i = 0;i<flowerbed.size();){
            //当为1时
            if(flowerbed[i]==1){
                i += 2;
            }
            //1,0,0(i),0型
            //else if(flowerbed[i+1]==0||i==flowerbed.size()-1)
            //||运算会先判断左侧，左侧为false时才会判断右侧，
            //边界判断在这里就是防止边界时flowerbed数组越界，
            //如果不交换顺序就会先判断flowerbed[i+1]==0，当到达边界时就会导致异常
            else if(i==flowerbed.size()-1||flowerbed[i+1]==0)
            {
                --n;
                i += 2;
            }
            //0,0(i),1型
            else{i+=3;}

        }
        return n <= 0;
    }
};
// @lc code=end
