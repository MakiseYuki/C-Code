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

    
    int myints[] = { 32,71,12,45,26,80,53,33 };
    std::vector<int> myvector(myints, myints + 8);               // 32 71 12 45 26 80 53 33

    // using default comparison (operator <):
    std::sort(myvector.begin(), myvector.begin() + 4);           //(12 32 45 71)26 80 53 33

    // using function as comp
    std::sort(myvector.begin() + 4, myvector.end(), [](int& a, int& b) { return a < b; }); // 12 32 45 71(26 33 53 80)

    // using object as comp
    std::sort(myvector.begin(), myvector.end(), [](int& a, int& b) { return a < b; });     //(12 26 32 33 45 53 71 80)

    // print out content:
    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

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
