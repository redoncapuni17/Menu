#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <inttypes.h>
#include <stdbool.h>
#define dosya_ismi "c:\\data\\menu.txt"

int* D;
int N = 0;
int adet = 0;

void menu(void);
void dosya_oku(void);
void ekle(void);
void liste(void);
void ara(void);
void guncelle(void);
void sil_f(void);
void sil_m(void);
void dosya_yaz(void);

int main() {
	setlocale(LC_ALL, "Turkish");
	dosya_oku();
	do {
		menu();
	} while (1);
	system("pause");
	return 0;
}
void menu(void) {
	setlocale(LC_ALL, "Turkish");
	char secim;
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
		secim = _getch();
	} while (!(secim > 48 && secim < 56));
	printf("\n");
	switch (secim) {
	case 48:dosya_oku(); break;
	case 49:ekle(); break;
	case 50:ara(); break;
	case 51:liste(); break;
	case 52:guncelle(); break;
	case 53:sil_f(); break;
	case 54:sil_m(); break;
	case 55: {dosya_yaz(); printf("\nIyi gunler\n"); system("pause"); exit(-1); }
	}
}
void dosya_oku(void) {
	FILE* fp;

	int D_uz, i;
	fp = fopen(dosya_ismi, "r");
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
void ekle(void) {
	int deger;
	printf("Eklenecek deger : ");
	scanf("%d", &deger);
	if (adet + 1 > N) {
		printf("Dizi Dolu !");
		_getch();
	}
	else {
		D[adet] = deger;
		adet++;
		printf("Yeni deger dizi eklendi !\n");
		_getch();
	}
}
void liste(void) {
	int i;
	for (i = 0; i < N; i++) {
		if (D[i] != 0) {
			fprintf(stdout, "[%3d.] %d\n", i, D[i]);
		}
	}
	_getch();
}
void ara() {
	int i, ara_deger;
	bool durum = false;
	printf("Aranacak deger :");
	scanf("%d", &ara_deger);
	for (i = 0; i < N; i++) {
		if (D[i] != 0 && ara_deger == D[i]) {
			durum = true;
			break;
		}
	}
	if (durum)fprintf(stdout, "Buldum :[%3d.]  %d\n", i, D[i]);
	else printf("Bulamadim.\n");
	_getch();
}
void guncelle(void) {
	int i, gun_deger, deger;
	bool durum = false;
	printf("Guncellenecek deger : ");
	scanf("%d", &gun_deger);
	for (i = 0; i < N; i++) {
		if (D[i] != 0 && gun_deger == D[i]) {
			durum = true;
			break;
		}
	}
	if (durum) {
		fprintf(stdout, "Buldum : [%3d.] %d\n", i, D[i]);
		printf("Yeni deger : ");
		scanf("%d", &deger);
		D[i] = deger;
		printf("Guncellendi.\n");
	}
	else {
		printf("Bulamadim.\n");
	}
	_getch();
}
void sil_f(void) {
	int i, j, sil_deger;
	bool durum = false;
	printf("Silinecek  deger : ");
	scanf("%d", &sil_deger);
	for (i = 0; i < adet; i++) {
		if (sil_deger == D[i]) {
			durum = true;
			break;
		}
	}
	if (durum) {
		fprintf(stdout, "Buldum : [%3d.] %d\n", i, D[i]);
		for (j = i; j < adet; j++) {
			D[j] = D[j + 1];
		}
		printf("Deger silindi.\n");
		D[adet] = 0;
		adet--;
	}
	else {
		printf("Bulamadim.\n");
	}
	_getch();
}
void sil_m(void) {
	int i, j, sil_deger;
	bool durum = false;
	printf("Silinecek  deger : ");
	scanf("%d", &sil_deger);
	for (i = 0; i < N; i++) {
		if (D[i] != 0 && sil_deger == D[i]) {
			durum = true;
			break;
		}
	}
	if (durum) {
		fprintf(stdout, "Buldum : [%3d.] %d\n", i, D[i]);
		D[i] = 0;
		adet--;
		printf("Deger silindi.\n");
	}
	else {
		printf("Bulamadim.\n");
	}
	_getch();
}
void dosya_yaz(void) {
	FILE* fp;

	int D_uz, i;
	fp = fopen(dosya_ismi, "w");
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