/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
[1, 7],
[1, 2, 5],
[2, 6],
[1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
[1,2,2],
[5]
]

*/

/*
Author: AlkenWu
*/
#include <vector>
#include <algorithm>
using std::vector;
class Solution {
public:
	vector<vector<int>> ans;
	vector<int>         comb;

	void combination(vector<int> &nums, int pos, int target) {
		if (target < 0)
			return;

		if (target == 0) {
			ans.push_back(comb);
			return;
		}

		if (pos == nums.size())
			return;

		for (int i = pos; i < nums.size(); ++i) {
			if (nums[i] <= target) {
				comb.push_back(nums[i]);
				combination(nums, i + 1, target - nums[i]);
				comb.pop_back();
			}
		}
	}

public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		ans.clear();
		sort(candidates.begin(), candidates.end());
		for (int i = 0; i < candidates.size(); ++i)
		{
			while (i != 0 && candidates[i - 1] == candidates[i])
				++i;
			if (candidates[i] <= target) {
				comb.push_back(candidates[i]);
				combination(candidates, i + 1, target - candidates[i]);
				comb.pop_back();
			}
		}
		return ans;
	}
};