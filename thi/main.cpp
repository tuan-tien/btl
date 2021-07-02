#include"date.h"
#include"arrList.h"
#include"bookIndex.h"
#include"muonTra.h"
#include"docGia.h"
#include"bookHeader.h"
#include"String.h"
using namespace std;
#include<iostream>

struct dsdgList {
	dsdg* data;
	dsdgList* next;
};
struct dsdgListOut {
	dsdg* data;
	int outDate;
	dsdgListOut* next;
};


int choice();
void readerHandle(dsdg*& readerTree, arrList* codeDg);
void printReader(dsdg* readerTree);
void findBookByName(bookHeader** bookHeaderList, int n);
void BorrowBook(dsdg* readerTree, bookHeader** bookHeaderList, int n);
void giveBookBack(dsdg* readerTree, bookHeader** bookHeaderList, int n);
void printBookBorrowing(dsdg* readerTree, bookHeader** bookHeaderList, int n);
void printOutOfDateReader(dsdg* readerTree);
void printTop10Book(dsdg* readerTree, bookHeader** bookHeaderList, int n);
void makeListFromTree(dsdg*, dsdgList*&);
void makeListFromTree2(dsdg* readerTree, dsdgListOut*& lst, date);
void insertList(dsdg* tree, dsdgList*& list);
void insertList2(dsdg* tree, dsdgListOut*& list, date);
void check(dsdg* dg, date curr);
date findmaxOut(dsdg* tree);
void sumTop10(dsdg* readerTree, bookHeader** bookHeaderList, int n, int* arr);



int main() {
	arrList* codeBook = NULL;
	arrList* codeDg = NULL;
	bookHeader** bookHeaderList = NULL;
	int n = 0;
	dsdg* readerTree = NULL;
	int choose = 0;
	while (choose != 11) {
		choose = choice();
		switch (choose)
		{
		case 1:
			readerHandle(readerTree, codeDg);
			break;
		case 2:
			printReader(readerTree);
			break;
		case 3:
			inputBookHeader(bookHeaderList, n, codeBook);
			break;
		case 4:
			printBookHeaderNameInc(bookHeaderList, n);
			break;
		case 5:
			findBookByName(bookHeaderList, n);
			break;
		case 6:
			BorrowBook(readerTree, bookHeaderList, n);
			break;
		case 7:
			giveBookBack(readerTree, bookHeaderList, n);
			break;
		case 8:
			printBookBorrowing(readerTree, bookHeaderList, n);
			break;
		case 9:
			printOutOfDateReader(readerTree);
			break;
		case 10:
			printTop10Book(readerTree, bookHeaderList, n);
			break;
		default:
			cout << "Done!!" << endl;
		}
	}
	return 0;
}

int choice() {
	cout << "\n----------------------------menu--------------------------------";
	cout << "\n1) thong tin doc gia";
	cout << "\n2) in danh sach doc gia";
	cout << "\n3) nhap dau sach";
	cout << "\n4) in danh sach cac dau sach theo thu tu ten sach tang dan";
	cout << "\n5) tim sach theo ten";
	cout << "\n6) muon sach";
	cout << "\n7) tra sach";
	cout << "\n8) liet ke so sach ma doc gia dang muon";
	cout << "\n9) in danh sach doc gia qua han theo thoi gian giam dan";
	cout << "\n10) in 10 sach co so luot muon nhieu nhat";
	cout << "\n11) thoat";
	int n;
	cout << "\nlua chon: "; cin >> n;
	while (n < 1 || n > 11) {
		cout << "\nlua chon: "; cin >> n;
	}
	return n;
}
void readerHandle(dsdg*& readerTree, arrList* codeDg) {
	cout << "\n1) nhap doc gia";
	cout << "\n2) xoa doc gia";
	cout << "\n3) sua thong tin doc gia";
	int n = 0;
	cout << "\nlua chon: "; cin >> n;
	while (n < 1 || n > 3) {
		cout << "lua chon: "; cin >> n;
	}
	int ma;
	if (n != 1) {
		cout << "nhap ma doc gia: "; cin >> ma;
	}
	switch (n) {
	case 1:
		inputReader(readerTree, codeDg);
		break;
	case 2:
		deleteReader(readerTree, ma, codeDg);
		break;
	case 3:
		editReader(readerTree, ma, codeDg);
		break;
	}
}


void printReader(dsdg* readerTree) {
	cout << "\n1) xuat theo ten tang dan";
	cout << "\n2) xuat theo ma tang dan";
	int n;
	cout << "\nlua chon: "; cin >> n;
	while (n < 1 || n > 2) {
		cout << "\nlua chon: "; cin >> n;
	}
	if (n == 1) {
		dsdgList* lst = NULL;
		makeListFromTree(readerTree, lst);
		dsdgList* temp = lst;
		while (temp) {
			cout << "\nma dg: " << temp->data->MADG;
			cout << "\nho ten: " << temp->data->ho << " " << temp->data->ten;
			cout << "\nphai: " << temp->data->phai;
			cout << "\ntinh trang the: " << temp->data->trangThaiThe;
			cout << endl;
			temp = temp->next;
		}
		temp = lst;
		while (lst) {
			lst = lst->next;
			delete temp;
			temp = lst;
		}
	}
	else {
		printReaderLNR(readerTree);
	}
}

