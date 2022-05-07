

#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>
#include "students.h"

using namespace std;

void login();
bool authCheck(string username, string password);



class NodeType {
public:
	students info;
	NodeType *link;
};

class Queue
{
public:
	Queue();
	void enqueue(students student);
	void dequeue();
	bool swap(NodeType *from, NodeType *to);
	void list();
	bool isEmpty();
	void search(int id);
	void update(int recordID, students student);
	void clearAll();
	int size;
	void sort();
	NodeType *front;
	NodeType *rear;
	~Queue();
};

Queue::Queue()
{
	this->size = 0;
	this->front = NULL;
	this->rear = NULL;
}


void Queue::enqueue(students student) {

	NodeType * newNode = new NodeType;
	newNode->info = student;
	newNode->link = NULL;
	if (front == NULL)//inserting to an empty list
		front = rear = newNode;
	else
	{
		rear->link = newNode;
		rear = newNode;
	}
	cout << endl << "\n\tStudent " << student.name << " has been inserted!\n";
	size++;

}

void Queue::dequeue() {
	if (isEmpty())
		cout << endl << "\n\tList is empty!" << endl;
	else
	{
		NodeType * toBeDeleted = front;
		front = front->link;
		cout << endl << "\n\tStudent " << toBeDeleted->info.name << " has been deleted!\n";
		delete toBeDeleted;
		size--;
	}
}

void Queue::sort() {
	cout << "     **************************************************************" << endl;
	cout << "                   SORTING STUDENTS IN ACCENDING ORDER                     " << endl;
	cout << "     **************************************************************" << endl;

	int swapped, i;
	NodeType *ptr1 = front;
	NodeType *lptr = NULL;

	//Checking for empty list
	if (ptr1 == NULL)
		return;
	do
	{
		swapped = 0;
		ptr1 = front;

		while (ptr1->link != lptr)
		{
			if (ptr1->info.age > ptr1->link->info.age)
			{
				swap(ptr1, ptr1->link);
				swapped = 1;
			}
			ptr1 = ptr1->link;
		}
		lptr = ptr1;
	} while (swapped);
	cout << endl << "\n\tList is now in ascending order!\n";
}

bool Queue::swap(NodeType *a, NodeType *b) {
	students temp = a->info;
	a->info = b->info;
	b->info = temp;

	return true;
}

void Queue::list() {

	NodeType *temp = front;
	cout << "     **************************************************************" << endl;
	cout << "                       DISPLAY STUDENTS RECORD                     " << endl;
	cout << "     **************************************************************" << endl;
	int index = 0;

	while (temp != NULL)
	{
		cout << "\n ID: " << index << " " << "Name: " << temp->info.name << " " << "Age: " << temp->info.age << " \n";
		temp = temp->link;
		index++;
	}
}

void Queue::search(int id) {

	NodeType *temp = front;
	int index = 0;

	cout << "     **************************************************************" << endl;
	cout << "                       SEARCHING STUDENTS BY ID                     " << endl;
	cout << "     **************************************************************" << endl;

	while (temp != NULL)
	{
		if (index == id) {
			cout << "\n ID: " << id << " " << "Name: " << temp->info.name << " " << "Age: " << temp->info.age << " \n";
			return;
		}
		temp = temp->link;
		index++;
	}

	cout << "Customer not found \n";
}


bool Queue::isEmpty() {
	if (front == NULL)
		return true;
	else
		return false;
}

void Queue::clearAll() {

	cout << "     **************************************************************" << endl;
	cout << "                       Deleting All Records                     " << endl;
	cout << "     **************************************************************" << endl;

	NodeType *temp = front;

	while (temp != NULL)
	{

		temp = temp->link;
		dequeue();
	}

	cout << "Queue is empty \n";
}

