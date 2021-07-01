#include "arrList.h"
void insert(arrList*& first, arrList* nod) {
	nod->next = first;
	first = nod;
}
arrList* createNode(int n) {
	arrList* temp = new arrList;
	temp->data = n;
	temp->next = NULL;
	return temp;
}
int findElement(arrList* first, int n) {
	if (!first) return -1;
	else {
		int i = 0;
		arrList* temp = first;
		while (temp) {
			if (temp->data == n) return i;
			temp = temp->next;
			i++;
		}
		return -1;
	}
}
void deleteElement(arrList*& first, int n) {
	int pos = findElement(first, n);
	if (pos != -1) {
		arrList* temp = first;
		if (!pos) {
			first = first->next;
			delete temp;
		}
		else {
			for (int i = 0; i < pos - 1; i++) {
				temp = temp->next;
			}
			arrList* temp2 = temp->next;
			temp->next = temp2->next;
			delete temp2;
		}
	}
}
void deleteAllElement(arrList*& first) {
	arrList* temp = first;
	while (first) {
		first = first->next;
		delete temp;
		temp = first;
	}
}
int findElement(arrList* first, bool (*con)(arrList*)) {
	if (!first) return -1;
	else {
		int n = 0;
		arrList* temp = first;
		while (temp) {
			if (con(temp)) return n;
			temp = temp->next;
			n++;
		}
		return -1;
	}
}
void deleteElement(arrList*& first, bool (*con)(arrList*)) {
	int pos = findElement(first, con);
	if (pos != -1) {
		arrList* temp = first;
		if (!pos) {
			first = first->next;
			delete temp;
		}
		else {
			for (int i = 0; i < pos - 1; i++) {
				temp = temp->next;
			}
			arrList* temp2 = temp->next;
			temp->next = temp2->next;
			delete temp2;
		}
	}
}
