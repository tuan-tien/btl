#pragma once
#include<iostream>
using namespace std;

struct arrList {
	int data;
	struct arrList* next;
};
void insert(arrList*& first, arrList* nod);
arrList* createNode(int n = 0);
int findElement(arrList* first, int n = 0);
int findElement(arrList* first, bool (*con)(arrList* ));
void deleteElement(arrList*& first, bool (*con)(arrList*));
void deleteElement(arrList*& first, int n = 0);
void deleteAllElement(arrList*& first);
