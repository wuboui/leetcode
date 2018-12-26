/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
["ate","eat","tea"],
["nat","tan"],
["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/
#include <vector>
#include <string>
using std::vector;
using std::string;
class Group_Anagrams {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> str_m(27,0);
        str_m.resize(27);
        vector<vector<string> > res;
        vector<string> vec;
        size_t len = 0;
        for (auto itr = strs.begin(); itr != strs.end(); ++itr)
        {
            if (*itr == "A") continue;
            vector<int> vec1 = str_m;
            len = itr->length();
            for (size_t i = 0; i < len; ++i)
                ++vec1[(*itr)[i] - 'a'];
            find_group(strs, vec1, len, vec);
            res.push_back(vec);
        }
        return res;
    }

    void find_group(vector<string>& strs, vector<int>& num_arr, int len, vector<string>& res)
    {
        vector<int> nums = num_arr;
        for (auto itr = strs.begin(); itr != strs.end(); ++itr)
        {
            if (itr->length() != len) continue;
            auto i = 0;
            for (; i < len; ++i)
            {
                if (nums[(*itr)[i] - 'a'] <= 0)
                {
                    i = -1;
                    break;
                }
                --nums[(*itr)[i] - 'a'];
            }
            if (i != -1)
            {
                res.push_back(*itr);
                itr->clear();
            }
        }
    }
};