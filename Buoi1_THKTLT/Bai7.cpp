#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include "BaiTap.h"
#include <math.h>


void nhapM1C_SoNguyen(int*& a, int& n)
{ //a và n là tham chiếu vì sau khi nhập giá trị, a và n cần giữ các giá trị mới nhận trong hàm
	n = 10;
	a = (int*)malloc(n * sizeof(int)); // cấp phát a co 10 phần tử
	for (int i = 0; i < n; i++)
		//*(a + i) = rand() % 100;
		a[i] = rand() % 100;
}
void xuatM1C_SoNguyen(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		//printf("\nPhan tu thu %d co gia tri %d va dia chi o nho la %x", i, *(a + i), a + i);
		printf("\nPhan tu thu %d co gia tri %d va dia chi o nho la %x", i, a[i], &a[i]);
	}
}

void searchMax(int* a, int n) {
	int max = a[0];
	int* addMax = &max;
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
			addMax = &a[i];
		}
	}
	printf("\na.Phan tu lon nhat la %d tai dia chi %x", max, addMax);
}



void maxChanMinLe(int* a, int n)
{
	int max = a[0];
	int min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] % 2 == 0 && a[i] > max)
			max = a[i];
		if (a[i] % 2 != 0 && a[i] < min)
			min = a[i];
	}
	printf("\nb.Phan tu chan lon nhat la %d", max);
	printf("\nb.Phan tu le nho nhat la %d", min);
}

void xoaPhanTuCoGiaTri0(int*& a, int& n)
{
	int i = 0;
	while (i < n)
	{
		if (a[i] == 0)
		{
			for (int j = i; j < n - 1; j++)
				a[j] = a[j + 1];
			n--;
		}
		else
			i++;
	}
	a = (int*)realloc(a, n * sizeof(int));
	printf("\nc.Mang sau khi xoa phan tu co gia tri 0 la: ");
	xuatM1C_SoNguyen(a, n);
}
//Thêm phần tử x vào sao phần tử đầu tiên.
void themPhanTuVaoSauPhanTuDauTien(int*& a, int& n, int x)
{
	n++;
	a = (int*)realloc(a, n * sizeof(int));
	for (int i = n - 1; i > 0; i--)
		a[i] = a[i - 1];
	a[0] = x;
	printf("\nd.Mang sau khi them phan tu %d vao sau phan tu dau tien la: ", x);
	xuatM1C_SoNguyen(a, n);
}

void tinhTongCacSoChinhPhuong(int* a, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == (int)sqrt(a[i]) * (int)sqrt(a[i]))
			sum += a[i];
	}
	printf("\ne.Tong cac so chinh phuong trong mang la %d", sum);
}

//Xuất các số cực đại trong a. Biết rằng số cực đại là số lớn hơn các số quanh nó
void xuatSoCucDai(int* a, int n)
{
	printf("\nf.Cac so cuc dai trong mang la: ");
	for (int i = 1; i < n - 1; i++)
	{
		if (a[i] > a[i - 1] && a[i] > a[i + 1])
			printf("%d ", a[i]);
	}
}

void bai7()
{
	int* a;
	int n = 0;
	nhapM1C_SoNguyen(a, n);
	xuatM1C_SoNguyen(a, n);

	searchMax(a, n);
	
	maxChanMinLe(a, n);
	xoaPhanTuCoGiaTri0(a, n);
	themPhanTuVaoSauPhanTuDauTien(a, n, 100);
	tinhTongCacSoChinhPhuong(a, n);
	xuatSoCucDai(a, n);
	free(a);


	return;
}
