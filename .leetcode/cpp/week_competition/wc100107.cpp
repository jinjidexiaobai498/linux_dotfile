#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    // 1 1 x 1 1 1 1
    auto minIncrementOperations(vector<int>& nums, int k) -> long long
    {
        vector<bool> flags(nums.size(), false);
        auto gr_pair = [nums, k](const pair<int, long long>& a1, const pair<int, long long>& a2) {
            return (double)(a1.second / (k - nums[a1.first])) < (double)(a2.second / (k - nums[a2.first]));
        };
        priority_queue<pair<int, long long>, vector<pair<int, long long>>, decltype(gr_pair)> pque(gr_pair);

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= k) {
                int end = min((int)nums.size(), i + 3);
                for (int j = max(0, i - 2); j < end; j++) {
                    flags[j] = true;
                }
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < k) {
                int end = min((int)nums.size(), i + 3);
                long long sum = 0;
                for (int j = max(0, i - 2); j < end; j++) {
                    if (!flags[j])
                        sum += (k - nums[j]);
                }
                // pque.push({ i, sum_long(i, flags, nums, k) });
                pque.push({ i, sum });
            }
        }
        long long ans = 0;
        while (!pque.empty()) {
            auto elem = pque.top();
            auto index = elem.first;
            auto value = elem.second;
            if (flags[index]) {
                pque.pop();
                continue;
            }
            int end = min((int)nums.size(), index + 3);
            long long or_v = 0;
            for (int j = max(0, index - 2); j < end; j++) {
                if (!flags[j])
                    or_v += (k - nums[j]);
            }
            // auto or_v = sum_long(index, flags, nums, k);
            if (or_v != value) {
                pque.pop();
                pque.push({ index, or_v });
                continue;
            }
            end = min((int)nums.size(), index + 3);
            for (int j = max(0, index - 2); j < end; j++) {
                flags[j] = true;
            }
            ans += k - nums[index];
            pque.pop();
        }
        return ans;
    }

    auto sum_long(int index, vector<bool> flags, vector<int> nums, int k) -> long long
    {
        int end = min((int)nums.size(), index + 3);
        long long sum = 0;
        for (int j = max(0, index - 2); j < end; j++) {
            if (!flags[j])
                sum += (k - nums[j]);
        }

        return sum;
    }
};

void test2()
{
    auto ns = vector<int> { 0, 18, 28 };
    int k = 93;
    int res = Solution().minIncrementOperations(ns, k);
    // assert(res == 65);
}
void test1()
{
    auto ns = vector<int> { 2, 3, 0, 0, 2 };
    int k = 4;
    int res = Solution().minIncrementOperations(ns, k);
    assert(res == 3);
}
int main()
{
    // test1();
    test2();
}