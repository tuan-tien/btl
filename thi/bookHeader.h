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
int findBook(bookHeader** bookHeaderList, int n, int ma);
void add(bookHeader** &a1, int &n1, bookHeader** a2, int n2);
int findBook(bookHeader** bookHeaderList, int n, bool (*con)(bookHeader*));
void deleteBook(bookHeader** &bookHeaderList, int &n, bool (*con)(bookHeader*));
void deleteBook(bookHeader** &bookHeaderList, int &n, int pos);
void deleteAllBook(bookHeader** &bookHeaderList, int &n);
