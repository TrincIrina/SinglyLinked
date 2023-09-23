#include<iostream>
#include"SinglyLinkedList.h"
using namespace std;
using namespace myList;

void main() {

	SinglyLinkedList list;
	cout << list.to_string() << endl;

	list.push_front("8");
	list.push_back("1");
	list.push_back("2");
	list.push_back("3");
	list.print();
	list.push_front("7");
	list.push_back("2");
	list.push_back("4");
	list.print();
	list.push_front("0");
	list.push_back("2");
	list.push_back("5");
	cout << list.to_string() << endl;
	list.remove("4");
	list.remove_back();	
	list.remove_front();
	list.print();

	list.remove_all("9");
	list.remove_all("2");
	cout << list.to_string() << endl;
}