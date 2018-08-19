#include <string>
class substring_soulusion 
{
public:
	int return_index(const char& a, const std::string& str)
	{
		if (str.length() == 0 )
			return -1;
		for (int i = 0; i < str.length(); ++i)
		{
			if (str[i] == a) return i;
		}
		return -1;
	}
	int lengthOfLongestSubstring(std::string s) {
		if (s.length() == 0) return 0;
		std::string substring = "";
		substring += s.at(0);
		int index = 0;
		int maxlength = 1;
		int sublength = 0;
		for (int i = 1; i < s.length(); ++i)
		{
			index = return_index(s[i], substring);
			if (index == -1)
			{
				substring += s[i];
			}
			else
			{
				if (maxlength < substring.length())
					maxlength = substring.length();
				substring = s.substr(sublength + index + 1, i - index - sublength);
				sublength += index + 1;
			}
		}
		return maxlength > substring.length() ? maxlength:substring.length();
	}
};

