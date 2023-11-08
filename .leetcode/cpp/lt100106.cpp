#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    auto minimumSum(vector<int>& nums) -> int
    {
        vector<int> min_before(nums.size(), 0);
        vector<int> min_after(nums.size(), 51);

        min_before[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            min_before[i] = min(min_before[i - 1], nums[i - 1]);
        }

        min_after[nums.size() - 1] = nums.back();
        for (int i = nums.size() - 2; i >= 0; i--) {
            min_after[i] = min(min_after[i + 1], nums[i + 1]);
        }
        int sum = INT32_MAX;

        for (int i = 1; i < nums.size() - 1; i++) {
            if (nums[i] > min_before[i] && nums[i] > min_after[i]) {
                sum = min(sum, nums[i] + min_after[i] + min_before[i]);
            }
        }
        if (sum == INT32_MAX) {
            return -1;
        }

        return sum;
    }
};