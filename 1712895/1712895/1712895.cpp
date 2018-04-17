#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<wchar.h>
struct sinhvien
{
	wchar_t MSSV[10];
	wchar_t hoten[30];
	wchar_t gmail[30];
	wchar_t khoa[30];
	int nam;
	wchar_t ngaysinh[10];
	wchar_t hinh[50];
	wchar_t amnhac[100];
	wchar_t amthuc[100];
	wchar_t mota[1000];
};
typedef struct sinhvien SV;

void docfilesv(FILE* f, SV a[], int &n)
{
	n = 0;
	while (!feof(f)) {
		fwscanf(f, L"%[^,],%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^,],%[^,],%[^\n]\n", &a[n].MSSV, &a[n].hoten, &a[n].khoa,&a[n].gmail, &a[n].nam, &a[n].ngaysinh, &a[n].hinh, &a[n].mota, &a[n].amnhac,&a[n].amthuc);
		n++;
	}

}
int vitrichuoi(wchar_t* cha, wchar_t* con)
{
	wchar_t* chuoicon;
	if (chuoicon = wcsstr(cha, con))
	{
		return (chuoicon - cha);
	}
	else
	{
		return 0;
	}
}
void chenchuoivaovitri(wchar_t *s, wchar_t*a, int vt)
{
	wchar_t c[100];
	wcscpy(c, s + vt);
	wcscpy(s + vt, a);
	wcscat(s, c);
}
void xoa(wchar_t *cha,int vt,int n)
{
	wcscpy(cha + vt, cha + vt + n);
}
void mohtml(int &i,SV a[])
{
	
	FILE*html = _wfopen(L"../../html.txt",  L"r,ccs=UTF-16LE");
	
	fseek(html, 3, SEEK_SET);
		wchar_t vd[50] = L"";
		wchar_t tenfile[50];
		wcscpy(vd, L"../../Website/");
		wcscpy(tenfile, a[i].MSSV);
		wcscat(tenfile, L".html");
		wcscat(vd, tenfile);
		FILE*out = _wfopen(vd, L"w,ccs=UTF-16LE");
		wchar_t dong[255];
		int vt;
		wchar_t temp[100];
		while (!feof(html))
		{
			fgetws(dong, 255, html);
			
			if (vitrichuoi(dong, L"HCMUS-"))
			{
				wcscpy(temp, a[i].hoten);
				chenchuoivaovitri(dong, temp, vitrichuoi(dong, L"HCMUS-") + wcslen(L"HCMUS-"));
			}
			if (vitrichuoi(dong, L"(1)"))
			{
				
				wcscpy(temp, a[i].hoten);
				chenchuoivaovitri(dong, temp, vitrichuoi(dong, L"(1)") + wcslen(L"(1)"));
				xoa(dong, vitrichuoi(dong, L"(1)"),3);

			}
			if (vitrichuoi(dong, L"(2)"))
			{

				wcscpy(temp, a[i].khoa);
				chenchuoivaovitri(dong, temp, vitrichuoi(dong, L"(2)") + wcslen(L"(2)"));
				xoa(dong, vitrichuoi(dong, L"(2)"),3);

			}
			if (vitrichuoi(dong, L"(3)"))
			{

				wcscpy(temp, a[i].gmail);
				chenchuoivaovitri(dong, temp, vitrichuoi(dong, L"(3)") + wcslen(L"(3)"));
				xoa(dong, vitrichuoi(dong, L"(3)"), 3);

			}
			if (vitrichuoi(dong, L"(9)"))
			{

				wcscpy(temp, a[i].gmail);
				chenchuoivaovitri(dong, temp, vitrichuoi(dong, L"(9)") + wcslen(L"(9)"));
				xoa(dong, vitrichuoi(dong, L"(9)"), 3);

			}
			if (vitrichuoi(dong, L"(4)"))
			{

				wcscpy(temp, a[i].hinh);
				chenchuoivaovitri(dong, temp, vitrichuoi(dong, L"(4)") + wcslen(L"(4)"));
				xoa(dong, vitrichuoi(dong, L"(4)"),3);

			}
			if (vitrichuoi(dong, L"(5)"))
			{

				wcscpy(temp, a[i].hoten);
				chenchuoivaovitri(dong, temp, vitrichuoi(dong, L"(5)") + wcslen(L"(5)"));
				xoa(dong, vitrichuoi(dong, L"(5)"),3);

			}
			if (vitrichuoi(dong, L"(6)"))
			{

				wcscpy(temp, a[i].MSSV);
				chenchuoivaovitri(dong, temp, vitrichuoi(dong, L"(6)") + wcslen(L"(6)"));
				xoa(dong, vitrichuoi(dong, L"(6)"),3);

			}
			if (vitrichuoi(dong, L"(6)"))
			{

				wcscpy(temp, a[i].MSSV);
				chenchuoivaovitri(dong, temp, vitrichuoi(dong, L"(6)") + wcslen(L"(6)"));
				xoa(dong, vitrichuoi(dong, L"(6)"),3);

			}
			if (vitrichuoi(dong, L"(7)"))
			{

				wcscpy(temp, a[i].khoa);
				chenchuoivaovitri(dong, temp, vitrichuoi(dong, L"(7)") + wcslen(L"(7)"));
				xoa(dong, vitrichuoi(dong, L"(7)"),3);

			}
			if (vitrichuoi(dong, L"(8)"))
			{

				wcscpy(temp, a[i].ngaysinh);
				chenchuoivaovitri(dong, temp, vitrichuoi(dong, L"(8)") + wcslen(L"(8)"));
				xoa(dong, vitrichuoi(dong, L"(8)"),3);

			}
			if (vitrichuoi(dong, L"(10)"))
			{

				wcscpy(temp, a[i].amnhac);
				chenchuoivaovitri(dong, temp, vitrichuoi(dong, L"(10)") + wcslen(L"(10)"));
				xoa(dong, vitrichuoi(dong, L"(10)"),4);

			}
			if (vitrichuoi(dong, L"(11)"))
			{

				wcscpy(temp, a[i].amthuc);
				chenchuoivaovitri(dong, temp, vitrichuoi(dong, L"(11)") + wcslen(L"(11)"));
				xoa(dong, vitrichuoi(dong, L"(11)"), 4);

			}
			if (vitrichuoi(dong, L"Tôi là một người "))
			{
				wcscpy(temp, a[i].mota);
				chenchuoivaovitri(dong, temp, vitrichuoi(dong, L"Tôi là một người ") + wcslen(L"Tôi là một người "));
					}
			fwprintf(out,L"%s", dong);
		}
		fclose(html);
		fclose(out);
}


void main()
{
	
	
	FILE*f;
	f = _wfopen(L"../../thongtinsv.csv", L"r,ccs=UTF-16LE");
	
	if(!f)
	{
		wprintf(L"khong tim thay file ");
	}
	SV sv[100];
	int n;
	docfilesv(f, sv,n);
	for (int i = 0; i < n; i++)
	{
		mohtml(i, sv);
	}

	fclose(f);
}