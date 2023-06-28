#include <iostream>
#include <vector>
#include <stack>
#include <cctype>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        
        stack<int> scores;
        int output = 0;
        for(auto ops: operations)
        {
             cout<< "Value: "<<  ops << endl;
            if(ops == "C" )
            {
               
                if(! scores.empty())
                {
                     cout<< "Remove : "<<   scores.top() << endl;
                    scores.pop();
                }
            }
            else if(ops == "D")
            {
                if(! scores.empty())
                {
                    int tempVal = 2* scores.top();
                   
                    scores.push(tempVal);
                     cout<< "Insert Double: "<<  tempVal << endl;
                }
            }
            else if(ops == "+")
            {
                 cout<< "Insert +_ here: " << endl;
                if(scores.size() >= 2)
                {
                    int tempVal1 = scores.top();
                    scores.pop();   

                    int tempVal2 = scores.top();

                    scores.push(tempVal1);
                    scores.push(tempVal1 + tempVal2);
                    cout<< "Insert +:  tempVal1: "<<  tempVal1 << " tempVal2: "+ tempVal2 << endl;
                }
            }
            else 
            {
                
                int tempVal1 = stoi(ops);
                cout<< "Insert Number: "<<  tempVal1 << endl;
                scores.push(tempVal1);
            }
        }
    while(!scores.empty())
    {
        cout<< "All Value: "<<  scores.top() << endl;
        output += scores.top();
        scores.pop();
    }
    return output;
    }
};
int main()
{

    vector<string> testVec = {"1","C"};
    Solution s;
    int output = s.calPoints(testVec);

    cout<< "Output: "<< output;
}