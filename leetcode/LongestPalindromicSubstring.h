/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
*/
#include <string>
#include <stdio.h>
#include <iostream>
using std::string;
class PalindromicSubstring
{
public:
	bool IsPalindromicSubstringIns(string&  str, bool bhavend, string& s,int index,int& index_sub,int& len_sub)
	{
 		int len = str.length();
		if (bhavend)
		{
			for (int i = 0; i < len; ++i)
			{
				if (s[index + len + i] != str[len - i - 1])
				{
					if (i > 0)
					{
						index_sub = len - 1;
						len_sub = i;
						return true;
						
					}
					else
					{
						return 0;
					}
				
				}
			}
		}
		else
		{
			for (int i = 0; i < len -1; ++i)
			{
				if (s[index + len + i] != str[len - i -2])
				{
					if (i > 0)
					{
						index_sub = len - 1;
						len_sub = i + 1;
						return true;
					}
					else
					{
						return 0;
					}

				}
			}
		}
		len_sub = len;
		index_sub = len - 1;
		return true;
	};
	void GetSubstring(string& s, string& substring, int index, int num)
	{
		substring.clear();
		for (int i = 0; i<num; ++i)
		{
			substring += s[index + i];
		}
	};
	string longestPalindrome(string s) {
		string sub;
		if (s.length() <= 0 || s.length() > 1000)
			return sub;
		
		int temp_index = 0;
		string tempsub;
		bool bhavend;
		int index = 0;
		int len = 0;
		int temp_len = 0;
		for (int i = 1; i <= s.length(); ++i)
		{
			
			GetSubstring(s, tempsub, 0, i);
			if (IsPalindromicSubstringIns(tempsub, true, s, 0, temp_index,temp_len)  && temp_len*2 >len)
			{
				index = temp_index;
				len = temp_len * 2;
				bhavend = true;
			}
			else if (IsPalindromicSubstringIns(tempsub, false, s, 0, temp_index, temp_len) && temp_len * 2 - 1 > len)
			{
				index = temp_index;
				bhavend = false;
				len = temp_len * 2 - 1;
			}
		}
		
		if (len != 0)
		{
			sub = s.substr(index - ((len - 1) / 2), len);
		}
		return sub;
	}
};