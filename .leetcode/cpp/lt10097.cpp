#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <ranges>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    auto minGroupsForValidAssignment(vector<int>& nums) -> int
    {

        unordered_map<int, int> map;
        for (auto index_elem : nums) {
            map[index_elem] += 1;
        }
        if (map.size() == 1)
            return 1;

        unordered_map<int, int> umap;
        for (auto& entry : map) {
            umap[entry.second] += 1;
        }

        vector<int> groups;

        groups.reserve(umap.size());
        for (auto& entry : umap) {
            groups.push_back(entry.first);
        }

        sort(groups.begin(), groups.end());

        auto isRight = [groups](int elem_num) -> bool {
            for (auto group : groups) {
                int mod = group % elem_num;
                int num = group / elem_num;

                if (mod > num) {
                    return false;
                }
                if ((group / elem_num) > (group % elem_num)) {
                    return false;
                }
            }
            return true;
        };

        int part_num = 1;

        auto min_zone = *min_element(begin(groups), end(groups));

        for (int i = 1; i <= min_zone; i++) {

            int _part_num = min_zone / i;

            if (isRight(_part_num)) {
                part_num = (_part_num);
                break;
            }

            if (isRight(_part_num - 1)) {
                part_num = (_part_num - 1);
                break;
            }
        }

        int sum = 0;

        // if (part_num == 1) {
        //     for (auto group : groups) {
        //         sum += ((group >> 1) + (group & 1)) * umap[group];
        //     }
        //     return sum;
        // }

        for (auto group : groups) {
            int num = group / part_num;
            int mod = group % part_num;

            sum += (num - (num - mod) / (part_num + 1)) * umap[group];
        }
        return sum;
    }
};

auto main() -> int
{
    Solution sol;
    // auto nums = vector<int> { 10, 10, 10, 3, 1, 1 };
    auto nums = vector<int> { 1, 1, 1, 1, 1, 3, 3, 3, 3 };
    cout << sol.minGroupsForValidAssignment(nums) << endl;
}