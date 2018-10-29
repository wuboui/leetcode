/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
[1,2,3],
[1,3,2],
[2,1,3],
[2,3,1],
[3,1,2],
[3,2,1]
]

*/

#include <vector>

using std::vector;
class Permutations {
public:
    vector<vector<int> > __result;
    int count;
    vector<vector<int>> permute(vector<int>& nums) {
        __result.clear(); 
        vector<int> res;
        count = 0;
        res.reserve(nums.size());
        get_permutations(nums, res);
        return __result;
    }

    void get_permutations(vector<int> nums, vector<int> res)
    {
        if (nums.size() == count)
        {
            __result.push_back(res);
            return;
        }
        int temp = 0;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != -100)
            {
                res.push_back(nums[i]);
                temp = nums[i];
                nums[i] = -100;
                ++count;
                get_permutations(nums, res);
                nums[i] = temp;
                --count;
                res.pop_back();
            }
        }
    }
};