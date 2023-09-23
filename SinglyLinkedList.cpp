#include "SinglyLinkedList.h"

myList::SinglyLinkedList::Node::Node(std::string val)
	: val{ val }, next{ nullptr }
{
}

myList::SinglyLinkedList::Node::~Node()
{
	delete next;
}

myList::SinglyLinkedList::SinglyLinkedList()
	: first{ nullptr }, last{ nullptr }, size{ 0 }
{
}

myList::SinglyLinkedList::~SinglyLinkedList()
{
	while (first != nullptr)
		remove_front();
}

bool myList::SinglyLinkedList::is_empty()
{
	return first == nullptr;
}

void myList::SinglyLinkedList::push_front(std::string val)
{
	if (is_empty())
		first = last = new Node(val);
	else {
		Node* node = new Node(val);
		node->next = first;
		first = node;
	}	
	size++;
}

void myList::SinglyLinkedList::push_back(std::string val)
{
    if (is_empty()) {
        first = last = new Node(val);
    }
	else {
		last->next = new Node(val);
		last = last->next;
	}
    size++;
}

void myList::SinglyLinkedList::remove_front()
{
	if (is_empty()) {
		return;
	}
	if (first == last) {
		delete first;
		first = last = nullptr;
	}
	else {
		Node* removable = first;
		first = first->next;
		removable->next = nullptr;
		delete removable;
	}
	size--;
}

void myList::SinglyLinkedList::remove_back()
{
	if (is_empty()) {
		return;
	}
	if (first == last) {
		remove_front();
	}
	else {
		Node* pre_last;
		for (pre_last = first; pre_last->next->next != nullptr; pre_last = pre_last->next);
		pre_last->next = nullptr;
		delete last;
		last = pre_last;
	}
	size--;
}

bool myList::SinglyLinkedList::remove(std::string val)
{
	if (is_empty()) {
		return false;
	}
	if (first->val == val) {
		remove_front();
		return true;
	}
		
	for (Node* previos = first; previos->next != nullptr; previos = previos->next) {
		if (previos->next->val == val) {
			Node* removable = previos->next;	
			previos->next = removable->next;	
			removable->next = nullptr;			
			delete removable;					
			size--;
			return true;						
		}
	}
		
	return false;
}

void myList::SinglyLinkedList::remove_all(std::string val)
{
	if (is_empty())
		return;
	Node* p = first;
	int counter = 0;
	while (p != nullptr) {
		if (p->val == val) {
			counter++;
		}
		p = p->next;
	}
	if (counter > 0) {
		do {
			remove(val);
			counter--;
		} while (counter != 0);
	}
	else
		std::cout << "This element - " << val << " - does not exist\n";
}

std::string myList::SinglyLinkedList::to_string()
{
    if (is_empty())
        return "empty";
	std::ostringstream out;
	for (Node* node = first; node != nullptr; node = node->next) {
		out << node->val;
		if (node->next != nullptr) {
			out << " -> ";
		}
	}
	return out.str();
}

void myList::SinglyLinkedList::print()
{
	if (is_empty()) 
		return;
	Node* p = first;
	while (p) {
		p != nullptr;
		std::cout << p->val << " ";
		p = p->next;
	}
	std::cout << std::endl;
}

