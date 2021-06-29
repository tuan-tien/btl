#include<iostream>
using namespace std;

struct bookIndex {
	int maSach;
	int trangThai;
	int viTri;
	bookIndex* next;
};
struct bookHeader {
	int ISBN;
	char* tenSach;
	int soTrang;
	int namXuatBan;
	char* tacGia;
	char* theLoai;
	bookIndex* contro;
};
struct date {
	int day;
	int month;
	int year;
};
struct muonTra {
	int maSach;
	date ngayMuon;
	date ngayTra;
	int trangThai;
	muonTra* next;
};
struct dsdg {
	int MADG;
	char* ten;
	char* ho;
	int phai;
	int trangThaiThe;
	muonTra *contro;
	dsdg* left, * right;
};
struct dsdgList {
	dsdg* data;
	dsdgList* next;
};
struct dsdgListOut {
	dsdg* data;
	int outDate;
	dsdgListOut* next;
};
struct arrList {
	int data;
	struct arrList* next;
};

int choice();
void readerHandle(dsdg* &readerTree, arrList* codeDg);
void printReader(dsdg* readerTree);
void inputBookHeader(bookHeader** &bookHeaderList, int &n, arrList* );
void printBookHeaderNameInc(bookHeader** bookHeaderList, int n);
void findBookByName(bookHeader** bookHeaderList, int n);
void BorrowBook(dsdg* readerTree, bookHeader** bookHeaderList, int n);
void giveBookBack(dsdg* readerTree, bookHeader** bookHeaderList, int n);
void printBookBorrowing(dsdg* readerTree, bookHeader** bookHeaderList, int n);
void printOutOfDateReader(dsdg* readerTree);
void printTop10Book(dsdg* readerTree, bookHeader** bookHeaderList, int n);
void inputReader(dsdg* &readerTree, arrList* codeDg);
dsdg* createReaderNode(arrList* codeDg);
void insertReaderNode(dsdg*&, dsdg*);
void deleteReader(dsdg* &readerTree, int ma, arrList* );
void editReader(dsdg* &readerTree, int ma, arrList* codeDg);
void printReaderLNR(dsdg* readerTree);
void makeListFromTree(dsdg*, dsdgList*&);
void makeListFromTree2(dsdg* readerTree, dsdgListOut*& lst, date);
int compareString(char*, char*);
void insertList(dsdg* tree, dsdgList*& list);
void insertList2(dsdg* tree, dsdgListOut*& list, date);
bookIndex* createBookIndex(arrList* codeBook);
dsdg* findReader(dsdg* readerTree, char* ten);
bookHeader* findBook(bookHeader** bookHeaderList, int n, int ma);
date nhapDate();
date findmaxOut(dsdg* tree);
void check(dsdg* dg, date curr);
int operator-(date d1, date d2);
date operator+(date d1, int n);
date operator+(int n, date d1);
void sumTop10(dsdg* readerTree, bookHeader** bookHeaderList, int n, int* arr);
int compareTenHo(dsdg* , dsdg* );
void insert(arrList* &first, arrList* nod);
arrList* createNode(int n = 0);
int findElement(arrList* first, int n = 0);
void deleteElement(arrList* &first, int n = 0);

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
			inputBookHeader(bookHeaderList,n, codeBook);
			break;
		case 4:
			printBookHeaderNameInc(bookHeaderList,n);
			break;
		case 5:
			findBookByName(bookHeaderList,n);
			break;
		case 6:
			BorrowBook(readerTree, bookHeaderList,n);
			break;
		case 7:
			giveBookBack(readerTree, bookHeaderList,n);
			break;
		case 8:
			printBookBorrowing(readerTree, bookHeaderList,n);
			break;
		case 9:
			printOutOfDateReader(readerTree);
			break;
		case 10:
			printTop10Book(readerTree, bookHeaderList,n);
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
void inputReader(dsdg* &readerTree, arrList* codeDg) {
	int n;
	cout << "\nnhap so luong doc gia: "; cin >> n;
	for (int i = 0; i < n; i++) {
		insertReaderNode(readerTree, createReaderNode(codeDg));
	}
}
dsdg* createReaderNode(arrList* codeDg) {
	dsdg* temp = new dsdg;
	temp->MADG = rand() % 100001;
	while (findElement(codeDg, temp->MADG) != -1) {
		temp->MADG = rand() % 100001;
	}
	insert(codeDg,createNode(temp->MADG));
	cout << "nhap ho: "; cin.ignore();
	temp->ho = new char[100];
	cin.getline(temp->ho, 100);
	cout << "nhap ten: "; 
	temp->ten = new char[100];
	cin.getline(temp->ten, 100);
	cout << "nhap phai: "; cin >> temp->phai;
	cout << "nhap trang thai: "; cin >> temp->trangThaiThe;
	temp->contro = NULL;
	temp->left = temp->right = NULL;
	return temp;
}
void insertReaderNode(dsdg*& dad, dsdg* nod) {
	if (dad) {
		if (dad->MADG > nod->MADG) insertReaderNode(dad->left, nod);
		else insertReaderNode(dad->right, nod);
	}
	else {
		dad = nod;
	}
}
void deleteReader(dsdg* &dad, int ma, arrList* codeDg) {
	if (dad) {
		if (dad->MADG < ma) deleteReader(dad->right, ma, codeDg);
		if (dad->MADG > ma) deleteReader(dad->left, ma, codeDg);		
		dsdg* left = dad->left, * right = dad->right;
		deleteElement(codeDg, dad->MADG);
		delete dad;
		if (left) {
			dad = left;
			insertReaderNode(dad, right);
		}
		else if (right) {
			dad = right;
		}
		
	}
}
void editReader(dsdg* &dad, int ma, arrList* codeDg) {
	if (dad) {
		if (dad->MADG < ma) editReader(dad->right, ma, codeDg);
		else if (dad->MADG > ma) editReader(dad->left, ma, codeDg);
		else {
			dsdg* left = dad->left, * right = dad->right; 
			int madg = dad->MADG; 
			muonTra* con = dad->contro;
			delete dad;
			dad = createReaderNode(codeDg);
			dad->left = left;
			dad->right = right;
			dad->contro = con;
			dad->MADG = madg;
		}
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
void printReaderLNR(dsdg* dad) {
	if (dad){
		if (dad->left) printReaderLNR(dad->left);
		cout <<'\n' << dad->MADG << "  " << dad->ho << " " << dad->ten << "  " << dad->phai << "  " << dad->trangThaiThe << "  ";
		if (dad->right) printReaderLNR(dad->right);
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
int compareTenHo(dsdg* p1, dsdg* p2) {
	int temp = compareString(p1->ten, p2->ten);
	if (temp != 0) return temp;
	else return compareString(p1->ho, p2->ho);
}
int compareString(char* c1, char* c2) {
	int i = 0;
	while (c1[i] != '\0' && c2[i] != '\0') {
		if (c1[i] > c2[i]) return 1;
		else if (c1[i] < c2[i]) return 2;
		i++;
	}
	if (c1[i] == '\0' && c2[i] == '\0') return 0;
	else if (c1[i] == '\0') return 2;
	else return 1;
}
void inputBookHeader(bookHeader**& bookHeaderList, int &n, arrList* codeBook) {
	cout << "nhap so luong dau sach: ";
	cin >> n;
	if (bookHeaderList) delete[] bookHeaderList;
	bookHeaderList = new bookHeader*[n];
	for (int i = 0; i < n; i++) {
		bookHeaderList[i] = new bookHeader;
		cout << "\nnhap IBSN : "; cin >> bookHeaderList[i]->ISBN;
		bookHeaderList[i]->tenSach = new char[100];
		cout << "nhap ten sach : "; cin.ignore();cin.getline( bookHeaderList[i]->tenSach, 100);
		cout << "nhap so trang : "; cin >> bookHeaderList[i]->soTrang;
		cout << "nhap nam xuat ban : "; cin >> bookHeaderList[i]->namXuatBan;
		bookHeaderList[i]->tacGia = new char[100];
		cout << "nhap tac gia : "; cin.ignore(); cin.getline(bookHeaderList[i]->tacGia, 100);
		bookHeaderList[i]->theLoai = new char[100];
		cout << "nhap the loai: "; cin.getline(bookHeaderList[i]->theLoai, 100);
		bookHeaderList[i]->contro = createBookIndex(codeBook);
	}
}
bookIndex* createBookIndex(arrList* codeBook) {
	cout << "nhap so luong sach: ";
	int n;
	cin >> n;
	bookIndex* first =  NULL, * last = NULL;
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
	cout << "\n" << bookHeaderList[n-1]->ISBN << " " << bookHeaderList[n - 1]->tenSach << " " << bookHeaderList[n - 1]->theLoai << " " << bookHeaderList[n - 1]->soTrang << " " << bookHeaderList[n - 1]->tacGia << " " << bookHeaderList[n - 1]->namXuatBan;
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
	check(dg,current);
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
							muonTra* temp2 = new muonTra;
							temp2->maSach = temp->maSach;
							temp2->trangThai = 0;
							temp2->ngayMuon = current;
							temp2->ngayTra = current + 15;
							temp2->next = dg->contro;
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
int operator-(date d1, date d2) {
	return (d1.year - d2.year) * 365 + (d1.month - d2.month) * 30 + (d1.day - d2.day);
}
date operator+(date d1, int n) {
	d1.day += n;
	if (d1.day > 30) {
		d1.day -= 30;
		d1.month++;
	}
	if (d1.month > 12) {
		d1.month -= 12;
		d1.year++;
	}
	return d1;
}
date operator+(int n, date d1) {
	return d1 + n;
}

date nhapDate() {
	date temp;
	cout << "\nnhap ngay: "; cin >> temp.day;
	cout << "nhap thang: "; cin >> temp.month;
	cout << "nhap nam: "; cin >> temp.year;
	return temp;
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
			bookHeader* b = findBook(bookHeaderList,n,temp->maSach);
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
			bookHeader* temp2 = findBook(bookHeaderList, n, temp->maSach);
			cout << '\n' << temp2->ISBN << " " << temp2->tenSach << " " << temp2->soTrang << " " << temp2->tacGia << " " << temp2->theLoai << " " << temp2->namXuatBan << " " << temp->maSach;

		}
		temp = temp->next;
	}

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
dsdg* findReader(dsdg* readerTree, char* ten) {
	if (readerTree) {
		if (compareString(readerTree->ten, ten) == 0)return readerTree;
		else {
			dsdg* temp = findReader(readerTree->left, ten);
			dsdg* temp2 = findReader(readerTree->right, ten);
			if (temp) return temp;
			else {
				if (temp2) return temp2;
				else return NULL;
			}
		}
	}
	else return NULL;
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
	muonTra * temp = tree->contro;
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
			bookHeader* temp2 = findBook(bookHeaderList,n,temp->maSach);
			for (int i = 0; i < n; i++) {
				if (bookHeaderList[i] == temp2) {
					arr[i]++;
					break;
				}
			}
			temp = temp->next;
		}
		sumTop10(readerTree->right, bookHeaderList, n, arr);
	}
}
void insert(arrList* &first, arrList* nod) {
	nod->next = first;
	first = nod;
}
arrList* createNode(int n = 0) {
	arrList* temp = new arrList;
	temp->data = n;
	temp->next = NULL;
	return temp;
}
int findElement(arrList* first, int n = 0) {
	if (!first) return -1;
	else {
		int n = 0;
		arrList* temp = first;
		while (temp) {
			if (temp->data == n) return n;
			temp = temp->next;
			n++;
		}
		return -1;
	}
}
void deleteElement(arrList* &first, int n = 0) {
	int pos = findElement(first, n);
	if (pos != -1) {
		arrList* temp = first;
		if (!pos) {			
			first = first->next;
			delete temp;
		}
		else {
			for (int i = 0; i < n-1; i++) {
				temp = temp->next;
			}
			arrList* temp2 = temp->next;
			temp->next = temp2->next;
			delete temp2;
		}
	}
}
