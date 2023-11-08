// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1643 lang=cpp
 * @lcpr version=30102
 *
 * [1643] 第 K 条最小指令
 *
 * https://leetcode.cn/problems/kth-smallest-instructions/description/
 *
 * algorithms
 * Hard (48.44%)
 * Likes:    56
 * Dislikes: 0
 * Total Accepted:    3.5K
 * Total Submissions: 7.3K
 * Testcase Example:  '[2,3]\n1'
 *
 * Bob 站在单元格 (0, 0) ，想要前往目的地 destination ：(row, column) 。他只能向
 * 右 或向 下 走。你可以为 Bob 提供导航 指令 来帮助他到达目的地 destination 。
 *
 * 指令 用字符串表示，其中每个字符：
 *
 *
 * 'H' ，意味着水平向右移动
 * 'V' ，意味着竖直向下移动
 *
 *
 * 能够为 Bob 导航到目的地 destination 的指令可以有多种，例如，如果目的地
 * destination 是 (2, 3)，"HHHVV" 和 "HVHVH" 都是有效 指令 。
 *
 *
 *
 *
 * 然而，Bob 很挑剔。因为他的幸运数字是 k，他想要遵循 按字典序排列后的第 k
 * 条最小指令 的导航前往目的地 destination 。k  的编号 从 1 开始 。
 *
 * 给你一个整数数组 destination 和一个整数 k ，请你返回可以为 Bob
 * 提供前往目的地 destination 导航的 按字典序排列后的第 k 条最小指令 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：destination = [2,3], k = 1
 * 输出："HHHVV"
 * 解释：能前往 (2, 3) 的所有导航指令 按字典序排列后 如下所示：
 * ["HHHVV", "HHVHV", "HHVVH", "HVHHV", "HVHVH", "HVVHH", "VHHHV", "VHHVH",
 * "VHVHH", "VVHHH"].
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：destination = [2,3], k = 2
 * 输出："HHVHV"
 *
 *
 * 示例 3：
 *
 *
 *
 * 输入：destination = [2,3], k = 3
 * 输出："HHVVH"
 *
 *
 *
 *
 * 提示：
 *
 *
 * destination.length == 2
 * 1 <= row, column <= 15
 * 1 <= k <= nCr(row + column, row)，其中 nCr(a, b) 表示组合数，即从 a
 * 个物品中选 b 个物品的不同方案数。
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
#include <sstream>
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
    auto kthSmallestPath(vector<int>& destination, int k) -> string
    {
        int sum = destination[0] + destination[1];
        char ss[sum + 1];
        ss[sum] = '\0';

        int s_index = 0;
        const int n = destination[1];
        const int x = destination[0];
        auto dp = vector<vector<int>>(n + 1, vector<int>(x + 1, 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= x; j++) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        int ix = n;
        int iy = x;
        while (ix > 0) {
            if (k <= dp[ix - 1][iy]) {
                ss[s_index++] = 'H';
                ix -= 1;
            } else {
                ss[s_index++] = 'V';
                k -= dp[ix - 1][iy];
                iy -= 1;
            }
        }
        while (s_index < sum) {
            ss[s_index++] = 'V';
        }

        return ss;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName= kthSmallestPath
// paramTypes= ["number[]","number"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [2,3]\n1\n
// @lcpr case=end

// @lcpr case=start
// [2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [2,3]\n3\n
// @lcpr case=end

 */
