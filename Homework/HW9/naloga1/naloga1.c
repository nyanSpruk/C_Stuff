
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga1.h"

int vrniOceno(Student *student, int stPo, char *predmet)
{
    for (int i = 0; i < stPo; i++)
    {
        char *temp = student->po[i].predmet;
        if (strcmp(temp, predmet) == 0)
            return student->po[i].ocena;
    }
    return 1;
}

VO **opravili(Student **studentje, int stStudentov, char *predmet, int *stVO)
{
    VO **vvo = malloc(stStudentov * sizeof(VO *));
    *stVO = 0;
    for (int i = 0; i < stStudentov; i++)
    {
        Student *student = studentje[i];

        int ocena = vrniOceno(student, student->stPO, predmet);
        if (ocena >= 6)
        {
            int vpisna = student->vpisna;

            int indeks = 0;
            while (indeks < *stVO && (ocena < vvo[indeks]->ocena || (ocena == vvo[indeks]->ocena &&
                                                                     vvo[indeks]->vpisna < studentje[i]->vpisna)))
                indeks++;

            for (int j = *stVO; j > indeks; j--)
            {
                vvo[j] = vvo[j - 1];
            }

            vvo[indeks] = malloc(sizeof(VO));
            vvo[indeks]->vpisna = studentje[i]->vpisna;
            vvo[indeks]->ocena = ocena;
            (*stVO)++;
        }
        // *stVO = stPo;
    }
    return vvo;
}
// void izvedi(Student **studentje, int stStudentov, char *predmet)
// {
//     int stVO = 0;
//     VO **vvo = opravili(studentje, stStudentov, predmet, &stVO);
//     printf("[");
//     for (int i = 0; i < stVO; i++)
//     {
//         VO *vo = vvo[i];
//         if (i > 0)
//         {
//             printf(", ");
//         }
//         printf("%d/%d", vo->vpisna, vo->ocena);
//     }
//     printf("]\n");
// }

int main()
{
    // Student *studentje[] = {
    //     (Student[]){
    //         555,
    //         (PO[]){{"FIZ", 10}, {"P1", 6}, {"P2", 7}, {"ODV", 5}, {"ARS", 6}},
    //         5},
    //     (Student[]){
    //         444,
    //         (PO[]){{"FIZ", 9}, {"P1", 7}, {"P2", 7}, {"ODV", 6}, {"ARS", 7}},
    //         5},
    //     (Student[]){
    //         333,
    //         (PO[]){{"FIZ", 8}, {"P1", 8}, {"P2", 7}, {"ODV", 5}, {"ARS", 6}, {"OMA", 10}},
    //         6},
    //     (Student[]){
    //         222,
    //         (PO[]){{"FIZ", 7}, {"P1", 9}, {"P2", 7}, {"ODV", 6}, {"ARS", 7}},
    //         5},
    //     (Student[]){
    //         111,
    //         (PO[]){{"FIZ", 6}, {"P1", 10}, {"P2", 7}, {"ODV", 5}, {"ARS", 6}},
    //         5},
    // };
    // int stStudentov = sizeof(studentje) / sizeof(studentje[0]);

    // izvedi(studentje, stStudentov, "FIZ");
    // izvedi(studentje, stStudentov, "P1");
    // izvedi(studentje, stStudentov, "P2");
    // izvedi(studentje, stStudentov, "ODV");
    // izvedi(studentje, stStudentov, "ARS");
    // izvedi(studentje, stStudentov, "OMA");

    // exit(0);
    return 0;
}