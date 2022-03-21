// LC268.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>

using namespace std;

/*
题目：丢失的数字

给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。
*/
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		//第一种方法：求和法，据说可能会溢出，需要考虑
		/*int sum = 0;
		int len = nums.size();
		for (size_t i = 0; i < len; i++)
		{
			sum += nums[i];
		}
		return len*(len + 1) / 2 - sum;*/

		//第二种方法:异或
		int res = 0;
		for (size_t i = 0; i < nums.size(); i++)
		{
			res ^= nums[i] ^ i;
		}
		return res^nums.size();
	}
};


int main()
{
	Solution sol;
	vector<int> nums = { 9,6,4,2,3,5,7,0,1 };
	printf("%d\n", sol.missingNumber(nums));
	system("pause");
    return 0;
}

