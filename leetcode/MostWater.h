#include <vector>
class MostWater
{
public:
	int maxArea(std::vector<int>& height) {
		if (height.size() < 2)
			return 0;
		double max = 0;
		int val = 0;
		int width = 0;
		for (size_t i = 0; i < height.size(); ++i)
		{
			val = height[i];
			width = select_most(height, val, i);
			if (max < val * width)
			{
				max = val * width;
			}
		}
		return max;
	}
	int select_most(std::vector<int>& height, int val, int val_index)
	{
		int width = 0;
		for (int i = height.size() - 1; i >val_index; --i)
		{
			if (height[i] >= val)
			{
				width = i - val_index ;
				break;
			}
		}
		if (width >= val_index)
			return width;
		for (size_t i = 0; i < val_index; ++i)
		{
			if (height[i] >= val)
			{
				if (width < (val_index - i))
				{
					width = val_index - i;
				}
				break;
			}
		}
		return width;
	}
};