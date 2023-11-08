// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1488 lang=cpp
 * @lcpr version=21917
 *
 * [1488] 避免洪水泛滥
 *
 * https://leetcode.cn/problems/avoid-flood-in-the-city/description/
 *
 * algorithms
 * Medium (26.27%)
 * Likes:    176
 * Dislikes: 0
 * Total Accepted:    19.3K
 * Total Submissions: 68K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 你的国家有无数个湖泊，所有湖泊一开始都是空的。当第
 * n 个湖泊下雨前是空的，那么它就会装满水。如果第 n 个湖泊下雨前是
 * 满的 ，这个湖泊会发生 洪水 。你的目标是避免任意一个湖泊发生洪水。
 *
 * 给你一个整数数组 rains ，其中：
 *
 *
 * rains[i] > 0 表示第 i 天时，第 rains[i] 个湖泊会下雨。
 * rains[i] == 0 表示第 i 天没有湖泊会下雨，你可以选择 一个 湖泊并
 * 抽干 这个湖泊的水。
 *
 *
 * 请返回一个数组 ans ，满足：
 *
 *
 * ans.length == rains.length
 * 如果 rains[i] > 0 ，那么ans[i] == -1 。
 * 如果 rains[i] == 0 ，ans[i] 是你第 i 天选择抽干的湖泊。
 *
 *
 * 如果有多种可行解，请返回它们中的 任意一个 。如果没办法阻止洪水，请返回一个
 * 空的数组 。
 *
 * 请注意，如果你选择抽干一个装满水的湖泊，它会变成一个空的湖泊。但如果你选择抽干一个空的湖泊，那么将无事发生。
 *
 *
 *
 * 示例 1：
 *
 * 输入：rains = [1,2,3,4]
 * 输出：[-1,-1,-1,-1]
 * 解释：第一天后，装满水的湖泊包括 [1]
 * 第二天后，装满水的湖泊包括 [1,2]
 * 第三天后，装满水的湖泊包括 [1,2,3]
 * 第四天后，装满水的湖泊包括 [1,2,3,4]
 * 没有哪一天你可以抽干任何湖泊的水，也没有湖泊会发生洪水。
 *
 *
 * 示例 2：
 *
 * 输入：rains = [1,2,0,0,2,1]
 * 输出：[-1,-1,2,1,-1,-1]
 * 解释：第一天后，装满水的湖泊包括 [1]
 * 第二天后，装满水的湖泊包括 [1,2]
 * 第三天后，我们抽干湖泊 2 。所以剩下装满水的湖泊包括 [1]
 * 第四天后，我们抽干湖泊 1 。所以暂时没有装满水的湖泊了。
 * 第五天后，装满水的湖泊包括 [2]。
 * 第六天后，装满水的湖泊包括 [1,2]。
 * 可以看出，这个方案下不会有洪水发生。同时， [-1,-1,1,2,-1,-1]
 * 也是另一个可行的没有洪水的方案。
 *
 *
 * 示例 3：
 *
 * 输入：rains = [1,2,0,1,2]
 * 输出：[]
 * 解释：第二天后，装满水的湖泊包括 [1,2]。我们可以在第三天抽干一个湖泊的水。
 * 但第三天后，湖泊 1 和 2
 * 都会再次下雨，所以不管我们第三天抽干哪个湖泊的水，另一个湖泊都会发生洪水。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= rains.length <= 10^5
 * 0 <= rains[i] <= 10^9
 *
 *
 */
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cstddef>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

#define DEBUG_L
// #include "debug.cpp"

// @lc code=start

class Solution {
public:
  /*
  for lakeX in rains
      if lakeX == 0:
          获得可以工作的日子，被存在 worklist中
          workList 存储的是 index ，就是date,
      else :
          if lakeX not in rainedMap :
              标记lakeX是rained
              他的开始坐标被存储在map中
          else :
              从map获取worklist中他的位置，然后删除最近的一个工作日
              标记他为norained
  */

