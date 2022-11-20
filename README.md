# yazi-reflect
a tiny c++ reflect library

## example

定义类
```c++
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
```

三个注册反射宏

1、注册类对象反射
```c++
REGISTER_CLASS(A);
```
其中，A为类名称。

2、注册类成员数据反射
```c++
REGISTER_CLASS_FIELD(A, m_name, string);
```
其中，m_name为成员数据的名称，string为成员数据的类型。

3、注册类成员函数反射
```c++
REGISTER_CLASS_METHOD(A, f2, int, int);
```
其中、f2为成员函数的名称，接着第一个int为函数返回值，后面为函数的可变参数类型列表。

用法

```c++
#include <iostream>
using namespace std;

#include "ClassFactory.h"
using namespace yazi::reflect;

#include "test/A.h"

int main()
{
    ClassFactory * factory = Singleton<ClassFactory>::instance();
    Object * a = factory->create_class("A");
    
    string name;
    a->get("m_name", name);
    a->set("m_name", "kitty");

    int age;
    a->get("m_age", age);
    a->set("m_age", 30);

    a->call("f1");
    int num = a->call<int>("f2", 123);

    return 0;
}
```


