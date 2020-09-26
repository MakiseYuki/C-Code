// Algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "Solution.cpp"
#include <iterator>
#include <array>
using namespace std;

string addBinary(string a, string b);

int main()
{
	
	string s = "0p";
	
	class Solution sl;
	cout << sl.isPalindrome(s);

	return 0;
}

string addBinary(string a, string b) {
	string ans;
	int la = a.length(), lb = b.length();
	int ma =  la >= lb  ? la : lb;

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
		int cha = a[la - i]-48, chb = b[lb - i]-48;
		
		if (!res) {
			ans.insert(0,1,(char(cha ^ chb) + 48));
			res = cha & chb;
		}
		else {
			ans.insert(0,1,((char(cha ^ chb)^res) + 48));
			res = char(cha | chb) & res;
		}
		
	}

	if (res) ans.insert(0,1,'1');
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






	

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
