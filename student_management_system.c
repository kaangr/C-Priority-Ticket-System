#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Öğrencilerin isim-soy isim ve öğrenci numaraları bağlı liste yapısında tutulacaktır. Sizden bir program yazmanızı istiyorum. Bu programda aşağıdaki menü seçenekleri ile işlem yapabilmeliyim.
1- Öğrenci Ekleme: Öğrencinin isim soy isim ve numarası kullanıcıdan istenir ve bağlı listeye yapısına eklenir.
2- Öğrenci arama: Öğrencinin numarası ile liste üzerinde arama işlemi yapılır. Öğrenci bulunur ise bilgileri, bulunmaz ise bilgi mesajı ekrana yazılır.
3- Öğrenci silme: Öğrenci numarası verilen kayıt listeden silinir.
4-Listeyi yazdırma: Tüm kayıtlı öğrencilerin bilgileri ekrana yazılır.
*/

typedef struct Student
{
    char name[25];
    char surname[25];
    int number;
    struct Student *next;

} Student;
Student *head;
Student *student1;
void error_null(){
    printf("error! listede Ogrenci Yok!");
}

void delete_student(Student *student)
{ 
    int number;
    int sira = 1;
    int i;
    int buldu_mu = 0;
    Student *temp;
    

    if(student ==NULL){
       error_null();
        return;
    }

    printf("\nSilme istediginiz  ogrencinin numarasini girin=>");
    scanf("%d", &number);
    while (student != NULL)
    {
        if (student->number == number)
        {
            buldu_mu = 1;
            break;
        }
        student = student->next;
        sira++;
    }

    if (buldu_mu != 1)
    {
        printf("\nAradiginiz numaraya ile kayitli ögrenci bulunamadi!\n");
        exit(0);
    }
    printf("\n%d. sira, numara: %d\n", sira, student->number);

    if (sira == 1)
    {
        printf("\nif ici\n");
        temp = student;
        head = student->next;
        free(temp);
    }
    else if(sira!=1){
        printf("\nelse if ici\n");
        printf("ögrencinin nosu= %d",student->number);
        student=head;

        for(i=1;i<sira-1;i++)
            student = student->next;
        //printf("%\nfor ici numara =%d\n", student->number);

        temp=student->next;
        student->next = student->next->next;

        free(temp);

    }
    printf("Silindi");
}

void print_student_list(Student *student)
{
    if(student ==NULL){
error_null();
return;
    }
    int count = 0;
    while (student != NULL)
    {
        printf("\n\tisim: %s, soyisim: %s ,numara : %d\n", student->name, student->surname, student->number);
        student = student->next;

        count++;
    }

    printf("\tlistedeki eleman sayisi=> %d\n", count);
}

void add_student(Student *h)
{

    char student_name[25];
    char student_surname[25];
    int student_number;
    printf("\nOgrencinin ismi >");
    scanf("%s", student_name); // boşluklu değerler için ^\n kullan

    printf("\nOgrencinin soyismi >");
    scanf("%s", student_surname);

    printf("\nOgrencinin numarasi >");
    scanf("%d", &student_number);

    //  printf("if ocnesi degerler %s %s %d %u",&student_name,&student_surname,student_number);

    if (h == NULL)
    {
        printf("\nif ici\n");
        head = (Student *)malloc(sizeof(Student));
        strcpy(head->name, student_name),           // printf(" \n%s\t",head->name);
                strcpy(head->surname, student_surname), // printf("%s\t",head->surname);
                head->number = student_number,          // printf("%d\t",&head->name);
                head->next = NULL;
    }
    else
    {
        printf("\nelse ici\n");
        while (h->next != NULL)
        {
            h = h->next;
        }

        h->next = (Student *)malloc(sizeof(Student));
        strcpy(h->next->name, student_name);
        strcpy(h->next->surname, student_surname);
        h->next->number = student_number;

        h->next->next = NULL;
    }
    // printf("\n%s %s %d\n", h->name, h->surname, h->number);
}

void search_student(Student *student)
{
    if(student==NULL){
error_null();
return;
    }
    int number;
    int i = 1;
    int buldu_mu = 0;
    printf("\naradiginiz ogrencinin kayitli girin=>");
    scanf("%d", &number);
    while (student != NULL)
    {

        if (student->number == number)
        {
            printf("\n%d. sira, isim: %s, soyisim: %s , numara: %d\n", i, student->name, student->surname, student->number);
            buldu_mu = 1;
        }

        student = student->next;
        i++;
    }

    if (buldu_mu != 1)
    {
        printf("\nAradiginiz numaraya ile kayitli ögrenci bulunamadi!\n");
    }
}
int main()
{
    head=(Student *)malloc(sizeof(Student));
    student1=(Student *)malloc(sizeof(Student));
    strcpy(head->name, "Serpil"),
            strcpy(head->surname,"ÜStebay" ),
               head->number=123456;

    strcpy(student1->name, "Ayse"),
            strcpy(student1->surname,"Gül" ),
            student1->number=123457 ;

    head->next = student1;

    int secim;
    do
    {
        printf("\n\n\t0 =CİKİS\n");
        printf("\t1 = OGRENCI EKLE\n");
        printf("\t2 = OGRENCI ARAMA\n");
        printf("\t3 =OGRENCI SİLME\n");
        printf("\t4= OGRENCILERI YAZDIRMA\n");

        scanf("%d", &secim);
        switch (secim)
        {
            case 0:

                break;
            case 1:
                add_student(head);
                break;
            case 2:
                search_student(head);
                break;
            case 3:
                delete_student(head);
                break;
            case 4:
                print_student_list(head);
                break;

            default:
                printf("lutfen dogru bir deger giriniz\n");
                break;
        }
    } while (secim != 0);
}

