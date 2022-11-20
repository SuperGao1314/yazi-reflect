#pragma once

#include <string>
using namespace std;

#include "ClassRegister.h"
using namespace yazi::reflect;


class B : public Object
{
public:
    B() : m_name("b") {}
    ~B() {}

private:
    string m_name;
};

REGISTER_CLASS(B);
