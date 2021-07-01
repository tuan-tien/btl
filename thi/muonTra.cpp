#include "muonTra.h"
void insert(muonTra*& first, muonTra* nod) {
	nod->next = first;
	first = nod;
}
muonTra* createMuonTraNode() {
	muonTra* temp = new muonTra;
	cout << "nhap ma sach: "; cin >> temp->maSach;
	cout << "nhap trang thai: "; cin >> temp->trangThai;
	cout << "nhap ngay muon: \n";
	temp->ngayMuon = nhapDate();
	temp->ngayTra = temp->ngayMuon + 15;
	temp->next = NULL;
	return temp;
}
muonTra* createMuonTraNode(int ma, int tt, date ngm, date  ngt, muonTra* ne) {
	muonTra* temp = new muonTra;
	temp->maSach = ma;
	temp->trangThai = tt;
	temp->ngayMuon = ngm;
	temp->ngayTra = ngt;
	temp->next = ne;
	return temp;
}
int findElement(muonTra* first, int n) {
	if (!first) return -1;
	else {
		int i = 0;
		muonTra* temp = first;
		while (temp) {
			if (temp->maSach == n) return i;
			temp = temp->next;
			i++;
		}
		return -1;
	}
}
int findElement(muonTra* first, bool (*con)(muonTra*)) {
	if (!first) return -1;
	else {
		int n = 0;
		muonTra* temp = first;
		while (temp) {
			if (con(temp)) return n;
			temp = temp->next;
			n++;
		}
		return -1;
	}
}
void deleteElement(muonTra*& first, bool (*con)(muonTra*)) {
	int pos = findElement(first, con);
	if (pos != -1) {
		muonTra* temp = first;
		if (!pos) {
			first = first->next;
			delete temp;
		}
		else {
			for (int i = 0; i < pos - 1; i++) {
				temp = temp->next;
			}
			muonTra* temp2 = temp->next;
			temp->next = temp2->next;
			delete temp2;
		}
	}
}
void deleteElement(muonTra*& first, int n) {
	int pos = findElement(first, n );
	if (pos != -1) {
		muonTra* temp = first;
		if (!pos) {
			first = first->next;
			delete temp;
		}
		else {
			for (int i = 0; i < pos - 1; i++) {
				temp = temp->next;
			}
			muonTra* temp2 = temp->next;
			temp->next = temp2->next;
			delete temp2;
		}
	}
}
void deleteAllElement(muonTra*& first) {
	muonTra* temp = first;
	while (first) {
		first = first->next;
		delete temp;
		temp = first;
	}
}