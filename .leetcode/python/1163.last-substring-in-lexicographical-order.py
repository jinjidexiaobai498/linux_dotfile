#
# @lc app=leetcode.cn id=1163 lang=python3
# @lcpr version=21917
#
# [1163] 按字典序排在最后的子串
#
# https://leetcode.cn/problems/last-substring-in-lexicographical-order/description/
#
# algorithms
# Hard (35.06%)
# Likes:    182
# Dislikes: 0
# Total Accepted:    22.6K
# Total Submissions: 64.3K
# Testcase Example:  '"abab"'
#
# 给你一个字符串 s ，找出它的所有子串并按字典序排列，返回排在最后的那个子串。
#
#
#
# 示例 1：
#
# 输入：s = "abab"
# 输出："bab"
# 解释：我们可以找出 7 个子串 ["a", "ab", "aba", "abab", "b", "ba", "bab"]。按字典序排在最后的子串是
# "bab"。
#
#
# 示例 2：
#
# 输入：s = "leetcode"
# 输出："tcode"
#
#
#
#
# 提示：
#
#
# 1 <= s.length <= 4 * 10^5
# s 仅含有小写英文字符。
#
#
#


# @lc code=start
class Solution:
    def lastSubstring(self, s: str) -> str:
        len = 0
        startIndex = 0
        stack = list()

        pass


# 16  分钟


# @lc code=end


#
# @lcpr case=start
# "abab"\n
# @lcpr case=end

# @lcpr case=start
# "leetcode"\n
# @lcpr case=end

#
