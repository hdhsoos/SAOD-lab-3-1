#pragma once
#include <iostream>

typedef struct ListElem {
	int data;
	ListElem* next;
	ListElem* prev;
};

typedef struct List {
	ListElem* head = nullptr;
	int count = 0;
};


void push(List& list);
void push_front(List& list, int data);
void remove(List& list);
int failure();
void menu();
void output_list(List& list);
void routput_list(List& list);
inline bool is_Empty(List& list) { return list.head == nullptr; }
void find(List& list, int data);
void rfind(List& list, int data);
void destroy(List& list);