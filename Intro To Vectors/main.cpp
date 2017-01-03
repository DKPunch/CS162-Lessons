#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> vecList;
	vecList.resize(10);

	for (int j = 0; j < 10; j++) {
		vecList[j] = j;
		cout << vecList[j] << endl;
	}
	cout << "\nAfter adding 2 elements to the end...\n" << endl;

	vecList.push_back(10);
	vecList.push_back(11);

	for (int i = 0; i < vecList.size(); i++) {
		cout << vecList[i] << endl;
	}

	system("pause");
	return 0;
}