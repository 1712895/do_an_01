#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<wchar.h>
struct sinhvien
{
	wchar_t MSSV[10];
	wchar_t hoten[30];
	wchar_t khoa[30];
	int nam;
	wchar_t ngaysinh[10];
	wchar_t hinh[50];
	wchar_t mota[1000];
	wchar_t sothich[1000];
};
typedef struct sinhvien SV;

void docfilesv(FILE* f, SV a[],int &i)
{
	 i = 0;
	while (!feof(f)) {
	fwscanf(f, L"%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^,],%[^\n]\n", &a[i].MSSV, &a[i].hoten, &a[i].khoa, &a[i].nam, &a[i].ngaysinh, &a[i].hinh, &a[i].mota, &a[i].sothich);
	i++;
	}

}




void main()
{
	
	
	FILE*f;
	f = _wfopen(L"C:\\Users\\Administrator\\Desktop\\doan_01\\thongtin.csv", L"r,ccs=UTF-16LE");
	FILE*out;
	out = _wfopen(L"C:\\Users\\Administrator\\Desktop\\doan_01\\thu.csv", L"w,ccs=UTF-16LE");
	if (f == NULL)
	{
		wprintf(L"khong tim thay file ");
	}
	SV sv[100];
	int i;
	docfilesv(f, sv,i);
	
	
	fclose(out);
	fclose(f);
}