#pragma once
#include <string>
#include <sstream>
#include <iostream>

namespace myList {
	class SinglyLinkedList
	{
	private:
		// ”зел списка
		class Node {
			// дл€ класса Node класс SinglyLinkedList помечаетс€ как дружественный
			friend class SinglyLinkedList;
		private:
			std::string val;   // данные узла
			Node* next;        // ссылка на следующий элемент
		public:
			// конструктор и дестркутор
			Node(std::string val);
			~Node();

		};
	private:
		// ѕол€ списка
		Node* first;       // указатель на первый элемент
		Node* last;        // указатель на последний элемент
		int size;          // размер списка
	public:
		// конструкторы и дестркутор
		SinglyLinkedList();
		~SinglyLinkedList();

		// операции со списком
		bool is_empty();                   // проверка: €вл€етс€ ли список пустым
		void push_front(std::string val);  // добавление нового элемента в начало списка
		void push_back(std::string val);   // добавление нового элемента в конец списка
		void remove_front();			   // удалить элемент из начала
		void remove_back();				   // удалить элемент из конца
		bool remove(std::string val);	   // удаление элемента по значению (первое вхождение)
		
		// удаление всех вхождений элемента по значению
		void remove_all(std::string val);

		std::string to_string();		   // получение списка в виде строки (метод дл€ отладки)
		void print();                      // метод вывода списка
				
	};
}
