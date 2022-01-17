/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
//不使用数据结构装中间数据

class Solution {
public:
    int reverse(int x) {
        // int min = -2147483648;
        // int max = 2147483647;
        int rev = 0;
        while(x!=0){
            if(rev<min/10||rev>max/10)//问题中间的数学描述，直接提炼数学表达式，用代码表示即可
                return 0;
            int mod = x % 10;
            x /= 10;//这里用到了数据类型的自动转化功能
            rev = rev * 10 + mod;
        }
        return rev;
    }
private:
    int min = -2147483648;
    int max = 2147483647;
};

//使用栈

// class Solution {
// public:
//     int reverse(int x) {
//         int s(0);
//         long long rev(0);

//         if(x<0)
//             s = -x;
//         else s = x;

//         //数字转字符串
//         stringstream ss ;
//         ss.clear();
//         ss << s;
//         string sx;
//         ss >> sx;

//         for (int i = sx.size() - 1;i >= 0;--i){ 
//           rev = rev * 10 + (sx[i]-'0');
//         }
//         if((x>=0&&rev>max)||(x<0&&(-rev)<min))//错，出现溢出
//             return 0;  
//   
//         return (x < 0) ? -(int)rev : (int)rev;
//     }

// private:
//     int min = -2147483648;
//     int max = 2147483647;
// };
/*
class Solution
{
public:
    int reverse(int x)
    {
        long result; //利用long避免溢出
        if (x == INT_MIN)
        {
            return 0;
        }
        if (x < 0)
        {
            return -reverse(-x);
        }
        stringstream ss;
        ss << x;
        string tmpStr;
        ss >> tmpStr;

        int tmpStrSize = int(tmpStr.size());
        string resultStr;
        for (int index = tmpStrSize - 1; index >= 0; index--)
        {
            resultStr.push_back(tmpStr[index]);
        }
        ss.clear(); //使用前记得clear
        ss << resultStr;
        ss >> result;
        if (result > INT_MAX)
        {
            return 0;
        }
        return int(result);
    }
};
*/

// @lc code=end

