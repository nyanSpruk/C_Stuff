
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "naloga.h"

int poisciStudenta(Student **studentje, int stStudentov, int vpisna)
{
    for (int i = 0; i < stStudentov; i++)
        if (studentje[i]->vpisna == vpisna)
            return i;

    return -1;
}

int poisciPO(Student *student, char *predmet)
{
    for (int i = 0; i < student->stPO; i++)
    {
        if (strcmp(student->po[i].predmet, predmet) == 0)
            return i;
    }

    return -1;
}

int dodaj(Student **studentje, int stStudentov, int vpisna, char *predmet, int ocena)
{
    int ix = poisciStudenta(studentje, stStudentov, vpisna);

    if (ix == -1)
    {
        Student *temp = malloc(sizeof(Student));
        temp->vpisna = vpisna;
        temp->stPO = 1;
        temp->po = malloc(10 * sizeof(PO));
        temp->po[0].ocena = ocena;
        strcpy(temp->po[0].predmet, predmet);
        studentje[stStudentov] = temp;
        stStudentov++;
    }
    else
    {
        int ixPo = poisciPO(studentje[ix], predmet);
        if (ixPo == -1)
        {
            studentje[ix]->po[studentje[ix]->stPO].ocena = ocena;
            strcpy(studentje[ix]->po[studentje[ix]->stPO].predmet, predmet);
            studentje[ix]->stPO++;
        }
        else
        {
            studentje[ix]->po[ixPo].ocena = ocena;
        }
    }
    return stStudentov;
}

int main()
{
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}
