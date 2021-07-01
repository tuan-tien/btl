#include"date.h"

int operator-(date d1, date d2) {
	return (d1.year - d2.year) * 365 + (d1.month - d2.month) * 30 + (d1.day - d2.day);
}
date operator+(date d1, int n) {
	d1.day += n;
	while (d1.day > 30) {
		d1.day -= 30;
		d1.month++;
	}
	while (d1.day < 0) {
		d1.day += 30;
		d1.month--;
	}
	while (d1.month > 12) {
		d1.month -= 12;
		d1.year++;
	}
	while (d1.month < 1) {
		d1.month += 12;
		d1.year--;
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
date operator-(date d1, int n) {
	return d1 + n * (-1);
}
istream& operator>>(istream& inp, date& d) {
	cout << "nhap ngay: "; inp >> d.day;
	cout << "nhap thang: "; inp >> d.month;
	cout << "nhap nam: "; inp >> d.year;
	return inp;
}
ostream& operator<<(ostream& out, date d) {
	out << d.day << "/" << d.month << "/" << d.year << endl;
	return out;
}
