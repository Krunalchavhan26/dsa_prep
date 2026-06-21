#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < minPrice)
            {
                minPrice = prices[i]; // update min
            }
            int profit = prices[i] - minPrice; // today's profit
            if (profit > maxProfit)
            {
                maxProfit = profit;
            }
        }
        return maxProfit;
    }
};

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution sol;
    cout << sol.maxProfit(prices) << endl; // 5
    return 0;
}
