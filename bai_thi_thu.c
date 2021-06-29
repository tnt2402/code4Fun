#include <stdio.h>
#include <string.h>
#include <ctype.h>
struct sinhVien {
    char name[31];
    char id[13], home_town[31];
    float gpa;
};
typedef struct sinhVien SV;

void in();
void menu();
void nhap();
void search_gpa_home();
void search_mssv();
void sort();


SV a[100];

int first_run = 1, count = 0, sum_gpa = 0;
float gpa_average;
int main() {
    menu();
    return 0;
}

void menu() {
    fflush(stdout);
    int x;
    printf("\n**************** M E N U *******************\n");
    printf("\n1. Nhap thong tin sinh vien.");
    printf("\n2. In thong tin sinh vien.");
    printf("\n3. Tim kiem theo MSSV.");
    printf("\n4. Tim kiem theo GPA va que quan.");
    printf("\n5. Sap xep");
    printf("\n6. Thoat\n");
    printf("[+] Nhap lua chon: "); scanf("%d", &x);
    switch (x) {
        case 1:
            nhap();
            break;
        case 2: 
            in();
            break;
        case 3:
            search_mssv();
            break;
        case 4:
            search_gpa_home();
            break;
        case 5:
            sort();
            break;
        default:
            printf("\nDang thoat khoi chuong trinh....\n");
    }

}

void nhap() {
    int num;
    if (first_run == 1) {
        printf("\n[+] Nhap so luong sinh vien: ");
        first_run = 0;
    }
    else {
        printf("\n[+] Nhap so luong sinh vien them vao: ");
    }
    scanf("%d", &num);
    for (int i=count; i < num + count; i++) {
        char tmp[30];
        fgetc(stdin);
        printf("\n[+] Sinh vien thu %d", i+1);
        printf("\n    Ten: "); 
        gets(a[i].name);
        printf("\n    ID: "); 
        gets(a[i].id);
        printf("    Que quan: "); 
        gets(a[i].home_town);
        for(int j = 0; a[i].home_town[j]; j++){
            a[i].home_town[j] = tolower(a[i].home_town[j]);
        }
        do {
            printf("    GPA: "); scanf("%f", &a[i].gpa);
            if (0 > a[i].gpa || 4 < a[i].gpa) {
                printf("\n[!] GPA khong hop le !!!!\n");
            }
            else {
                sum_gpa += a[i].gpa;
                break;
            }
        }
        while (1==1);
    }
    count += num;
    menu();
}
void in() {
    printf("\nSTT    |     Ten          |   MSSV    |    Que quan       |    GPA  \n");
    for (int i=0; i < count; i++) {
        printf("\n%d | %s | %s | %s | %f |\n", i+1, a[i].name, a[i].id, a[i].home_town, a[i].gpa);
        gpa_average = (float) sum_gpa / count;
    }
    printf("\nDiem GPA trung binh tat ca sinh vien: %4f\n", gpa_average);

    menu();
}

void search_mssv() {
    char mssv[12];
    int counter = 0;
    printf("[+] Nhap MSSV can tim: "); scanf("%s", mssv);
    for (int i=0; i < count; i++) {
        if (strcmp(mssv, a[i].id) == 0) {
            counter++;
        }
    }
    if (counter == 0) {
        printf("\n[!] Khong tim thay");
        menu();
    }
    printf("\nSTT |     Ten     |    MSSV   |   Que quan   |  GPA  |\n");
    for (int i=0; i < count; i++) {
        if (strcmp(mssv, a[i].id) == 0) {
            printf("\n%d | %s|  %s  |  %s  | %f |\n", i+1, a[i].name, a[i].id, a[i].home_town, a[i].gpa);
        }
    }
    menu();
}

void search_gpa_home() {
    char home[30];
    fgetc(stdin);
    printf("\n[+] Nhap que quan: "); gets(home);
    for(int i = 0; home[i]; i++){
      home[i] = tolower(home[i]);
    }    
    printf("\nSTT |     Ten     |    MSSV   |   Que quan   |  GPA  |\n");
    for (int i=0; i < count; i++) {
        if (a[i].gpa > gpa_average && strcmp(home, a[i].home_town) == 0) {
            printf("\n%d | %s|  %s  |  %s  | %f |\n", i+1, a[i].name, a[i].id, a[i].home_town, a[i].gpa);
        }
    }
    menu();
}
void sort() {
    SV tmp; 
    for (int i=0; i < count - 1; i++) {
        for (int j=i; j < count; j++) {
            if (a[i].gpa < a[j].gpa) {
                tmp = a[i];
                a[i] = a[j];
                a[j]= tmp;
            }
        }
    }
    printf("\n[+] Da sap xep xong !!!\n");
    menu();
}