  // count and lakeID
  // list<pair<int, vector<int>>> workDaysList;
  auto avoidFlood(vector<int> &rains) -> vector<int> {
    list<pair<int, set<int>>> workDaysList;
    unordered_map<int, list<pair<int, set<int>>>::iterator> lakeMap(
        rains.size() * 2);
    vector<int> ans(rains.size(), -1);

    for (int i = 0; i < rains.size(); i++) {
      if (rains[i] == 0) {
        // 暂时记作随机清理1号湖 lake1,因为不下雨什么都不做，记为-1是错的
        ans[i] = 1;
        workDaysList.push_back({i, {rains[i]}});

      } else if (lakeMap.count(rains[i]) == 0) {
        if (workDaysList.empty() || workDaysList.back().first > 0) {
          workDaysList.push_back({-1, {}});
        } else {
          workDaysList.back().first -= 1;
          // workDaysList.back().second.push_back(rains[i]);
          workDaysList.back().second.insert(rains[i]);
        }

        lakeMap[rains[i]] = (--(workDaysList.end()));
      } else {

        auto count_iter = lakeMap[rains[i]];

        auto base = count_iter;
        auto p_iter = (++base);

        while (p_iter != workDaysList.begin() && p_iter->first <= 0) {

          for (auto lakeId : p_iter->second) {
            lakeMap[lakeId] = count_iter;
            count_iter->second.insert(lakeId);
          }
          count_iter->first += p_iter->first;
          

          // begin(p_iter->second), end(p_iter->second)
          auto cur = p_iter;
          p_iter++;
          workDaysList.erase(cur);
        }

        if (p_iter == workDaysList.end()) {
          return vector<int>{};
        }

        auto workdays_iter = p_iter;

        ans[workdays_iter->first] = rains[i];
        workDaysList.erase(workdays_iter);

        count_iter->first = count_iter->first + 1;
        count_iter->second.erase(rains[i]);

        if (count_iter->first == 0) {
          workDaysList.erase(count_iter);
        }

        if (workDaysList.empty() || workDaysList.back().first > 0) {
          workDaysList.push_back({-1, {rains[i]}});
        } else {
          workDaysList.back().first -= 1;
          workDaysList.back().second.insert(rains[i]);
        }

        lakeMap[rains[i]] = (--(workDaysList.end()));
      }
    }
    return ans;
  }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName= avoidFlood
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,0,0,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,0,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,3,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,2,0,3,0,2,0,0,0,1,2,3]\n
// @lcpr case=end

// @lcpr case=start
//[24526,23938,93949,0,61370,0,0,80971,0,0,0,55547,0,80482,74942,77698,54795,0,0,0,0,77698,0,0,54410,0,0,23938,0,0,0,0,0,0,75018,0,0,47564,0,24526,0,0,0,48639,0,68554,39045,75357,48639,6992,0,47564,54410,0,0,0,74942,6992,40783,82220,0,75018,0,61370,0,0,68554,0,0,82220,0,40783,55547,80971,0,93949,87360,0,87360,39045,0,80482,75357,0,0,54795]\n
// @lcpr case=end

// @lcpr case=start
//[0,72328,0,0,94598,54189,39171,53361,0,0,0,72742,0,98613,16696,0,32756,23537,0,94598,0,0,0,11594,27703,0,0,0,20081,0,24645,0,0,0,0,0,0,0,2711,98613,0,0,0,0,0,91987,0,0,0,22762,23537,0,0,0,0,54189,0,0,87770,0,0,0,0,27703,0,0,0,0,20081,16696,0,0,0,0,0,0,0,35903,0,72742,0,0,0,35903,0,0,91987,76728,0,0,0,0,2711,0,0,11594,0,0,22762,24645,0,0,0,0,0,53361,0,87770,0,0,39171,0,24577,0,0,0,24577,0,0,72328,0,0,32756,0,0,76728]\n
// @lcpr case=end
 */
// int main() {
//   Solution sol;
//   vector<int> rains = {
//       24526, 23938, 93949, 0,     61370, 0,     0,     80971, 0,     0,
//       0,     55547, 0,     80482, 74942, 77698, 54795, 0,     0,     0,
//       0,     77698, 0,     0,     54410, 0,     0,     23938, 0,     0,
//       0,     0,     0,     0,     75018, 0,     0,     47564, 0,     24526,
//       0,     0,     0,     48639, 0,     68554, 39045, 75357, 48639, 6992,
//       0,     47564, 54410, 0,     0,     0,     74942, 6992,  40783, 82220,
//       0,     75018, 0,     61370, 0,     0,     68554, 0,     0,     82220,
//       0,     40783, 55547, 80971, 0,     93949, 87360, 0,     87360, 39045,
//       0,     80482, 75357, 0,     0,     54795};
//   auto ans = sol.avoidFlood(rains);
//   for (auto x : ans) {
//     cout << x << " ";
//   }
//   cout << endl;
//   return 0;
// }
