#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <sstream>
#include <unordered_map>
#include <set>
#include <iostream>

using namespace std;

class RecentCounter {
public:
	RecentCounter() {

	}

	int ping(int t) {

	}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
 

class Solution {
public:
	string toLowerCase(string str) {
		
		for_each(str.begin(), str.end(), [](char& c) {
			c = ::tolower(c);
			});
		return str;
	}

	int numJewelsInStones(string J, string S) {
		int count = 0;
		for (int i = 0; i < J.length(); i++) {

			for (int j = 0; j < S.length(); j++) {
				if (S.at(j) == J.at(i)) {
					count = count + 1;
				}
			}
		}
		return count;
	}

	string defangIPaddr(string address) {

		string str;
		for (int i = 0; i < address.length(); i++) {
			if (address.at(i) == '.') {
				str.push_back('[');
				str.push_back('.');
				str.push_back(']');
			}
			else
				str.push_back(address.at(i));
		}
		return str;
	}

	int heightChecker(vector<int>& heights) {
		vector<int> sort_height;
		sort_height = heights;
		sort(sort_height.begin(), sort_height.end());

		int count = 0;
		int len = heights.size();
		for (int i = 0; i < len; i++) {
			if (heights.at(i) != sort_height.at(i)) {
				count++;
			}
		}
		return count;
	}

	vector<int> selfDividingNumbers(int left, int right) {

		vector<int> result;

		for (int num = left; num <= right; num++) {
			int temp = num; bool pass = true;

			while (temp > 0) {
				int dit = temp % 10;
				if (dit == 0) {
					pass = false;
					break;
				}

				if (num % dit != 0) {
					pass = false;
				}
				temp = temp / 10;

			}
			if (pass)
				result.push_back(num);

		}
		return result;
		
	}

	int peakIndexInMountainArray(vector<int>& A) {

		int lo = 0, hi = A.size() - 1;
		while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (A[mi] < A[mi + 1])
                lo = mi + 1;
            else
                hi = mi;
        }
        return lo;
        
    }

	bool isValid(string s) {
		stack<int> buff;
		int len = s.length();
		bool flag = true;

		for (int i = 0; i < len; i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
				buff.push(s[i]);
			}
			else if (!buff.empty() &&
				((buff.top() == '{' && s[i] == '}') || (buff.top() == '(' && s[i] == ')') || (buff.top() == '[' && s[i] == ']')))
			{
				buff.pop();
			}
			else {
				flag = false;
				break;
			}
		}

