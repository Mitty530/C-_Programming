//
//  main.cpp
//  DressMe
//
//  Created by Syed Araiz Haider on 27/07/2019.
//  Copyright © 2019 Syed Araiz Haider. All rights reserved.
//
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include "windows.h"
#include <limits> //for std::mumeric_limits
using namespace std;
void login();
//Structure that represents a single cloth
struct Cloth {
	int id;             //Unique ID Of Clothes
	string type;        //Type Of Cloth
	string description; //Description Of Cloth
	int quantity;   //Quantity
	string color;
	double size;
	double price;
	bool isForSale; //True if cloth is for sale or not

	Cloth(int id) {
		this->id = id;
		type = "";
		description = "";
		quantity = 0;
		color = "";
		size = 0;
		price = 0;
		isForSale = false;
	}
	Cloth() {
		id = 0;
		type = "";
		description = "";
		quantity = 0;
		color = "";
		size = 0;
		price = 0;
		isForSale = false;
	}
	//Parameterized Constructor
	Cloth(int id, string type, string description, int quantity, string color, double size, double price, bool sale) {
		this->id = id;
		this->type = type;
		this->description = description;
		this->quantity = quantity;
		this->color = color;
		this->size = size;
		this->price = price;
		isForSale = sale;
	}
	//Operator Overloaded To Use In Other Classes
	Cloth operator = (Cloth const &cloth)
	{
		this->id = cloth.id;
		this->type = cloth.type;
		this->description = cloth.description;
		this->quantity = cloth.quantity;
		this->color = cloth.color;
		this->size = cloth.size;
		this->price = cloth.price;
		this->isForSale = cloth.isForSale;
		return *this;
	}
	bool operator > (Cloth const &cloth) {
		return (this->price > cloth.price) ? true : false;
	}
	bool operator < (Cloth const &cloth) {
		return (this->price < cloth.price) ? true : false;
	}
	friend ostream & operator << (ostream &out, const Cloth &c);
};
ostream & operator << (ostream &out, const Cloth &c)
{
	out << "Cloth With ID: " << c.id << " are as :" << endl;
	out << "Type: " << c.type << endl;
	out << "Description: " << c.description << endl;
	out << "Quantity: " << c.quantity << endl;
	out << "Color: " << c.color << endl;
	out << "Size: " << c.size << endl;
	out << "Price: " << c.price << endl;
	return out;
}
template <class T>
struct Node {
	T data;
	struct Node* next;
	struct Node* prev;
};
template <class T>
class DoublyLinkedList {
public:
	Node<T> *root;
	DoublyLinkedList() {
		root = NULL;
	}
	DoublyLinkedList(T data) {
		root = new Node<T>();
		root->data = data;
	}
	void push(Node<T>** head_ref, T &new_data)
	{
		Node<T>* new_node = new Node<T>();
		new_node->data = new_data;
		new_node->next = (*head_ref);
		new_node->prev = NULL;
		if ((*head_ref) != NULL)
			(*head_ref)->prev = new_node;
		(*head_ref) = new_node;
	}
	void insertAfter(Node<T>* prev_node, T &new_data)
	{
		if (prev_node == NULL) {
			printf("the given previous node cannot be NULL");
			return;
		}
		Node<T>* new_node = new Node<T>();
		new_node->data = new_data;
		new_node->next = prev_node->next;
		prev_node->next = new_node;
		new_node->prev = prev_node;
		if (new_node->next != NULL)
			new_node->next->prev = new_node;
	}
	void append(Node<T>** head_ref, T &new_data)
	{
		struct Node<T>* new_node = new Node<T>();
		struct Node<T>* last = *head_ref;
		new_node->data = new_data;
		new_node->next = NULL;
		if (*head_ref == NULL) {
			new_node->prev = NULL;
			*head_ref = new_node;
			return;
		}
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
		new_node->prev = last;
		return;
	}
	//Sort All Nodes On Basis Of Price
	void bubbleSort(Node<T> *start) {
		int swapped;
		Node<T> *ptr1;
		Node<T> *lptr = NULL;
		if (start == NULL)
			return;
		do {
			swapped = 0;
			ptr1 = start;
			while (ptr1->next != lptr) {
				if (ptr1->data > ptr1->next->data) {
					swap(ptr1->data, ptr1->next->data);
					swapped = 1;
				}
				ptr1 = ptr1->next;
			}
			lptr = ptr1;
		} while (swapped);
	}
	// function to find out middle element
	Node<T>* middle(Node<T>* start, Node<T>* last)
	{
		if (start == NULL)
			return NULL;

		struct Node<T>* slow = start;
		struct Node<T>* fast = start->next;

		while (fast != last) {
			fast = fast->next;
			if (fast != last) {
				slow = slow->next;
				fast = fast->next;
			}
		}
		return slow;
	}
	Node<T>* find(Node<T> *head, int value) //Binary Search
	{
		struct Node<T>* start = head;
		struct Node<T>* last = NULL;
		do
		{
			Node<T>* mid = middle(start, last);
			if (mid == NULL)
				return NULL;
			if (mid->data == value)
				return mid;
			else if (mid->data < value)
				start = mid->next;
			else
				last = mid;

		} while (last == NULL ||
			last != start);
		return NULL;
	}
	Node<T>* findNode(string id) {
		Node<T>* current = root;
		while (current != NULL) {
			if (current->data.id == id) {
				return current;
			}
			current = current->next;
		}
		return NULL;
	}
	bool alreadyExsist(int id) {
		Node<T>* current = root;
		while (current != NULL) {
			if (current->data.id == id) {
				return true;
			}
			current = current->next;
		}
		return false;
	}
	bool alreadyExsist(string id) {
		Node<T>* current = root;
		while (current != NULL) {
			if (current->data.id == id) {
				return true;
			}
			current = current->next;
		}
		return false;
	}
	Node<T>* findNode(int id) {
		Node<T>* current = root;
		while (current != NULL) {
			if (current->data.id == id) {
				return current;
			}
			current = current->next;
		}
		return NULL;
	}
	void displayClothesOfType(string type) {
		Node<T>* current = root;
		while (current != NULL) {
			if (current->data.type == type) {
				cout << (current->data) << endl;
			}
			current = current->next;
		}
	}
	void deleteNode(Node<T>** head_ref, Node<T>* del)
	{
		if (*head_ref == NULL || del == NULL)
			return;
		if (*head_ref == del)
			*head_ref = del->next;
		if (del->next != NULL) {
			del->next->prev = del->prev;
		}
		if (del->prev != NULL) {
			del->prev->next = del->next;
		}
		free(del);
		return;
	}
	void remove(string id) {
		deleteNode(&root, findNode(id));
	}
	void remove(int id) {
		deleteNode(&root, findNode(id));
	}
	void printListForward(Node<T>* node)
	{
		Node<T>* last = new Node<T>();
		while (node != NULL) {
			cout << node->data << endl;
			last = node;
			node = node->next;
		}
	}
	void printListBackward(Node<T>* node)
	{
		Node<T>* last = new Node<T>();
		while (last != NULL) {
			cout << last->data;
			last = last->prev;
		}
	}
	double getTotalPriceOfClothes(Node<T>* node) {
		double totalPrice = 0;
		Node<T>* last = new Node<T>();
		while (node != NULL) {
			totalPrice = node->data.price;
			last = node;
			node = node->next;
		}
		return totalPrice;
	}
	void printAllClothesForSale(Node<T>* node) {
		bubbleSort(root);
		Node<T>* last = new Node<T>();
		while (node != NULL) {
			if (node->data.isForSale == true) {
				cout << node->data << endl;
			}
			last = node;
			node = node->next;
		}
	}
	void addNewCloth() {
		string type = "";
		cout << "Enter Type Of Cloth: ";
		cin >> type;

		int id = 0;
		cout << "Enter ID Of Cloth: ";
		cin >> id;

		string description = "";
		cout << "Enter Description Of Cloth: ";
		cin >> description;

		int quantity = 0;
		cout << "Enter Quantity Of Cloth: ";
		cin >> quantity;

		string color = "";
		cout << "Enter Color Of Cloth: ";
		cin >> color;

		double size = 0;
		cout << "Enter Size Of Cloth: ";
		cin >> size;

		double price = 0;
		cout << "Enter Price Of Cloth: ";
		cin >> price;

		Cloth cloth1(id, type, description, quantity, color, size, price, false);
		append(&root, cloth1);
	}
};
void displayMenu() {
	cout << "********************************************************\n";
	cout << "			DressMe Clothing Sdn. Bhd		\n";
	cout << "********************************************************\n";
	cout << ("\n");
	cout << "Enter '1' to view list of clothes\nEnter '2' to add new clothes\nEnter '3' to search for a type of clothing\nEnter '4' to View list of clothes that are for sale\nEnter '5' to select clothes for order\nEnter '6' to Checkout order\nEnter '7' to view all orders\nEnter '8' to modify an order\nEnter '9' to delete an order\nEnter '0' to Quit" << endl;
}
//Class That represents Order Entity
class Order {
private:
	string address;
	string buyerName;
	string contact;
	double totalPrice;
	bool isCheckedOut;
	DoublyLinkedList<Cloth*> stock;
	DoublyLinkedList<Cloth> *clothes;
public:
	bool isDeliveryRequired;
	string id;
	Order() {
		clothes = new DoublyLinkedList<Cloth>();
		totalPrice = 10;
		isCheckedOut = false;
		address = contact = "";
	}
	Order(string id, string name, string address, string contact) {
		clothes = new DoublyLinkedList<Cloth>();
		this->id = id;
		if (address == "0") {
			isDeliveryRequired = false;
		}
		else {
			isDeliveryRequired = true;
		}
		this->address = address;
		this->buyerName = name;
		this->contact = contact;
		isCheckedOut = false;
	}
	double getTotalPrice() {
		return totalPrice;
	}
	void setTotalPrice(double price) {
		this->totalPrice = price;
	}
	void checkOutOrder() {
		isCheckedOut = true;
	}
	void addOrder(Cloth &cloth) {
		this->totalPrice += cloth.price;
		clothes->append(&clothes->root, cloth);
	}
	void removeCloth(Cloth cloth) {
		totalPrice -= cloth.price;
		clothes->remove(cloth.id);
	}
	Order operator = (Order const &order) {
		this->id = order.id;
		this->isDeliveryRequired = order.isDeliveryRequired;
		this->address = order.address;
		this->buyerName = order.buyerName;
		this->clothes = order.clothes;
		this->contact = order.contact;
		this->totalPrice = order.totalPrice;
		return *this;
	}
	void modify(DoublyLinkedList<Cloth> stock) {
		cout << "Enter:\n\t'1' to modify Address\n\t'2' to modify Buyer name \n\t'3' to modify contact\n\t'0' to Go back" << endl;
		string input = "-1";
		cin >> input;
		if (input == "1") {
			cout << "Enter new address: ";
			string addr;
			cin >> addr;
			this->address = addr;
		}
		else if (input == "2") {
			cout << "Enter new name: ";
			string name;
			cin >> name;
			this->buyerName = name;
		}
		else if (input == "3") {
			cout << "Enter new contact: ";
			string contact;
			cin >> contact;
			this->contact = contact;
		}
		else if (input == "0") {
			return;
		}
	}
	bool operator > (Order &order) {
		bool firstOne = (this->totalPrice > order.totalPrice) ? true : false;
		if (this->isDeliveryRequired && !order.isDeliveryRequired) {
			firstOne = false;
		}
		return firstOne;
	}
	bool operator < (Order &order) {
		bool firstOne = (this->totalPrice < order.totalPrice) ? true : false;
		if (this->isDeliveryRequired && !order.isDeliveryRequired) {
			firstOne = false;
		}
		return firstOne;
	}
	friend ostream & operator << (ostream &out, const Order &c);
};
ostream & operator << (ostream &out, const Order &c)
{
	out << "Order With ID " << c.id << " are as :" << endl;
	out << "From: " << c.buyerName << endl;
	out << "To: " << c.address << endl;
	out << "Contact: " << c.contact << endl;
	out << "Total Price: " << c.totalPrice << endl;
	if (c.isCheckedOut) {
		out << "Order is Checked Out." << endl;
	}
	return out;
}
//This class manages all orders and stock of clothes and operation performed on them
class ManagingClass {
public:
	ManagingClass() {

	}
	DoublyLinkedList<Cloth> dList;
	DoublyLinkedList<Order> orders;
	void addCloth(Cloth cloth) {
		srand((unsigned)time(0));
		if (dList.alreadyExsist(cloth.id)) {
			cout << "Item with this ID is already added in list." << endl;
			return;
		}
		dList.append(&dList.root, cloth);
	}
	void printClothesSortedByPrice() {
		dList.bubbleSort(dList.root);
		dList.printListForward(dList.root);
	}
	void getNewClothInputFromUser() {
		dList.addNewCloth();
	}
	void printSaleClothes() {
		dList.printAllClothesForSale(dList.root);
	}
	void printClothesOfType() {
		string type;
		cout << "Enter Type Of Clothing That You Wanna See: ";
		cin >> type;
		dList.displayClothesOfType(type);
	}
	void printOrdersSortedByPrice() {
		orders.bubbleSort(orders.root);
		orders.printListForward(orders.root);
	}
	void placeOrder() {
		int id;
		cout << "Enter ID Of Cloth You Wanna Order: ";
		cin >> id;
		string orderID = "0";
		string name;
		cout << "Enter Your Name: ";
		cin >> name;
		string address = "";
		cout << "Enter Your Address(If Delivery Required Else Enter '0'): ";
		cin >> address;
		string contact = "";
		cout << "Enter Your Contact: ";
		cin >> contact;

		srand((unsigned)time(0));
		long int random_integer = rand() % 10000000;
		orderID = to_string(random_integer + 1);
		while (orders.alreadyExsist(orderID)) {
			cout << "Already Exists..." << endl;
			random_integer = rand() % 10000000;
			orderID = to_string(random_integer);
		}
		dList.findNode(id)->data.quantity -= 1;
		if (dList.findNode(id)->data.quantity > 0) {
			Order order(orderID, name, address, contact);
			order.addOrder(dList.findNode(id)->data);

			orders.append(&orders.root, order);
			cout << "Order Added..." << endl;
		}
		else {
			cout << "This item is currently unavailable in our stock." << endl;
			dList.findNode(id)->data.quantity = 0;
		}
	}
	void checkoutOrder() {
		string id;
		cout << "Enter ID Of Order You Wanna Checkout: ";
		cin >> id;
		orders.findNode(id)->data.checkOutOrder();
		cout << "Order Checked Out..." << endl;
	}
	void modifyOrder() {
		string id;
		cout << "Enter ID Of Order You Wanna Modify: ";
		cin >> id;
		if (orders.findNode(id)->data.isDeliveryRequired) {
			orders.findNode(id)->data.modify(dList);
		}
		else {
			cout << "This is not a delivery order." << endl;
		}
	}
	void removeOrder() {
		string id;
		cout << "Enter ID Of Order You Wanna Remove: ";
		cin >> id;
		orders.remove(id);
		cout << "Order Removed." << endl;
		orders.printListForward(orders.root);
	}
};
int main(int argc, const char * argv[]) {
	login();
	ManagingClass manager;
	int id = 0;
	string type = "Jeans";
	string description = "Made in USA.";
	int quantity = 20;
	string color = "Red";
	double size = 12.0;
	double price = 10.0;
	bool isForSale = true;
	Cloth cloth1(id, type, description, quantity, color, size, price, isForSale);

	id = 1;
	type = "Shorts";
	description = "Made in China.";
	quantity = 20;
	color = "Red";
	size = 12.0;
	price = 75.0;
	isForSale = false;
	Cloth cloth2(id, type, description, quantity, color, size, price, isForSale);

	id = 2;
	type = "Skirt";
	description = "Made in China.";
	quantity = 20;
	color = "Red";
	size = 12.0;
	price = 750.0;
	isForSale = false;
	Cloth cloth3(id, type, description, quantity, color, size, price, isForSale);

	id = 3;
	type = "Slacks";
	description = "Made in China.";
	quantity = 20;
	color = "Red";
	size = 12.0;
	price = 20.0;
	isForSale = false;
	Cloth cloth4(id, type, description, quantity, color, size, price, isForSale);

	id = 4;
	type = "Shirt";
	description = "Made in USA.";
	quantity = 0;
	color = "Red";
	size = 12.0;
	price = 4000.0;
	isForSale = true;
	Cloth cloth5(id, type, description, quantity, color, size, price, isForSale);

	id = 5;
	type = "Trouser";
	description = "Made in China.";
	quantity = 20;
	color = "Red";
	size = 12.0;
	price = 250.0;
	isForSale = false;
	Cloth cloth6(id, type, description, quantity, color, size, price, isForSale);

	id = 6;
	type = "Trouser";
	description = "Made in China.";
	quantity = 240;
	color = "Blue";
	size = 22.0;
	price = 100.0;
	isForSale = false;
	Cloth cloth7(id, type, description, quantity, color, size, price, isForSale);


	id = 7;
	type = "Jeans";
	description = "Made in USA.";
	quantity = 25;
	color = "Blue";
	size = 23.0;
	price = 25.0;
	isForSale = true;
	Cloth cloth8(id, type, description, quantity, color, size, price, isForSale);

	id = 8;
	type = "Slacks";
	description = "Made in China.";
	quantity = 15;
	color = "White";
	size = 30.0;
	price = 75.0;
	isForSale = false;
	Cloth cloth9(id, type, description, quantity, color, size, price, isForSale);

	id = 9;
	type = "Shirt";
	description = "Made in USA.";
	quantity = 30;
	color = "Red";
	size = 17.0;
	price = 25.0;
	isForSale = false;
	Cloth cloth10(id, type, description, quantity, color, size, price, isForSale);

	id = 10;
	type = "Skirts";
	description = "Made in China.";
	quantity = 40;
	color = "Pink";
	size = 29.0;
	price = 20.0;
	isForSale = false;
	Cloth cloth11(id, type, description, quantity, color, size, price, isForSale);

	id = 11;
	type = "Trousers";
	description = "Made in China.";
	quantity = 18;
	color = "Green";
	size = 27.0;
	price = 35.0;
	isForSale = false;
	Cloth cloth12(id, type, description, quantity, color, size, price, isForSale);

	id = 12;
	type = "Shorts";
	description = "Made in China.";
	quantity = 35;
	color = "Brown";
	size = 18.0;
	price = 100.0;
	isForSale = false;
	Cloth cloth13(id, type, description, quantity, color, size, price, isForSale);

	id = 13;
	type = "Slacks";
	description = "Made in China.";
	quantity = 26;
	color = "Yelow";
	size = 20.0;
	price = 90.0;
	isForSale = false;
	Cloth cloth14(id, type, description, quantity, color, size, price, isForSale);

	id = 14;
	type = "Jeans";
	description = "Made in USA.";
	quantity = 35;
	color = "Black";
	size = 28.0;
	price = 79.0;
	isForSale = false;
	Cloth cloth15(id, type, description, quantity, color, size, price, isForSale);

	id = 15;
	type = "Short";
	description = "Made in USA.";
	quantity = 28;
	color = "Violet";
	size = 17.0;
	price = 50.0;
	isForSale = false;
	Cloth cloth16(id, type, description, quantity, color, size, price, isForSale);

	manager.addCloth(cloth1);
	manager.addCloth(cloth2);
	manager.addCloth(cloth3);
	manager.addCloth(cloth4);
	manager.addCloth(cloth5);
	manager.addCloth(cloth6);
	manager.addCloth(cloth7);
	manager.addCloth(cloth8);
	manager.addCloth(cloth9);
	manager.addCloth(cloth10);
	manager.addCloth(cloth11);
	manager.addCloth(cloth12);
	manager.addCloth(cloth13);
	manager.addCloth(cloth14);
	manager.addCloth(cloth15);
	manager.addCloth(cloth16);

	string input = "";
	while (true) {
		displayMenu();
		cin >> input;
		if (input == "1") {
			manager.printClothesSortedByPrice();
		}
		else if (input == "2") {
			manager.getNewClothInputFromUser();
			manager.printClothesSortedByPrice();
		}
		else if (input == "3") {
			manager.printClothesOfType();
		}
		else if (input == "4") {
			manager.printSaleClothes();
		}
		else if (input == "5") {
			manager.placeOrder();
		}
		else if (input == "6") {
			manager.checkoutOrder();
		}
		else if (input == "7") {
			manager.printOrdersSortedByPrice();
		}
		else if (input == "8") {
			manager.modifyOrder();
		}
		else if (input == "9") {
			manager.removeOrder();
		}
		else if (input == "0") {
			break;
		}
		else {
			//system("CLS");
			cout << "Invalid Input. Try Again..." << endl;
		}
	}
	return 0;
}

