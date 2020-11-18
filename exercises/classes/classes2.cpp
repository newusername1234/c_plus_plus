#include "../../std_lib_facilities.h"
// how to represent a date in a program

// simple Date
// guarantee initialization with constructor
// provide some notational convenience
// struct SDate {
//     int y,m,d;
//     SDate(int y, int m, int d) { // member function w same name as class is constructor
//         // check for valid date
//     };
//     void add_day(int n);
// };

// // Date my_birthday; // error: my_birthday not initialized
// // Date today(12,24,2007); // runtime error. fails constructor check
// SDate last(2000,12,31); // OK (colloquial)
// SDate christmas = SDate(1976,12,24); // also OK (verbose)

// last.add_day(1);
// add_day(2); // error: what date?

// simple Date (control access)
// class CDate {
//     int y,m,d;
// public:
//     CDate(int y, int m, int d) {
//         // check for valid date and initialize
//     };
//     void add_day(int n) {
//         // increase days by n
//     }
//     int month() {return m;}
//     int day() {return d;}
//     int year() {return y;}
// };

// CDate birthday(1970,12,30); // OK
// birthday.m = 14; // error: CDate::m is private
// cout << birthday.month() << endl; // we provided a way to read m

// people put public interface first
// class Date {
// public:
//     Date(int y, int m, int d); // constructor: check for valid date and initialize
//     void add_day(int n); // increase by n days
//     int month();
//     // ...
// private:
//     int y,m,d; // year, month, day
// };

// when we define a member outside its class we need to say which class its a member of
// Date::Date(int yy, int mm, int dd) // constructor
//      :y(yy), m(mm), d(dd)          // note: member initializers
// {
// }
// // the :y(yy), m(mm), d(dd) notation is how we initialize members
// // we could have written:
// Date::Date(int yy, int mm, int dd)
// {
//     y = yy;
//     m = mm;
//     d = dd;
// }

// void Date::add_day(int n)
// {
//     // ...
// }

// int month() // oops: forgot Date::
// {
//     return m;   // not the member function, cant access m
// }

class Date {
public:
    class Invalid {}; //to be used as exception
    Date(int y, int m, int d); // check for valid date and initialize
    // ...
private:
    int y, m, d; // year, month, day
    bool check(); // return true if date is valid
};
// dont define functions in class declaration unless one statement
Date::Date(int yy, int mm, int dd)
     :y(yy), m(mm), d(dd) //initialize data members
{
    if (!check()) throw Invalid(); // check for validity
}

bool Date::check() // return true if date is valid
{
    if (m<1||m>12) return false;
    // ...
}

// void f(int x, int y)
// try {
//     Date dxy(2004,x,y);
//     cout << dxy << '\n';
//     // dxy.add_day(2);
// }
// catch(Date::Invalid) {
//     error("invalid date");
// }

// -----------------------------------------------------
// enum specifies its set of values as symbolic constants
// enum Month {
//     Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
// };
// if you leave it to the compiler to pick a value itll start with 0 and increment

Month operator++(Month &m) // preincrement operator
{
    m = (m==Dec) ? Jan : Month(m+1); // wrap around
    return m;
}
// dec clashes with other names. caps them if global
// define enumerations in more limited scopes such as within a class
// Month::dec
Month m = Dec;

class Date {
public:
    enum Month {
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };
    // use Month type to prevent confusion over 4/5/20 and 5/4/20
    Date(int y, Month m, int d); // check for valid date and initialize
    // ...
private:
    int y;
    Month m;
    int d;
}

Date dx1(1998, 4, 3); // error: 2nd argument not a Month
Date dx2(1998, 4, Date::mar) // error: 2nd argument not a Month
Date dx2(4, Date::mar, 1998) // runtime error: day 1998
Date dx2(Date::mar, 4, 1998) // error: 2nd arg not Month
Date dx3(1998, Date::mar, 30); // OK


int main()
{
    ++m;
    cout << m << endl;
}