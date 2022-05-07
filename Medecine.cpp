#include<iostream>
#include <string>
#include <sstream>
#include<stdlib.h>
#include <queue>


using namespace std;

// Basic Functions **************************************************************************
void Menu();
void Login();

// Medicine Menu Functions - Stack *********************************************************
void ItemMenu();

class Nodes { 
public:
		string data;
	Nodes *next;
};


class ItemLinkedList {
public:
	Nodes* top;
	int size;

	ItemLinkedList();
	~ItemLinkedList();
	void AddItem(string medicine);
	void DeleteItem();
	
	void DisplayItems();
	
	bool StockEmpty();
	bool StockFull();
	void StockSize();
	void GetTopItem();
};

//constructor for initial node initialization
ItemLinkedList::ItemLinkedList()
{
	this->size = 0;
	this->top = NULL;
}


//deconstructor to destroy the list in memory
ItemLinkedList::~ItemLinkedList()
{
	cout << "Deleting the Pharmacy Stock!" << endl << endl;
	Nodes *current = top;
	while (top != NULL)
	{
		current = current->next;
		delete top;
		top = current;
	}
}

//method to insert new Medicine in the Pharmacy Stock
void ItemLinkedList::AddItem(string item)
{
	Nodes * newNode = new Nodes;
	newNode->data = item;
	newNode->next = top;
	top = newNode;
	size++;
	cout << endl << "\nItem - " << item << " Added to Clothing Stock " << endl<< endl;

	system("pause");
}

//method to delete the first item of the list
void ItemLinkedList::DeleteItem()
{
	if (StockEmpty())
	{
		cout << "\nClothing Stock is Empty" << endl;
	}
	else
	{
		Nodes * remove_med = top;
		top = top->next;
		cout << "\n Item " << remove_med->data << " deleted from Clothing Stock!" << endl;
		delete remove_med;
		size--;
	}
	system("pause");
}

// Function to Display all the Items in the Pharmacy
void ItemLinkedList::DisplayItems()
{
	int i = 0; // For numbering the Queue list
	if (StockEmpty())
	{
		cout << "\nClothing Stock is Empty" << endl;
		cout << "\nItem List not Available" << endl;
	}
	else 
	{
		Nodes *med = top;
		cout << "Item List" << endl<< endl;
		while (med != NULL)
		{
			i++; // To increment by one
			cout << "#" << i << " "<< med->data << endl;
			med = med->next;
		}
	}
	cout << endl;
	system("pause");
}
// check if Item Stock is Empty 
bool ItemLinkedList::StockEmpty()
{
	if (top == NULL) {

		return true;
	}
	else
		return false;
}
//check the top Item of the List
void ItemLinkedList::GetTopItem()
{
	if (StockEmpty())
		cout << "The Clothing Stock is Empty " << endl << endl;
	else
		cout << "The Last Item Added to the Stock was : " << top->data << endl<< endl;
	system("pause");
}

// Function to check the current number of Items in stock
void ItemLinkedList::StockSize()
{
	
	cout << "The Clothing Stock size is currently: " << size << " Item" << endl << endl;
	system("pause");

}
// Function to Check if the Clothing Stock is full or not
bool ItemLinkedList::StockFull() {
	if (size < 5) {
		
		return true;
	}
    else
		return false;
}

// *************************************************************************** END OF STACK

// Customers Funcions - Queue ***************************************************************
void CustomersMenu();
class CustomersQueue {
	
	

public:

	Nodes* front;
	Nodes* back;

	CustomersQueue(); // Queue Constructor
	//~CustomersQueue(); // Queue Decosntructor

	bool isEmptyQueue(); //Function to determine whether the queue is empty.

	bool isFullQueue(); //Function to determine whether the queue is full.


	void AddCustomer(string name);
	void FrontCustomer();
	void BackCustomer();
	void DisplayCustomers();
	void RemoveCustomer();
	void QueueSize();
	
};

