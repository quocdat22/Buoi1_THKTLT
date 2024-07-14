#include "BaiTap.h"
#include <stdlib.h>
#include <stdio.h>


struct PhanSo
{
	int tu;
	int mau;
};

void khoiTaoMangPhanSoB12(PhanSo*& arr, int n) {
	arr = (PhanSo*)malloc(n * sizeof(PhanSo));
	for (int i = 0; i < n; i++) {
		arr[i].tu = rand() % 10;
		arr[i].mau = rand() % 10 + 1;

		
	}
}

void xuatMangPhanSoB12(PhanSo* arr, int n) {
	
	//printf("Danh sach mang dong khoi tao ngau nhien \n");
	printf("STT \t Gia tri\n");
	for (int i = 0; i < n; i++) {
		printf("%d \t %d/%d\n", i , arr[i].tu, arr[i].mau);
	}
}

int soSanhHaiPhanSoBai12(PhanSo a, PhanSo b) {
	int tu1 = a.tu * b.mau;
	int tu2 = b.tu * a.mau;

	if (tu1 > tu2) { //a>b
		return 1;
	}
	else if (tu1 < tu2) { //a<b
		return -1;
	}
	else { //a=b
		return 0;
	}
}

void timPhanSoLonNhatBai12(PhanSo* arr, int n) {
	PhanSo max = arr[0];
	for (int i = 1; i < n; i++) {
		if (soSanhHaiPhanSoBai12(arr[i], max) == 1) {
			max = arr[i];
		}
	}
	printf("Phan so lon nhat la: %d/%d\n", max.tu, max.mau);
}

void timPhanSoNhoNhatBai12(PhanSo* arr, int n) {
	PhanSo min = arr[0];
	for (int i = 1; i < n; i++) {
		if (soSanhHaiPhanSoBai12(arr[i], min) == -1) {
			min = arr[i];
		}
	}
	printf("Phan so nho nhat la: %d/%d\n", min.tu, min.mau);
}

void xoaPhanTuTaiViTriK(PhanSo* arr, int &n, int k) {
	
	for(int i = k ; i < n; i++) {
		arr[i] = arr[i + 1];
	}
	n--;
}

void themPhanTuXTaiViTriK(PhanSo* arr, int& n, int k, PhanSo x) {
	arr = (PhanSo*)realloc(arr, (n + 1) * sizeof(PhanSo));
	for (int i = n; i > k; i--) {
		arr[i] = arr[i - 1];
	}
	arr[k] = x;
	n++;
}

void bai12() {
	PhanSo* arr;
	int n;
	printf("Nhap so luong phan so: ");
	scanf_s("%d", &n);

	khoiTaoMangPhanSoB12(arr, n);
	xuatMangPhanSoB12(arr, n);


	printf("\nCau a:\n");
	timPhanSoLonNhatBai12(arr, n);
	timPhanSoNhoNhatBai12(arr, n);

	printf("\nCau b:\n");
	xoaPhanTuTaiViTriK(arr, n, 3);
	printf("Danh sach mang sau khi xoa phan tu tai vi tri k = 3\n");
	xuatMangPhanSoB12(arr, n);

	printf("\nCau c:\n");
	PhanSo x;
	x.tu = 4;
	x.mau = 5;
	themPhanTuXTaiViTriK(arr, n, 3, x);
	printf("Danh sach mang sau khi them phan tu x(4/5) tai vi tri k = 3\n");
	xuatMangPhanSoB12(arr, n);

	free(arr);

	return;
}