/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-09-29 16:57:46
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-09-29 18:30:38
 * @FilePath: /.leetcode/数学/求一个数的最大质数.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
//求一个数的最大质数
//整体思路：模拟短除法因式分解：
//两端2、n，不断往中间挤（++x;\n/=x;），
//直到挤到中间某个数n==x处
int MaxZhishu(int n){
    int x = 2,ret=0;
    while(n){
        if(n%x){//找出能是n整除的数x
            ++x;
        }else{
            ret = n;
            n /= x;
            if(n==1){
                return ret;
            }
        }
    }
    return 0;
}