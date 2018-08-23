/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

*/
/*
through this problem let me know how different in the leetcode level 
*/
/*
author: Alkenwu
*/
#include<stdio.h>
#include <vector>
#include <string>
using std::vector;
using std::string;
class lettercombation
{
public:
	vector<string> letterCombinations(string digits) {
		vector<int> nums;
		nums.reserve(digits.length());
		vector<string> vec_str;
		if (digits.length() <= 0)
			return vec_str;
		vec_str.reserve(8);
		vec_str.push_back("abc");
		vec_str.push_back("def");
		vec_str.push_back("ghi");
		vec_str.push_back("jkl");
		vec_str.push_back("mno");
		vec_str.push_back("pqrs");
		vec_str.push_back("tuv");
		vec_str.push_back("wxyz");
		vector<string> vec_res;
		int num;
		int vec_size = 1;
		for (size_t i = 0; i < digits.length(); ++i)
		{
			num = digits[i] - '0';
			if (num >= 2 && num <= 9)
			{
				vec_size *= vec_str[num - 2].length();
				nums.push_back(num);
			}
			else
				return  vec_res;
		}
		vec_res.reserve(vec_size);
		std::vector<string> vec_temp;
		string str;
		for (size_t j = 0; j < vec_str[nums[0] - 2].length(); ++j)
		{
			str = "";
			str += vec_str[nums[0] - 2][j];
			vec_res.push_back(str);
		}
		vec_temp = vec_res;
		for (size_t i = 1; i < digits.length(); ++i)
		{
			vec_res.clear();
			for (auto itr = vec_temp.begin(); itr != vec_temp.end(); ++itr)
			{
				for (size_t j = 0; j < vec_str[nums[i] -2 ].length(); ++j)
				{
					str = *itr;
					str += vec_str[nums[i] - 2][j];
					vec_res.push_back(str);
				}
			}
			vec_temp = vec_res;
		}
		return vec_res;
	}

};