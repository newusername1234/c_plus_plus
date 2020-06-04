#include "../../std_lib_facilities.h"

int square(int x)
{
    return x * x;
}

void write_sorry()
{
    cout << "sorry\n";
}

int main()
{
    // for (int i = 97; i <= 122; ++i) {
    //     cout << char(i) << '\t' << i << '\n';
    // }
    write_sorry();
    for (int i = 0; i <= 100; ++i) {
        cout << i << '\t' << square(i) << '\n';
    }
}
