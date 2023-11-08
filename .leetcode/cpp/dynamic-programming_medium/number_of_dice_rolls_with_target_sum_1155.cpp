// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1155 lang=cpp
 * @lcpr version=30102
 *
 * [1155] 掷骰子等于目标和的方法数
 *
 * https://leetcode.cn/problems/number-of-dice-rolls-with-target-sum/description/
 *
 * algorithms
 * Medium (51.29%)
 * Likes:    175
 * Dislikes: 0
 * Total Accepted:    20.3K
 * Total Submissions: 39.3K
 * Testcase Example:  '1\n6\n3'
 *
 * 这里有 n 个一样的骰子，每个骰子上都有 k 个面，分别标号为 1 到 k 。
 *
 * 给定三个整数 n ,  k 和 target ，返回可能的方式(从总共 k^n 种方式中)滚动骰子的数量，使正面朝上的数字之和等于 target 。
 *
 * 答案可能很大，你需要对 10^9 + 7 取模 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 1, k = 6, target = 3
 * 输出：1
 * 解释：你扔一个有 6 个面的骰子。
 * 得到 3 的和只有一种方法。
 *
 *
 * 示例 2：
 *
 * 输入：n = 2, k = 6, target = 7
 * 输出：6
 * 解释：你扔两个骰子，每个骰子有 6 个面。
 * 得到 7 的和有 6 种方法：1+6 2+5 3+4 4+3 5+2 6+1。
 *
 *
 * 示例 3：
 *
 * 输入：n = 30, k = 30, target = 500
 * 输出：222616187
 * 解释：返回的结果必须是对 10^9 + 7 取模。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n, k <= 30
 * 1 <= target <= 1000
 *
 *
 */

// @lcpr-template-start
#include <algorithm>
#include <array>
#include <bitset>
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
// @lcpr-template-end
// @lc code=start

class Solution {
public:
    auto numRollsToTarget(int n, int k, int target) -> int
    {
        auto dp = vector<int>(target + 1, 0);
        const int MOD = 1e9 + 7;
        dp[0] = 1;

        for (int _n = 1; _n <= min(target, n); _n++) {
            int end = min(target, _n * k);
            dp[end] = 0;

            //通过 sum (|i=1~k| f(x-i,n-1)) 求出最后一位 f(end,n)的值,来逆推其他值
            for (int i = 1; i <= k; i++) {
                dp[end] += end - i >= 0 ? dp[end - i] : 0;
                while (dp[end] >= MOD) {
                    dp[end] -= MOD;
                }
                while (dp[end] < 0) {
                    dp[end] += MOD;
                }
            }

            for (int tar = end - 1; tar >= _n; tar--) {
                dp[tar] = dp[tar + 1] - dp[tar] + (tar > k ? dp[tar - k] : 0);
                while (dp[tar] >= MOD) {
                    dp[tar] -= MOD;
                }
                while (dp[tar] < 0) {
                    dp[tar] += MOD;
                }
            }

            //进入下一论前，删除不合法值，删除 0~_n -1,和 大于(_n-1)*k的值为 0,这里只需要把dp[n-1] = 0 ,其他值都会自动被覆盖或者为初始值0,未被访问,
            dp[_n - 1] = 0;
        }

        return dp[target];
    }
};
// @lc code=end

/*
// @lcpr case=start
// 1\n6\n3\n
// @lcpr case=end

// @lcpr case=start
// 2\n6\n7\n
// @lcpr case=end

// @lcpr case=start
// 30\n30\n500\n
// @lcpr case=end

 */
