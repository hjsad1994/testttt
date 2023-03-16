#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int const MAX = 10;
typedef struct tiemcoffe {
    char masp[50];
    char sp[50];
    int loai;
    char tennv[50];
    int ngay;
    int thang;
    int nam;
    int sl;
    float dg;
} tc;
void delRow(char x[]) {
    size_t n = strlen(x);
    if (x[n - 1] == '\n')
        x[n - 1] = '\0';
}
void toUpperCase(char* s)
{
    while (*s) {
        if (*s >= 'a' && *s <= 'z') {
            *s = *s - 32;
        }
        s++;
    }
}
void nhapsl(int &n) {
    printf("Nhap so san pham: ");
    scanf("%d", &n);
}
void inputProduct(tc &x) {
    fflush(stdin);
    printf("\nNhap ma san pham: "); fgets(x.masp, sizeof(x.masp), stdin); delRow(x.masp);
    fflush(stdin);
    printf("Nhap ten san pham: "); fgets(x.sp, sizeof(x.sp), stdin); delRow(x.sp);
    do {
        printf("Nhap loai (1,2): "); scanf("%d", &x.loai);
    } while(x.loai < 1 || x.loai > 2);
    fflush(stdin);
    printf("Nhap ten nhan vien: "); fgets(x.tennv, sizeof(x.tennv), stdin); delRow(x.tennv);
    fflush(stdin);
    printf("Nhap ngay: "); scanf("%d", &x.ngay);
    printf("Nhap thang: "); scanf("%d", &x.thang);
    printf("Nhap nam: "); scanf("%d", &x.nam);
    printf("Nhap so luong: "); scanf("%d", &x.sl);
    printf("Nhap don gia: "); scanf("%f", &x.dg);
}
void outputProduct(tc x) {
    printf("\nMa san pham: %s", x.masp);
    printf("\nTen san pham: %s", x.sp);
    printf("\nloai san pham (1,2): %d", x.loai);
    printf("\nTen nhan vien: %s", x.tennv);
    printf("\nNgay: %d", x.ngay);
    printf("\nThang: %d", x.thang);
    printf("\nNam: %d", x.nam);
    printf("\nSo luong: %d", x.sl);
    printf("\nGia tien: %f", x.dg);
}
void input_List_Product(tc a[], int n) {
    printf("==================");
    for(int i = 0; i < n; i++) {
        printf("\nNHAP DANH TT CUON SACH THU (%d)", i+ 1);
        inputProduct(a[i]);
        
    }
}
void output_List_Product(tc a[], int n) {
    printf("\nDANH SACH CUON SACH\n");
    for(int i = 0; i < n; i++) {
        outputProduct(a[i]);
        printf("\n==================\n");
    }
}
void col_total_money(tc a[], int n) {
    float result = 0;
    for(int i = 0; i < n; i++) {
        outputProduct(a[i]);
        result += a[i].dg * a[i].sl;
        printf("\nTotal money: %2f", result);
        result = 0;
    }
}
void sum_of_product(tc a[], int n) {
    int result = 0;
    int flag = 0;
    for(int i = 0; i < n; i++) {
        if((a[i].thang == 3 && a[i].loai == 1)) {
            result += a[i].dg;
        }
    }
    if(result == 0) {
        printf("KHONG CO SAN PHAM\n");
    }
    else {
    printf("Tong Tien Trong Thang 3: %d", result);
    }
}
void bestsaler(tc a[], int n) {
    tc B[MAX];
    int max = 0;
    int temp = 0;
    for(int i = 0; i < n; i++) {
        if(a[i].sl > max && a[i].thang <= 6) {
            max = a[i].sl;
            B[temp] = a[i];
        }
    }
    output_List_Product(B, 1);
}
void find_Product(tc a[], char nProduct[], int n)
{
    tc B[MAX];
    char* ten_sp;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        ten_sp = (char*) malloc(strlen(a[i].sp) + 1);
        strncpy(ten_sp, a[i].sp, strlen(a[i].sp) + 1);
        toUpperCase(ten_sp);
        toUpperCase(nProduct);
        if (strstr(ten_sp, nProduct))
        {
            B[temp] = a[i];
            temp++;
        }
        free(ten_sp); 
    }
    output_List_Product(B, temp);
}
void find_ProductCode(tc a[], char cProduct[], int n)
{
    tc B[MAX];
    char* ma_sp;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        ma_sp = (char*) malloc(strlen(a[i].masp) + 1);
        strncpy(ma_sp, a[i].masp, strlen(a[i].masp) + 1);
        toUpperCase(ma_sp);
        toUpperCase(cProduct);
        if (strstr(ma_sp, cProduct))
        {
            B[temp] = a[i];
            temp++;
        }
        free(ma_sp); 
    }
    output_List_Product(B, temp);
}
int count_nv_loai2(tc a[], int n) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(a[i].loai == 2) { 
            count++;
        }
    }
    return count;
}
void nhaptensp(char *s[]) {
    printf("Nhap TEN san pham muon tim kiem: ");
    scanf("%s", *s);
}
void nhapmasp(char *s[]) {
    printf("Nhap MA san pham muon tim kiem: ");
    scanf("%s", *s);
}
void menu() {

    printf("1.Nhap Danh Sach Nhan Vien\n");
    printf("2.Xuat Danh Sach Nhan Vien\n");
    printf("3.Cot Thanh Tien\n");
    printf("4.Tinh Tong Tien San Pham Trong Thang 3 Loai 1\n");
    printf("5.Xuat Ten San Pham Ban Chay Nhat 6 Thang Dau Nam\n");
    printf("6.Tim San Pham Theo Ten\n");
    printf("7.Tim San Pham Theo Ma\n");
    printf("8.Dem So Luong Nv Ban Hang Loai 2\n");
    printf("0.THOAT MENU\n");
}
void XuatMenu(int n)
{
    tc a[MAX];
    int selec;
    do
    {
        printf("\nNhap Lua Chon: ");
        scanf("%d", &selec);
        switch (selec)
        {
        case 1:
        {
            input_List_Product(a,n);
            break;
        }
        case 2:
        {
            output_List_Product(a,n);
            break;
        }
        case 3: {
            col_total_money(a,n);
            break;
        }
        case 4: {
            sum_of_product(a,n);
            break;
        }
        case 5: {
            bestsaler(a,n);
            break;
        }
        case 6:
        {
            char* ten_sp = (char*) malloc(10 * sizeof(char));
            nhaptensp(&ten_sp);
            find_Product(a, ten_sp, n);
            break;
        }
        case 7: {
            char* ten_masp = (char*) malloc(10 * sizeof(char));
            nhapmasp(&ten_masp);
            find_ProductCode(a,ten_masp,n);
            break;
        }
        case 8: {
            if(count_nv_loai2(a,n) == 0) {
                printf("KHONG CO NHAN VIEN LOAI 2");
            }
            else {
                printf("So luong nv loai 2: %d", count_nv_loai2(a,n));
            }
            break;
        }               
        default:
            break;
        }
    } while (selec != 0);
}
int main() {
    int n;
    tc a[MAX];
    nhapsl(n);
    menu();
    XuatMenu(n);
    return 0;
}