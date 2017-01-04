#include <iostream>

using namespace std;

class Node {
public:
	int number;
	Node * next;
};

bool isEmpty(Node * head);
char menu();
void insertAsFirstElement(Node *& head, Node *& last, int number);
void insert(Node *& head, Node *& last, int number);
void remove(Node *& head, Node *& last);
void showList(Node * current);

int main() {
	Node * head = nullptr;
	Node * last = nullptr;
	int number;
	char reply;

	menu();

	switch (tolower(reply)) {
	case '1':
		cout << "Please enter a number: ";
		cin >> number;
		insert(head, last, number);
		break;
	case '2':
		addCourse();
		break;
	case '3':
		deleteCourse();
		break;
	case '4':
		return 0;
		break;
	default:
		cout << "Error, invalid input.\n" << std::endl;
		break;
	}
	system("pause");
	return 0;

}

bool isEmpty(Node * head) {
	if (head == nullptr) {
		return true;
	}
	else {
		return false;
	}

}

char menu() {
	char choice;

	cout << "Welcome to the Course Transcript and GPA program." << endl;

	do {    // Welcome Screen
		cout << "What would you like to do:\n"
			<< "1: Add item from list.\n"
			<< "2: Remove item from list.\n"
			<< "3: Display list.\n"
			<< "4: Quit program." << endl;
		cout << "--> ";
		cin >> choice;

	} while (toupper(choice) != '4');
}

void insertAsFirstElement(Node *& head, Node *& last, int number) {
	Node * temp = new Node; // create new temp node
	temp->number = number; // assign variable number to data spot that temp points to
	temp->next = nullptr; // assign next ptr to point at nullptr
	head = temp; // assign temp as first spot on list
	last = temp; // assign temp as last spot on list
	// because there is only 1 item on the list at the moment.
}

void insert(Node *& head, Node *& last, int number) {
	if (isEmpty(head)) {
		insertAsFirstElement(head, last, number);
	}
	else {
		Node * temp = new Node; // create new temp node
		temp->number = number; // assign variable number to data spot that temp points to
		temp->next = nullptr; // assign next ptr to point at nullptr
		last->next = temp; // set previous last value to temp
		last = temp; // update last to point to temp
	}

}

void remove(Node *& head, Node *& last) {
	if (isEmpty(head)) {
		cout << "\nThe list is empty, cannot remove any nodes!!" << endl;
	}
	else if (head == last) {
		delete head;
		head = nullptr;
		last = nullptr;
	}
	else {
		Node * temp = head;
		head = head->next;
		delete temp;
	}
}

void showList(Node * current) {
	if (isEmpty(current)) {
		cout << "\nThe list is empty." << endl;
	}
	else {
		cout << "\nThe list contains: " << endl;
		while (current != nullptr) {
			cout << current->number << endl;
			current = current->next;
		}
	}


}