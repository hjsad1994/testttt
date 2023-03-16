#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
struct Date {
	int Ng;
	int T;
	int N;
};
typedef struct Quanlytiem {
	char Ma[20];
	char Tensp[20];
	char Loai;
	char Tennv[20];
	Date NgayBan;
	int Sl;
	int Dg;
	int Ng;
	int T;
	int N;
} Ql;
void Menu() {
	printf("\n==HAY CHON CONG VIEC");
	printf("\n1.Nhap danh sach san pham!");
	printf("\n2.Xuat danh sach san pham!");
	printf("\n3.Them cot thanh tien! ");
	printf("\n4.Tinh tong tien sp trong thang 3!");
	printf("\n5.Tinh tong tien sp ban chay nhat trong 6 thang dau!");
	printf("\n6.Tim san pham theo ten!");
	printf("\n7.Tim san pham theo ma!");
	printf("\n8.Dem so luong nv ban hang loai 2!");
	printf("\n9.KET THUC!");
}
void Nsl(int &n) {
	do {
		printf("\n Nhap so luong san pham can quan ly: ");
		scanf("%d",&n);
	} while(n<0||n>10);
}
void Nngay(Date &t) {
	printf("Nhap ngay  :");
	scanf("%d",&t.Ng);
	printf("Nhap thang :");
	scanf("%d",&t.T);
	printf("Nhap nam   :");
	scanf("%d",&t.N);
}
void Xngay(Date t) {
	printf("\t%d/%d/%d",t.Ng,t.T,t.N);
}
void Nhap1sp(Ql &s) {
	printf("Nhap ma san pham 		:");
	fflush(stdin);
	gets(s.Ma);
	printf("Nhap ten san pham     	:");
	fflush(stdin);
	gets(s.Tensp);
	do {
		printf("Nhap loai ['1' -- '2']  :");
		s.Loai=getche();
	} while(s.Loai!='1'&&s.Loai!='2');
	printf("\nNhap ten nhan vien   	:");
	fflush(stdin);
	gets(s.Tennv);
	printf("==Nhap ngay ban==\n");
	Nngay(s.NgayBan);
	printf("Nhap so luong     	    :");
	scanf("%d",&s.Sl);
	printf("Nhap don gia      	  	:");
	scanf("%d",&s.Dg);
}
void Xuat1sp(Ql s) {
	printf("%s \t ",s.Ma);
	printf("%s \t ",s.Tensp);
	if(s.Loai=='1')
		printf("Loai I \t");
	else
		printf("Loai II\t");

	printf("%s \t ",s.Tennv);
	Xngay(s.NgayBan);
	printf("\t%d \t ",s.Sl);
	printf("%d \t ",s.Dg);
}
void NhapDS(Ql a[],int n) {
	for(int i=0; i<n; i++) {
		printf("\n Nhap nhan vien thu %d\n",i+1);
		Nhap1sp(a[i]);
	}
}
void XuatDS(Ql a[],int n) {
	for(int i=0; i<n; i++) {
		Xuat1sp(a[i]);
		printf("\n");
	}
}
float Tong(Ql a[],int n) {
	int t=0;
	for(int i=0; i<n; i++) {
		t+=a[i].Dg*a[i].Sl;
	}
	return t;
}
void Tien(Ql s) {
	float t=0;
	printf("%s \t ",s.Ma);
	printf("%s \t ",s.Tensp);
	if(s.Loai=='1')
		printf("Loai I\t");
	else
		printf("Loai II\t");
	printf("%s \t ",s.Tennv);
	Xngay(s.NgayBan);
	printf("\t%d \t ",s.Sl);
	printf("%d \t ",s.Dg);
	t=s.Dg*s.Sl;
	printf("  %f",t);
}
void Thanhtien(Ql a[],int n) {
	for(int i=0; i<n; i++) {
		Tien(a[i]);
		printf("\n");
	}
}

int Dem(Ql a[], int n) {
	int dem=0;
	for(int i=0; i<n; i++) {
		if(a[i].Loai=='2')
			dem+=1;
		else
			printf("0");
	}
	return dem;
}
void Timspten(Ql a[],char Tensp[],int n) {
	Ql b[50];
	char tensps[100];
	int tamp=0;
	for(int i=0; i<n; i++) {
		strcpy(tensps,a[i].Tensp);
		if(strstr(strupr(tensps),strupr(Tensp))) {
			b[tamp] = a[i];
			tamp++;
		}
		XuatDS(b,tamp);
	}
}
void Timspa(Ql a[],char Ma[],int n) {
	Ql b[50];
	char masps[100];
	int tamp=0;
	for(int i=0; i<n; i++) {
		strcpy(masps,a[i].Ma);
		if(strstr(strupr(masps),strupr(Ma))) {
			b[tamp] = a[i];
			tamp++;
		}
		XuatDS(b,tamp);
	}
}
void TongT3(Ql a[],int n) {
	float t3=0;
	for(int i=0; i<n; i++) {
		if(a[i].T=3&&a[i].Loai=='1') {
			t3+=a[i].Sl*a[i].Dg;
		}
	}
	printf("Tong tien thang 3 loai I=%f\n",t3);
}
float TongT6(Ql a[],int n) {
	int max=0;
	for(int i=0; i<n; i++) {
		if(a[i].T<=6) {
			max=a[0].Sl*a[0].Dg;
			if(max<a[i].Sl*a[i].Dg) {
				max=a[i].Sl*a[i].Dg;
			}
		}
	}
	return max;
}
int main() {
	Ql a[100];
	Date t;
	int n,cv;
	char Tensptim[20];
	char Maxsptim[20];


	do {
		Menu();
		printf("\nHay nhap cong viec");
		scanf("%d", &cv);
		switch(cv) {
			case 1:
				Nsl(n);
				NhapDS(a,n);
				getch();
				break;
			case 2:
				XuatDS(a,n);
				getch();
				break;
			case 3:
				Thanhtien(a,n);
				break;
			case 4:
				TongT3(a,n);
				break;
			case 5:
				printf("San Pham ban chay nhat trong 6 thang dau=%f",TongT6(a,n));
				break;
			case 6:
				printf("nhap ten can tim:\n");
				fflush(stdin);
				scanf("%s",&Tensptim);
				Timspten(a,Tensptim,n);
				break;
			case 7:
				printf("nhap ma can tim:\n");
				fflush(stdin);
				scanf("%s",&Maxsptim);
				Timspa(a,Maxsptim,n);
				break;

			case 8:
				printf("co %d nhan vien ban hang loai 2", Dem(a,n));
				break;
			default:
				break;
		}
	} while(1);


}


