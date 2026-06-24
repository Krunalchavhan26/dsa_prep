#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxSum = INT_MIN, currentSum = 0;

        for (int val : nums)
        {
            currentSum = max(val, currentSum + val);
            maxSum = max(currentSum, maxSum);
        }
        return maxSum;
    }
};

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution sol;
    cout << sol.maxSubArray(nums) << endl; // 6
    return 0;
}