// Queue Cunstructor
CustomersQueue::CustomersQueue()
{
	front = NULL;
	back = NULL;
}

// Function to Add a new Customer to the Queue
void CustomersQueue::AddCustomer(string name)
{
	Nodes * newCustomer = new Nodes;
	newCustomer->data = name;
	newCustomer->next = NULL;

	// Used when inserting the First Customer to the queue
	if (front == NULL)
	{
		front = newCustomer;
		back = newCustomer;
	}
	else
	{
		back->next = newCustomer;
		back = newCustomer;
	}
	cout << "Customer Added to the Queue: " << name << endl << endl;
	system("pause");
}

// Function to remove a Customer from the Queue
void CustomersQueue::RemoveCustomer() 
{
	if (isEmptyQueue())
	{
		cout << " There are no Customers in the Queue to be removed" << endl << endl;
	}

	if (front == back)
	{
		free(front);
			front = back = NULL;
			cout << " The Customer has finished receiving Service " << endl;
			cout << " Customer Removed from the Queue: " << front->data << endl << endl;
	}
	else
	{
		cout << " The Customer has finished receiving Service " << endl;
		cout << " Customer Removed from the Queue: " << front->data << endl << endl;
		Nodes* newCustomer = front;
		front = front->next;
		free(newCustomer);
	}
	system("pause");
}

// Function to Display the Customers Queue
void CustomersQueue::DisplayCustomers()
{
	int i = 0; // For numbering the Queue list
	if (isEmptyQueue())
	{
		cout << " There are no Customers in the Queue" << endl;
			cout << "The Queue is empty " << endl << endl;
	}
	else
	{
		
		Nodes *Customer = front;
		cout << "Customers Queue " << endl<< endl;
		while (Customer != NULL)
		{
			i++;  // Increment the i by one
			cout << "#" <<i <<" " << Customer->data << endl;
			Customer = Customer->next;
		}

	}
	cout << endl;
	system("pause");
}

void CustomersQueue::FrontCustomer()
{
	if (isEmptyQueue())
		cout << "The are no Customers Waiting in the queue" << endl << endl;
	else
	cout << "The person at the front of the queue is " << front->data <<endl << endl;
	system("pause");
}
void CustomersQueue::BackCustomer()
{
	if (isEmptyQueue())
		cout << "The are no Customers Waiting in the queue" << endl << endl;
	else
		
	cout << "The Customer at the end of the queue is " << back->data << endl << endl;

	system("pause");
}

// Function to check if Queue is Empty or not
bool CustomersQueue::isEmptyQueue()
{
	if (front == NULL && back == NULL)
		return true;
	else
		return false;
}

// Function to Check the Number of people waiting in the Queue
void CustomersQueue::QueueSize()
{
	int i = 0;
	Nodes *Customer = front;
	
	while (Customer != NULL)
	{
		i++;  // Increment the i by one
		
		Customer = Customer->next;
	}

	cout << "The Number of Customers waiting in the Queue are : " << i << " Customers " << endl;
	cout << endl;
	system("pause");
}


 //Main Function
void main(){
	
	system("Color 30"); // Choose the color of the background
	
	Login();
	


	system("\n\npause");
	
}

