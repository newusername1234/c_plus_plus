#include "../../std_lib_facilities.h"

int main()
{
    // cout << "Do you like fish?\n";
    // string s;
    // cin >> s;
    // switch (s) { // switch val must be char, int, or enum
    //     case "no":
    //         cout << "nope";
    //         break;
    //     case "yes":
    //         cout << "yup";
    //         break;
    //     default:
    //         cout << "???";
    //         break;
    // }
    cout << "Please enter a digit\n";
    char a;
    while(cin>>a) {
        switch (a) {
            case '0': case '2': case '4': case '6': case '8':
                cout << "is even\n";
                break;
            case '1': case '3': case '5': case '7': case '9':
                cout << "is odd\n";
                break;
            default:
                cout << "is not a digit\n";
                break;
        }
    }
}