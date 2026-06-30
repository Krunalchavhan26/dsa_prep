#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int maxWater = 0;
        int lp = 0, rp = height.size() - 1;
        int w, ht, currWater = 0;

        while (lp < rp)
        {
            w = rp - lp;
            ht = min(height[lp], height[rp]);
            currWater = w * ht;

            maxWater = max(maxWater, currWater);

            height[lp] < height[rp] ? lp++ : rp--;
        }

        return maxWater;
    }
};

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution sol;
    cout << sol.maxArea(height) << endl; // 49
    return 0;
}