/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'.


A sudoku puzzle...


...and its solution numbers marked in red.

Note:

The given board contain only digits 1-9 and the character '.'.
You may assume that the given Sudoku puzzle will have a single unique solution.
The given board size is always 9x9.

*/
/*
it is important that the stack capacity if use recursive 
*/
/*
Author: AlkenWu
*/
#pragma once
#include<stdio.h>
#include<vector>
using std::vector;

#define  fun(x,y) (x*9+y)  

class SuDoKu
{
public:
	vector< vector<char> >* board;
	vector<vector<char> > nums;
	int count = 0;
	void set_board(vector< vector<char> >* b) { board = b; nums.resize(9 * 9 * 9); count = 0; }
	bool slove(size_t x,size_t y)
	{
		if (y >= 9)
		{
			x = y / 9;
			y = y % 9;
		}
		if (x == 8 && y == 8 && (*board)[x][y] != '.')
		{
			return true;
		}
		if ((*board)[x][y] != '.')
		{
			size_t i;
			for ( i = fun(x,y); i < 9*9; ++i)
			{
				if ((*board)[i / 9][i % 9] == '.')
				{
					x = i / 9;
					y = i % 9;
					break;
				}
			}
			if (i == 9 * 9)
				return true;
		}

		getAllVaildValue(x, y);
		char value = '0';
		while ((value = getNextVaildValue(x, y)) != '.')
		{
			set_board_xy(x, y, value);
			if (slove(x, y + 1))
				return true;
			set_board_xy(x, y, '.');
		}

		return false;
	}

	bool  getAllVaildValue(size_t x,size_t y)
	{
		nums[fun(x,y)].clear();
		for (int i = 0 ;i < 9; ++i)
		{
			nums[fun(x, y)].push_back(1);
		}
		for (size_t i = 0; i < 9; ++i)
		{
			if ((*board)[x][i] != '.')
				nums[fun(x, y)][(*board)[x][i] - '0' - 1] = 0;
			if ((*board)[i][y] != '.')
				nums[fun(x, y)][(*board)[i][y] - '0' - 1] = 0;
			if ((*board)[(x / 3) * 3 + i / 3][(y / 3) * 3 + i % 3] != '.')
				nums[fun(x, y)][(*board)[(x / 3) * 3 + i / 3][(y / 3) * 3 + i % 3] - '0' - 1] = 0;
		}
		for (int i = 0; i < 9; ++i)
		{
			printf("%d ", nums[fun(x, y)][i] == 0 ? 0 : 1);
		}
		printf("\n count: %d \n",count);
		++count;
		return true;
	}
	char getNextVaildValue(size_t x, size_t y)
	{
		for (size_t i = 0; i < nums[fun(x, y)].size(); ++i)
		{
			if (nums[fun(x, y)][i] != 0)
			{
				nums[fun(x, y)][i] = 0;
				return i + 1 + '0';
			}
		}
		return '.';
	}

	void set_board_xy(size_t x, size_t y, char value)
	{
		(*board)[x][y] = value;
	}
};