		if (buff.empty()&&flag)
			return true;
		else
			return false;
	}

	void reverseString(vector<char>& s) {
		int left = 0, right = s.size()-1;

		while (left < right) {
			char temp;
			temp = s[left];
			s[left] = s[right];
			s[right] = temp;

			left++;
			right--;
		}

	}

	int maximum69Number(int num) {
		stringstream ss;
		ss << num;
		string numStr;
		ss >> numStr;

		for (int i = 0; i < numStr.length(); i++) {
			if (numStr[i] == '6') {
				numStr[i] = '9';
				break;
			}
		}
		
		ss.clear();
		ss << numStr;

		int x = 0;
		ss >> x;

		return x;
	}

	int findNumbers(vector<int>& nums) {
		int len = nums.size();
		int total = 0;
		for (int i = 0; i < len; i++) {
			stringstream ss;
			ss << nums[i];
			string s;
			ss >> s;

			int numLen = s.length();
			if (numLen % 2 == 0) {
				total += 1;
			}

			ss.clear();
			s.clear();
		}
		return total;
	}
	
	int rangeSumBST(TreeNode* root, int L, int R) {

	}

	string removeVowels(string S) {
		return string(S.begin(), remove_if(S.begin(), S.end(), [](char c) {return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; }));
	}

	int numberOfSteps(int num) {
		int step = 0;
		while (num != 0) {
			if (num % 2 == 0) {
				num = num / 2;
				step++;
			}
			else
			{
				num = num - 1;
				step++;
			}
		}
		return step;
	}

	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> mp;
		
		for (int i = 0; nums.size(); i++) {
			if (mp.find(target - nums[i]) != mp.end()) // No use of iterator
				return { mp.find(target - nums[i])->second,i };
			mp[nums[i]] = i;
		}
		return {};
	}
	
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int sum = 0;
		ListNode* l3 = NULL;
		ListNode** node = &l3;
		while (l1 != NULL || l2 != NULL || sum > 0)
		{
			if (l1 != NULL){
				sum += l1->val;
				l1 = l1->next;
			}

			if (l2 != NULL){
				sum += l2->val;
				l2 = l2->next;
			}

			(*node) = new ListNode(sum % 10);
			sum /= 10;
			node = &((*node)->next);
		}
		return l3;
	
	}

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1) return l2;
		if (l2 && l2->val < l1->val) swap(l1, l2);
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}

	int maxSubArray(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}

		int ans = nums[0];
		int sum = nums[0];

		for (int i = 1; i < nums.size(); ++i) {
			sum = max(nums[i], sum + nums[i]);
			if (ans < sum) {
				ans = sum;
			}
		}
		return ans;
	}

	bool isPalindrome(int x) {
		long long int temp = 0,tempx = x;
		
		if (x < 0)
			return false;
		else {
			while (tempx > 0) {
				int i = tempx % 10;
				tempx = tempx / 10;
				temp = temp * 10 + i;
			}

			return temp == x ? true: false;
		}
	}

	vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		int num = nums.size();
		vector<int> ans;

		for (int i = 0; i < num; i++) {
			int count = 0;
			for (int j = 0; j < num; j++) {
				if (nums.at(j)<nums.at(i)) {
					count++;
				}
			}
			ans.push_back(count);
		}
		return ans;
	}

	int maxProfit(vector<int>& prices) {
		
		if (prices.size() == 0)
			return 0;

		auto profit{ 0 };
		auto curr = INT_MAX;

		for (std::size_t idx{ 0 }; idx < prices.size(); ++idx)
		{
			// curr is the lowest price, if we find a price lower than that, replace it
			if (prices[idx] < curr)
			{
				curr = prices[idx];
			}
			// This checks if the profit by selling the stock on this day is greater than the already computed profit
			else if ((prices[idx] - curr) > profit)
			{
				profit = prices[idx] - curr;
			}
		}

		return profit;
	}

	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		int n = buildings.size();
		vector <vector <int> > v(n * 2);
		vector <int> point(2);
		for (int i = 0; i < buildings.size(); i++) {
			point[0] = buildings[i][0]; point[1] = buildings[i][2]; v[i] = point;
			point[0] = buildings[i][1]; point[1] = -buildings[i][2]; v[n + i] = point;
		}
		sort(v.begin(), v.end(), [](auto& a, auto& b) {
			return a[0] < b[0];
		});

		vector <vector <int>> ans;
		multiset <int, greater<int>> ma;
		for (int i = 0; i < v.size(); i++) {
			if (v[i][1] < 0) {
				ma.erase(ma.find(abs(v[i][1])));
			}
			else {
				ma.insert(v[i][1]);
			}

			if (i != v.size() - 1 && v[i][0] == v[i + 1][0]) continue;
			point[0] = v[i][0]; point[1] = ma.size() > 0 ? *ma.begin() : 0;
			if (ans.size() == 0 || ans.back()[1] != point[1]) {
				if (i != v.size() - 1 && point[1] == 0 && v[i + 1][0] - 1 <= v[i][0]) continue;
				ans.push_back(point);
			}
		}
		return ans;
	}

	int maxSubArray(vector<int>& nums) {

		int length = nums.size();

		if (length == 0) return 0;

		int sum = 0; int ans = INT_MIN;
		for (int i = 0; i < length; i++) {
			sum += nums[i];
			ans = max(ans, sum);
			if (sum < 0) sum = 0;
		}
		return ans;
	}
};