#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1);

        // prefix
        for (int i = 1; i < n; i++)
        {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // suffix
        int suffix = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            suffix *= nums[i + 1]; // ith suffix
            ans[i] *= suffix;
        }

        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    Solution sol;
    vector<int> result = sol.productExceptSelf(nums);
    for (int x : result)
        cout << x << " ";
    cout << endl; // 24 12 8 6
    return 0;
}