#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int length = nums.size();
        
        vector<int> result;

        for(int i = 0; i < length - 1; i++){
            for(int j = i + 1; j < length; j++){
                if((nums[i] + nums[j]) == target){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }

        return result;
    }
};

int main(){
    vector<int> nums = {2,7,11,15};
    int target = 9;

    Solution sol;
    vector<int> result = sol.twoSum(nums, target);

    cout << result[0] << ", " << result[1] << endl;
}

// Psudo Code
