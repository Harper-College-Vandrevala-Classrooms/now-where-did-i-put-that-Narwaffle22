// Now Where Did I Put That.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>
#include <string>
using namespace std;

int findWhereIPutThat(string search, string key) {
	//if (!isCaseSensitive) {
	//	key = tolower(key);
	//}
	
	if (key.length() <= 1) {
		for (int i = 0; i < search.length(); i++) {
			string s{ search[i] };
			if (s == key) {
				return i;
			}
		}
	} else {
		for (int i = 0; i < search.length(); i++) {
			string s = "";
			for (int j = 0; j < key.length(); j++) {
				if (i+j < search.length()) {
					s += { search[i+j] };
				}
				
			}
			if (s == key) {
				return i;
			}
		}
	}
	return -1;
}

int findWhereIPutThat(string search, char key) {
	for (int i = 0; i < search.length(); i++) {
		if (search[i] == key) {
			return i;
		}
	}
	return -1;
}

int main()
{
	assert(findWhereIPutThat("something","e") == 3);
	cout << "check 1\n";
	assert(findWhereIPutThat("something", 'e') == 3);
	cout << "check 2\n";
	assert(findWhereIPutThat("The quick brown fox", 'e') == 2);
	cout << "check 3\n";
	assert(findWhereIPutThat("The quick brown fox", "e") == 2);
	cout << "check 4\n";
	assert(findWhereIPutThat("The quick brown fox", ' ') == 3);
	cout << "check 5\n";
	assert(findWhereIPutThat("The quick brown fox", "quick") == 4);
	cout << "check 6\n";
	assert(findWhereIPutThat("The quick brown fox", "quiet") == -1);
	cout << "check 7\n";
}