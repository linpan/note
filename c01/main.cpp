#include <thread>
#include <string>
#include <sstream>
#include <assert.h>
#include <iostream>
/* thread constructor 构造器并不知道 bind funnction 参数的类型,
 *
 * */

void f_with_ref(int& n) { ++n; }

void f_with_ptr(std::unique_ptr<int> p)
{
    std::cout << *p;
}

class A {
public:
    void f_with_class(int i) { std::cout << i; }
};

void f_with_bf(int i,std::string const& s)
{
    std::cout << s << std::endl;
}
int main()
{
     // ref
    int i = 1;
    // without ref, pass funnction with rvaule.
    std::thread t1(f_with_ref, std::ref(i));
    t1.join();
    // unique_ptr
    std::unique_ptr<int> p(new int(42));
    std::thread t2(f_with_ptr, std::move(p));
    t2.join();
    //class
    A a;
    std::thread t3(&A::f_with_class, &a, 42); // 第一个参数为成员函数地址，第二个参数为实例地址
    t3.join();
    std::cout << i; // 2

    char buffer[1024]= {'a','b'};
    std::thread t5(f_with_bf, 3, std::string(buffer));
    t5.join();
}
