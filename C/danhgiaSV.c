#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef union{
    char gradeChar;
    float gradeNum;
}grade;

typedef enum{
    CHAR,
    NUMBER
}typeGrade;

typedef struct{
    char name[20];
    char id[10];
    grade Grade;
    typeGrade type;
}student;

int compareName(const student *a, const student *b){
    const char *studenA = a->name;
    const char *studenB = b->name;
    while(*studenA && *studenB && *studenA == *studenB){
        ++studenA;
        ++studenB;
    }
    return (int)(*studenA) - (int)(*studenB);
}

int compareId(const student *a, const student *b){
    const char *studenA = a->id;
    const char *studenB = b->id;
    while(*studenA && *studenB && *studenA == *studenB){
        ++studenA;
        ++studenB;
    }
    return (int)(*studenA) - (int)(*studenB);
}

int compareGrade(const student *a, const student *b){
    if(a->type == NUMBER && b->type == NUMBER)
        return (int)(a->Grade.gradeNum - b->Grade.gradeNum);
    else if(a->type == CHAR && b->type == CHAR)
        return (int)((a->Grade.gradeChar - b->Grade.gradeChar)*(-1));
    else if(a->type == CHAR && b->type == NUMBER)
        return (int)((a->Grade.gradeChar - b->Grade.gradeNum));
    else if(a->type == NUMBER && b->type == CHAR)
        return (int)((a->Grade.gradeNum - b->Grade.gradeChar));
}

void sortStudent(student studentsList[], int n, int(*compare)(const student*,const student*)){
    for(int i = 0; i < n -1; i ++){
        for (int j = 0; j < n - i -1; j++){
            if(compare(studentsList + j, studentsList + j + 1) > 0){
                student temp = studentsList[j];
                studentsList[j] = studentsList[j+1];
                studentsList[j+1] = temp;
            }
        }
    }
}

void printList(student *list, int n){
    for(int i = 0; i < n; i++){
        printf("Name: %s\tID: %s\tGrade: ", list[i].name, list[i].id);
        if(list[i].type == CHAR)
            printf("%c\r\n",list[i].Grade.gradeChar);
        else
            printf("%f\r\n",list[i].Grade.gradeNum);
    }
}

int main(int argc, char const *argv[])
{
    student studentList[] = {
        {.name = "Tam", .id = "I101", .Grade.gradeNum = 9.5, .type = NUMBER},
        {.name = "Binh", .id = "I105", .Grade.gradeChar = 'C', .type = CHAR},
        {.name = "Khanh", .id = "I103", .Grade.gradeNum = 8.3, .type = NUMBER},
        {.name = "Dung", .id = "I102", .Grade.gradeChar = 'A', .type = CHAR}
    };
    sortStudent(studentList,4,&compareGrade);
    printList(studentList,4);
    return 0;
}
