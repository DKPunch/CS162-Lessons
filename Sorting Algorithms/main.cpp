#include <iostream>
using namespace std;

// Function Prototypes
void bubbleSort(int list[], int length);
void insertionSort(int list[], int length);
void binarySearch(int list[], int length, int searchItem);

int main() {
	int list[] = {55, 99, 66, 77, 12, 21, 11, 33, 47, 44};
	int i, search;
	char choice;

	cout << "The unsorted list is: " << endl;

	for (i = 0; i < 10; i++) {
		cout << list[i] << endl;
	}

	//bubbleSort(list, 10);
	insertionSort(list, 10);

	cout << "\nAfter sorting, the list elements are now:\n";

	for (i = 0; i < 10; i++) {
		cout << list[i] << endl;
	}

	cout << "\nLets try the search function..." << endl;

	do {
		cout << "Please enter a number to search for: ";
		cin >> search;
		binarySearch(list, 10, search);
		cout << "Would you like to search for another number? (y/n) ";
		cin >> choice;
	} while (choice == 'Y' || choice == 'y');

	cout << "Exiting program...\n";

	system("pause");
	return 0;
}

// Simple sorting algorithm, but not very efficient for
// sorting large amounts of data. A Bubble sort does 
// a lot of single comparisons.
void bubbleSort(int list[], int length) {
	int temp, i, j;		// 'i' is the index and 'j' is the iteration

	for (j = 1; j < length; j++) {   // start iteration in front of first element (j = 1) 
		for (i = 0; i < length - j; i++) { // second iteration starts at element 0
			if (list[i] > list[i + 1]) { // compare 'i' to 'i + 1' and switch if i > next in line
				temp = list[i];			// stores list[i] into temp
				list[i] = list[i + 1];  // if list[i] is greater, store i + 1 into list[i]
				list[i + 1] = temp;		// stores temp into list[i + 1], completing the swap
			}
		}
	}
}

// A slightly more efficient sorting algorithm.
// Insertion sorting attempts to move each element
// into its proper place.
void insertionSort(int list[], int length) {
	int temp, first, location;

	for (first = 1; first < length; first++) {
		if (list[first] < list[first - 1]) {
			temp = list[first];
			location = first;

			do{
				list[location] = list[location - 1];
				location--;
			} 
			while (location > 0 && list[location - 1] > temp);

			list[location] = temp;
		}
	}
}

// A searching algorithm that splits the data in half
// and searches each half for an item.
void binarySearch(int list[], int length, int searchItem) {
	int first = 0;
	int last = length - 1;
	int mid;
	bool found = false;

	while (first <= last && !found) {
		mid = (first + last) / 2;
		if (list[mid] == searchItem) {
			found = true;
		}
		else if (list[mid] > searchItem) {
			last = mid - 1;
		}
		else {
			first = mid + 1;
		}
	}
	if (found) {
		cout << "Found number " << list[mid] << " at position " 
			<< mid << " in the array." << endl;
	}
	else {
		cout << "Sorry, could not find that number in the array.\n";
	}
}
