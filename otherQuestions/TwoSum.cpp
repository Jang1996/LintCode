/*
两数之和

描述
笔记
数据
评测
给一个整数数组，找到两个数使得他们的和等于一个给定的数 target。

你需要实现的函数twoSum需要返回这两个数的下标, 并且第一个下标小于第二个下标。注意这里下标的范围是 1 到 n，不是以 0 开头。

注意事项

你可以假设只有一组答案。

您在真实的面试中是否遇到过这个题？ Yes
样例
给出 numbers = [2, 7, 11, 15], target = 9, 返回 [1, 2].

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
				// {  v.push_back(i+1);v.push_back(j+1);return v;} 这里不能直接push_back，因为nums已经被排序，此时的i，j不是nums[i]、nums[j]在原来的nums的顺序。			
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
