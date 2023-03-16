#include<stdio.h>
#include<string.h>
#include<conio.h>
#define MAX 100
typedef struct Coffe
{
    char MaSp[15];
    char TenSp[20];
    int LoaiSp;
    char TenNV[30];
    int Ngay;
    int Thang;
    int Nam;
    int SoLuong;
    float DonGia;
}caffe;
void NhapDanhSach(Coffe &caffe)
{
    printf("Nhap ma san pham\n");
    fflush(stdin);
    scanf("%s",&caffe.MaSp);
    printf("Ten san pham\n");
    fflush(stdin);
    gets(caffe.TenSp);
    do
    {
        printf("Loai san pham(1,2)\n");
        caffe.LoaiSp=getche();
    }
    while(caffe.LoaiSp!='1'&&caffe.LoaiSp!='2');
    printf("\nTen nhan vien\n");
    fflush(stdin);
    gets(caffe.TenNV);
    printf("Nhap ngay ban\n");
    fflush(stdin);
    scanf("%d",&caffe.Ngay);
    printf("Thang ngay ban\n");
    fflush(stdin);
    scanf("%d",&caffe.Thang);
    printf("Nhap nam ban\n");
    fflush(stdin);
    scanf("%d",&caffe.Nam);
    printf("Nhap so luong\n");
    fflush(stdin);
    scanf("%d",&caffe.SoLuong);
    printf("Nhap don gia\n");
    fflush(stdin);
    scanf("%f",&caffe.DonGia);
}
void XuatDanhSach(Coffe caffe)
{
    printf("MaSp: %s, ",caffe.MaSp);
    printf("Ten Sp: %s, ",caffe.TenSp);
    if(caffe.LoaiSp=='1')
        printf("1, ");
    else
        printf("2, ");
    printf("Ten NV: %s, ",caffe.TenNV);
    printf("DATE: %d/%d/%d, ",caffe.Ngay,caffe.Thang,caffe.Nam);
    printf("So luong: %d, ",caffe.SoLuong);
    printf("Don gia: %.2f",caffe.DonGia);
}
void NhapDuLieu(Coffe caffe[],int &n)
{
    do
    {
        printf("Nhap so luong san pham: ");
        scanf("%d",&n);
    }
    while(n<0||n>5);

    for(int i=0;i<n;i++)
    {
        printf("Nhap nhan vien thu %d: \n",i+1);
        NhapDanhSach(caffe[i]);
    }
}
void XuatDuLieu(Coffe caffe[],int n)
{
    for(int i=0;i<n;i++)
    {
        XuatDanhSach(caffe[i]);
        printf("\n");
    }
}
void ThemCotThanhTien(Coffe caffe[],int n)
{
    float tong=0;
    for(int i=0;i<n;i++)
    {
        XuatDanhSach(caffe[i]);
        tong+=caffe[i].DonGia*caffe[i].SoLuong;
        printf(", Thanh Tien: %.2f\n",tong);
        tong=0;
    }
}
void SPThang3(Coffe caffe[],int n)
{
    int tong=0;
    for(int i=0;i<n;i++)
    {
        if(caffe[i].LoaiSp=='1'&&caffe[i].Thang==3)
        {
            tong+=caffe[i].DonGia*caffe[i].SoLuong;
        }
    }
    printf("Tong tien trong thang 3 voi san pham loai 1 la: %d",tong);
}
void Hot6ThangDau(Coffe caffe[],int n)
{
    Coffe B[MAX];
    int temp=0;
    int max=0;
    for(int i=0;i<n;i++)
    {
        if(caffe[i].SoLuong>max&&caffe[i].Thang<=6)
        {
            max=caffe[i].SoLuong;
            B[temp]=caffe[i];
        }
    }   
    XuatDuLieu(B,1);
}
void TimTen(Coffe caffe[],char TenSp[],int n)
{
    int dem=0;
    for(int i=0;i<n;i++)
    {
        if(strcmp(caffe[i].TenSp,TenSp)==0)
        {
            XuatDanhSach(caffe[i]);
            dem++;
        }
    }
    if(dem==0)
    {
        printf("Khong tim thay san pham co ma la %s\n",TenSp);
    }
}
void TimMa(Coffe caffe[],char MaSp[],int n)
{
    int dem=0;
    for(int i=0;i<n;i++)
    {
        if(strcmp(caffe[i].MaSp,MaSp)==0)
        {
            XuatDanhSach(caffe[i]);
            dem++;
        }
    }
    if(dem==0)
    {
        printf("Khong tim thay san pham co ma la %s\n", MaSp);
    }
}
void DemLoai2(Coffe caffe[],int n)
{
    int dem=0;
    for(int i=0;i<n;i++)
        if(caffe[i].LoaiSp=='2')
            dem++;
    printf("So luong nhan vien ban hang loai 2: %d",dem);
    if(dem==0)
        printf("Khong tim thay nhan vien co ma la 2\n");
}
int main()
{
    Coffe caffe[MAX];
    int n;
    char TenSp[20];
    char MaSp[20];
    int Menu;
    do
    {
        printf("\n---------------Menu----------------\n");
        printf("1.Nhap danh sach\n");
        printf("2.Xuat danh sach\n");
        printf("3.Them cot thanh tien\n");
        printf("4.Tong tien sp ban trong thang 3 voi loai 1\n");
        printf("5.Ten san pham ban chay trong 6 thang dau nam\n");
        printf("6.Tim san pham theo ten\n");
        printf("7.Tim san pham theo ma\n");
        printf("8.Dem so luong nhan vien ban hang loai 2\n");
        printf("0.Thoat\n");
        scanf("%d",&Menu);
        switch(Menu)
        {
            case 0:
                printf("Xin Cam On");
                break;
            case 1:
                NhapDuLieu(caffe,n);
                break;
            case 2:
                XuatDuLieu(caffe,n);
                break;
            case 3:
                ThemCotThanhTien(caffe,n);
                break;
            case 4:
                SPThang3(caffe,n);
                break;
            case 5:
                Hot6ThangDau(caffe,n);
                break;
            case 6:
                printf("Nhap ten san pham muon tim\n");
                scanf("%s",&TenSp);
                TimTen(caffe,TenSp,n);
                break;
            case 7:
                printf("Nhap ma san pham muon tim\n");
                scanf("%s",&MaSp);
                TimMa(caffe,MaSp,n);
                break;
            case 8:
                DemLoai2(caffe,n);
                break;
            default:
                printf("Lua chon khong hop le\n");
                break;
        }
    }while(Menu!=0);
}