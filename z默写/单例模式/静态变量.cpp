/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-26 17:24:28
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-08-26 17:46:28
 * @FilePath: /.leetcode/z默写/单例模式/静态变量.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
class Single{
public:
    static Single* GetInstance();
private:
    Single();
    Single(Singl &instance);
    Single &operator=(const Single &instance);
    ~Single();
};
Single*GetInstance(){
    static Single instance;
    return &instance;
}
int main(){
    Single *instance = Single::GetInstance();
}