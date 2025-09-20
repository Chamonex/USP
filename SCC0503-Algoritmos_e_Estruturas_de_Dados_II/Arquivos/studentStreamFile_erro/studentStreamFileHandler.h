#include <stdio.h>
#define SIZE 3
#define STUDENTFILENAME "student.txt"

typedef struct student_t {
    char name[20];
    int age;
    int grade;
} Student;

Student readStudentDataFromInput() {
    Student student;

    printf("nome do estudante: ");
    scanf("%s", student.name);
    printf("\nidade: ");
    scanf("%d", &student.age);
    printf("nota: ");
    scanf("%d", &student.grade);
    printf("\n");
    return student;
}

void writeStudentDataInFile(Student student, FILE *filePointer) {
    fprintf(filePointer, "%s", student.name);
    fprintf(filePointer, "%d", student.age);
    fprintf(filePointer, "%d", student.grade);
}

void createStudentFile() {
    FILE *filePointer = fopen(STUDENTFILENAME, "w");
    printf("Lendo dados do teclado\n\n");
    for (int i = 0; i < SIZE; i++) {
        Student student = readStudentDataFromInput();
        writeStudentDataInFile(student, filePointer);
    }
    fclose(filePointer);
}

Student readStudentDataInFile(FILE* filePointer) {
    Student student;
    fscanf(filePointer, "%s", student.name);
    fscanf(filePointer, "%d", student.age);
    fscanf(filePointer, "%d", student.grade);
    return student;
}

void printStudentData(Student student) {
    printf("Nome: %s", student.name);
    printf("Idade: %d", student.age);
    printf("Nota: %d", student.grade);
}

void readStudentFile() {
    FILE *filePointer = fopen(STUDENTFILENAME, "r");
    printf("Dados no arquivo\n\n");
    for (int i = 0; i < SIZE; i++) {
        Student student = readStudentDataInFile(filePointer);
        printStudentData(student);
    }
    fclose(filePointer);
}
