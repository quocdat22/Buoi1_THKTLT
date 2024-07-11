#include "BaiTap.h"
#include<stdio.h>
#include <string>
#include <dos.h>

static int currentYear = 2024;

struct Date {
	int day = 0;
	int month = 0;
	int year = 0;
};

struct NguoiLaoDong {
	char hoTen[50];
	Date ngaySinh;
	char gioiTinh[10];
};

bool kiemTraNgaySinh(Date ngaySinh) {
	if(ngaySinh.day < 1 || ngaySinh.day > 30 || ngaySinh.day == 0) {
		return false;
	}
	if(ngaySinh.month < 1 || ngaySinh.month > 12 || ngaySinh.month == 0) {
		return false;
	}
	if(ngaySinh.year < 1900 || ngaySinh.year > currentYear || ngaySinh.year == 0) {
		return false;
	}
	return true;

}

bool kiemTraGioiTinh(char* gioiTinh) {
	if(strcmp(gioiTinh, "nam") != 0 && strcmp(gioiTinh, "nu") != 0) {
		return false;
	}
	return true;
}

void nhapThongTin(char* hoTen, Date& ngaySinh, char* gioiTinh) {
	 
	printf("Nhap ho ten: ");
	scanf_s("%s", hoTen, 50);

	
	do {
		printf("Nhap ngay sinh (dd/mm/yyyy): ");
		scanf_s("%d/%d/%d", &ngaySinh.day, &ngaySinh.month, &ngaySinh.year);
		if (!kiemTraNgaySinh(ngaySinh)) {
			printf("Ngay sinh khong hop le! Vui long nhap lai.\n");
		}
	} while (!kiemTraNgaySinh(ngaySinh));

	do {
		printf("Nhap gioi tinh (nam/nu): ");
		scanf_s("%s", gioiTinh, 10);
		if (!kiemTraGioiTinh(gioiTinh)) {
			printf("Gioi tinh khong hop le! Vui long nhap lai.\n");
		}
	} while (!kiemTraGioiTinh(gioiTinh));
}

void kiemTraTuoiLongDong(char* gioiTinh,Date ngaySinh) {
	if (strcmp(gioiTinh,"nam")) {
		int tuoi = currentYear - ngaySinh.year;
		if (tuoi < 18 || tuoi > 62) {
			printf("Khong nam trong do tuoi long dong");
		}
		
	}
	if (strcmp(gioiTinh, "nu")) {
		int tuoi = currentYear - ngaySinh.year;
		if (tuoi < 18 || tuoi > 60) {
			printf("Khong nam trong do tuoi long dong");
		}

	}
}
int tinhTuoi(int namSinh) {

	return currentYear - namSinh;
}

int tinhThoiGianNghiHuu(Date ngaySinh, char* gioiTinh) {
	int thoiGianNghiHuu = 0, namNghiHuu = 0;
	int tuoi = tinhTuoi(ngaySinh.year);
	if (strcmp(gioiTinh, "nam") == 0) {
		thoiGianNghiHuu = 62 - tuoi;
		namNghiHuu = currentYear + thoiGianNghiHuu;
		return namNghiHuu;
	}
	else {
		int thoiGianNghiHuu = 60 - tuoi;
		int namNghiHuu = currentYear + thoiGianNghiHuu;
		return namNghiHuu;
	}
	
}


void xuatThongTin(char* hoTen, Date ngaySinh, char* gioiTinh) {
	printf("Ho ten: %s\n", hoTen);
	printf("Ngay sinh: %02d/%02d/%04d\n", ngaySinh.day, ngaySinh.month, ngaySinh.year);
	printf("Gioi tinh: %s\n", gioiTinh);
	kiemTraTuoiLongDong(gioiTinh, ngaySinh);
	//Nguyễn Văn An, giới tính nam, sinh ngày 20/03/1990. Hiện tại (năm 2021) An đã 31 tuổi.Thời gian An được nghỉ hưu là tháng 03 / 2052.
	int namNghiHuu = tinhThoiGianNghiHuu(ngaySinh, gioiTinh);
	/*printf("%s, gioi tinh %s, sinh ngay %02d/%02d/%04d. Hien tai (nam %d) %s da %d tuoi. Thoi gian %s duoc nghi huu la thang %d.\n",
		hoTen,gioiTinh,ngaySinh.day,ngaySinh.month,ngaySinh.year,currentYear,tinhTuoi(ngaySinh.year),hoTen, namNghiHuu);*/
	printf("Thoi gian %s duoc nghi huu la thang %d.\n", hoTen, namNghiHuu);
}





void bai6() {
	/*char hoTen[50], gioiTinh[10];
	struct Date ngaySinh;*/

	NguoiLaoDong nguoiLaoDong;

	
	//nhapThongTin(hoTen, ngaySinh, gioiTinh);
	nhapThongTin(nguoiLaoDong.hoTen, nguoiLaoDong.ngaySinh, nguoiLaoDong.gioiTinh);
	xuatThongTin(nguoiLaoDong.hoTen, nguoiLaoDong.ngaySinh, nguoiLaoDong.gioiTinh);
	//xuatThongTin(hoTen, ngaySinh, gioiTinh);
	
	return;
}