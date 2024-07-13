#include "BaiTap.h"
#include<stdlib.h>
#include<stdio.h>

void nhapM1C_SoNguyen(int*& a, int n)
{ 
	a = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		//*(a + i) = rand() % 100;
		a[i] = rand() % 100;
}
void xuatM1C_SoNguyen_b11(int* a, int n)
{
	printf("Phan tu so\t|\tGia tri\t|\t Dia chi");
	for (int i = 0; i < n; i++)
	{
		//printf("\nPhan tu thu %d co gia tri %d va dia chi o nho la %x", i, *(a + i), a + i);
		printf("\n%d \t\t\t %d \t\t %x", i, a[i], &a[i]);
	}
	printf("\n");
}

//Xuất các số cực tiểu trong a. Biết rằng số cực tiểu là số nhỏ hơn các số quanh nó.
void xuatSoCucTieu(int* a, int n)
{
	int count = 0;
	printf("\na.Cac so cuc tieu trong mang la: ");

	if (n < 3) {
		printf("Khong co so cuc tieu trong mang");
		return;
	}

	for (int i = 1; i < n - 1; i++)
	{
		if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
			printf("%d ", a[i]);
			count++;
		}
			
	}
	if (count == 0) {
		printf("Khong co so cuc tieu trong mang");
	}
}

//Xóa phần tử tại vị trí k
void xoaPhanTuTaiViTriK(int*& a, int &n, int k)
{
	for (int i = k; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
	a = (int*)realloc(a, n * sizeof(int));
}

void thucThiXoaPhanTuTaiViTriK(int*& a, int& n, int k)
{
	xoaPhanTuTaiViTriK(a, n, k);
	printf("\nb. Mang sau khi xoa phan tu tai vi tri %d la: \n", k);
	xuatM1C_SoNguyen_b11(a, n);
}

void themPhanTuTaiViTriK(int*& a, int& n, int k, int x) {
	if (k < 0 || k > n) {
		printf("Vi tri k khong hop le.\n");
		return;
	}
	n++;
	//a = (int*)realloc(a, n * sizeof(int));
	
	for (int i = n-1; i > k; i--) {
		a[i] = a[i - 1];
	}
	a[k] = x;

	printf("\nb. Mang sau khi them phan tu %d tai vi tri %d la: \n", x, k);
	xuatM1C_SoNguyen_b11(a, n);
}

//Chuyển số chẵn lên đầu mảng, số lẻ xuống cuối mảng.
void chuyenSoChanLenDauSoLeXuongCuoi(int*& a, int n)
{
	int i = 0, j = n - 1;
	while (i < j)
	{
		while (a[i] % 2 == 0 && i < j)
			i++;
		while (a[j] % 2 != 0 && i < j)
			j--;
		if (i < j)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	printf("\nc. Mang sau khi chuyen so chan len dau, so le xuong cuoi la: \n");
	xuatM1C_SoNguyen_b11(a, n);
}


//Kiểm tra mảng có chứa chẵn lẻ xen kẻ không?
void kiemTraMangCoChuaChanLeXenKe(int* a, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0 && a[i] % 2 != 0)
		{
			count++;
		}
		if (i % 2 != 0 && a[i] % 2 == 0)
		{
			count++;
		}
	}
	if (count == 0)
	{
		printf("\nd. Mang khong chua chan le xen ke");
	}
	else
	{
		printf("\nd. Mang chua chan le xen ke");
	}
}

void bai11() {

	int* a;
	int n = 10;
	nhapM1C_SoNguyen(a, n);
	xuatM1C_SoNguyen_b11(a, n);

	xuatSoCucTieu(a, n);

	thucThiXoaPhanTuTaiViTriK(a, n, 3);

	themPhanTuTaiViTriK(a, n, 3, 100);

	chuyenSoChanLenDauSoLeXuongCuoi(a, n);

	kiemTraMangCoChuaChanLeXenKe(a, n);

	printf("\n");

	return;
}