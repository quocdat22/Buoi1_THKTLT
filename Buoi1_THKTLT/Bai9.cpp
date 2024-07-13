#include "BaiTap.h"
#include<stdio.h>


void tinhTong2So(float* a, float* b, float* &tong) {
	tong = a;
	*tong = *a + *b;
	printf("\nTong cua 2 so la: \t %.2f \t co dia chi la %x", *tong, &tong);
}

void tinhHieu2So(float* a, float* b, float* &hieu) {
	hieu = a;
	*hieu = *a - *b;
	printf("\nHieu cua 2 so la: \t %.2f \t co dia chi la %x", *hieu, &hieu);
}

void tinhTich2So(float* a, float* b, float* &tich) {
	tich = a;
	*tich = *a * *b;
	printf("\nTich cua 2 so la: \t %.2f \t co dia chi la %x", *tich, &tich);
}

void tinhThuong2So(float* a, float* b, float* &thuong) {
	thuong = a;
	*thuong = *a / *b;
	printf("\nThuong cua 2 so la: \t %.2f \t co dia chi la %x", *thuong, &thuong);
}



void bai9() {
	float a = 5.7, b = 4.8;
	float* pa = &a;
	float* pb = &b;
	float* tong;
	float* hieu;
	float* tich;
	float* thuong;
	printf("So a: %.2f va So b : %.2f\n", a, b);
	tinhTong2So(pa, pb, tong);
	tinhHieu2So(pa, pb, hieu);
	tinhTich2So(pa, pb, tich);
	tinhThuong2So(pa, pb, thuong);
	printf("\n");
	return;
}