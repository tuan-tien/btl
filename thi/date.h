#pragma once
#include<iostream>
using namespace std;

struct date {
	int day;
	int month;
	int year;
};
int operator-(date d1, date d2);
date operator-(date d1, int n);
date operator+(date d1, int n);
date operator+(int n, date d1);
date nhapDate();
istream& operator>>(istream& inp, date& d);
ostream& operator<<(ostream& out, date d);
