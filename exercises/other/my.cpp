#include "./my.h"
#include<iostream>
using namespace std;

int foo;

void print_foo()
{
    cout << foo << endl;
}

void print(int i)
{
    cout << i << endl;
}

void swap_v(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout << "arg a: " << a << endl;
    cout << "arg b: " << b << endl;
}

void swap_r(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout << "arg a: " << a << endl;
    cout << "arg b: " << b << endl;
}

// void swap_cr(const int &a, const int &b)
// {
//     int temp;
//     temp = a;
//     a = b;
//     b = temp;
// }