void Login()
{
	string pass;
	string user;

	system("cls");
	cout << "********************************************************\n";
	cout << "			DRESSME CLOTHING Sdn. Bhd.         			\n";
	cout << "********************************************************\n";

	cout << "\nPlease Login Into the System";
	cout << "\nUsername :\n";
	cin >>user;
	cout << "\nPassword :\n";
	cin >>pass;

	if (user == "admin" && pass == "pass")
	{
		cout << " \nLogin Sucessfull ..... " << endl;
		cout << " \nWelcome to the DRESSME CLOTHING Sdn. Bhd.  \n" << endl<<endl;
		system("pause");
		Menu();
	}
	else
	{
		cout << "\nLogin Failed .... " << endl;
		cout << "\nAdministrator Username or Password is incorrect " << endl;
		cout << "\nPlease Try again .... " ;
		cout << endl << endl;
		system("pause");
		Login();

	}


}
void Menu()
{

	int option; 
	
	
	system("cls");
	cout << "********************************************************\n" << endl;
	cout << "			 PDRESSME CLOTHING Sdn. Bhd. 		\n";
	cout << "********************************************************\n" << endl;


	cout << "\nPlease enter an Option" << endl;
	cout << "1. Items Menu" << endl;
	cout << "2. Customers Menu" << endl;
	cout << "3. Log Out" << endl;
	cout << "4. Exit." << endl;
	cout << "Selected Option: ";
	cin >> option;
	cout << endl << endl;
	system("pause");

	switch (option) {
	case 1:
		ItemsMenu();
		
		break;
	case 2:
		CustomersMenu();
		break;
	case 3:
		Login();
		break;
	
	case 4:
		exit(0);
		break;
	}

}


void ItemsMenu()
{

	int option;
	ItemLinkedList Stack;
	string iname;

	

	while (true) {
		system("cls");
		cout << "********************************************************\n" << endl;
		cout << "			Items Menu			\n";
		cout << "********************************************************\n" << endl;

		cout << "\nPlease enter an Option" << endl;
		cout << "1. Add Item" << endl;
		cout << "2. Delete Item" << endl;
		cout << "3. Stock Size " << endl;
		cout << "4. Display All Items" << endl;
		cout << "5. Go Back" << endl;
		cout << "Selected Option: " ;
		cin >> option;
		cout << endl << endl;
		system("pause");

		switch (option) {
		case 1:
			system("cls");
			if (Stack.StockFull()) {
				cout << "\nInsert the Item Name:  ";
				cin >> iname;
				Stack.AddItem(iname);
				
			}
			else
			{
				cout << "The Clothing Stock is Full " << endl;
				cout << "The Item cannot be Added " << endl;
				system("\n\npause");
			}
				break;
			
		case 2:
			system("cls");
			
				Stack.DeleteItem();
				
			
			break;
		case 3:
			system("cls");
			
			Stack.StockSize();

			
			break;

		case 4:
			system("cls");
			
				Stack.DisplayItems();
				
			
			break;
		case 5:
			Menu();
			
			break;
		}
	}
}

void CustomersMenu()
{

	CustomersQueue Queue;
	int option;
	string name;

	while (true) {
		system("cls");
		cout << "********************************************************\n" << endl;
		cout << "			Customers Service Menu			\n";
		cout << "********************************************************\n" << endl;

		cout << "\nPlease enter an Option" << endl;
		cout << "1. Add Customer to Service Waiting Queue" << endl;
		cout << "2. Check Customer currently Receiving Service" << endl;
		cout << "3. Check Customer at the end of the Queue" << endl;
		cout << "4. Service Completed - Remove Customer" << endl;
		cout << "5. Display Customers Queue " << endl;
		cout << "6. Number of Customers in Queue " << endl;
		cout << "7. Go Back " << endl;
		cout << "Selected Option: ";
		cin >> option;
		cout << endl << endl;
		system("pause");

		switch (option) {
		case 1: // Add custumer to the Queue
			system("cls");
			cout << "\nInsert the Customer  Name:  ";
			cin >> name;
			Queue.AddCustomer(name);
			

			break;
		case 2: // Check who is in the front of the queue
			system("cls");
			Queue.FrontCustomer();
			break;
		case 3: // Check who is at the back of the queue
			system("cls");
			Queue.BackCustomer();
			

			break;

		case 4: // Remove customer from the queue
			system("cls");
			Queue.RemoveCustomer();
			break;
		case 5: // Display the Customers List 
			system("cls");
			Queue.DisplayCustomers();
			break;

		case 6: // Queue Size
			system("cls");
			Queue.QueueSize();
			break;

		case 7: // Go to the Main Menu
			Menu();
			break;
		}
	}
}

