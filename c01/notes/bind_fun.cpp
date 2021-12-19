//
// Created by rct on 2021/12/19.
//


#include <iostream>
#include <functional>

void fun(int& _a, int& _b, int _c)
{
    _a++;
    _b++;
    _c++;

    std::cout << "in    fun a:" << _a << " b:" << _b << " c:" << _c << std::endl;
}

int main() {

    int a = 1, b = 1, c = 1;

    auto c_fun = std::bind(fun, a, std::ref(b), std::ref(c));
    c_fun();
    std::cout << "after fun a:" << a << " b:" << b << " c:" << c << std::endl;

    return 0;

}