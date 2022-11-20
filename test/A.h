#pragma once

#include <string>
using namespace std;

#include "ClassRegister.h"
using namespace yazi::reflect;


class A : public Object
{
public:
    A() : m_name("a"), m_age(18) {}

    void f1()
    {
        std::cout << "f1" << std::endl;
    }

    int f2(int a)
    {
        std::cout << "f2" << std::endl;
        return a;
    }

public:
    string m_name;
    int m_age;
};

REGISTER_CLASS(A);
REGISTER_CLASS_FIELD(A, m_name, string);
REGISTER_CLASS_FIELD(A, m_age, int);
REGISTER_CLASS_METHOD(A, f1, void);
REGISTER_CLASS_METHOD(A, f2, int, int);