void makeListFromTree(dsdg* tree, dsdgList*& list) {
	if (tree) {
		if (tree->left) makeListFromTree(tree->left, list);
		insertList(tree, list);
		if (tree->right) makeListFromTree(tree->right, list);
	}
}
void insertList(dsdg* tree, dsdgList*& list) {
	if (list) {
		if (list->next)
		{
			if (compareTenHo(tree, list->data) == 2) {
				dsdgList* temp = new dsdgList;
				temp->data = tree;
				temp->next = list;
				list = temp;
			}
			dsdgList* temp = list;
			while (temp->next) {
				if (compareTenHo(tree, temp->next->data) == 2) {
					break;
				}
				temp = temp->next;
			}
			dsdgList* val = new dsdgList;
			val->data = tree;
			if (temp->next) val->next = temp->next;
			else val->next = NULL;
			temp->next = val;
		}
		else
		{
			if (compareTenHo(tree, list->data) == 2) {
				dsdgList* temp = new dsdgList;
				temp->data = tree;
				temp->next = list;
				list = temp;
			}
			else {
				dsdgList* temp = new dsdgList;
				temp->data = tree;
				list->next = temp;
				temp->next = NULL;
			}
		}
	}
	else {
		list = new dsdgList;
		list->data = tree;
		list->next = NULL;
	}
}

void findBookByName(bookHeader** bookHeaderList, int n) {
	char str[100];
	cout << "nhap ten sach: "; cin.ignore(); cin.getline(str, 100);
	for (int i = 0; i < n; i++) {
		if (compareString(str, bookHeaderList[i]->tenSach) == 0) {
			cout << "\n" << bookHeaderList[i]->ISBN << " " << bookHeaderList[i]->tenSach << " " << bookHeaderList[i]->theLoai << " " << bookHeaderList[i]->soTrang << " " << bookHeaderList[i]->tacGia << " " << bookHeaderList[i]->namXuatBan;
			break;
		}
	}
}
void BorrowBook(dsdg* readerTree, bookHeader** bookHeaderList, int n) {
	date current;
	current = nhapDate();
	cout << "\nnhap ten doc gia can muon: ";
	char ten[100];
	cin.ignore(100, '\n'); cin.getline(ten, 100);
	dsdg* dg = findReader(readerTree, ten);
	check(dg, current);
	if (dg->trangThaiThe == 0) {
		cout << "\nkhong muon duoc vi da bi khoa the";
		return;
	}
	else {
		cout << "\nnhap so luong sach can muon( >= 1 va <= 3): "; int num;
		cin >> num;
		while (num < 1 || num > 3) {
			cout << "\nnhap lai: "; cin >> num;
		}
		cin.ignore();
		for (int r = 0; r < num; r++) {
			char tenSach[100];
			cout << "\nnhap ten sach: "; cin.getline(tenSach, 100);
			for (int i = 0; i < n; i++) {
				if (compareString(bookHeaderList[i]->tenSach, tenSach) == 0) {
					bookIndex* temp = bookHeaderList[i]->contro;
					while (temp) {
						if (temp->trangThai == 0) {
							temp->trangThai = 1;
							muonTra* temp2 = createMuonTraNode(temp->maSach, 0, current, current+15, dg->contro);
							dg->contro = temp2;
							break;
						}
						temp = temp->next;
					}
					if (!temp) cout << "\nkhong con sach ten " << bookHeaderList[i]->tenSach;
					else cout << "\nda muon duoc sach ten " << bookHeaderList[i]->tenSach;
					break;
				}
			}
		}


	}
}
void check(dsdg* dg, date curr) {
	muonTra* temp = dg->contro;
	int borrowing = 0;
	while (temp) {
		if (temp->trangThai == 2) {
			dg->trangThaiThe = 0;
			return;
		}
		else if (temp->trangThai == 0 && temp->ngayTra - curr < 0) {
			dg->trangThaiThe = 0;
			return;
		}
		else if (temp->trangThai == 0) {
			borrowing++;
			if (borrowing >= 3) {
				dg->trangThaiThe = 0;
				return;
			}
		}
		temp = temp->next;
	}
	dg->trangThaiThe = 1;
}

