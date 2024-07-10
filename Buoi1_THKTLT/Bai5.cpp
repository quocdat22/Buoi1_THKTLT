#include<stdio.h>
#include "BaiTap.h"

void bai5() {
	int a, b, c;
	printf("Nhap a: ");
	scanf_s("%d", &a);
	printf("Nhap b: ");
	scanf_s("%d", &b);
	printf("Nhap c: ");
	scanf_s("%d", &c);

	if (a == b) {
		printf("Mau so phai khac 0 \n");
	}
	else
	{
		printf("c / (a - b) = %d", c / (a - b));
	}

	
}