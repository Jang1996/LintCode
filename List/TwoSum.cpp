/*
����֮��

����
�ʼ�
����
����
��һ���������飬�ҵ�������ʹ�����ǵĺ͵���һ���������� target��

����Ҫʵ�ֵĺ���twoSum��Ҫ���������������±�, ���ҵ�һ���±�С�ڵڶ����±ꡣע�������±�ķ�Χ�� 1 �� n�������� 0 ��ͷ��

ע������

����Լ���ֻ��һ��𰸡�

������ʵ���������Ƿ�����������⣿ Yes
����
���� numbers = [2, 7, 11, 15], target = 9, ���� [1, 2].

*/

//Solution 1:

class Solution {
public:
	/*
	* @param numbers : An array of Integer
	* @param target : target = numbers[index1] + numbers[index2]
	* @return : [index1+1, index2+1] (index1 < index2)
	*/
	vector<int> twoSum(vector<int> &nums, int target) {
		// write your code here
		vector<int>v; int i = 0, j = nums.size() - 1, m = 0;
		
		vector<int> NUM(nums); int p = 0, q = 0;
		sort(nums.begin(), nums.end());
		while (i<j){
			m = nums[i] + nums[j];
			if (m == target)
				// {  v.push_back(i+1);v.push_back(j+1);return v;}
				break;
			if (m>target) j--;
			if (m<target) i++;

		}
		for (auto c : NUM){
			p++;
			if (c == nums[i]) v.push_back(p);
			if (nums[i] != nums[j]){
				if (c == nums[j]) v.push_back(p);
			}
		}

		return v;
	}
};
//Solution2:
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> m;
		for (int i = 0; i < nums.size(); ++i) {
			if (m.count(target - nums[i])) {
				return{ i, m[target - nums[i]] };
			}
			m[nums[i]] = i;
		}
		return{};
	}
};