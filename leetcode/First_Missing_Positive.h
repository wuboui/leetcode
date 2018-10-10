/*
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Note:

Your algorithm should run in O(n) time and uses constant extra space.

*/
/*
Author:AlkenWu
*/

#include <vector>
#include <algorithm>
using std::vector;
class MissingPositive{
public:
	int firstMissingPositive(vector<int>& nums) {
		if (nums.empty())
			return 1;
		sort(nums.begin(), nums.end());
		int end = nums.size() - 1;
		int start = 0;
		size_t index = 0;
		while (end > start)
		{
			index = start + (end - start) / 2;
			if (nums[index] == 0 || nums[start] == 0 || nums[end] == 0)
			{
				if (nums[start] == 0)
					index = start;

				else if (nums[end] == 0)
					index = start;
				break;
			}
			

			if (nums[index + 1] / nums[index] <= 0)
				break;

			if (nums[index]> 0)
			{
				end = index;
			}
			else
			{
				start = index;
			}
		}
		while (nums[index] <= 0 && index< nums.size() - 1)
			++index;
		if (nums[index] != 1)
			return 1;
		for (size_t i = index; i<nums.size() - 1; ++i)
		{
			if (nums[i + 1] - nums[i] > 1)
				return nums[i] + 1;
		}
		return nums.back() + 1;
	}
};