#include <stdio.h>
#include <string.h>
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

    // tamanho do campo nome:
    int fieldSize = strlen(student.name); // usando strlen para CHAR[]
    // escrevendo indicador de tamanho:
    fprintf(filePointer, "%d", fieldSize);
    // escrevendo campo nome:
    fwrite(&student.name, fieldSize, 1, filePointer);

    // idade:
    fieldSize = sizeof(student.age); // usando sizeof para INT
    fprintf(filePointer, "%d", fieldSize);
    fwrite(&student.age, fieldSize, 1, filePointer);

    // nota:
    fieldSize = sizeof(student.grade);
    fprintf(filePointer, "%d", fieldSize);
    fwrite(&student.grade, fieldSize, 1, filePointer);

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
    int fieldSize;

    // lendo tamanho do campo nome:
    fscanf(filePointer, "%d", &fieldSize);
    // lendo campo nome:
    fread(student.name, fieldSize, 1, filePointer);
    // adicionar fim à string:
    student.name[fieldSize] = '\0';

    //idade:
    fscanf(filePointer, "%d", &fieldSize);
    fread(&student.age, fieldSize, 1, filePointer);

    // nota:
    fscanf(filePointer, "%d", &fieldSize);
    fread(&student.grade, fieldSize, 1, filePointer);

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
