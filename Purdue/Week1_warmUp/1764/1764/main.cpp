#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable : 4996)

using namespace std;

int main() {
	int size1, size2;
	scanf("%d %d", &size1, &size2);

	vector<string> name1, name2;
	for (int i = 0; i < size1; i++) {
		string s;
		cin >> s;
		name1.push_back(s);
	}
	for (int i = 0; i < size2; i++) {
		string s;
		cin >> s; 
		name2.push_back(s);
	}

	name1.insert(name1.end(), name2.begin(), name2.end());
	sort(name1.begin(), name1.end());

	int count = 0;
	vector<string> noname;
	for (int i = 0; i < name1.size(); i++) {
		if (name1[i] == name1[i + 1]) {
			count++;
			noname.push_back(name1[i]);
			i++;
		}
	}
	
	printf("%d\n", count);
	for (int i = 0; i < noname.size(); i++) {
		cout << noname[i] << endl;
	}
	return 0;
}