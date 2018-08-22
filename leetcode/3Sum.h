/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 

Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.
*/
/*
this solusion use time too long,optimized after
*/
#include <vector>
#include <algorithm> 
#include<stdio.h>
using std::vector;
class ThreeSum
{
public:
	vector<vector<int>> threesum(vector<int>& nums)
	{
		vector<vector<int>> res;
		if (nums.size() <= 2)
			return res;
		int len = nums.size();
		int index_half = 0;
		int index_start = 0;
		int index_end = 0;
		std::sort(nums.begin(),nums.end());
		vector<int> temp;
		for (int i = 0; i < len-2;)
		{
			
			for (int j = i + 1; j < len - 1; )
			{
				if (nums[i] + nums[j] + nums[len - 1] < 0)
				{
					++j;
					continue;
				}
				index_half = (len - j - 1 )/ 2 + j;
				if (index_half == j)
					++index_half;
				index_start = j;
				index_end = len - 1;
				while (1)
				{	
					if (index_half <= j) break;
					
					if (nums[i] + nums[j] + nums[index_half] == 0)
					{
						temp.push_back(nums[i]);
						temp.push_back(nums[j]);
						temp.push_back(nums[index_half]);
						res.push_back(temp);
						temp.clear();
						break;
					}
					else if (nums[i] + nums[j] + nums[index_half] < 0)
					{
						if (index_half == len - 1 || index_half == index_start)
							break;
						index_start = index_half;
						index_half = index_half == len - 2 ? len - 1 : index_half + (index_end - index_half) / 2;
					}
					else
					{
						if (index_half == 0 || index_half == index_end)
							break;
						index_end = index_half;
						index_half = index_half == 1? 0: index_half - (index_half -index_start) / 2;

					}
				}
				++j;
				while (j < len -1 && nums[j] == nums[j - 1])
				{
					++j;
				}
			}
			++i;
			while (i < len -2 &&nums[i] == nums[i - 1])
			{
				++i;
			}
		}
		return res;
	}
};
