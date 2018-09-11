/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 �� 1,3,2
3,2,1 �� 1,2,3
1,1,5 �� 1,5,1
*/
/*
i think this problem just like  a question that have to find the law;
author: Alkenwu
*/
#include <stdio.h>
#include<vector>
#include <algorithm>
using std::vector;
class Next_Permutation{
public:
	void nextPermutation(vector<int>& nums) {
		int num = 0;
		bool bhavesort = false;
		vector<int>::reverse_iterator  iter;
		for (vector<int>::reverse_iterator itr = nums.rbegin(); itr != nums.rend(); ++itr)
		{
			if (itr + 1 != nums.rend() && *itr > *(itr + 1))
			{
				num = *(itr + 1);
				iter = itr + 1;
				std::sort(nums.rbegin(), itr+1, [](int a, int b){
					return a > b;
				}
			);
				break;
			}
			else if (itr + 1 == nums.rend())
			{
				bhavesort = true;
			}
		}
		if (bhavesort)
		{
			std::sort(nums.begin(), nums.end());
		}
		else
		{
			for (vector<int>::reverse_iterator itr = nums.rbegin(); itr != nums.rend(); ++itr)
			{
				if (num >= *itr)
				{
					*iter = *(itr - 1);
					*(itr - 1) = num;
					break;
				}
			}
		}
	}
};