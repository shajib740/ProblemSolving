#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using std::vector;
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        bool isValidAnagram = true;
        if(s.length() != t.length())
        {
            isValidAnagram = false;
        }
       

    unordered_map<string,int> charInFirstString;
    unordered_map<string,int> charInSecondString;

    for(int i = 0; i< s.length();i++)
    {
        auto getExistingValue = charInFirstString.find(s[i]);
        if( getExistingValue != charInFirstString.end())
        {
            charInFirstString.insert( std::make_pair<std::string,int>(s[i],1));
        }
        charInFirstString[s[i]]++;
    }
    for(int i = 0; i< t.length();i++)
    {
    charInSecondString[t[i]]++;
    }
    for(auto i = charInFirstString.begin(); i !=charInFirstString.end(); i++ )
    {
        cout<< i->first << " "<< i->second<<endl; 
       auto checkSecondString = charInSecondString.find(i->first);
        if((i->first == checkSecondString->first) && (i->second == checkSecondString->second ))
            continue;
        else
        isValidAnagram = false;
    }
    for(auto i = charInSecondString.begin(); i !=charInSecondString.end(); i++ )
    {
       cout<< i->first << " "<< i->second<<endl; 

    
    }

        return isValidAnagram;
    }
};
int main(){
   
    
    vector<int> vect{-4,-1,0,3,10 };
    Solution sltn;
    string s = "ratt", t = "ttra1";
    bool isAnagram = sltn.isAnagram(s, t);
    cout<<"isAnagram: " <<isAnagram ;
    return 0;
}
