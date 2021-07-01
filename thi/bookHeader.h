#pragma once
using namespace std;
#include<iostream>
#include"bookIndex.h"
#include"arrList.h"
struct bookHeader {
	int ISBN;
	char* tenSach;
	int soTrang;
	int namXuatBan;
	char* tacGia;
	char* theLoai;
	bookIndex* contro;
};
void inputBookHeader(bookHeader**& bookHeaderList, int& n, arrList*);
void printBookHeaderNameInc(bookHeader** bookHeaderList, int n);
bookHeader* findBook(bookHeader** bookHeaderList, int n, int ma);