#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Name_pairs {
public:
    void read_names();
    void read_ages();
    // void print(); dont need with operator<< overload
    void sort_names_ages();
    std::vector<std::string> get_names() const;
    std::vector<double> get_ages() const;
private:
    std::vector<std::string> names;
    std::vector<double> ages;
};

std::vector<std::string> Name_pairs::get_names() const
{
    return names;
}

std::vector<double> Name_pairs::get_ages() const
{
    return ages;
}

void Name_pairs::read_names()
{
    std::string name;
    while (std::cin>>name)
        names.push_back(name);
    std::cin.clear();
}

void Name_pairs::read_ages()
{
    double age;
    for (int i=0; i<names.size(); ++i) {
        std::cout << "Age for " << names[i] << ":" << '\n';
        std::cin >> age;
        ages.push_back(age);
    }
}

// void Name_pairs::print()
// {
//     for (int i=0; i<names.size(); ++i)
//         std::cout << names[i] << ", " << ages[i] << std::endl;
// }

void Name_pairs::sort_names_ages()
{
    std::vector<std::string> unsorted_names = names;
    std::vector<double> sorted_ages;
    std::sort(names.begin(), names.end());
    for (int i=0; i<names.size(); ++i)
        for (int j=0; j<unsorted_names.size(); ++j)
            if (names[i]==unsorted_names[j])
                sorted_ages.push_back(ages[j]);
    ages = sorted_ages;
}

std::ostream &operator<<(std::ostream &os, const Name_pairs &n)
{
    for (std::size_t i=0; i<n.get_names().size(); ++i)
        os << n.get_names()[i] << ", " << n.get_ages()[i] << '\n';
    return os;
}

bool operator==(const Name_pairs &a, const Name_pairs &b)
{
    return a.get_names()==b.get_names()
            && a.get_ages()==b.get_ages();
}

bool operator!=(const Name_pairs &a, const Name_pairs &b)
{
    return !(a==b);
}

int main()
{
    Name_pairs x = Name_pairs();
    x.read_names();
    x.read_ages();
    std::cout << x;
    Name_pairs y = Name_pairs();
    y.read_names();
    y.read_ages();
    std::cout << "x==y? " << std::boolalpha << (x==y) << '\n';
    x.sort_names_ages();
    y.sort_names_ages();
    std::cout << "sorted x == sorted y? " << std::boolalpha << (x==y) << '\n';
}