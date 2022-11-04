/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-09-13 15:18:38
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-09-13 15:19:03
 * @FilePath: /.leetcode/字符串/468.验证ip地址.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=468 lang=cpp
 *
 * [468] 验证IP地址
 */

// @lc code=start


//双指针，每次循环找到一个窗口，进行解析
class Solution {
public:
    string validIPAddress(string queryIP) {
        //string::npos表示不存在的位置
        if (queryIP.find('.') != string::npos) {
            // IPv4
            int last = -1;
            for (int i = 0; i < 4; ++i) {
                int cur = i == 3 ? queryIP.size() : queryIP.find('.', last + 1);
                if (cur == string::npos) {
                    return "Neither";
                }
                if (cur - last - 1 < 1 || cur - last - 1 > 3) {
                    return "Neither";
                }
                int addr = 0;
                for (int j = last + 1; j < cur; ++j) {
                    if (!isdigit(queryIP[j])) {
                        return "Neither";
                    }
                    addr = addr * 10 + (queryIP[j] - '0');
                }
                if (addr > 255) {
                    return "Neither";
                }
                if (addr > 0 && queryIP[last + 1] == '0') {
                    return "Neither";
                }
                if (addr == 0 && cur - last - 1 > 1) {
                    return "Neither";
                }
                last = cur;
            }
            return "IPv4";
        }
        else {
            // IPv6
            int last = -1;
            for (int i = 0; i < 8; ++i) {
                int cur = (i == 7 ? queryIP.size() : queryIP.find(':', last + 1));
                if (cur == string::npos) {
                    return "Neither";
                }
                if (cur - last - 1 < 1 || cur - last - 1 > 4) {
                    return "Neither";
                }
                for (int j = last + 1; j < cur; ++j) {
                    if (!isdigit(queryIP[j]) && !('a' <= tolower(queryIP[j]) && tolower(queryIP[j]) <= 'f')) {
                        return "Neither";
                    }
                }
                last = cur;
            }
            return "IPv6";
        }
    }
};
// @lc code=end

