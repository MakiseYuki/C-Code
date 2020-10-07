// Algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "Solution.cpp"
#include <iterator>
#include <array>
#include <cstdlib>
using namespace std;

int myrandom(int i) { return rand() % i; }

int main()
{
	//class Solution sol;
	/*vector <vector<char>> mat = {{'1', '0', '1', '0', '0'} ,{'1', '0', '1', '1', '1'},{'1', '1', '1', '1', '1' }, {'1', '0', '0', '1', '0'}};
	int ans = sol.maximalRectangle(mat);
	cout << ans;*/

	/*vector <int> arr = { 0,1,1,0,1,1,1,0,0,1 };
	int ans = sol.largestRectangleArea(arr);
	arr.push_back(0);
	cout << ans;*/

	/*vector<int> arr = { 1,2,3,4,5 };
	Solution* obj = new Solution(arr);
	vector<int> param = obj->shuffle();

	int len = param.size();
	for (int i = 0; i < len; i++) {
		cout << param[i];
	}
	delete obj;*/
	cout << "Program" << endl;
	vector<int> arr = { 1,2,3,4,5,6,7,8,9,10 };
	Solution* obj = new Solution(arr);
	vector<int> s = obj->shuffle();
	for (int i = 0; i < s.size(); i++) {
		cout << s[i];
	}

	return 0;
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
