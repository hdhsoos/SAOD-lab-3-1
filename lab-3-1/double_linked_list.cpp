#include "laba3.h"

using namespace std;

void find(List& list, int data) {
	ListElem* cur{ list.head };
	int count = 0;
	if (is_Empty(list)) {
		cout << "—писок пуст, искать нечего" << endl;
	}
	else {
		while (cur != nullptr && cur->data != data) {
			cur = cur->next;
			count++;
		}
		if (cur != nullptr) cout << "»скомый элемент найден под индексом: " << count << endl;
		else cout << "Ёлемент не найден" << endl;
	}
}

void rfind(List& list, int data) {
	ListElem* cur{ list.head->prev };
	int count{ 0 };

	if (is_Empty(list)) {
		cout << "—писок пуст, искать нечего" << endl;
	}
	else {
		while (cur != nullptr && cur->data != data) {
			cur = cur->prev;
			count++;
		}
		if (cur != nullptr) cout << "»скомый элемент найден под индексом: " << list.count - count << endl;
		else cout << "Ёлемент не найден" << endl;
	}
}


void push_front(List& list, int data) {
	ListElem* node = new ListElem, * cur = list.head;
	node->data = data;
	if (is_Empty(list)) {
		list.head = node;
		list.head->next = list.head->prev = list.head;
	}
	else {
		ListElem* tail = list.head->prev;
		list.head->prev = node;
		list.head = node;
		list.head->next = cur;
		list.head->prev = tail;
		tail->next = list.head;
		if (list.count == 1) tail->prev = list.head;
	}
	list.count++;
}

void push(List& list) {
	int command;
	ListElem* cur{ list.head };
	int data, push_data;
	cout << "¬ведите элемент, который хотите добавить" << endl;
	cin >> push_data;
	if (is_Empty(list)) {
		push_front(list, push_data);
	}
	else {
		cout << "¬ведите элемент, относительно которого хотите выполнить добавление" << endl;
		cin >> data;
		cout << "¬ведите способ добавлени€:\n0. ¬ставить перед элементом\n1. ¬ставить после элемента" << endl;
		command = failure();
		if (command == 0) {
			if (list.head->data == data) {
				push_front(list, push_data);
			}
			else {
				if (cur != nullptr) cur = cur->next;
				while (cur != nullptr && cur->next != list.head && cur->data != data) {
					cur = cur->next;
				}
				if (cur != list.head) {
					ListElem* new_node = new ListElem;
					new_node->data = push_data;
					new_node->next = cur;
					new_node->prev = cur->prev;
					cur->prev->next = new_node;
					cur->prev = new_node;
					list.count++;
				}
				else {
					cout << "Ёлемент не найден" << endl;
				}
			}
		}
		else if (command == 1) {
			if (list.head->data == data) {
				ListElem* new_node = new ListElem;
				new_node->data = push_data;
				new_node->next = list.head->next;
				new_node->prev = list.head;
				list.head->next = new_node;
				if (list.count == 1) list.head->prev = new_node;
				else list.head->next->prev = new_node;
				list.count++;
			}
			else {
				if (cur != nullptr) cur = cur->next;
				while (cur != nullptr && cur->next != list.head && cur->data != data) {
					cur = cur->next;
				}
				if (cur != list.head) {
					ListElem* new_node = new ListElem;
					new_node->data = push_data;
					new_node->next = cur->next;
					new_node->prev = cur;
					cur->next->prev = new_node;
					cur->next = new_node;
					list.count++;
				}
				else {
					cout << "Ёлемент не найден" << endl;
				}
			}
		}

	}
}

void remove(List& list) {
	if (is_Empty(list)) {
		cout << "—писок пуст, удал€ть нечего" << endl;
	}
	else {
		ListElem* cur = list.head;
		int data;
		cout << "¬ведите информационную часть удал€емого элемента" << endl;
		cin >> data;
		if (list.head->data == data) {
			ListElem* tail = list.head->prev;
			list.head = list.head->next;
			tail->next = list.head;
			list.head->prev = tail;
			delete cur;
			list.count--;
		}
		else {
			while (cur != nullptr && cur->next != list.head && cur->data != data) {
				cur = cur->next;
			}
			if (cur != list.head) {
				cur->prev->next = cur->next;
				cur->next->prev = cur->prev;
				delete cur;
				list.count--;
			}
			else {
				cout << "Ёлемент не найден" << endl;
			}
		}
		if (list.count == 0) list.head = nullptr;
	}
}


void output_list(List& list) {
	if (is_Empty(list)) {
		cout << "—писок пуст" << endl;
	}
	else {
		ListElem* cur{ list.head };
		do {
			cout << cur->data << " ";
			cur = cur->next;
		} while (cur != nullptr && cur != list.head);
		cout << endl;
	}
}

void routput_list(List& list) {
	if (is_Empty(list)) {
		cout << "—писок пуст" << endl;
	}
	else {
		ListElem* cur{ list.head->prev };
		do {
			cout << cur->data << " ";
			cur = cur->prev;
		} while (cur != nullptr && cur != list.head);
		cout << list.head->data << endl << endl;
	}
}

void destroy(List& list) {
	if (!is_Empty(list)) {
		ListElem* cur{ list.head };
		do {
			list.head = list.head->next;
			delete cur;
			cur = list.head;
			list.count--;
		} while (list.count);
		if (list.count == 0) list.head = nullptr;
	}
}