void login() {
	system("Color 30"); // Choose the color of the background

	string user;
	string pass;
	cout << "********************************************************\n";
	cout << "			DressMre Clothing Sdn. Bhd		\n";
	cout << "********************************************************\n";
	cout << ("\n");
	cout << ("1. ADMIN\n");
	cout << ("\n");
	cout << ("2. CUSTOMER\n");
	cout << ("\n");
	cout << ("PLEASE KINDLY ENTER YOUR LOGIN DETAILS BELOW\n");

	int person;
	cin >> person;
	switch (person) {
	case 1:
		cout << "\nPlease Login Into the System";
		cout << "\nUsername : ";
		cin >> user;
		cout << "\nPassword : ";
		cin >> pass;
		if (user == "maha" && pass == "maha")
		{
			cout << "\nLogin Sucessfull ..... " << endl;
			Sleep(3000);
			cout << " \nWelcome to the DressMe Clothing \n" << endl << endl;
			Sleep(1000);


			break;

		}
		else
		{
			cout << "\nLogin Failed .... " << endl;
			cout << "\nAdministrator Username or Password is incorrect " << endl;
			cout << "\nPlease Try again .... ";
			cout << endl << endl;
			Sleep(10000);

			break;

		}

	case 2:
		cout << "\nPlease Login Into the System";
		cout << "\nUsername :\n";
		cin >> user;
		cout << "\nPassword :\n";
		cin >> pass;
		if (user == "maha" && pass == "maha")
		{
			cout << " \nLogin Sucessfull ..... " << endl;
			Sleep(3000);
			cout << " \nWelcome to the DressMe Clothing \n" << endl << endl;
			Sleep(1000);


			break;
		}
		else
		{
			cout << "\nLogin Failed .... " << endl;
			cout << "\nCustomer Username or Password is incorrect " << endl;
			cout << "\nPlease Try again .... ";
			cout << endl << endl;
			Sleep(3000);

			break;


		}



	default:
		cout << "Not a Valid Choice.\n";
		displayMenu();
		break;






	}
}