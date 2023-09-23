#pragma once
#include <string>
#include <sstream>
#include <iostream>

namespace myList {
	class SinglyLinkedList
	{
	private:
		// ���� ������
		class Node {
			// ��� ������ Node ����� SinglyLinkedList ���������� ��� �������������
			friend class SinglyLinkedList;
		private:
			std::string val;   // ������ ����
			Node* next;        // ������ �� ��������� �������
		public:
			// ����������� � ����������
			Node(std::string val);
			~Node();

		};
	private:
		// ���� ������
		Node* first;       // ��������� �� ������ �������
		Node* last;        // ��������� �� ��������� �������
		int size;          // ������ ������
	public:
		// ������������ � ����������
		SinglyLinkedList();
		~SinglyLinkedList();

		// �������� �� �������
		bool is_empty();                   // ��������: �������� �� ������ ������
		void push_front(std::string val);  // ���������� ������ �������� � ������ ������
		void push_back(std::string val);   // ���������� ������ �������� � ����� ������
		void remove_front();			   // ������� ������� �� ������
		void remove_back();				   // ������� ������� �� �����
		bool remove(std::string val);	   // �������� �������� �� �������� (������ ���������)
		
		// �������� ���� ��������� �������� �� ��������
		void remove_all(std::string val);

		std::string to_string();		   // ��������� ������ � ���� ������ (����� ��� �������)
		void print();                      // ����� ������ ������
				
	};
}
