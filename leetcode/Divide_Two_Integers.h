/*
Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. 
For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
*/
/*
it isn't work that use traditional way,so the bit operation bear in mind 
Author by Alkenwu
*/


class Solution {
public:
	int divide(int dividend, int divisor) {

		if (!divisor || (dividend == INT_MIN && divisor == -1))
			return INT_MAX;
		bool bdf = false;
		int result = 0;
		if (dividend == INT_MIN)
		{
			if (divisor > 0)
			{
				bdf = true;
				dividend |= divisor;
				++result;
			}
			else
			{
				dividend |= -divisor;
				++result;
			}
		}
		if (divisor == INT_MIN)
		{
			return result;
		}
		if (dividend< 0 && divisor > 0)
		{
			bdf = true;
			div(-dividend, divisor, result);
		}
		else if (dividend > 0 && divisor < 0)
		{
			bdf = true;
			div(dividend, -divisor, result);
		}
		else if (dividend < 0 && divisor < 0)
		{
			div(-dividend, -divisor, result);
		}
		else
		{
			div(dividend, divisor, result);
		}
		return bdf ? -result : result;
	}
	void div(int dividend, int divisor, int& res)
	{
		if (dividend < divisor)
		{
			return;
		}
		int mul = 1;
		long long  temp = divisor;
		while (divisor <= dividend)
		{
			temp = divisor;
			mul = 1;
			while (dividend >= temp << 1)
			{
				temp <<= 1;
				mul <<= 1;
			}
			dividend -= temp;
			res += mul;
		}

	}
};