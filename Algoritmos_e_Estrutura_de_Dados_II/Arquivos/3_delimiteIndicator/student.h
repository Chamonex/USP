#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 3
#define STUDENTFILENAME "student.txt"

// definindo o delimitador
#define DELIMITERCHAR '|'


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

    // o delimitador fica NO FIM de cada campo

    fprintf(filePointer, "%s", student.name);
    fputc(DELIMITERCHAR, filePointer);

    fprintf(filePointer, "%d", student.age);
    fputc(DELIMITERCHAR, filePointer);

    fprintf(filePointer, "%d", student.grade);
    fputc(DELIMITERCHAR, filePointer);

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

static void readCurrentInput(FILE* filePointer, char* currentInput) {
    // recebe o arquivo
    // recebe uma string que vai ser a palavra lida

    // letra atual
    char currentChar = fgetc(filePointer);
    // index atual
    int currentIndex = 0;

    while((currentChar != EOF) && (currentChar != DELIMITERCHAR)) {
    // enquanto não chegar no fim da palavra ou no fim do arquivo:
        // atribui o char atual na string e implementa o index
        currentInput[currentIndex++] = currentChar;
        // le o próximo char
        currentChar = fgetc(filePointer);
    }
    currentInput[currentIndex] = '\0';  // delimitar fim
}

Student readStudentDataInFile(FILE* filePointer) {

    Student student;

    // palavra que vai ser lida (tamanho limite de):
    char currentInput[50];
    // ler nome:
    readCurrentInput(filePointer, currentInput);
    strcpy(student.name, currentInput); // strcpy para string

    // ler idade:
    readCurrentInput(filePointer, currentInput);
    student.age = atoi(currentInput);   // atoi para converter string em int

    // ler nota:
    readCurrentInput(filePointer, currentInput);
    student.grade = atoi(currentInput);

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
