
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "naloga.h"

int poisciStudenta(Student **studentje, int stStudentov, int vpisna)
{
    for (int i = 0; i < stStudentov; i++)
    {
        if (studentje[i]->vpisna == vpisna)
            return i;
    }

    return -1;
}

int poisciPO(Student *student, char *predmet)
{
    int stPO = student->stPO;
    for (int i = 0; i < stPO; i++)
    {
        if (strcmp(student->po[i].predmet, predmet) == 0)
            return i;
    }

    return -1;
}

int dodaj(Student **studentje, int stStudentov, int vpisna, char *predmet, int ocena)
{
    int indexStudenta = poisciStudenta(studentje, stStudentov, vpisna);
    if (indexStudenta != -1)
    {
        int indexPredmeta = poisciPO(studentje[indexStudenta], predmet);
        if (indexPredmeta != -1)
        {
            studentje[indexStudenta]->po[indexPredmeta].ocena = ocena;
        }
        else
        {
            studentje[indexStudenta]->po[studentje[indexStudenta]->stPO].ocena = ocena;
            strcpy(studentje[indexStudenta]->po[studentje[indexStudenta]->stPO].predmet, predmet);
            studentje[indexStudenta]->stPO++;
        }
    }
    else
    {
        Student *novS = malloc(1 * sizeof(Student));
        novS->vpisna = vpisna;
        novS->stPO = 1;
        novS->po = malloc(10 * sizeof(PO));
        novS->po[0].ocena = ocena;
        strcpy(novS->po[0].predmet, predmet);
        studentje[stStudentov] = novS;
        stStudentov++;
    }
    return stStudentov;
}

int main()
{
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}