void giveBookBack(dsdg* readerTree, bookHeader** bookHeaderList, int n) {
	cout << "\nnhap ten doc gia tra sach: ";
	char ten[100];
	cin.ignore(100, '\n'); cin.getline(ten, 100);
	dsdg* dg = findReader(readerTree, ten);
	cout << "\nnhap ten sach tra: ";
	char tenSach[100];
	cin.getline(tenSach, 100);
	muonTra* temp = dg->contro;
	while (temp) {
		if (temp->trangThai == 0) {
			bookHeader* b = bookHeaderList[findBook(bookHeaderList, n, temp->maSach)];
			if (compareString(b->tenSach, tenSach) == 0) {
				temp->trangThai = 1;
				bookIndex* c = b->contro;
				while (c) {
					if (c->maSach == temp->maSach) {
						c->trangThai = 0;
						break;
					}
					c = c->next;
				}
				if (c) {
					cout << "\nda tra thanh cong cuon " << b->tenSach;
					break;
				}
			}
		}
		temp = temp->next;
	}
}
void printBookBorrowing(dsdg* readerTree, bookHeader** bookHeaderList, int n) {
	char ten[100];
	cout << "nhap ten doc gia can liet ke sach: "; cin.ignore(); cin.getline(ten, 100);
	dsdg* dg = findReader(readerTree, ten);
	if (!dg) {
		cout << "\nkhong tim thay doc gia";
		return;
	}
	muonTra* temp = dg->contro;
	while (temp) {
		if (temp->trangThai == 0) {
			bookHeader* temp2 = bookHeaderList[findBook(bookHeaderList, n, temp->maSach)];
			cout << '\n' << temp2->ISBN << " " << temp2->tenSach << " " << temp2->soTrang << " " << temp2->tacGia << " " << temp2->theLoai << " " << temp2->namXuatBan << " " << temp->maSach;

		}
		temp = temp->next;
	}

}
void printOutOfDateReader(dsdg* readerTree) {
	dsdgListOut* lst = NULL;
	date current;
	current = nhapDate();
	makeListFromTree2(readerTree, lst, current);
	dsdgListOut* temp = lst;
	while (temp) {
		cout << "\nma dg: " << temp->data->MADG;
		cout << "\nho ten: " << temp->data->ho << " " << temp->data->ten;
		cout << "\nphai: " << temp->data->phai;
		cout << "\ntinh trang the: " << temp->data->trangThaiThe;
		cout << endl;
		temp = temp->next;
	}
	temp = lst;
	while (lst) {
		lst = lst->next;
		delete temp;
		temp = lst;
	}
}
void makeListFromTree2(dsdg* tree, dsdgListOut*& list, date curr) {
	if (tree) {
		if (tree->left) makeListFromTree2(tree->left, list, curr);
		insertList2(tree, list, curr);
		if (tree->right) makeListFromTree2(tree->right, list, curr);
	}
}
void insertList2(dsdg* tree, dsdgListOut*& list, date curr) {
	if (list) {
		if (list->next)
		{
			dsdgListOut* temp = new dsdgListOut;
			temp->data = tree;
			temp->outDate = curr - findmaxOut(tree);
			if (temp->outDate > list->outDate) {
				temp->next = list;
				list = temp;
			}
			else {
				dsdgListOut* temp2 = list;
				while (temp2->next) {
					if (temp->outDate > temp2->next->outDate) {
						temp->next = temp2->next;
						temp2->next = temp;
						break;
					}
					temp2 = temp2->next;
				}
				if (!temp2->next) {
					temp->next = NULL;
					temp2->next = temp;
				}
			}
		}
		else
		{
			dsdgListOut* temp = new dsdgListOut;
			temp->data = tree;
			temp->outDate = curr - findmaxOut(tree);
			if (temp->outDate > list->outDate) {
				temp->next = list;
				list = temp;
			}
			else {
				list->next = temp;
				temp->next = NULL;
			}
		}
	}
	else {
		list = new dsdgListOut;
		list->data = tree;
		list->outDate = curr - findmaxOut(tree);
		list->next = NULL;
	}
}
date findmaxOut(dsdg* tree) {
	int ini = 0;
	date max;
	max.day = 0;
	max.month = 0;
	max.year = 0;
	muonTra* temp = tree->contro;
	while (temp) {
		if (temp->trangThai == 0) {
			if (!ini) {
				max = temp->ngayTra;
				ini = 1;
			}
			else {
				if (max - temp->ngayTra > 0) {
					max = temp->ngayTra;
				}
			}
		}
		temp = temp->next;
	}
	return max;

}
void printTop10Book(dsdg* readerTree, bookHeader** bookHeaderList, int n) {
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = 0;
	}
	sumTop10(readerTree, bookHeaderList, n, arr);
	int max = 0;
	int* arrPos = new int[n];
	for (int i = 0; i < n; i++) {
		arrPos[i] = i;
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[arrPos[i]] < arr[arrPos[j]]) {
				int temp = arrPos[i];
				arrPos[i] = arrPos[j];
				arrPos[j] = temp;
			}
		}
	}
	if (n > 10) n = 10;
	for (int i = 0; i < n; i++) {
		bookHeader* temp2 = bookHeaderList[arrPos[i]];
		cout << '\n' << temp2->ISBN << " " << temp2->tenSach << " " << temp2->soTrang << " " << temp2->tacGia << " " << temp2->theLoai;
	}
}
void sumTop10(dsdg* readerTree, bookHeader** bookHeaderList, int n, int* arr) {
	if (readerTree) {
		sumTop10(readerTree->left, bookHeaderList, n, arr);
		muonTra* temp = readerTree->contro;
		while (temp) {
			arr[findBook(bookHeaderList, n, temp->maSach)] ++;
			temp = temp->next;
		}
		sumTop10(readerTree->right, bookHeaderList, n, arr);
	}
}

