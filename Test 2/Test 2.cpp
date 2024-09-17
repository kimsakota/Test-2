#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

// Stacks and Queues 

const int MAX_SIZE = 10;


// TREE 
// Singly Linked List


void sum(int* arr, int n) {
	int maxSum = 0; 
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++) {
			int sum = 0;
			for (int k = i; k <= j; k++)
				sum += arr[k];
			if (sum > maxSum)
				maxSum = sum;
		}
	cout << maxSum;
}
vector<pair<int, int>> findPair(vector<int> const& nums, int target) {
	int n = nums.size();
	vector<pair<int, int>> v;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (nums[i] + nums[j] == target)
				v.push_back({ nums[i], nums[j] });
	return v;
}

vector<int> Count(vector<int> nums, int m, int n) {
	vector<int> vecto;
	for (int i = m; i <= n; i++)
		vecto.push_back(nums[i]);
	return vecto;
}
class Solution {
public:
	// 1
	pair<int, int> findPair(vector<int> const& nums, int target)
	{
		int n = nums.size();
		pair<int, int> v;
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				if (nums[i] + nums[j] == target) {
					v.first = nums[i];
					v.second = nums[j];
				}		
		return v;
	}
	// 2
	set<vector<int>> getAllZeroSumSubarrays(vector<int> const &nums)
	{
		set<vector<int>> subarrays;
		int n = nums.size();
		for(int i = 0; i < n; i++) {
			int num = 0;
			for(int j = i; j < n; j++) {
				num += nums[j];
				if (num == 0)
					subarrays.insert(vector<int>(nums.begin() + i, nums.begin() + j + 1));
			}
		}
		return subarrays;
	}
	// 6
	void shiftMatrix(vector<vector<int>>& mat)
	{
		set<vector<int>> set;
		
	}
	//7
	vector<int> findLargestSubarray(vector<int> const& nums)
	{
		vector<int> vecto;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			int temp = (nums[i] == 0 ? 0 : 1);
			vecto.push_back(nums[i]);
			for (int j = i + 1; j < n; j++) {
				if (nums[j] != temp) {
					vecto.push_back(nums[j]);
					temp = nums[j];
				}
				else {
					vecto.clear();
					break;
				}
			}
		}
		if (vecto.size() % 2 != 0) vecto.erase(vecto.begin() + vecto.size());
		return vecto;
	}
	
};

class Solution1
{
public:
	vector<int> findMaxLenSubarray(vector<int> const& nums, int target)
	{
		int n = nums.size();
		vector<int> get = { };
		for (int i = 0; i < n; i++) {
			int num = 0;
			vector<int> vecto;
			for (int j = i; j < n; j++) {
				num += nums[j];
				if (num == target)
					vecto = Count(nums, i, j);
			}
			if (vecto.size() > get.size())
				get = vecto;
		}
		return get;
	}
};

int main() {
	/*vector<int> nums = { 4, 2, -3, -1, 0, 4 };
	Solution name;
	set<vector<int>> result = name.getAllZeroSumSubarrays(nums);
	if (result.size() == 0) cout << "-1 -1";
	for (auto x : result)
		for (auto num : x)
			cout << num << " ";*/

	vector<int> nums = { 0, 0, 0, 0, 0  };
	Solution name;
	vector<int> result = name.findLargestSubarray(nums);
	for (auto x : result)
		cout << x << " ";
	/*int n = 6;
	int arr[] = { -2, 11, -4, 13, -5, 2 };
	sum(arr, n);*/
	return 0;
}