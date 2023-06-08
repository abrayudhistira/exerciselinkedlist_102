#include <iostream> 
#include <string> 
using namespace std; 

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
	Node* prev;
};

class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
}

void addNode();
bool search(int rollno, Node** yudhistira, Node** abra);
bool listEmpty();
bool delNode(int rollNo);
void traverse();
};

void CircularLinkedList::addNode() { //write your answer here
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student: ";
	cin >> nim;
	cout << "\nEnter the name of the student: ";
	cin >> nm;
	Node* newNode = new Node();	//step 1
	newNode->rollNumber = nim;		//step 2
	newNode->name = nm;			//step 2

	/*insert a node in the begining of a doubly - lined list*/
	if (LAST == NULL || nim <= LAST->rollNumber) {
		if (LAST != NULL && nim == LAST->rollNumber) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = LAST; //step 3
		if (LAST != NULL)
			LAST->prev = newNode; //step 4
		newNode->prev = NULL; //step 5
		LAST = newNode; //step 6
		return;
	}

	/*inserting a Node Between Two Nodes in the list*/
	Node* abra = LAST; //step 1.a
	Node* yudhistira = NULL; //step 1.b
	while (abra->next != NULL && abra->next->rollNumber < nim)  //step 1.c
	{
		yudhistira = abra; //1.d
		abra = abra->next; //1.e
	}
	if (abra->next != NULL && nim == abra->next->rollNumber) {
		cout << "\nDuplicate roll numbers not allowes" << endl;
		return;
	}

	newNode->next = abra->next; //step 4
	newNode->prev = abra; // step 5
	if (abra->next != NULL)
		abra->next->prev = newNode; //step 6
	abra->next = newNode; //step 7
}

bool CircularLinkedList::search(int rollno, Node** yudhistira, Node** abra) {
	*yudhistira = LAST->next;
	*abra = LAST->next;
	while (*abra != LAST) {
		if (rollno == (*abra)->rollNumber) {
			return true;
		}
		*yudhistira = *abra;
		*abra = (*abra)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}

bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}
bool CircularLinkedList::delNode(int rollno) { //write your answer here
	Node* yudhistira, * abra;
	yudhistira = abra = NULL;
	if (search(rollno, &yudhistira, &abra) == false)
		return false;
	if (abra->next != NULL)
		abra->next->prev = yudhistira; //step 2
	if (yudhistira != NULL)
		yudhistira->next = abra->next; //step 3
	else
		LAST = abra->next;

	delete abra; //step 4
	return true;
}

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
}

	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != NULL) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}

int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
				obj.addNode();
			}
			case '2': {
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}