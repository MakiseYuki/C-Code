#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <sstream>
#include <unordered_map>
#include <set>
#include <iostream>
#include <queue>
#include <random>

using namespace std;

const string EMPTY = "";

const string X[] = { EMPTY, "One ", "Two ", "Three ", "Four ", "Five ",
			"Six ", "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ",
			"Twelve ", "Thirteen ", "Fourteen ", "Fifteen ",
			"Sixteen ", "Seventeen ", "Eighteen ", "Nineteen " };

const string Y[] = { EMPTY, EMPTY, "Twenty ", "Thirty ", "Forty ", "Fifty ",
				"Sixty ", "Seventy ", "Eighty ", "Ninety " };

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//struct ListNode {
//	int val;
//	ListNode* next;
//	ListNode(int x) : val(x), next(NULL) {}
//};

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};
 

class Solution {
private: 
	vector<int>origin, s;
public:
	Solution(vector<int>& nums) {
		origin = nums;
		s = nums;
	}

	int myrandom(int i) { return rand() % i; }
	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return origin;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		random_shuffle(s.begin(), s.end());
		return s;
	}


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
			mp[nums[i]] = i;
			if (mp.find(target - nums[i]) != mp.end()) // No use of iterator
				return { mp.find(target - nums[i])->second,i };
			
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

	/*int maxSubArray(vector<int>& nums) {

		int length = nums.size();

		if (length == 0) return 0;

		int sum = 0; int ans = INT_MIN;
		for (int i = 0; i < length; i++) {
			sum += nums[i];
			ans = max(ans, sum);
			if (sum < 0) sum = 0;
		}
		return ans;
	}*/

	vector<int> twoSum2(vector<int>& numbers, int target) {
		unordered_map<int, int> map;
		vector<int> index;

		for (int i = 0; i < numbers.size(); i++) {
			if (map.find(target - numbers[i]) != map.end()) {
				index.push_back(map[target - numbers[i]] + 1);
				index.push_back(i + 1);
				return index;
			}
			else {
				map[numbers[i]] = i;
			}
		}
		return index;
		
	}

	bool isBoomerang(vector<vector<int>>& points) {
		return (points[2][0] - points[0][0]) * (points[1][1] - points[0][1]) == (points[1][0] - points[0][0]) * (points[2][1] - points[0][1]) ? false : true;
	}

	int addDigits(int num) {

		int ori = num; int rev = 0; int temp = ori;
		while (temp >= 10) {
			ori = temp;
			while (ori >= 10) {
				rev = rev + ori % 10;
				ori = ori / 10;
				temp = rev + ori;
			}
			rev = 0;
		}
		return temp;
	}

	string multiply(string num1, string num2) {
		int n = num1.size(), m = num2.size();
		vector<int> a(n), b(m);
		for (int i = 0; i < n; ++i) {
			a[i] = num1[n - 1 - i] - '0';
		}
		for (int j = 0; j < m; ++j) {
			b[j] = num2[m - 1 - j] - '0';
		}
		vector<int> ans(n + m + 1, 0);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				ans[i + j] += a[i] * b[j];
			}
		}
		int carry = 0;
		for (int i = 0; i <= n + m; ++i) {
			int pres = ans[i] + carry;
			carry = pres / 10;
			ans[i] = pres % 10;
		}
		int beg;
		for (beg = n + m; beg > 0; --beg) {
			if (ans[beg] != 0) { break; }
		}
		string fin = "";
		for (int i = beg; i >= 0; --i) {
			fin += ((char)(ans[i] + '0'));
		}
		return fin;
		}

	void dfs(int i, int j, vector<vector<char>>& grid) {
		if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] - '0' == 0)
			return;
		grid[i][j] = 0 + '0';
		dfs(i + 1, j, grid);
		dfs(i - 1, j, grid);
		dfs(i, j + 1, grid);
		dfs(i, j - 1, grid);
	}

	int numIslands(vector<vector<char>>& grid) {
		int count = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] - '0' == 1) {
					count++;
					dfs(i, j, grid);
				}
			}
		}
		return count;
	}
	
	ListNode* reverseList(ListNode* head) {
		ListNode*ans , *curr , *left ;
		ans = NULL;
		curr = head;
		left = head;

		while (curr) {
			left = curr->next;
			curr->next = ans;
			ans = curr;
			curr = left;
		}
		return ans;
		
	}

	bool isAlienSorted(vector<string>& words, string order) {

		for (int i = 0; i < words.size() - 1; i++) {

			for (int j = 0; j < words[i].size(); j++) {

				if (order.find(words[i][j]) > order.find(words[i + 1][j]))
				{
					return false; break;
				}
				else if (order.find(words[i][j]) < order.find(words[i + 1][j])) break;

				if (order.find(words[i][j]) == order.find(words[i + 1][j])) {
					if (words[i][j + 1] == NULL)  return true;

					if (words[i + 1][j + 1] == NULL)  return false;
				}

			}

		}
		return true;
	}

	int orangesRotting(vector<vector<int>>& grid)
	{
		int n, m;
		n = grid.size(), m = grid[0].size();
		queue<vector<int>> q;
		vector<vector<int>> visited(n, vector<int>(m, -1));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (grid[i][j] == 2)
				{
					vector<int> temp(2);
					temp[0] = i;
					temp[1] = j;
					q.push(temp);
					temp.clear();
					visited[i][j] = 0;
				}
			}
		}
		while (q.size() != 0)
		{
			vector<int> s(2);
			s[0] = q.front()[0];
			s[1] = q.front()[1];
			q.pop();
			if (s[0] > 0)
			{
				vector<int> temp(2);
				temp[0] = s[0] - 1;
				temp[1] = s[1];
				if (grid[temp[0]][temp[1]] == 1 && visited[temp[0]][temp[1]] == -1)
				{
					visited[temp[0]][temp[1]] = visited[s[0]][s[1]] + 1;
					q.push(temp);
				}
				temp.clear();
			}
			if (s[1] > 0)
			{
				vector<int> temp(2);
				temp[0] = s[0];
				temp[1] = s[1] - 1;
				if (grid[temp[0]][temp[1]] == 1 && visited[temp[0]][temp[1]] == -1)
				{
					visited[temp[0]][temp[1]] = visited[s[0]][s[1]] + 1;
					q.push(temp);
				}
				temp.clear();
			}
			if (s[0] < n - 1)
			{
				vector<int> temp(2);
				temp[0] = s[0] + 1;
				temp[1] = s[1];
				if (grid[temp[0]][temp[1]] == 1 && visited[temp[0]][temp[1]] == -1)
				{
					visited[temp[0]][temp[1]] = visited[s[0]][s[1]] + 1;
					q.push(temp);
				}
				temp.clear();
			}
			if (s[1] < m - 1)
			{
				vector<int> temp(2);
				temp[0] = s[0];
				temp[1] = s[1] + 1;
				if (grid[temp[0]][temp[1]] == 1 && visited[temp[0]][temp[1]] == -1)
				{
					visited[temp[0]][temp[1]] = visited[s[0]][s[1]] + 1;
					q.push(temp);
				}
				temp.clear();
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				ans = max(ans, visited[i][j]);
				if (grid[i][j] == 1 && visited[i][j] == -1) return -1;
			}
		}
		return ans;
	}

	//ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	//	int value = 0;                              //
	//	value = l1->val + l2->val;                 // add the first values of l1 and l2 to l  
	//	ListNode* l = new ListNode(value % 10);  //
	//	value /= 10;   // now 'value' holds the reminder

	//	ListNode* ptr = l;
	//	while (l1->next != NULL || l2->next != NULL) {
	//		if (l1->next != NULL && l2->next != NULL) {   // if both l1 and l2 still have value
	//			l1 = l1->next;  l2 = l2->next;
	//			value += l1->val + l2->val;
	//			ListNode* node = new ListNode(value % 10);
	//			value /= 10;
	//			ptr->next = node;
	//			ptr = node;
	//		}

	//		else if (l2->next != NULL) {    // if only l2 still has value
	//			l2 = l2->next;
	//			value += l2->val;
	//			ListNode* node = new ListNode(value % 10);
	//			value /= 10;
	//			ptr->next = node;
	//			ptr = node;
	//		}

	//		else {    // if only l1 still has value
	//			l1 = l1->next;
	//			value += l1->val;
	//			ListNode* node = new ListNode(value % 10);
	//			value /= 10;
	//			ptr->next = node;
	//			ptr = node;
	//		}
	//	}

	//	if (value > 0) {     // check if there is a reminder from the last sum
	//		ListNode* node = new ListNode(value);
	//		ptr->next = node;
	//	}

	//	return l;
	//}

	int trap(vector<int>& h) {
		int n = h.size(), ans = 0, lm = 0, rm = 0, l = 0, r = n - 1;
		if (n <= 2) return 0;
		while (l <= r) {
			rm = max(rm, h[r]);
			lm = max(lm, h[l]);
			if (lm <= rm) ans += lm - h[l++];
			else ans += rm - h[r--];
		}
		return ans;
	}

	vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();
		int pro = 1, zeron = 0;
		bool zeroflag = false;
		vector<int> ans(n);
		for (int i = 0; i < n; i++) {
			if (nums[i] == 0) {
				zeroflag = true;
				zeron++;
			}
			else {
				pro *= nums[i];
			}
		}
		if (zeroflag == true) {
			if (zeron >= 2) {
				ans = vector<int>(n, 0);
			}
			else {
				for (int i = 0; i < n; i++) {
					if (nums[i] != 0) {
						ans[i] = 0;
					}
					else {
						ans[i] = pro;
					}
				}
			}
		}
		else{
			for (int i = 0; i < n; i++) {
				ans[i] = pro / nums[i];
			}
		}
		return ans;
		
	}

	string transToDigit(int num, string suffix) {
		//cout << "Function is right here with input " << num << endl;


		if (num == 0) {
			return EMPTY;
		}

		if (num > 19) {
			return Y[num / 10] + X[num % 10] + suffix;
		}
		else {
			return X[num] + suffix;
		}

	}

	string numberToWords(unsigned long long int num) {
		string res;
		res = transToDigit((num % 100), "");

		/*if (num > 100 && num % 100) {
			res = "and " + res;
		}*/
		if (num == 0) {
			res = "Zero ";
		}
		else {
		res = transToDigit((num / 100) % 10, "Hundred ") + res;
		res = transToDigit((num / 1000) % 100, "Thousand ") + res;
		
		if ((num / 1000) % 100 == 0 && (num % 1000000) / 100000 != 0) { res = transToDigit((num / 100000) % 10, "Hundred Thousand ") + res; }
		else { res = transToDigit((num / 100000) % 10, "Hundred ") + res; }

		res = transToDigit((num / 1000000) % 100, "Million ") + res;
		
		if ((num / 1000000) % 100 == 0 && (num % 1000000000) / 100000000 != 0) { res = transToDigit((num / 100000000) % 10, "Hundred Million ") + res; }
		else { res = transToDigit((num / 100000000) % 10, "Hundred ") + res; }

		res = transToDigit((num / 1000000000) % 100, "Billion ") + res;
		
		}
		res.pop_back();
		return res;
	}

	vector<string> fizzBuzz(int n) {
		vector<string> ans(n);
		for (int i = 0; i < n; i++) {
			ans[i] = to_string(i + 1);

			if ((i + 1) % 15 == 0) { ans[i] = "FizzBuzz"; }
			else if ((i + 1) % 3 == 0) { ans[i] = "Fizz"; }
			else if ((i + 1) % 5 == 0) { ans[i] = "Buzz"; }

		}

		return ans;
	}

	bool isPalindrome(string s) {
		string a, b;
		int len = s.size();
		
		for_each(s.begin(), s.end(), [](char& c) {
			c = ::tolower(c);
		});

		for (int i = 0; i < len; i++) {
			if(s.at(i)>=97 && s.at(i)<=122 || s.at(i) >= 48 && s.at(i) <= 57) a += s.at(i);
			if(s.at(len-i-1)>=97 && s.at(len-i-1)<=122 || s.at(len - i - 1) >= 48 && s.at(len - i - 1) <= 57) b += s.at(len-i-1);

		}

		/*cout << a << endl;
		cout << b << endl;*/

		for (int i = 0; i < a.size(); i++) {
			if (a.at(i) != b.at(i)) return false;
		}
		return true;
	
	}

	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		int len_x = matrix[0].size();
		int len_y = matrix.size();

		for (int j = len_y - 1; j >= 0; j--) {
			int x = 0, y = j;
			while (y + 1 < len_y && x + 1 < len_x) {
				if (matrix[y][x] != matrix[y + 1][x + 1]) return false;
				y++;
				x++;
			}
		}

		for (int i = 0; i < len_x; i++) {
			int x = i, y = 0;
			while (x + 1 < len_x && y + 1 < len_y) {
				if (matrix[y][x] != matrix[y + 1][x + 1]) return false;
				y++;
				x++;
			}
		}

		return true;
	}

	string addBinary(string a, string b) {
		string ans;
		int la = a.length(), lb = b.length();
		int ma = la >= lb ? la : lb;

		if (la > lb) {
			b.insert(0, la - lb, '0');
			lb = b.length();
		}
		else if (lb > la) {
			a.insert(0, lb - la, '0');
			la = a.length();
		}

		bool res = false;
		for (int i = 1; i <= ma; i++) {
			int cha = a[la - i] - 48, chb = b[lb - i] - 48;

			if (!res) {
				ans.insert(0, 1, (char(cha ^ chb) + 48));
				res = cha & chb;
			}
			else {
				ans.insert(0, 1, ((char(cha ^ chb) ^ res) + 48));
				res = char(cha | chb) & res;
			}

		}

		if (res) ans.insert(0, 1, '1');
		return ans;
	}

	string longestCommonPrefix(vector<string>& strs) {

		int len = strs.size();
		if (len == 0)
			return "";

		string ans;
		auto str = strs[0];
		int len2 = str.size();

		for (int i = 0; i < len2; ++i)
		{
			for (int j = 1; j < len; ++j)
			{
				if (i == strs[j].size() || str[i] != strs[j][i])
					return ans;
			}
			ans += str[i];
		}
		return ans;
	}

	int singleNumber(vector<int>& nums) {
		unordered_map<int, int> map;
		int ans = 0;
		for (int i = 0; i < nums.size(); i++) {
			map[nums[i]] += 1;
		}

		for (auto i : map) {
			if (i.second != 2) {
				ans = i.first;
				break;
			}
		}
		return ans;

	}

	int maximalRectangle(vector<vector<char>>& mat) {
		int m, n, ans = 0, tans;

		m = mat.size();      if (m == 0) return 0;
		n = mat[0].size();

		vector<int> heights = vector<int>(n, 0);

		for (int i = 0; i < m; i++)
		{
			//Find the heights of histogram
			for (int j = 0; j < n; j++)
			{
				if (mat[i][j] == '1')
				{
					heights[j]++;
				}
				else
				{
					heights[j] = 0;
				}
			}

			//Find the largest rectangle possible in histogram
			tans = largestRectangleArea(heights);

			if (tans > ans) ans = tans;
		}
		return ans;
	}

	int largestRectangleArea(vector<int> arr) {
		arr.push_back(0);
		int n = arr.size(), ans = 0, k, cur, vz = 0;
		if (n == 1)return 0;

		int* cnt;
		cnt = new int[n];

		for (int i = 0; i < n; i++)
		{
			if (vz == 0 || arr[vz - 1] < arr[i])
			{
				arr[vz] = arr[i];
				cnt[vz] = 1;
				vz++;
			}
			else
			{
				k = 0;
				while (vz)
				{
					cur = arr[vz - 1];
					if (cur < arr[i]) break;
					k += cnt[vz - 1];
					ans = max(ans, k * cur);
					vz--;
				}
				arr[vz] = arr[i];
				cnt[vz] = k + 1;
				vz++;
			}
		}
		delete [] cnt;
		return ans;
	}

	int minTimeToVisitAllPoints(vector<vector<int>>& points) {
		int counter = 0;
		for (int i = 1; i < points.size(); i++) {
			int x = abs(points[i][0] - points[i - 1][0]);
			int y = abs(points[i][1] - points[i - 1][1]);
			counter += (x > y) ? x : y;
		}
		return counter;
	}

	vector<string> commonChars(vector<string>& A) {
		vector<string> res;
		vector<vector<int>> temp;
		int i, j;

		for (i = 0; i < A.size(); i++) {
			vector<int> level(26, 0);
			for (j = 0; j < A[i].size(); j++) {
				level[A[i][j] - 'a']++;
			}
			temp.push_back(level);
		}

		for (i = 0; i < 26; i++) {
			int min = INT_MAX;

			for (j = 0; j < temp.size(); j++) {
				if (temp[j][i] < min) min = temp[j][i];
			}
			while (min) {
				string p;
				p += i + 'a';
				res.push_back(p);
				min--;
			}
		}
		return res;
	}
	
};