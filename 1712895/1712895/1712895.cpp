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

void docfile(FILE* f,SV &a,FILE*out)
{
	
	{

		fwscanf(f,L"%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^,],%[^\n]\n", &a.MSSV, &a.hoten,&a.khoa,&a.nam,&a.ngaysinh,&a.hinh,&a.mota,&a.sothich);
		fwprintf(out, L"%s,%s", a.MSSV,a.hoten);

	}
	
	
}
int sodong(FILE*f)
{
	int b = 1;
	wchar_t line[255];
	while (fgetws(line, 255, f))
	{
		b++;
	}
	return b;
}

void main()
{
	int *n=NULL;
	SV b;
	FILE*f=NULL;
	f = _wfopen(L"C:\\Users\\Administrator\\Desktop\\doan_01\\thongtinsv.csv", L"r,ccs=UTF-16LE");
	FILE*out;
	out = _wfopen(L"C:\\Users\\Administrator\\Desktop\\doan_01\\thu.csv", L"w,ccs=UTF-16LE");
	if (f == NULL)
	{
		wprintf(L"không tìm thấy file ");
	}

	docfile(f,b,out);
	
	
	for (int i = 0; i < sodong(f); i++)
	{
		docfile(f, b, out);
	}
	fclose(out);
	fclose(f);
}