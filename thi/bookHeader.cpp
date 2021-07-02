#include "bookHeader.h"
void inputBookHeader(bookHeader**& bookHeaderList, int& n, arrList* codeBook) {
	int ch;
	cout << "1) nhap them: ";
	cout << "\n2) nhap moi: " << endl;
	cin >> ch;
	while (ch < 1 || ch > 2) {
		cout << "lua chon: "; cin >> ch;
	}
	int sl;
	cout << "nhap so luong dau sach: ";
	cin >> sl;
	bookHeader** temp = bookHeaderList;
	if (ch == 2) {
		if (bookHeaderList) deleteAllBook(bookHeaderList,n);		
	}
	bookHeaderList = new bookHeader * [sl];
	for (int i = 0; i < sl; i++) {
		bookHeaderList[i] = new bookHeader;
		cout << "\nnhap IBSN : "; cin >> bookHeaderList[i]->ISBN;
		bookHeaderList[i]->tenSach = new char[100];
		cout << "nhap ten sach : "; cin.ignore(); cin.getline(bookHeaderList[i]->tenSach, 100);
		cout << "nhap so trang : "; cin >> bookHeaderList[i]->soTrang;
		cout << "nhap nam xuat ban : "; cin >> bookHeaderList[i]->namXuatBan;
		bookHeaderList[i]->tacGia = new char[100];
		cout << "nhap tac gia : "; cin.ignore(); cin.getline(bookHeaderList[i]->tacGia, 100);
		bookHeaderList[i]->theLoai = new char[100];
		cout << "nhap the loai: "; cin.getline(bookHeaderList[i]->theLoai, 100);
		bookHeaderList[i]->contro = createBookIndex(codeBook);
	}
	if (ch == 1) {
		add(temp, n, bookHeaderList, sl);
		bookHeaderList = temp;
	}
}
void printBookHeaderNameInc(bookHeader** bookHeaderList, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (bookHeaderList[i]->tenSach > bookHeaderList[j]->tenSach) {
				bookHeader* temp = bookHeaderList[i];
				bookHeaderList[i] = bookHeaderList[j];
				bookHeaderList[j] = temp;
			}
		}
		cout << "\n" << bookHeaderList[i]->ISBN << " " << bookHeaderList[i]->tenSach << " " << bookHeaderList[i]->theLoai << " " << bookHeaderList[i]->soTrang << " " << bookHeaderList[i]->tacGia << " " << bookHeaderList[i]->namXuatBan;
	}
	cout << "\n" << bookHeaderList[n - 1]->ISBN << " " << bookHeaderList[n - 1]->tenSach << " " << bookHeaderList[n - 1]->theLoai << " " << bookHeaderList[n - 1]->soTrang << " " << bookHeaderList[n - 1]->tacGia << " " << bookHeaderList[n - 1]->namXuatBan;
}
int findBook(bookHeader** bookHeaderList, int n, int ma) {
	for (int i = 0; i < n; i++) {
		bookIndex* temp = bookHeaderList[i]->contro;
		while (temp) {
			if (temp->maSach == ma) return i;
			temp = temp->next;
		}
	}
}
void add(bookHeader** &a1, int &n1, bookHeader** a2, int n2) {
	bookHeader** temp = new bookHeader * [n1 + n2];
	for (int i = 0; i < n1; i++) temp[i] = a1[i];
	for (int i = 0; i < n2; i++) temp[i + n1] = a2[i];
	delete[] a1;
	a1 = temp;
	n1 += n2;
}
int findBook(bookHeader** bookHeaderList, int n, bool (*con)(bookHeader*)) {
	for (int i = 0; i < n; i++) {
		if (con(bookHeaderList[i])) return i;
	}
}
void deleteBook(bookHeader** &bookHeaderList, int &n, bool (*con)(bookHeader*)) {
	deleteBook(bookHeaderList,n,findBook(bookHeaderList, n, con));
}
void deleteBook(bookHeader** &bookHeaderList, int &n, int pos) {
	if (pos >= 0 && pos < n) {
		bookHeader* temp = bookHeaderList[pos];
		for (int i = pos; i < n - 1; i++) {
			bookHeaderList[i] = bookHeaderList[i + 1];
		}
		deleteAllBookIndexNod(temp->contro);
		delete temp->tacGia;
		delete temp->tenSach;
		delete temp->theLoai;
		delete temp;
		temp = NULL;
		n--;
	}
}
void deleteAllBook(bookHeader** &bookHeaderList, int &n) {
	while(n > 0){		
		deleteBook(bookHeaderList, n, n - 1);	
	}
	bookHeaderList = NULL;
}