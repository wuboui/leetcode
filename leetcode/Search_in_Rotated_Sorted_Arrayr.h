/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

*/

/*
i have two solusion for this problem,the second solusion is that i have learned from others

Author:Alken
*/

class Search {
public:
	int search(vector<int>& nums, int target) {
		/* this is the second solusion that used binaty search */
		if (nums.empty())
			return -1;
		if (nums.size() == 1)
			return nums[0] == target ? 0 : -1;
		size_t middle = 0;
		int l = 0;
		int r = nums.size() - 2;
		while (l <= r && nums.size() >= 2)
		{
			size_t m = (l + r) / 2;
			if (nums[m] > nums[m + 1])
				middle = m;
			if (nums[m] > nums.back())
				l = m + 1;
			else
				r = m - 1;
		}
		l = target >= nums.front() ? 0 : middle + 1;
		r = target >nums.back() ? middle : nums.size() - 1;
		while (l <= r)
		{
			size_t m = (l + r) / 2;
			if (target == nums[m])
				return m;
			if (nums[m] >= target)
				r = m - 1;
			else
				l = m + 1;
		}
		return -1;
		/*
		this is the first solusion that finished by me only

		if (nums.empty())
			return -1;
		if (nums.size() == 1)
			return nums[0] == target ? 0 : -1;
		int count = 0;
		int index = -1;
		if (nums[0] < nums.back())
		{
			for (int i = 0; i< nums.size() - 1; ++i)
			{
				if (nums[i] > nums[i + 1])
					return -1;
				if (target == nums[i])
					index = i;
				if (target == nums[i + 1])
					index = i + 1;
			}
		}
		else
		{
			count = 1;

			for (int i = 0; i< nums.size() - 1; ++i)
			{
				if (nums[i] > nums[i + 1])
				{
					if (count)
						--count;
					else
						return -1;
				}
				if (target == nums[i])
					index = i;
				if (target == nums[i + 1])
					index = i + 1;
			}
		}
		return index;*/
	}
};