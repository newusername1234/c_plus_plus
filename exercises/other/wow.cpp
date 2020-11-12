#include "../std_lib_facilities.h"

int fib(vector<int> &v)
{
    int max = v[0];
    for (int i=0; i<v.size(); ++i)
        if (v[i] > max)
            max = v[i];
    return max;
}

int main()
{
    vector<int> vi;
    vi.push_back(123);
    vi.push_back(1);
    // vi.push_back(124);
    // vi.push_back(1000);
    cout << fib(vi);
}
