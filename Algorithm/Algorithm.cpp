// Algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "Solution.cpp"
#include <iterator>
#include <array>

using namespace std;

bool myfunction(int i, int j) { return (i < j); }

struct myclass {
    bool operator() (int i, int j) { return (i < j); }
} myobject;

int main()
{
	Solution Solution;
	std::cout << "Hello World!\n";

	int target = 9;
	vector<int> numbers = { 2,7,11,15 };

	vector<int> ans = Solution.twoSum2(numbers, target);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans.at(i) << " ";
	}
	

	
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
