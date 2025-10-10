#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
//Khai bao 1 sinh vien

struct SinhVien {
	int mssv;
	char hoTen[50];
	double diemTB;
};
int main(){
	/*SinhVien sv1 = {1234, "Nguyen Van A", 8.0 };
	printf("mssv la:%d\n", sv1.mssv);
	printf("ho ten sv la: %s\n", sv1.hoTen);
	printf("diem tb: %f\n", sv1.diemTB);
	//printf("%d\n", sizeof(sv1));

    SinhVien sv2;
    printf("hay nhap ho so sinh vien 2:\n");
    printf("nhap mssv:\n");
    scanf("%d", &sv2.mssv);
    printf("nhap ho ten:");
    scanf("%s", sv2.hoTen);
    printf("\nNhap diem TB:");
    scanf("%lf", &sv2.diemTB);
    printf("\nho ten la: %s", sv2.hoTen);
    printf("\nmssv: %d", sv2.mssv);
    printf("\ndiem tb la: %lf", sv2.diemTB);*/



SinhVien arr[100];
int N,i, flag;
double max= arr[0].diemTB;
double diem=0;
printf("Hay nhap so luong sinh vien:");
scanf("%d", &N);
for(i=0; i<N; i++){
	printf("hay nhap ho so sinh vien [%d]:\n", i);
    printf("nhap mssv:\n");
    scanf("%d", &arr[i].mssv);
    printf("nhap ho ten:");
    scanf("%s", &arr[i].hoTen);
    printf("\nNhap diem TB:");
    scanf("%lf", &arr[i].diemTB);
    char c = getchar();
    //printf("\nho ten la: %s", &arr[i].hoTen);
    //printf("\nmssv: %d", &arr[i].mssv);
    //printf("\ndiem tb la: %lf", &arr[i].diemTB);
	diem += arr[i].diemTB;
	if(max<arr[i].diemTB){ max = arr[i].diemTB;flag = i;
	} 
	
}

double Tb;
Tb=diem/N;
printf("Diem TB: %f\n",Tb);
printf("Diem trung binh cao nhat la: %f\n",max);
printf("Diem tb cao nhat la cua %s", arr[flag].hoTen);
	} 

