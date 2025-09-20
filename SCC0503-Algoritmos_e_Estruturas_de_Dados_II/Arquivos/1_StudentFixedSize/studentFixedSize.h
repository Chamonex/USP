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

    fwrite(&student, sizeof(Student), 1, filePointer);

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
    fread(&student, sizeof(Student), 1, filePointer);
    return student;
}

void printStudentData(Student student) {
    printf("Nome: %s\n", student.name);
    printf("Idade: %d\n", student.age);
    printf("Nota: %d\n", student.grade);
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
