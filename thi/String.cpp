#include "String.h"
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
