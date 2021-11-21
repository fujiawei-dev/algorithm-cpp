//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。 
//
// 有效括号组合需满足：左括号必须以正确的顺序闭合。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 3
//输出：["((()))","(()())","(())()","()(())","()()()"]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：["()"]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 8 
// 
// Related Topics 字符串 动态规划 回溯 👍 2159 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<vector<string>>results = { {""}, {"()"}};
		for (int i = 2; i < n + 1; i++)
		{
			vector<string>result;
			for (int j = 0; j < i; j++)
			{
				vector<string>l1 = results[j];
				vector<string>l2 = results[i-1-j];
				for (int i1 = 0; i1 < l1.size(); i1++)
				{
					for (int i2 = 0; i2 < l2.size(); i2++)
					{
						result.push_back("(" + l1[i1] + ")" + l2[i2]);
					}
				}
			}
			results.push_back(result);
		}
		return results[n];
	}
};
//leetcode submit region end(Prohibit modification and deletion)
