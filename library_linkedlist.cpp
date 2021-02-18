
#include <iostream>
using namespace std;
class node {
	friend class list;
	string author ;
	string name;
	int no;
	node*next;
public:
	node(string na, string a, int n) {
		author = a;
		name = na;
		no = n;
		next = NULL;
	}
};
class list {
private:
	node*head;
public:
	list() {
		head = NULL;
	}
	void add() {
		int n = 0;
		string na,a;
		char choice = ' ';
		do {
			cout << "enter details" << endl;
			cout << "enter name of the book " << endl;
			cin >> na;
			cout<<"enter the name of the author"<<endl;
			cin>>a;
			cout << "enter isbn number" << endl;
			cin >> n;
			node*temp;
			node*ptr;
			temp = new node(na, a, n);
			if (head == NULL) {
				head = temp;
			} else {
				ptr = head;
				while (ptr->next != NULL) {
					ptr = ptr->next;
				}
				ptr->next = temp;
			}
			cout << "do u want to add more?" << endl;
			cout << "press y to continue." << endl;
			cout << "press n to stop ." << endl;
			cin >> choice;
		} while (choice != 'n');
	}

	void display() {
		node *ptr;
		for (ptr = head; ptr != NULL; ptr = ptr->next) {
			cout << "the name of the book is :" << ptr->name << endl;
			cout << "the  author name is :" << ptr->author << endl;
			cout << "the isbn no is :" << ptr->no << endl;
			cout << endl;
		}
	}



	void insert(int pos) {

		string na,a;
		int n;
		int i = 0;
		node*ptr;
		node*temp;
		temp = new node(na, a, n);
		cout << "enter the new details to be inserted  " << endl;
		cout << "enter name " << endl;
		cin >> na;
		cout << "enter author name " << endl;
		cin >> a;
		cout << "enter isbn no " << endl;
		cin >> n;
		temp = new node(na, a, n);
		if (head == NULL) {
			head = temp;
		} else if (pos == 1) {
			temp->next = head;
			head = temp;
		} else {
			for (i = 0, ptr = head; i < pos - 1, ptr != NULL;
					i++, ptr = ptr->next) {
				temp->next = ptr->next;
				ptr->next = temp;
			}
		}
	}
	void search() {

		cout << "enter the book name to be searched" << endl;
	    string m;

		cin >> m;
		if (head == NULL) {
			cout << "the list is empty" << endl;
		} else {

			node * ptr;
			for (ptr = head; ptr != NULL; ptr = ptr->next) {
				if (ptr->name==m) {

					cout << "the name is :" << ptr->name << endl;
					cout << "the author name is :" << ptr->author<< endl;
					cout << "the isbn no is :" << ptr->no<< endl;


				}
			}
		}


	}
	
	
};
int main() {
	int p;
	list l;
	int choice;
	l.add();
	do {
		cout << "enter your choice ";
		cout << "enter 1 for display" << endl;
		cout << "enter 2 for search the book" << endl;
		cout << "enter 3 for insert" << endl;

		cout << "enter 0 for exit" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			l.display();
			break;


		case 2:
			l.search();
			break;
		case 3:
			cout << "enter position" << endl;
			cin >> p;
			l.insert(p);
			l.display();
			break;

		}
	} while (choice != 0);
}

