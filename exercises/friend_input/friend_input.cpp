#include "../../std_lib_facilities.h"

int main()
{
    cout << "Enter the name of the person you want to write to\n";
    string first_name;
    cin >> first_name;
    cout << "Dear " << first_name << ",\n"
        << "\tHow are you?\n"
        << "\tI'm fine.\n" 
        << "\tI hope we can get together soon.\n"
        << "\tOh that's right. We live together.\n"
        << "\tHow could I forget? Hahahaaaaaaaa\n";
    string friend_name;
    cin >> friend_name;
    cout << "Have you seen " << friend_name << " lately?\n";
    char friend_sex = 0;
    cin >> friend_sex;
    if (friend_sex == 'm')
        cout << "If you see " << friend_name
            << " please ask him to call me.\n";
    else if (friend_sex == 'f')
        cout << "If you see " << friend_name
            << " please ask her to call me.\n";
    int age;
    cin >> age;
    if (age < 12)
        cout << "Next year you will be " 
            << age + 1
            << '\n';
    else if (age == 17)
        cout << "Next year you will be able to vote.\n";
    else if (age > 70)
        cout << "I hope you are enjoying retirement.\n";
    else if (age > 0 && age < 110)
        cout << "I hear you just had a birthday and you are "
            << age << " years old.\n"
            << "HAPPY BIRTHDAY!\n";
    else
        error("you're kidding!");
    cout << "Yours sincerely,\n\n\tWes\n";
}