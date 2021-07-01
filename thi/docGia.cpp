#include "docGia.h"

void inputReader(dsdg*& readerTree, arrList* codeDg) {
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
	insert(codeDg, createNode(temp->MADG));
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
void deleteReader(dsdg*& dad, int ma, arrList* codeDg) {
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
void editReader(dsdg*& dad, int ma, arrList* codeDg) {
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
void printReaderLNR(dsdg* dad) {
	if (dad) {
		if (dad->left) printReaderLNR(dad->left);
		cout << '\n' << dad->MADG << "  " << dad->ho << " " << dad->ten << "  " << dad->phai << "  " << dad->trangThaiThe << "  ";
		if (dad->right) printReaderLNR(dad->right);
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
int compareTenHo(dsdg* p1, dsdg* p2) {
	int temp = compareString(p1->ten, p2->ten);
	if (temp != 0) return temp;
	else return compareString(p1->ho, p2->ho);
}