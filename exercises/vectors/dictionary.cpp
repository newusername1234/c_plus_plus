#include "../../std_lib_facilities.h"
// <
int main()
{
    vector<string> words;
    string temp;
    while (cin >> temp)         //read whitespace-separated words
        words.push_back(temp);
    
    cout << "Number of words: " << words.size() << '\n';

    sort(words.begin(), words.end()); // sort from beginning to end

    string disliked = "fudge";
    // vector<string> dislikes;    forEach c++ syntax? 

    for (int i = 0; i < words.size(); ++i)
        if (i == 0 || words[i - 1] != words[i]) // only cout new words
            if (words[i] == disliked)
                cout << "BLEEP" << '\n';
            else
                cout << words[i] << '\n';
}