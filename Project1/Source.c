#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <inttypes.h>
#include <stdbool.h>
#define filename "c:\\data\\menu.txt"

int* D;
int N = 0;
int adet = 0;

void menu(void);
void read_file(void);
void add(void);
void list(void);
void search(void);
void update(void);
void delete_ph(void);
void delete_l(void);
void write_file(void);

int main() {
	setlocale(LC_ALL, "Turkish");
	read_file();
	do {
		menu();
	} while (1);
	system("pause");
	return 0;
}
void menu(void) {
	setlocale(LC_ALL, "Turkish");
	char choose;
	system("cls");
	printf("[Array Size : %d adet : %d] Menu\n", N, adet);
	printf("  0-Read From File\n");
	printf("  1-Add Record\n");
	printf("  2-Search Record\n");
	printf("  3-List Record\n");
	printf("  4-Update Record\n");
	printf("  5-Record Physical\n");
	printf("  6-Delete Record Logical\n");
	printf("  7-Save and Exit\n");
	printf("Choose (1/2/3/4/5/6/7)? : ");
	do {
		choose = _getch();
	} while (!(choose > 48 && choose < 56));
	printf("\n");
	switch (choose) {
	case 48:read_file(); break;
	case 49:add(); break;
	case 50:search(); break;
	case 51:list(); break;
	case 52:update(); break;
	case 53:delete_ph(); break;
	case 54:delete_l(); break;
	case 55: {read_file(); printf("\nHave a Nice Day\n"); system("pause"); exit(-1); }
	}
}
void read_file(void) {
	FILE* fp;

	int D_uz, i;
	fp = fopen(filename, "r");
	fseek(fp, 0, SEEK_END);
	D_uz = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	adet = D_uz / sizeof(int);
	printf("Adet %d\n", adet);
	N = adet * 2;
	D = (int*)calloc(N, sizeof(int));
	for (i = 0; i < adet; i++) {
		fscanf(fp, "%d\n", &D[i]);
	}
	fclose(fp);
}
void add(void) {
	int value;
	printf("Value to add : ");
	scanf("%d", &value);
	if (adet + 1 > N) {
		printf("Array Full !");
		_getch();
	}
	else {
		D[adet] = value;
		adet++;
		printf("Added new value array !\n");
		_getch();
	}
}
void list(void) {
	int i;
	for (i = 0; i < N; i++) {
		if (D[i] != 0) {
			fprintf(stdout, "[%3d.] %d\n", i, D[i]);
		}
	}
	_getch();
}
void search() {
	int i, intermediate_value;
	bool situation = false;
	printf("Value to look for :");
	scanf("%d", &intermediate_value);
	for (i = 0; i < N; i++) {
		if (D[i] != 0 && intermediate_value == D[i]) {
			situation = true;
			break;
		}
	}
	if (situation)fprintf(stdout, "I found :[%3d.]  %d\n", i, D[i]);
	else printf("I couldn't found it.\n");
	_getch();
}
void update(void) {
	int i, value_day, value;
	bool situation = false;
	printf("Value to Update : ");
	scanf("%d", &value_day);
	for (i = 0; i < N; i++) {
		if (D[i] != 0 && value_day == D[i]) {
			situation = true;
			break;
		}
	}
	if (situation) {
		fprintf(stdout, "I found : [%3d.] %d\n", i, D[i]);
		printf("New value : ");
		scanf("%d", &value);
		D[i] = value;
		printf("Updated.\n");
	}
	else {
		printf("I couldn't fount it.\n");
	}
	_getch();
}
void delete_ph(void) {
	int i, j, delete_value;
	bool situation = false;
	printf("Value to Deleted : ");
	scanf("%d", &delete_value);
	for (i = 0; i < adet; i++) {
		if (delete_value == D[i]) {
			situation = true;
			break;
		}
	}
	if (situation) {
		fprintf(stdout, "I found : [%3d.] %d\n", i, D[i]);
		for (j = i; j < adet; j++) {
			D[j] = D[j + 1];
		}
		printf("Value deleted.\n");
		D[adet] = 0;
		adet--;
	}
	else {
		printf("I couldn't found it.\n");
	}
	_getch();
}
void delete_l(void) {
	int i, j, delete_value;
	bool situation = false;
	printf("Value to Deleted : ");
	scanf("%d", &delete_value);
	for (i = 0; i < N; i++) {
		if (D[i] != 0 && delete_value == D[i]) {
			situation = true;
			break;
		}
	}
	if (situation) {
		fprintf(stdout, "I found : [%3d.] %d\n", i, D[i]);
		D[i] = 0;
		adet--;
		printf("Value Deleted.\n");
	}
	else {
		printf("I couldn't found it.\n");
	}
	_getch();
}
void write_file(void) {
	FILE* fp;

	int D_uz, i;
	fp = fopen(filename, "w");
	for (i = 0; i < N; i++) {
		if (D[i] != 0) {
			fprintf(fp, "%d\n", D[i]);
		}
	}
	fclose(fp);
}
void buffersil(void) {
	while (getchar() != '\n');
} 