/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
*/
/*
use other's submission

let me know a explaintion that use a data struct . 
*/
#include <string>
#include<stdio.h>
#include<stack>
#include<map>
using std::pair;
using std::stack;
using std::string;
class Longest_Valid_Parentheser{
public:
	int longestValidParentheses(string s) {
		/*if (s.length() <= 1)
			return 0;
			int result = 0;
			int left = 0;
			for (size_t i = 0; i <= s.length() - 1; ++i)
			{
			if (s[i] == ')' && left == 0)
			{
			continue;
			}
			if (s[i] == '(')
			{
			++left;
			}
			else if (s[i] == ')')
			{
			--left;
			result += 2;
			}

			}
			return result;*/
		int max = 0;
		stack<pair<int, int>> calStack;
		int prevLength = 0;
		size_t i = 0;
		while (i < s.length()) {
			if (s[i] == '(') {
				calStack.push(pair<int, int>(i, prevLength));
				prevLength = 0;
				i++;
				continue;
			}

			//s[i]==')'
			if (calStack.empty()) {
				prevLength = 0;
				i++;
				continue;
			}

			auto p = calStack.top();
			calStack.pop();
			int newL = i - p.first + 1 + p.second;
			if (newL > max) {
				max = newL;
			}
			prevLength = newL;
			i++;
		}

		return max;
	}
};