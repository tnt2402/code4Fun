#include <stdio.h>
#include <string.h>

int tinhtien(int a, int b, char *LH) {
    int result;
    if (strcmp(LH, "gia dinh") == 0) result = 450 * (b - a);
    if (strcmp(LH, "san xuat") == 0) result = 500 * (b - a);
    if (strcmp(LH, "kinh doanh") == 0) result = 550 * (b - a);
    return result;
}

int main() {
    /* Nhap m ban ghi vao */
    int m;
    printf("[+] So ban ghi muon nhap: ");
    scanf("%d", &m);
    int result;
    /* vi tri xuat du lieu */
    char dir[30] = "test.txt"; //nho sua lai dia chi
    
    /* khai bao file can viet vao */
    FILE *fptr;
    fptr = fopen(dir, "a");
    for (int i=0; i < m; i++) {
        char CHUHO[30];
        char LH[20];
        int CSS, CST, TT;
        printf("\n[-] Nhap ten chu ho: ");
        scanf(" %[^\t\n]s", &CHUHO);
        printf("[!] Cac loai ho co the dang ki:\n1. Gia dinh\n2. San xuat\n3. Kinh doanh\n");
        printf("[-] Nhap loai ho: ");
        scanf(" %[^\t\n]s", &LH);
        printf("[-] Nhap chi so truoc - CST: ");
        scanf("%d", &CST);
        printf("[-] Nhap chi so sau - CSS: ");
        scanf("%d", &CSS);
        TT = tinhtien(CST, CSS, LH);
        printf("[$] Thanh tien: %d", TT);
        printf("\n***********************\n[+] Du lieu gia dinh ban vua nhap:\n***********************\n");
        printf("1. Chu ho: %s\n2. Loai ho: %s\n3. Chi so truoc: %d\n4. Chi so sau: %d\n5. Tong tien: %d", CHUHO, LH, CST, CSS, TT);
        printf("\n\n[!] Da them ban ghi vao file !!!\n");
        fprintf(fptr, "\n%s - %s - %d - %d - %d", CHUHO, LH, CST, CSS, TT);
    }
    printf("\n[$] Bye bye !");
    fclose(fptr);
    return 0;
}
