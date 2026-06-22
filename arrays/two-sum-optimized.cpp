#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++)
        {
            int need = target - nums[i];
            if (map.count(need))
            {
                return {map[need], i};
            }
            map[nums[i]] = i;
        }

        return {};
    }
};

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution sol;
    vector<int> result = sol.twoSum(nums, target);

    cout << result[0] << ", " << result[1] << endl;
}

// Psudo Code
