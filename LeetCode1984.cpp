#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minimumDifference(vector<int>& nums, int k) {

        int minimum = INT_MAX;
        int left = 0;
        int right = k-1;
        sort(nums.begin(),nums.end());
        int window = 0;
        while( right < nums.size()){
            cout<< "nums["<<left<<"]: "<< nums[left] << " nums["<< right <<"]: " << nums[right] << endl;
            minimum = min(minimum, nums[right] - nums[left]);
            right++;
            left++;

            
          
        }   
         return minimum; 
    }

};
int main()
{
    //1,4,7,9
vector<int> testVec = {9,4,1,7};
    Solution s;
    int minimum = s.minimumDifference(testVec, 3);
    cout << "Minimun "<< minimum;
}