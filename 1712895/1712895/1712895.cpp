#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>

struct sinhvien
{
	char MSSV[10];
	char hoten[30];
	char khoa[30];
	int nam;
	char ngaysinh[10];
	char hinh[50];
	char mota[1000];
	char sothich[1000];
};
typedef struct sinhvien SV;

void docfile(FILE* f,SV &a,FILE*out)
{
	
	{
		fscanf(f,"%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^,],%[^'\n']", &a.MSSV, &a.hoten,&a.khoa,&a.nam,&a.ngaysinh,&a.hinh,&a.mota,&a.sothich);
		fprintf(out, "%s,%s,%s,%d,%s,%s,%s,%s", &a.MSSV, &a.hoten, &a.khoa, &a.nam, &a.ngaysinh, &a.hinh, &a.mota, &a.sothich);

	}
	
	
}


void main()
{
	int *n=NULL;
	SV b;
	FILE*f;
	f = fopen("C:\\Users\\Administrator\\Desktop\\doan_01\\thongtinsv.csv", "rt");
	FILE*out;
	out = fopen("C:\\Users\\Administrator\\Desktop\\doan_01\\thu.csv", "wt");
	if (f == NULL)
	{
		printf("khong tim thay file ");
	}

	docfile(f,b,out);
	
	fclose(out);
	fclose(f);
}