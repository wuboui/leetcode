/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:

Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
Example 5:

Input:
s = "acdcb"
p = "a*c?b"
Output: false
*/
/*
i think before this problem is too complicated, when i see others solution.
*/
/*
Author:alkenwu
*/


#include <string>
using std::string;
class Wildcard_Matching
{
public:
    bool isMatch(string s, string p)
    {
        return Match(s, p, 0, 0);
    }

    bool Match(string s, string p, size_t index_s, size_t index_p)
    {
        size_t haveall = -1, index = -1;;
        size_t i = index_p;
        size_t k = index_s;
        for (; k < s.length();)
        {
            if (i < p.length() && p[i] == s[k])
            {
                ++i;
                ++k;
                continue;
            }
            else if (p[i] == '*')
            {
                while (p[i] == '*')
                {
                    ++i;
                }
                index = k;
                haveall = i;
                continue;
            }
            else if (p[i] == '?')
            {
                ++i;
                ++k;
                continue;
            }
           
            if (haveall)
            {
                ++index;
                i = haveall;
                k = index;
                continue;
            }
            else return false;
           
        }
       while (i < p.length() && p[i] == '*')
            ++i;
        return i == p.length();
    }
};  