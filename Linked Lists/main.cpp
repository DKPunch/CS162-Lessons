#include <iostream>

using namespace std;

class Node {
public:
	int number;
	Node * next;
};

// Function Prototypes
bool isEmpty(Node * head);
char menu();
void insertAsFirstElement(Node *& head, Node *& last, int number);
void insert(Node *& head, Node *& last, int number);
void remove(Node *& head, Node *& last);
void showList(Node * current);

int main() {
	Node * head = nullptr;
	Node * last = nullptr;
	int num;
	char reply;

	cout << "Example Linked List program.\n" << endl;

	do {
		reply = menu();

		switch (reply) {
		case '1':
			cout << "Please enter a number: ";
			cin >> num;
			insert(head, last, num);
			break;
		case '2':
			remove(head, last);
			break;
		case '3':
			showList(head);
			break;
		case '4':
			cout << "Terminating Program...\n" << endl;
			break;
		default:
			cout << "Invalid input. Please try again.\n" << endl;
			break;
		}
	} while (reply != '4');

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

	// Welcome Screen
	cout << "Main Menu:" << endl;
	cout << "What would you like to do...\n"
		<< "1: Add item from list.\n"
		<< "2: Remove item from list.\n"
		<< "3: Display list.\n"
		<< "4: Quit program." << endl;
	cout << "--> ";
	cin >> choice;
	return choice;
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
	cout << "Successfully added " << number << " to the list.\n" << endl;
}

void remove(Node *& head, Node *& last) {
	if (isEmpty(head)) {
		cout << "\nThe list is empty, cannot remove any nodes!!\n" << endl;
	}
	else if (head == last) {
		delete head;  // delete dynamic memory
		head = nullptr; // make sure pointer points to null
		last = nullptr; // make sure pointer points to null
		cout << "Successfully removed the first node from the list.\n" << endl;
	}
	else {
		Node * temp = head; // temp ptr set to head
		head = head->next; // set head ptr to point at the data stored at next
		delete temp; // delete dynamic memory stored at temp
		cout << "Successfully removed the first node from the list.\n" << endl;
	}
}

void showList(Node * current) {
	if (isEmpty(current)) {
		cout << "\nThe list is empty.\n" << endl;
	}
	else {
		cout << "\nThe list contains: " << endl;
		while (current != nullptr) { // while not at the end of the list
			cout << current->number << endl; // print data stored at node
			current = current->next; // make current ptr point to next node
		}
		cout << "\n";
	}
}
