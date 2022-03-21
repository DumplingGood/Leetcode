// LC242.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>

using namespace std;
/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
*/

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.length()!=t.length())
		{
			return false;
		}
		int arr[26];
		memset(arr, 0, sizeof(int) * 26);
		for (size_t i = 0; i < s.length(); i++)
		{
			arr[s[i] - 'a']++;
			arr[t[i] - 'a']--;
		}
		for (size_t i = 0; i < 26; i++)
		{
			if (arr[i]!=0)
			{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	Solution sol;
	string s = "rat";
	string t = "car";
	sol.isAnagram(s, t) ? printf("true") : printf("false");
	system("pause");
    return 0;
}

