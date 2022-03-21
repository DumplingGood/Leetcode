// LC088.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>

using namespace std;
/*
题目：合并两个有序数组

给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，
其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n
*/
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (n < 1) return;
		if (m < 1)
		{
			nums1.clear();
			for (size_t i = 0; i < n; i++)
			{
				nums1.push_back(nums2[i]);
			}
			return;
		}
		vector<int> arrTmp;
		int iStart1, iStart2;
		iStart1 = iStart2 = 0;
		while (iStart1 < m && iStart2 < n)
		{
			arrTmp.push_back(nums1[iStart1] < nums2[iStart2] ? nums1[iStart1++] : nums2[iStart2++]);
			//如果nums1到头了，
			if (iStart1 == m)
			{
				for (size_t i = iStart2; i < n; i++)
				{
					arrTmp.push_back(nums2[i]);
				}
			}
			if (iStart2 == n)
			{
				for (size_t i = iStart1; i < m; i++)
				{
					arrTmp.push_back(nums1[i]);
				}
			}
		}
		nums1.clear();
		for (size_t i = 0; i < n + m; i++)
		{
			nums1.push_back(arrTmp[i]);
		}
		return;
	}
};

int main()
{
	Solution sol;
	vector<int> nums1 = { 1,5,9,15 };
	int m = 4;
	vector<int> nums2 = {};
	int n = 0;
	sol.merge(nums1, m, nums2, n);
	printf("[");
	for (int i = 0; i < m + n; i++)
	{
		if (i != 0)
		{
			printf(" %d",nums1[i]);
		}
		else
		{
			printf("%d", nums1[i]);
		}
	}
	printf("]\n");
	system("pause");
    return 0;
}

