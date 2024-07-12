#include "BaiTap.h"
#include <stdlib.h>
#include <stdio.h>

struct PhanSo
{
	int tu;
	int mau;
};

void khoiTaoMangPhanSo(PhanSo *&arr, int n) {
	arr = (PhanSo*)malloc(n * sizeof(PhanSo));
	for (int i = 0; i < n; i++) {
		arr[i].tu = rand() % 10;
		arr[i].mau = rand() % 10 + 1;

		/*printf("Nhap tu so cua phan so thu %d: ", i + 1);
		scanf_s("%d", &arr[i].tu);
		printf("Nhap mau so cua phan so thu %d: ", i + 1);
		scanf_s("%d", &arr[i].mau);*/
	}
}

void xuatMangPhanSo(PhanSo *arr, int n) {
	//printf("Danh sach mang dong khoi tao ngau nhien \n");
	for (int i = 0; i < n; i++) {
		printf("Phan so thu %d: %d/%d\n", i + 1, arr[i].tu, arr[i].mau);
	}
}

void xuatPhanSoCoMauLonHonTu(PhanSo* arr, int n) {
	printf("b.Cac phan so co mau lon hon tu so: \n");
	for (int i = 0; i < n; i++) {
		if (arr[i].mau > arr[i].tu) {
			printf("Phan so thu %d: %d/%d\n", i + 1, arr[i].tu, arr[i].mau);
		}
	}
}
void demSoPhanTuMauTuChan(PhanSo* arr, int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i].mau % 2 == 0 && arr[i].tu % 2 == 0) {
			count++;
		}
	}
	printf("c.So phan so co tu va mau so deu chan: %d\n", count);
}

int timUocChungLonNhat(int mau, int tu) { 
	if (tu == 0) {
		return mau;
	}
	else {
		return timUocChungLonNhat(tu, mau % tu);
	}
}


void rutGonPhanSoToanMang(PhanSo* arr, int n) {
	for(int i = 0; i < n; i++) {
		int ucln = timUocChungLonNhat(arr[i].mau, arr[i].tu);
		arr[i].tu = arr[i].tu / ucln;
		arr[i].mau = arr[i].mau / ucln;
	}
	printf("Danh sach mang sau khi rut gon: \n");
	xuatMangPhanSo(arr, n);
}

void rutGonPhanSoToanMangKhongIn(PhanSo* arr, int n) {
	for (int i = 0; i < n; i++) {
		int ucln = timUocChungLonNhat(arr[i].mau, arr[i].tu);
		arr[i].tu = arr[i].tu / ucln;
		arr[i].mau = arr[i].mau / ucln;
	}
	
}

void rutGonPhanSo(PhanSo &ps) {
	PhanSo result;
	int ucln = timUocChungLonNhat(ps.mau, ps.tu);
	ps.mau /= ucln;
	ps.tu /= ucln;
}

void tinhTichCuaPhanTuMang(PhanSo* arr, int n) {
	PhanSo result;
	result.mau = arr[0].mau;
	result.tu = arr[0].tu;

	for (int i = 1; i < n; i++) {
		result.mau *= arr[i].mau;
		result.tu *= arr[i].tu;
	}

	rutGonPhanSo(result);
	
	printf("e. Tich cua cac phan tu trong mang la: %d/%d\n", result.mau, result.tu);
}


int soSanhPhanSo(PhanSo ps1, PhanSo ps2) {
	int tu1 = ps1.tu * ps2.mau;
	int tu2 = ps2.tu * ps1.mau;

	if (tu1 > tu2) {
		return 1;
	}
	else if (tu1 < tu2) {
		return -1;
	}
	else {
		return 0;
	}
}

void timPhanSoLonNhat(PhanSo* arr, int n) {
	rutGonPhanSoToanMangKhongIn(arr, n);
	PhanSo max = arr[0];
	for (int i = 1; i < n; i++) {
		if (soSanhPhanSo(max, arr[i]) == -1) {
			max = arr[i];
		}
	}
	printf("f. Phan so lon nhat la: %d/%d\n", max.tu, max.mau);
}





void bai8() {
	int n;
	printf("Nhap so luong phan so: ");
	scanf_s("%d", &n);

	PhanSo *arr;
	//a
	khoiTaoMangPhanSo(arr, n);
	xuatMangPhanSo(arr, n);

	//b
	xuatPhanSoCoMauLonHonTu(arr, n);

	//c
	demSoPhanTuMauTuChan(arr, n);

	//d
	rutGonPhanSoToanMang(arr, n);

	//e
	tinhTichCuaPhanTuMang(arr, n);

	//f
	timPhanSoLonNhat(arr, n);

	free(arr);


}