void Queue::update(int id, students student) {

	NodeType *temp = front;
	int index = 0;

	cout << "     **************************************************************" << endl;
	cout << "                       Updating Students BY ID                     " << endl;
	cout << "     **************************************************************" << endl;

	while (temp != NULL)
	{
		if (index == id) {
			cout << "tudent found \n";
			cout << "Updating record \n";

			temp->info.name = student.name;
			temp->info.age = student.age;
			temp->info.phone = student.phone;
			temp->info.gender = student.gender;
			//cout << "\n ID: " << id << " " << "Name: " << temp->info.name << " " << "Age: " << temp->info.age << " \n";
			return;
		}
		temp = temp->link;
		index++;
	}

	//If found please swap this record with the new one
}

Queue::~Queue()
{
}


class App
{
public:
	App();
	void displayOptions();
	void login();
	~App();
protected:
	Queue studentQueue;
	void add();
	void destroy();
	void list();
	void sort();
	void count();
	void update();
	void search();
	void deleteAll();
};



App::App()
{


	displayOptions();

	Queue queue;
	this->studentQueue = queue;
}

void App::login() {

}

void App::displayOptions() {

	cout << "\n";
	cout << "Enter 1 to add Student Record \n";
	cout << "Enter 2 to delete Student Record \n";
	cout << "Enter 3 to display all Students \n";
	cout << "Enter 4 to sort Student Ascendingly \n";
	cout << "Enter 5 to search \n";
	cout << "Enter 6 to Delete All \n";
	cout << "Enter 7 to Update a Record \n";
	cout << "Enter 8 to get total number of students \n";
	cout << "Enter 9 to Exit \n";

	int request;
	cin >> request;

	switch (request) {
	case 1:
		add();
		break;
	case 2:
		destroy();
		break;
	case 3:
		list();
		break;
	case 4:
		sort();
		break;
	case 5:
		search();
		break;
	case 6:
		deleteAll();
		break;
	case 7:
		update();
		break;
	case 8:
		count();
		break;
	case 9:
		exit(0);
	default:
		cout << "Invalid option \n";
		displayOptions();
	}


}

void App::add() {
	cout << "Adding a new Student Record \n\n";

	students student;
	student.insert();
	studentQueue.enqueue(student);

	displayOptions();

}

void App::destroy() {
	cout << "Deleting a Student Record \n\n";

	studentQueue.dequeue();

	displayOptions();
}

void App::list() {
	cout << "Listing all Studenr Record \n\n";

	studentQueue.list();
	displayOptions();

}

void App::sort() {
	cout << "Sorting all Student Record \n\n";
	studentQueue.sort();
	displayOptions();

}
void App::search() {
	cout << "Searching a Student Record \n\n";

	cout << "Enter Student ID: ";
	int recordID;

	cin >> recordID;

	studentQueue.search(recordID);

	displayOptions();

}

void App::count() {

	cout << "Total Number of Students is: " << studentQueue.size << endl;

	displayOptions();
}

void App::update() {
	cout << "Enter Student ID: ";
	int recordID;

	cin >> recordID;

	studentQueue.search(recordID);

	students student;

	student.insert();


	studentQueue.update(recordID, student);

	displayOptions();

}

void App::deleteAll() {
	studentQueue.clearAll();

	displayOptions();
}

App::~App()
{
}


int main()
{
	int request;
	system("cls");
	cout << "===== Welcome to APU Student Management System ====== \n";
	cout << "Enter 1 to Login \n";
	cout << "Enter 0 to exit \n";
	cout << "\n\n Enter your Choice: ";


	cin >> request;

	switch (request) {
	case 1:
		login();
		break;
	case 0:
		exit(0);
		break;
	default:
		cout << "Try Again !!!";
		exit(0);
	}

	return 0;
}

void login() {

	string username, password;
	char ch;

	cout << "\n Enter username: "; cin >> username;
	cout << "\n Enter password: ";

	ch = _getch();

	while (ch != 13 || ch == 127 || ch == 8) {
		password.push_back(ch);
		cout << '*';
		ch = _getch();
	}

	while (!authCheck(username, password)) {
		cout << "\n Please try again....";
		login();
	}

	cout << "\n\n ===== Logged in Successfully ====== \n\n";

	// If we are here then
	// Then login is successful
	App app;

}

bool authCheck(string username, string password) {
	return (username == "admin" && password == "admin");
}



