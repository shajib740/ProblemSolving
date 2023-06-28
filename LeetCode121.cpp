#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using std::vector;
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       
      
        int buyPrice = prices[0]; // 7
        int sellPrice = prices[1];// 1
        int maxProfit=0;
      
            for(int j =0; j<prices.size()-1;j++){
                if(buyPrice < sellPrice)
                {
                    int currentMaxProfit = sellPrice - buyPrice ; //  2
                    if(maxProfit < currentMaxProfit)
                    {
                        maxProfit = currentMaxProfit;
                    }
                }
                else
                {
                buyPrice = sellPrice;
                }
                if( j+1+1 <= prices.size()-1 )
                  sellPrice = prices[j+1+1];
            }
        return  maxProfit;
    }
};
int main(){
   
    
    vector<int> vect{7,1,5,3,6,9};
    Solution s;
    int profit = s.maxProfit(vect);
    cout<< "maxProfit: "<< profit<< endl;
   
    return 0;
}
