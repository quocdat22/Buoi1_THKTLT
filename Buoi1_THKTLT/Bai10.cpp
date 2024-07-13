#include "BaiTap.h"
#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <string.h>


#pragma warning(disable:4996)

void nhapChuoi(char* &st) {
	// Nhập chuỗi từ bàn phím
	printf("Nhap chuoi: ");
	fgets(st, 100, stdin);
    //scanf_s("%99s", st, 100);
}

void kiemTraBoNho(char* st) {
    if (st == NULL) {
        printf("Cap phat bo nho that bai\n");
        return;
    }
}

void xuatChuoiConTro(char* st) {
    char* ptr = st;
    while (*ptr != '\0') {
        printf("%c", *ptr);
        ptr++;
    }
    printf("\n");
}

void xuatChuoi(char st) {
    
    while (st != '\0') {
        printf("%c", st);
        st++;
    }
    printf("\n");
}

void giaiPhongBoNho(char* st) {
	free(st);
	st = NULL;
}

void chuyenChuoiInHoa(char* st) {
    char* ptr = st;
    int i = 0;
    while (ptr[i] != '\0') {
		if (ptr[i] >= 'a' && ptr[i] <= 'z') {
			ptr[i] = ptr[i] - 32;
		}
		i++;
	}
 
    
    printf("\nb. Chuoi sau khi chuyen thanh chu hoa: ");
    xuatChuoiConTro(ptr);

    /*while (*ptr != '\0') {
        printf("%c", *ptr);
        ptr++;
    }
    printf("\n");*/
}

void chuyenKyTuInHoaSauKhoangTrang(char* st) {
	char* ptr = st;
    int i = 0;
    // Kiểm tra và chuyển đổi ký tự đầu tiên của chuỗi nếu là chữ cái thường
    if (ptr[0] >= 97 && ptr[0] <= 122) {
        ptr[0] -= 32;
    }
    while (ptr[i] != '\0') {
        if (ptr[i] == ' ' && ptr[i + 1] >= 97 && ptr[i + 1] <= 122) {
            ptr[i + 1] -= 32;
        }
        i++;
    }
    printf("\nc. Chuoi sau khi chuyen ky tu dau tien cua moi tu thanh chu hoa: ");
    xuatChuoiConTro(ptr);
    
}


void bai10() {
    
    char* st = (char*)malloc(100 * sizeof(char)); // Cấp phát 100 bytes
    //char st[100];
    kiemTraBoNho(st);
    
    nhapChuoi(st);
    
    //xuatChuoiConTro(st);

    // Sao lưu chuỗi ban đầu
    char* originalSt = (char*)malloc(100 * sizeof(char));
    kiemTraBoNho(originalSt);
    strcpy(originalSt, st);

    chuyenChuoiInHoa(st);

    // Khôi phục chuỗi gốc từ bản sao lưu
    strcpy(st, originalSt);

    chuyenKyTuInHoaSauKhoangTrang(st);

    giaiPhongBoNho(originalSt);
    giaiPhongBoNho(st);

    return;
}