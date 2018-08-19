/*You are playing the following Flip Game with your friend: Given a string that contains only these two characters : +and - , 
you and your friend take turns to flip two consecutive "++" into "--".The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to compute all possible states of the string after one valid move.*/
#include<stdio.h>
#include <vector>
#include <string>
using std::vector;
using std::string;
class flipgame
{
public:
	vector<string> generatePossibleNextMoves(string &s) {
		// write your code here
		vector<string> vec_str;
		if (s.length() < 2)
			return vec_str;
		string str = s;
		for (int i = 0; i < s.length() - 1; ++i)
		{
			if (s[i] == s[i + 1] && s[i] == '+')
			{
				str = s;
				str[i] = str[i + 1] = '-';
				vec_str.push_back(str);
				
			}
		}
		return vec_str;
	}
};
