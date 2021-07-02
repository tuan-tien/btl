#pragma once
#include<iostream>
#include"arrList.h"
using namespace std;
struct bookIndex {
	int maSach;
	int trangThai;
	int viTri;
	bookIndex* next;
};
bookIndex* createBookIndex(arrList* codeBook);
void deleteAllBookIndexNod(bookIndex* first);
