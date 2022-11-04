/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-26 17:32:03
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-09-29 15:49:23
 * @FilePath: /.leetcode/z默写/单例模式/懒汉+锁.cpp
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
    if(m_Instance==nullptr){//上锁前if的原因：每次获取实例的时候都要先上锁，之后再解锁，如果有很多线程的话，可能会造成大量线程的阻塞
        lock();
        if(m_Instance==nullptr){
            m_Instance=new Single();
        }
        unlock();
    }
    return m_Instance;
}
int main(){
    Single *instance = Single::GetInstance();
}

class Single{
public:
    static Single *GetInstance();

private:
    Single();
    Single(Single &instance);
    Single &operator=(const Single &instance);
    ~Single();
    static Single *m_Instance;
};
Single*Single::GetInstance(){
    if(m_Instance==nullptr){
        lock();
        if(m_Instance==nullptr){
            m_Instance = new Single();
        }
        unlock();
    }
    return m_Instance;
}
int main(){
    Single *instance = Single::GetInstance();
}
class Single{
public:
    static Single *GetInstance();
private:
    Single();
    Single(Single &instance);
    Single &operator=(const Single &instance);
    ~Single();
    static Single *m_Instance;
};
Single*Single::GetInstance(){
    if(m_Instance==nullptr){
        lock();
        if(m_Instance==nullptr){
            m_Instance = new Single();
        }
        unlock();
    }
    return m_Instance;
}
int main(){
    Single *instance=Single::GetInstance();
}