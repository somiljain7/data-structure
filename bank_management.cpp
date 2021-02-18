
#include <iostream>
using namespace std;
class node {
friend class list;
int account_no;
string name;
float balance;
node * next;
public:
node(int ac, string na, float b) {
account_no = ac;
name = na;
balance = b;
next = NULL;
}
};
class list {
private:
node * head;
node*temp;
public:
list() {
head = NULL;
}
void add() {
int ac;
string na;
float b;
char choice = ' ';
do {
cout << "enter details" << endl;
cout << "enter account no" << endl;
cin >> ac;
cout << "enter name" << endl;
cin >> na;
cout << "enter balance" << endl;
cin >> b;
node * temp;
node * ptr;
temp = new node(ac, na, b);
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
node * ptr;
for (ptr = head; ptr != NULL; ptr = ptr->next) {
cout << "the account no is :" << ptr->account_no << endl;
cout << "the name is :" << ptr->name << endl;
cout << "the balance is :" << ptr->balance << endl;
}
}
void insert(int pos) {
int ac;
string na;
float b;
int i = 0;
node * ptr;
node * temp;
temp = new node(ac, na, b);
cout << "enter the new details to be inserted  " << endl;
cout << "enter account no" << endl;
cin >> ac;
cout << "enter name " << endl;
cin >> na;
cout << "enter balance " << endl;
cin >> b;
temp = new node(ac, na, b);
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
void del(int pos) {
node * t;
cout << "enter the position " << endl;
cin >> pos;
if (pos == 1) {
t = head;
head = head->next;
} else {
int i = 0;
node * ptr;
node * t;
for (i = 0, ptr = head; i < pos - 1, ptr != NULL;
i++, ptr = ptr->next) {
t = ptr->next;
ptr->next = t->next;
}
delete (t);
}
}

void del() {
int s;
cout << "enter account no be be deleted" << endl;
cin >> s;
node * t;
node * ptr;
ptr = head;
t = head;
while (ptr != NULL) {

if(head->account_no==s)
{
head=head->next;
delete(ptr);
}
if (ptr->account_no == s) {
t->next = ptr->next;
ptr->next = NULL;
delete (ptr);
} else {
t = ptr;
ptr = ptr->next;

}
}

}
void searching() {
int i = 0;

cout << "enter the account no to be searched" << endl;
int sno = 0;
cin >> sno;
if (head == NULL) {
cout << "list is empty" << endl;
} else {
int flag = 0;
node * ptr;
for (ptr = head; ptr != NULL; ptr = ptr->next) {
if (ptr->account_no == sno) {
cout << "found" << endl;
cout << "The account no is " << sno << endl;
cout << "the name is " << ptr->name << endl;
cout << "the balance is" << ptr->balance << endl;
flag = 1;
break;
} else if (flag == 0) {
cout << "not found" << endl;

}
}
}
}



void update() {
int ba;
node * temp;
cout << "enter bank account details" << endl;
cin >> ba;
for (temp = head; temp != NULL; temp = temp->next) {
if (temp->account_no == ba) {
int amount;
int c;
cout << "enter amount" << endl;
cin >> amount;
cout << "enter 1 for withdrawal" << endl;
cout << "enter 2 for deposit" << endl;
cin >> c;
switch (c) {
case 1:
temp->balance = temp->balance - amount;
break;
case 2:
temp->balance = temp->balance + amount;
break;
}
} else {
cout << "no account found" << endl;
}
}
}
};
int main() {
int choice = 0;
int pos = 0;
int posi = 0;
list a;
a.add();
a.display();
do {
cout << "enter your choice ";
cout << "enter 1 for inserting" << endl;
cout << "enter 2 for deletion" << endl;
cout << "enter 3 for search" << endl;
cout << "enter 4 for update" << endl;
cout<<"enter 5 to delete first student"<<endl;
cout << "enter 0 for exit" << endl;
cin >> choice;
switch (choice) {
case 1:
cout << "enter position " << endl;
cin >> pos;
a.insert(pos);
a.display();
break;
case 2:
int ans;
cout << " 1 to delete using account no" << endl;
cout << " 2 to delete node using position of node" << endl;
cin >> ans;
switch (ans) {
case 2:
a.del(posi);
a.display();
break;
case 1:
a.del();
a.display();
break;
}
break;
case 3:
a.searching();
break;
case 4:
a.update();
a.display();
break;

}
} while (choice != 0);
return 0;
}
