#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 3
#define STUDENTFILENAME "student.txt"

// definindo o delimitador
#define DELIMITERCHAR '|'
// definindo tag delimiter
#define TAGDELIMITERCHAR '='
// definindo tags
#define NAMETAG "NAME"
#define AGETAG "AGE"
#define GRADETAG "GRADE"

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

    fprintf(filePointer, "%s", NAMETAG);        // tag
    fputc(TAGDELIMITERCHAR, filePointer);       // tag delimiter
    fprintf(filePointer, "%s", student.name);   // conteudo

    fputc(DELIMITERCHAR, filePointer);          // delimiter
    fprintf(filePointer, "%s", AGETAG);         // tag
    fputc(TAGDELIMITERCHAR, filePointer);       // tag delimiter
    fprintf(filePointer, "%d", student.age);

    fputc(DELIMITERCHAR, filePointer);
    fprintf(filePointer, "%s", GRADETAG);
    fputc(TAGDELIMITERCHAR, filePointer);
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

static void readCurrentInput(FILE* filePointer, char* currentInput, char delimiter) {
    // o delimiter vai variar, se estou lendo a TAG ou o conteudo

    char currentChar = fgetc(filePointer);
    int currentIndex = 0;

    while((currentChar != EOF) && (currentChar != delimiter)) {
        currentInput[currentIndex++] = currentChar;
        currentChar = fgetc(filePointer);
    }
    currentInput[currentIndex] = '\0';  // delimitar fim
}

Student readStudentDataInFile(FILE* filePointer) {

    Student student;
    int nFields = 0;
    char currentInput[50], currentTag[50];
    do {
        // ler a tag em currentTag.         delimiter = TAGDELIMITER
        readCurrentInput(filePointer, currentTag, TAGDELIMITERCHAR);
        // ler o conteudo em currentInput   delimiter = DELIMITER
        readCurrentInput(filePointer, currentInput, DELIMITERCHAR);
        // se leu o nome:
        if (strcmp(currentTag, NAMETAG) == 0) {
            strcpy(student.name, currentInput);
        } // se leu idade:
        else if (strcmp(currentTag, AGETAG) == 0) {
            student.age = atoi(currentInput);
        } // se leu nota:
        else if (strcmp(currentTag, GRADETAG) == 0) {
            student.grade = atoi(currentInput);
        }
        nFields++;
    }
    while(nFields < SIZE);

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
