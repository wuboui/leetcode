/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

*/
/*
the result is unexcepted for me

Author: AlkenWu
*/

class Find {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result;
		if (nums.empty())
		{
			result.push_back(-1);
			result.push_back(-1);
			return result;
		}
		if (nums.size() == 1 && nums[0] == target)
		{
			result.push_back(0);
			result.push_back(0);
			return result;
		}
		int start = -1, end = -1;
		for (size_t i = 0; i <= nums.size() - 2; ++i)
		{
			if (nums[i] > nums[i + 1])
			{
				result.push_back(-1);
				result.push_back(-1);
				return result;
			}
			if (start == -1 && nums[i] == target)
			{
				start = end = i;
			}
			if (start != -1 && nums[i + 1] == target)
			{
				end = i + 1;
			}
			if (start == -1 && nums[i + 1] == target)
			{
				start = end = i + 1;
			}
		}
		result.push_back(start);
		result.push_back(end);
		return result;
	}
};
