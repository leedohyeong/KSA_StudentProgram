#include <stdio.h>
#include <string.h>
#define max_length 256 //길이 설정

struct student
{
    char name[50];
    char sex[50];
    int birth;
    char phone[50];
    char email[50];
    char major[50];
    char project[50];
};

void swap(struct student* a, struct student* b)
{
    struct student temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    FILE* fp = NULL;
    fopen_s(&fp, "student2.txt", "r");
    struct student list[25];
    char ss[50];
    int i = 0;
    int m = 0;


    while (!feof(fp))
    {
        fscanf_s(fp, "%s, %d\n", &list[i].name, 10);
        fscanf_s(fp, "%s, %d\n", &list[i].sex, 10);
        fscanf_s(fp, "%d, %d\n", &list[i].birth, 10);
        fscanf_s(fp, "%s, %d\n", &list[i].phone, 20);
        fscanf_s(fp, "%s, %d\n", &list[i].email, 30);
        fscanf_s(fp, "%s, %d\n", &list[i].major, 50);
        fscanf_s(fp, "%s, %d\n", &list[i].project, 50);
        i++;

    }

    while (1) {

        
        int j = 0;
        int n = 3;
        int z = 0;
        int p = 0;

        printf("KSA 2021 인공지능프로그램 참여 학생 검색 프로그램 입니다.\n");
        printf("옵션을 선택하세요 : 1. Name 2. Sex 3. Project 4. Birth\n");
        scanf_s("%d", &m);

        while (1) {
            switch (m)
            {
            case 1:
                printf("이름을 검색하세요 : \n");
                scanf_s("%s", ss, sizeof(ss));

                for (int a = 0; a < 25; a++)
                {
                    if (n != 0)
                    {
                        z++;
                        n = strcmp(list[a].name, ss);

                    }
                }
                if (n != 0 && z == 25)
                {
                    printf("이름을 다시 검색하세요\n");
                    z = 0;
                    n = 3;
                    continue;

                }
                if (n == 0) {

                    printf("%s\n", list[z - 1].name);
                    printf("%s\n", list[z - 1].sex);
                    printf("%d\n", list[z - 1].birth);
                    printf("%s\n", list[z - 1].phone);
                    printf("%s\n", list[z - 1].email);
                    printf("%s\n", list[z - 1].major);
                    printf("%s\n", list[z - 1].project);
                }

                break;

            case 2:

                printf("성별을 검색하세요 : \n");
                scanf_s("%s", ss, sizeof(ss));
                for (int a = 0; a < 25; a++)
                {
                    if (n != 0)
                    {
                        z++;
                        n = strcmp(list[a].sex, ss);

                    }
                    if (n == 0) {
                        printf("%s %s %s %s %s  \t", list[a].name, list[a].phone, list[a].email, list[a].major, list[a].project);
                        printf("\n");
                        n = 3;
                        ++p;
                    }
                }
                if (p == 0 && z == 25)
                {
                    printf("성별을 다시 검색하세요 \n");
                    z = 0;
                    n = 3;
                    continue;

                }

                break;

            case 3:

                printf("선택 기업을 검색하세요 : \n");
                scanf_s("%s", ss, sizeof(ss));
                for (int a = 0; a < 25; a++)
                {
                    if (n != 0)
                    {
                        z++;
                        n = strcmp(list[a].project, ss);

                    }
                    if (n == 0) {
                        printf("%s %s %s %s %s  \t", list[a].name, list[a].phone, list[a].email, list[a].major, list[a].sex);
                        printf("\n");
                        n = 3;
                        ++p;
                    }
                }
                if (p == 0 && z == 25)
                {
                    printf("기업을 다시 검색하세요 \n");

                    z = 0;
                    n = 3;
                    continue;
                }

                break;

            case 4:
                for (i = 0; i < 25; i++)
                {
                    for (j = 0; j < 24; j++)
                    {
                        if (list[j].birth > list[j + 1].birth)
                        {
                            swap(&list[j], &list[j + 1]);
                        }
                    }
                }
                for (i = 0; i < 25; i++)
                {
                    printf("%s : %d\n", list[i].name, list[i].birth);
                }
                break;
            }

            break;

        }
        p = 0;
        m = 0;
        z = 0;
        n = 3;

    }
    fclose(fp);

    return 0;

}