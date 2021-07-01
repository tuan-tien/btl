#include "bookIndex.h"
bookIndex* createBookIndex(arrList* codeBook) {
	cout << "nhap so luong sach: ";
	int n;
	cin >> n;
	bookIndex* first = NULL, * last = NULL;
	for (int i = 0; i < n; i++) {
		bookIndex* temp = new bookIndex;
		cout << "nhap ma sach: "; cin >> temp->maSach;
		while (findElement(codeBook, temp->maSach) != -1) {
			cout << "nhap lai ma sach: "; cin >> temp->maSach;
		}
		insert(codeBook, createNode(temp->maSach));
		cout << "nhap trang thai: "; cin >> temp->trangThai;
		cout << "nhap vi tri: "; cin >> temp->viTri;
		temp->next = NULL;
		if (!first) first = last = temp;
		else {
			last->next = temp;
			last = last->next;
		}
	}
	return first;
}