// LRU Cache.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

int main()
{
    std::cout << "Chinese Virus!\n";
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

int cap;
list<pair<int, int>> lst;
unordered_map<int, list<pair<int, int>>::iterator> hsh_list;

class LRUCache {
public:
	LRUCache(int capacity) {
		cap = capacity;
		lst.clear();
		hsh_list.clear();
	}

	int get(int key) {
		auto itr = hsh_list.find(key);
		if (itr == hsh_list.end())
			return -1;
		lst.splice(lst.begin(), lst, itr->second);
		hsh_list[key] = lst.begin();
		return hsh_list[key]->second;
	}

	void put(int key, int value) {

		auto itr = hsh_list.find(key);
		if (itr != hsh_list.end())
		{
			itr->second->second = value;
			lst.splice(lst.begin(), lst, itr->second);
		}
		else
			if (lst.size() == cap)
			{
				hsh_list.erase(lst.back().first);
				lst.pop_back();
				lst.push_front(pair<int, int>(key, value));
			}
			else
				lst.push_front(pair<int, int>(key, value));
		hsh_list[key] = lst.begin();
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
static int fastio = []() {
#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(0);
	return 0;
}();

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
