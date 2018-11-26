/*
The n-queens puzzle is the problem of placing n queens on an n¡Án chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:

Input: 4
Output: [
[".Q..",  // Solution 1
"...Q",
"Q...",
"..Q."],

["..Q.",  // Solution 2
"Q...",
"...Q",
".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
*/

#include<vector>
#include<string>
#include<map>
using std::string;
using std::vector;
using std::pair;

class N_Queens{
public:
    vector<pair<int, int>> vec_num;
    vector<vector<string>> vec_res;
    vector<vector<string>> solveNQueens(int n) {

        if (n == 1)
            return vector<vector<string> >(1, vector<string>(1,"Q"));

        if (n <= 3)
            return vector<vector<string>>();
        sloveQ_i(n, n, vector<string>());
        return vec_res;

        // for(siz)

    }

    void sloveQ_i(int n, int num, vector<string> vec_str)
    {

        if (num == 0)
        {
            vec_res.push_back(vec_str);
            return;
        }
        vector<int> vec_row(n, 1);
        string str(n, '.');

        for (auto itr = vec_num.begin(); itr != vec_num.end(); ++itr)
        {
            vec_row[itr->first] = 0;
            if (itr->first - (- num + itr->second) >= 0)
                vec_row[itr->first - (- num + itr->second)] = 0;
            if (itr->first + (-num + itr->second) < n)
                vec_row[itr->first + ( -num + itr->second)] = 0;

        }
        for (size_t i = 0 ; i < n; ++i)
        {
            if (vec_row[i] != 0)
            {
                str[i] = 'Q';
                vec_str.push_back(str);
                vec_num.push_back(std::make_pair(i, num));
                //vec
                sloveQ_i(n, num - 1, vec_str);
                vec_str.pop_back();
                vec_num.pop_back();
                str[i] = '.';
            }
        }
    }
};