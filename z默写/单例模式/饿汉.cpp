/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-26 17:46:51
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-08-26 17:56:14
 * @FilePath: /.leetcode/z默写/单例模式/饿汉.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
class Single{
public:
    static Single* GetInstance();
private:
    Single();
    Single(Single &instance);
    Single &operator=(const Single &instance);
    ~Single();
    static Single *m_Instance;
};
Single*Single::GetInstance(){
    return m_Instance;
}

Single *Single::m_Instance = new Single();//全局在main之前
int main(){
    Single *instance = Single::GetInstance();
}