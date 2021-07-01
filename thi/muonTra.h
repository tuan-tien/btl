#pragma once
using namespace std;
#include<iostream>
#include"date.h"
struct muonTra {
	int maSach;
	date ngayMuon;
	date ngayTra;
	int trangThai;
	muonTra* next;
};
void insert(muonTra*& first, muonTra* nod);
muonTra* createMuonTraNode();
muonTra* createMuonTraNode(int ma, int tt, date ngm, date  ngt, muonTra* ne = NULL);
int findElement(muonTra* first, int ma = 0);
int findElement(muonTra* first, bool (*con)(muonTra*));
void deleteElement(muonTra*& first, bool (*con)(muonTra*));
void deleteElement(muonTra*& first, int n = 0);
void deleteAllElement(muonTra*& first);
