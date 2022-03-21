// LC268.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>

using namespace std;

/*
��Ŀ����ʧ������

����һ������ [0, n] �� n ���������� nums ���ҳ� [0, n] �����Χ��û�г����������е��Ǹ�����
*/
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		//��һ�ַ�������ͷ�����˵���ܻ��������Ҫ����
		/*int sum = 0;
		int len = nums.size();
		for (size_t i = 0; i < len; i++)
		{
			sum += nums[i];
		}
		return len*(len + 1) / 2 - sum;*/

		//�ڶ��ַ���:���
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

