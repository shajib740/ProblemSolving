#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int left = 0;
        int right;
        bool isDuplicate = false;
        unordered_set<int>  uniqueNumbers; 
        
        for(right = 0; right < nums.size(); right++)
        {
 
           cout<< "Current Index: " << right  << endl;
           if(right - left > k)
           {
             cout<< "Remove Index: " << left << " for value: "<< nums[left] << endl;
            int removedItem = nums[left];
            uniqueNumbers.erase(removedItem);
            left++;
           }

            if(uniqueNumbers.find(nums[right]) != uniqueNumbers.end()){
               //  cout<< "Duplicate: " << nums[right] << " at: "<< right << endl;
                isDuplicate = true;
                break;
            }
            
            uniqueNumbers.insert(nums[right]);  
            for (auto it = uniqueNumbers.begin(); it != uniqueNumbers.end(); it++) {
                     cout << *it << " ";
                }
                  cout<< endl;
        }

        return isDuplicate;
    }
};

int main()
{
    vector<int> testVec = {1};
    Solution s;
    bool haveDuplicate = s.containsNearbyDuplicate(testVec,1);
    cout << "HaveDuplicate?  "<< haveDuplicate;
}