#include <iostream>
#include <map>
#include <string>

int main()
{
    std::string str1;
    std::string str2;
    bool anagram;

    std::cout << "Enter the string #1: ";
    std::cin >> str1;
    std::cout << "Enter the string #2: ";
    std::cin >> str2;

    if (str1.length() != str2.length())
    {
        anagram = false;
    } else {
        std::map<char, int> str1char;
        std::map<char, int> str2char;

        for (int i = 0; i < str1.length(); ++i)
        {
            std::map<char, int>::iterator it1 = str1char.find(str1[i]);
            if (str1[i] == it1->first) it1->second += 1;
            else str1char.insert(std::pair<char, int>(str1[i], 1));

            std::map<char, int>::iterator it2 = str2char.find(str2[i]);
            if (str2[i] == it2->first) it2->second += 1;
            else str2char.insert(std::pair<char, int>(str2[i], 1));
        }

        std::map<char, int>::iterator it2 = str2char.begin();
        for (std::map<char, int>::iterator it1 = str1char.begin(); it1 != str1char.end(); ++it1)
        {
            if (it1->first != it2->first || it1->second != it2->second)
            {
                anagram = false;
                break;
            }
            it2++;
            anagram = true;
        }
    }
    std::cout << anagram;
}