#include "../../std_lib_facilities.h"

int main()
{
    // vector<double> v;
    // v.push_back(2.7);
    // v.push_back(5.6);
    // v.push_back(7.9);
    // for (int i = 0; i < v.size(); ++i)
    //     cout << "v[" << i << "]==" << v[i] << '\n';

    vector<double> temps;
    double temp;
    while (cin >> temp)
        temps.push_back(temp);

    // compute mean
    double sum = 0;
    for (int i = 0; i < temps.size(); ++i) sum += temps[i];
    cout << "Average temperature: " << sum / temps.size() << '\n';

    // compute median
    sort(temps.begin(), temps.end()); // sorts temps from beginning
    
    double median_temp;

    if (temps.size() % 2 != 0)
        median_temp = temps[temps.size() / 2];                                  // to end
    else
        median_temp = (temps[temps.size() / 2 - 1] + temps[temps.size() / 2]) / 2;

    cout << "Median temperature: " << median_temp << '\n';
}