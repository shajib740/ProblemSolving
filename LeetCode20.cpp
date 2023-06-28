#include<iostream>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {

        unordered_map<char, char> allParenthesis;
        allParenthesis.insert({')','('});
        allParenthesis.insert({'}','{'});
        allParenthesis.insert({']','['});


        stack<char> bracketList;
        bool isValid = false;
        for (auto ch: s)
        {
           // cout<<"Character: " << ch << endl;
            if(ch == '(' || ch == '{' || ch == '[' || bracketList.empty())
            {
                cout<< "Pushed: "<< ch << endl;
                bracketList.push(ch);
            }
            else 
            {
                auto it = allParenthesis.find(ch);
                if(it != allParenthesis.end())
                {
                   
                cout<< "Found: "<< ch << endl;
                    if( it->second == bracketList.top())
                    { 
                        cout<< "Poped: " <<  bracketList.top()<<endl;
                        bracketList.pop();

                    }
                    else{
                        
                        break;

                    }
                }
            }
        }
        if(bracketList.empty())
        {
            isValid = true;
        }
    
        return isValid;
    }
};
int main()
{
    Solution s;
    cout<< "Isvalid? "<<s.isValid("(])") <<endl;
}