#pragma once
using namespace std;
#include<iostream>
#include"muonTra.h"
#include"arrList.h"
#include"String.h"

struct dsdg {
	int MADG;
	char* ten;
	char* ho;
	int phai;
	int trangThaiThe;
	muonTra* contro;
	dsdg* left, * right;
};

void inputReader(dsdg*& readerTree, arrList* codeDg);
dsdg* createReaderNode(arrList* codeDg);
void insertReaderNode(dsdg*&, dsdg*);
void deleteReader(dsdg*& readerTree, int ma, arrList*);
void editReader(dsdg*& readerTree, int ma, arrList* codeDg);
void printReaderLNR(dsdg* readerTree);
dsdg* findReader(dsdg* readerTree, char* ten);
int compareTenHo(dsdg*, dsdg*);



