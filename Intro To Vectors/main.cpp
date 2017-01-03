#include <iostream>
#include <vector>

using namespace std;

// Funtion Prototypes
void printList(vector<int> & list);
void doubleList(vector<int> & list);
void insertionSort(vector<int> & list);

int main() {
	vector<int> vecList;
	vecList.resize(10);

	cout << "\nPrint list of 10 elements...\n" << endl;

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

	cout << "\nAlternate way to print list...\n" << endl;
	// Alternate way to print list
	printList(vecList);
	cout << "\nDouble the elements in the list, reprint...\n" << endl;
	// Double list, then reprint
	doubleList(vecList);
	printList(vecList);
	cout << "\nEmpty list...\n" << endl;
	// Empty list
	vecList.clear();
	printList(vecList);
	cout << "\nNo elements in the list to print...\n" << endl;
	// Refill list and print
	cout << "\nLets add some new unsorted elements...\n" << endl;
	vecList = { 22, 104, 99, 7, 33, 42, 20, 55, 4, 2 };
	printList(vecList);
	cout << "\nNow lets sort the list and print...\n" << endl;
	// Sort list and print
	insertionSort(vecList);
	printList(vecList);

	system("pause");
	return 0;
}

// Prints vector list
void printList(vector<int> & list) {
	for (auto p: list) {
		cout << p << " " << endl;
	}
}

// Doubles list
void doubleList(vector<int> & list) {
	for (auto & p : list) {
		p = p * 2;
	}
}

// Sorting algorithm
void insertionSort(vector<int> & list) {
	int temp, first, location;

	for (first = 1; first < list.size(); first++) {
		if (list[first] < list[first - 1]) {
			temp = list[first];
			location = first;

			do {
				list[location] = list[location - 1];
				location--;
			} while (location > 0 && list[location - 1] > temp);

			list[location] = temp;
		}
	}
}
