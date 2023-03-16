#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int const MAX = 100;
typedef struct cuonsach {
    char masach[10];
    char tensach[256];
    char tentg[50];
    char loaisach[50];
    int years;
    float prices;
    int sl;
    float sum_of_books;
} cs;
void nhapsl(int &n) {
    printf("Nhap so luong cuon sach: ");
    scanf("%d", &n);
}
void delRow(char x[]) {
    size_t n = strlen(x);
    if (x[n - 1] == '\n')
        x[n - 1] = '\0';
}
void nhaptt(cs &x) {
    fflush(stdin);
    printf("\nNhap ma sach: "); fgets(x.masach, sizeof(x.masach), stdin); delRow(x.masach);
    fflush(stdin);
    printf("Nhap ten sach: "); fgets(x.tensach, sizeof(x.tensach), stdin); delRow(x.tensach);
    printf("Nhap tac gia: "); fgets(x.tentg, sizeof(x.tentg), stdin); delRow(x.tentg);
    do {
        printf("Nhap loai sach: "); fgets(x.loaisach, sizeof(x.loaisach), stdin); delRow(x.loaisach);
        
    } while(strcmp(x.loaisach, "xh") != 0 && strcmp(x.loaisach, "tn") != 0 && strcmp(x.loaisach, "TN") && strcmp(x.loaisach, "XH"));
    printf("Nhap nam xuat ban: "); scanf("%d", &x.years);
    fflush(stdin);
    printf("Nhap gia tien:"); scanf("%f", &x.prices);
    printf("Nhap so luong:"); scanf("%d", &x.sl);
}
void xuat_tt_sach(cs x) {
    printf("\nMa sach: %s", x.masach);
    printf("\nTen sach: %s", x.tensach);
    printf("\nTen tac gia: %s", x.tentg);
    printf("\nTen loai sach: %s", x.loaisach);
    printf("\nNam xuat ban: %d", x.years);
    printf("\nGia tien: %f", x.prices);
    printf("\nSo luong: %d", x.sl);
}
void nhap_ds_sach(cs a[], int n) {
    printf("==================\n");
    for(int i = 0; i < n; i++) {
        printf("NHAP DANH TT CUON SACH THU (%d)", i+ 1);
        nhaptt(a[i]);
        
    }
}
void adding_new_book(cs a[], int &n) {
    for(int i = n; i <= n; i++) {
        printf("\nNHAP CUON SACH MUON THEM");
        nhaptt(a[n]);
    }
    n++;
}
void xuat_ds_sach(cs a[], int n) {
    printf("\nDANH SACH CUON SACH");
    for(int i = 0; i < n; i++) {
        xuat_tt_sach(a[i]);
        printf("\n==================\n");
    }
}
int sum_of_books(cs a[], int &n) {
    int temp = 0;
    for(int i = 0; i < n; i++) { 
        temp += a[i].prices;
    }
    return temp;
}
void swap(cs &a, cs &b)
{
    cs temp = a;
    a = b;
    b = temp;
}
void bbsort(cs a[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if (strcmp(a[j].masach, a[j+1].masach) > 0) {
                swap(a[j], a[j+1]);
            }
        }
    }
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
void findBook(cs a[], char sach[], int n)
{
    cs B[MAX];
    char* ten_sach;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        ten_sach = (char*) malloc(strlen(a[i].tensach) + 1);
        strncpy(ten_sach, a[i].tensach, strlen(a[i].tensach) + 1);
        toUpperCase(ten_sach);
        toUpperCase(sach);
        if (strstr(ten_sach, sach))
        {
            B[temp] = a[i];
            temp++;
        }
        free(ten_sach); 
    }
    xuat_ds_sach(B, temp);
}
void year2000(cs a[], int n) {
    cs B[MAX];
    int temp = 0;  
    for(int i = 0; i < n; i++) {
        if(a[i].years < 2000) {
            B[temp] = a[i];
            temp++;
        }
    }
    printf("%d", temp);
    // xuat_ds_sach(B, temp);
}
int book_price_higher(cs a[], int n) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(a[i].prices > 50000) {
            count++;
        }
    }
    return count;
}
void tim_sach_theo_loai(cs a[], char loai_sach[], int n) {
    cs B[MAX];
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(a[i].loaisach, loai_sach) == 0)
        {
            B[temp] = a[i];
            temp++;
        }
    }
    xuat_ds_sach(B, temp);
}
int main() {
    int n;
    cs a[MAX];
    char tim_sach[10];
    char loai_sach[10];
    // printf("nhap sach can tim: ");
    // fflush(stdin);
    // fgets(tim_sach, sizeof(tim_sach), stdin); delRow(tim_sach);
    printf("nhap  loai sach can tim: ");
    fgets(loai_sach, sizeof(loai_sach), stdin); delRow(loai_sach);
    // printf("%s", loai)
    fflush(stdin);
    nhapsl(n);
    nhap_ds_sach(a,n);
    adding_new_book(a,n);
    year2000(a,n);
    bbsort(a,n);
    tim_sach_theo_loai(a,loai_sach,n);
    xuat_ds_sach(a,n);
    findBook(a,tim_sach,n);
    printf("%d", book_price_higher(a,n));
    return 0;
}