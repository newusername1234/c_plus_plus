#include<iostream>
using namespace std;

class X {
    public:
        // public members:
        //      - the interface to users (accessible by all)
        // functions
        // types
        // data (often best kept private)
        int m;
        int mf(int v) {int old = m; m = v; return old;}
    private:
        // private members:
        //      - the implementation details (used by members of this class only)
        // functions
        // types
        // data
};

// class members are private by default
class Y {
    int mf(int); // cant access
};

// we have to go through a public function
// to access the private members
class Z {
    int m;
    int mf(int v) {int old = m; m = v; return old;}
public:
    int f(int i) {m=i; return mf(i);}
};

// a struct is a class where its members are public by default
// these two are equivalent:

// struct X {
//     int m;
//     // ...
// };

// class X {
// public:
//     int m;
//     // ...
// };

// structs are primarily used for data structures where
// members can take any value

int main()
{
    // X var;
    // var.m = 7;
    // int x = var.mf(9);
    // Y y_var;
    // y_var.mf(1); // error
    Z z;
    int y = z.f(1);
}