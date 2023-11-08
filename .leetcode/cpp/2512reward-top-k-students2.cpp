/*
 * @lc app=leetcode.cn id=2512 lang=cpp
 * @lcpr version=21917
 *
 * [2512] 奖励最顶尖的 K 名学生
 *
 * https://leetcode.cn/problems/reward-top-k-students/description/
 *
 * algorithms
 * Medium (46.48%)
 * Likes:    56
 * Dislikes: 0
 * Total Accepted:    20.7K
 * Total Submissions: 38.5K
 * Testcase Example:  '["smart","brilliant","studious"]\n' +
  '["not"]\n' +
  '["this student is studious","the student is smart"]\n' +
  '[1,2]\n' +
  '2'
 *
 * 给你两个字符串数组 positive_feedback 和 negative_feedback ，分别包含表示正面的和负面的词汇。不会
 * 有单词同时是正面的和负面的。
 *
 * 一开始，每位学生分数为 0 。每个正面的单词会给学生的分数 加 3 分，每个负面的词会给学生的分数 减  1 分。
 *
 * 给你 n 个学生的评语，用一个下标从 0 开始的字符串数组 report 和一个下标从 0 开始的整数数组 student_id 表示，其中
 * student_id[i] 表示这名学生的 ID ，这名学生的评语是 report[i] 。每名学生的 ID 互不相同。
 *
 * 给你一个整数 k ，请你返回按照得分 从高到低 最顶尖的 k 名学生。如果有多名学生分数相同，ID 越小排名越前。
 *
 *
 *
 * 示例 1：
 *
 * 输入：positive_feedback = ["smart","brilliant","studious"], negative_feedback =
 * ["not"], report = ["this student is studious","the student is smart"],
 * student_id = [1,2], k = 2
 * 输出：[1,2]
 * 解释：
 * 两名学生都有 1 个正面词汇，都得到 3 分，学生 1 的 ID 更小所以排名更前。
 *
 *
 * 示例 2：
 *
 * 输入：positive_feedback = ["smart","brilliant","studious"], negative_feedback =
 * ["not"], report = ["this student is not studious","the student is smart"],
 * student_id = [1,2], k = 2
 * 输出：[2,1]
 * 解释：
 * - ID 为 1 的学生有 1 个正面词汇和 1 个负面词汇，所以得分为 3-1=2 分。
 * - ID 为 2 的学生有 1 个正面词汇，得分为 3 分。
 * 学生 2 分数更高，所以返回 [2,1] 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= positive_feedback.length, negative_feedback.length <= 10^4
 * 1 <= positive_feedback[i].length, negative_feedback[j].length <= 100
 * positive_feedback[i] 和 negative_feedback[j] 都只包含小写英文字母。
 * positive_feedback 和 negative_feedback 中不会有相同单词。
 * n == report.length == student_id.length
 * 1 <= n <= 10^4
 * report[i] 只包含小写英文字母和空格 ' ' 。
 * report[i] 中连续单词之间有单个空格隔开。
 * 1 <= report[i].length <= 100
 * 1 <= student_id[i] <= 10^9
 * student_id[i] 的值 互不相同 。
 * 1 <= k <= n
 *
 *
 */
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <ranges>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start

struct Info {
    int id;
    int score;
    Info(int _id, int _score)
        : id(_id)
        , score(_score)
    {
    }
    auto operator<(const Info& other) -> bool
    {
        return (this->score == other.score) ? this->id > other.id : this->score
 > other.score;
	
    }
};
class Solution {
private:
    unordered_map<string, int> scoreMap;
    const int POSITIVE_SCORE = 3;
    const int NEGATIVE_SCORE = -1;
    const char DELIM = ' ';

public:
    auto topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) -> vector<int>
    {
        for (auto& entry : positive_feedback) {
            scoreMap[entry] = POSITIVE_SCORE;
        }

        for (auto& entry : negative_feedback) {
            scoreMap[entry] = NEGATIVE_SCORE;
        }
        vector<Info> docs;
        int studentIndex = 0;
        for (auto& str : report) {
            Info stuInfo = { student_id[studentIndex], 0 };
            int index = (int)str.find(DELIM);
            int preIndex = 0;
            while (index != string::npos) {
                while (preIndex < str.size() && str[preIndex] == ' ') {
                    preIndex++;
                }

                if (preIndex >= str.size()) {
                    break;
                }

                stuInfo.score += scoreMap[str.substr(preIndex, index - preIndex)];
                index++;
                preIndex = index;
                index = (int)str.find(DELIM, index);
            }
            if (preIndex < str.size()) {
                stuInfo.score += scoreMap[str.substr(preIndex, str.size() - preIndex)];
            }
            docs.push_back(stuInfo);
            studentIndex++;
        }
        sort(begin(docs), end(docs));
        vector<int> res;
        res.reserve(k);
        for (int i = 0; i < k; i++) {
            res.push_back(docs[i].id);
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["smart","brilliant","studious"]\n["not"]\n["this student isstudious","the student is smart"]\n[1,2]\n2\n
// @lcpr case=end

// @lcpr case=start
// ["smart","brilliant","studious"]\n["not"]\n["this student is notstudious","the student is smart"]\n[1,2]\n2\n
// @lcpr case=end

 */
