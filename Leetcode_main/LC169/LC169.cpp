// LC169.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>

using namespace std;

/*
题目：多数元素

给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。
*/
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int inum = nums[0];
		int icount = 1;
		for (size_t i = 1; i < nums.size(); i++)
		{
			if (inum == nums[i])
			{
				icount++;
				if (icount > nums.size() / 2)
				{
					return nums[i];
				}
			}
			else
			{
				icount--;
				if (icount == 0)
				{
					inum = nums[i + 1];
				}
			}
		}
		return inum;
	}
};


int main()
{
	Solution sol;
	vector<int> nums1 = { 2,2,1,1,1,2,2 };
	printf("%d\n", sol.majorityElement(nums1));
	system("pause");
    return 0;
}

