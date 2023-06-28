#include <iostream>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
    bool isPalindrome = true;
      //  string toLowerString = tolower(s);
    int j = s.size()-1;
    int i =0;
    while (   i!=j )
    {
        cout<< "s["<< i<<"]: " << s[i] << " s[j: "<<j<<"]: " << s[j]<< endl; 
        if( isalnum(s[i]) == 0 )
        {
             cout<< "NotAlpha Numreric s[i]: " << s[i]<< endl; 
            i++;
            continue;
        }
        if(isalnum(s[j])==0)
        {
            cout<< "NotAlpha Numreric s[j]: " << s[j]<< endl; 
            j--;
            continue;
        }
        if(tolower(s[i])!= tolower(s[j]))
        {
            cout<< "Not matched"<< endl;
            isPalindrome = false;
            break;
        }

        i++;
        j--;

    }
    return isPalindrome;

    }
};

int main()
{
    string testCase = ",,,,,,,,,,,,abaa";
    Solution s;
    bool isPalindrome = s.isPalindrome(testCase);
    cout<< testCase << "Is palidrome? "<< isPalindrome;
}