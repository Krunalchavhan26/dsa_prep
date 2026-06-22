#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int insertPos = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                nums[insertPos] = nums[i];
                insertPos++;
            }
        }

        for (int i = insertPos; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
    }
};

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    Solution sol;
    sol.moveZeroes(nums);
    for (int x : nums)
        cout << x << " ";
    cout << endl; // 1 3 12 0 0
    return 0;
}