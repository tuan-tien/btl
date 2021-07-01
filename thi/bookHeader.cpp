#include "bookHeader.h"
void inputBookHeader(bookHeader**& bookHeaderList, int& n, arrList* codeBook) {
	cout << "nhap so luong dau sach: ";
	cin >> n;
	if (bookHeaderList) delete[] bookHeaderList;
	bookHeaderList = new bookHeader * [n];
	for (int i = 0; i < n; i++) {
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
bookHeader* findBook(bookHeader** bookHeaderList, int n, int ma) {
	for (int i = 0; i < n; i++) {
		bookIndex* temp = bookHeaderList[i]->contro;
		while (temp) {
			if (temp->maSach == ma) return bookHeaderList[i];
			temp = temp->next;
		}
	}
}