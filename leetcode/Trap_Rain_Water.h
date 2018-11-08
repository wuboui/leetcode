/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

*/
/*

int trap(vector<int>& a) {

int n = a.size();

if(n==0)
return 0;

vector<int> leftmax(n,0);
vector<int> rightmax(n,0);

leftmax[0] = a[0];

int i,j,result=0;

for(i=1; i<n; i++)
{
leftmax[i] = max(a[i],leftmax[i-1]);
}

rightmax[n-1] = a[n-1];

for(j=n-2; j>=0; j--)
{
rightmax[j] = max(a[j],rightmax[j+1]);
}


// for(i=0; i<n; i++)
// {
//     cout<<leftmax[i]<<" ";
// }

for(i=0; i<n; i++)
{
result += min(leftmax[i],rightmax[i]) - a[i];
}

return result;

*/

#include <vector>
using std::vector;
class Trap_Water
{
public:
	vector<size_t> vec_index;
	vector<int> m_height;
	int leftindex = -1;
	bool bdown = false;
	bool bup = false;
	int trap(vector<int> & height)
	{
		vector<size_t> m_vec_index =  TrapWater(height);
		int res = 0;
		if (m_vec_index.empty())
			return 0;
		int minheight = 0;
		for (size_t i = 0; i < m_vec_index.size() - 1; ++i)
		{
			minheight = height[m_vec_index[i]];
			if (height[m_vec_index[i + 1]] < minheight)
				minheight = height[m_vec_index[i + 1]];
			for (size_t k = m_vec_index[i]; k <= m_vec_index[i + 1]; ++k)
			{
				if (height[k] > minheight) continue;
				res += (minheight - height[k]);
			}
		}
		return res;
	}

	vector<size_t> TrapWater(vector<int> height)
	{ 
		
		vec_index.clear();
		bdown = false;
		bup = false;
		for (size_t i = 0; i < height.size(); ++i)
		{

			if (!bdown && (i == height.size() - 1 || height[i] <= height[i + 1]))
				continue;

			if (bdown && bup && (i == height.size() - 1 || height[i] > height[i + 1]))
			{
				bdown = bup = false;
				if (vec_index.empty())
					vec_index.push_back(leftindex);
				vec_index.push_back(i);
				leftindex = -1;
			}
			if (i == height.size() - 1)
				continue;
			if (height[i] > height[i + 1])
			{
				if (leftindex == -1)
					leftindex = i;
				bdown = true;
			}
			if (height[i] < height[i + 1])
			{
				bup = true;
			}
		}
		
		if (vec_index.empty())
		{
			return vec_index;
		}
		m_height.swap(height);
		return TrapWaterIndex(vec_index);
	}
	vector<size_t> TrapWaterIndex(vector<size_t> index)
	{
		vec_index.clear();
		bdown = false;
		bup = false;
		int leftindex = -1;
		for (size_t i = 0; i < index.size(); ++i)
		{
			vec_index.push_back(index[i]);
			if (!bdown && (i == index.size() - 1 || m_height[index[i]] <= m_height[index[i + 1]]))
			{
				continue;
			}

			if (bdown && bup && (i == index.size() - 1 || m_height[index[i]] >= m_height[index[i + 1]] || m_height[index[i]] >= m_height[index[leftindex]]))
			{
				bdown = bup = false;
				while (leftindex < i)
				{
					vec_index.pop_back();
					++leftindex;
					if (m_height[vec_index.back()] >= m_height[index[i]]) break;
				}
				vec_index.push_back(index[i]);
				leftindex = -1;
			}
			if (i == index.size() - 1)
			{
				continue;
			}
			if (m_height[index[i]] > m_height[index[i + 1]])
			{
				if (leftindex == -1)
					leftindex = i;
				bdown = true;
			}
			if (m_height[index[i]] < m_height[index[i + 1]])
			{
				bup = true;
			}
		}
		if (vec_index.empty() || vec_index.size() == index.size())
		{
			return index;
		}
		return TrapWaterIndex(vec_index);
	}
};