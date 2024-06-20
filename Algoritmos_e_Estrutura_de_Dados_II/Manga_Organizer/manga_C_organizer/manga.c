#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manga.h"
#define PRIMARYINDEXFILE "primary.txt"

static Manga mangaPadrao(int i) {
    Manga manga;

    if (i == 1) {

        strcpy(manga.isbn, "isbnteste");
        strcpy(manga.title, "titleTeste");
        strcpy(manga.author, "authorTeste");
        manga.startYear = 1;
        manga.endYear = 2;
        strcpy(manga.gender, "genderTeste");
        strcpy(manga.magazine, "magazineTeste");
        strcpy(manga.editor, "editorTeste");
        manga.editionYear = 3;
        manga.totalVolumes = 10;
        manga.purchasedVolumes = 4;

    } else if (i == 2) {

        strcpy(manga.isbn, "isbnteste2");
        strcpy(manga.title, "titleTeste2");
        strcpy(manga.author, "authorTeste2");
        manga.startYear = 10;
        manga.endYear = 20;
        strcpy(manga.gender, "genderTeste2");
        strcpy(manga.magazine, "magazineTeste2");
        strcpy(manga.editor, "editorTeste2");
        manga.editionYear = 30;
        manga.totalVolumes = 100;
        manga.purchasedVolumes = 40;
    } else {

        strcpy(manga.isbn, "isbnteste");
        strcpy(manga.title, "titleTeste");
        strcpy(manga.author, "authorTeste");
        manga.startYear = 1;
        manga.endYear = 2;
        strcpy(manga.gender, "genderTeste");
        strcpy(manga.magazine, "magazineTeste");
        strcpy(manga.editor, "editorTeste");
        manga.editionYear = 3;
        manga.totalVolumes = 10;
        manga.purchasedVolumes = 4;
    }

    return manga;
}

void initFile() {
    FILE *fp = fopen(REGISTERSFILE, "w");
    fclose(fp);
}

static Manga readMangaFromInput() {
    Manga manga;

    printf("==     ADDING NEW MANGA    ==\n");
    printf("== Enter the details below ==\n");

    printf("\nISBN: ");
    scanf("%s", manga.isbn);
    printf("\nTítulo: ");
    scanf("%s", manga.title);
    printf("\nAutor: ");
    scanf("%s", manga.author);
    printf("\nStart year: ");
    scanf("%d", &manga.startYear);
    printf("\nEnd year: ");
    getchar();
    scanf("%d", &manga.endYear);
    printf("\nGender: ");
    scanf("%s", manga.gender);
    printf("\nMagazine: ");
    scanf("%s", manga.magazine);
    printf("\nEditor: ");
    scanf("%s", manga.editor);
    getchar();
    printf("\nEdition year: ");
    scanf("%d", &manga.editionYear);
    printf("\nTotal volumes: ");
    scanf("%d", &manga.totalVolumes);
    printf("\nPurchased volumes: ");
    scanf("%d", &manga.purchasedVolumes);
    
    return manga;
}

static void writeMangaInFile(Manga manga, FILE* filePointer) {
    printf("entrei");
    fwrite(&manga, sizeof(Manga), 1, filePointer);

}

static int fileExist() {
    FILE *fileExist = fopen(REGISTERSFILE, "r");
    if (fileExist) {
        printf("\n\no arquivo ja existe!\n\n");
        return 1;
    }
    else {
        printf("\n\no arquivo nao existe!\n\n");
        return 0;
    }
    fclose(fileExist);
}

static int PFfileExist() {
    FILE *fileExist = fopen(PRIMARYINDEXFILE, "r");
    if (fileExist) {
        printf("\n\no arquivo de index ja existe!\n\n");
        return 1;
    }
    else {
        printf("\n\no arquivo de index nao existe!\n\n");
        return 0;
    }
    fclose(fileExist);
}

static int PFgetLocation(char* isbn, int n) {
    FILE *fp = fopen(PRIMARYINDEXFILE, "r");
    PrimaryIndex *array = NULL;
    array = (PrimaryIndex *)malloc(n * sizeof(PrimaryIndex));
    int index = 0;
    //fread(&manga, sizeof(Manga), 1, fp);

    while(fread(&array[index], sizeof(PrimaryIndex), 1, fp)) {
        if (strcmp(array[index].isbn, isbn) > 0) {
            return index;
            // refazer toda a file
            // quando chegar no index, escrever novo index
            // escrever o resto
        }
    }
    fclose(fp);

    return 1;
}

static void PFwriteIndex(FILE* writer, PrimaryIndex pi, int n) {
    printf("COMPLEX ADD");
    FILE *reader = fopen(PRIMARYINDEXFILE, "r");
    PrimaryIndex *array = (PrimaryIndex*)malloc(n * sizeof(PrimaryIndex));
    int x = 0;
    while(fread(&array[x], sizeof(PrimaryIndex), 1, reader)) {
        if (strcmp(array[x].isbn, pi.isbn) > 0) {
            break;
        }
        x++;
    }

    array[x] = pi;
    
    while(x < n) {
        strcmp(array[x].isbn, pi.isbn);
        x++;
    }

    // tenho todos no array

    for (int i = 0; i < n; i++) {
        printf("%d\na", array[i].offset);
    }
    fclose(reader);

}

static void PFsimpleWriteIndex(FILE* fp, PrimaryIndex pi, int n) {
    printf("SIMPLE ADD");
    fwrite(&pi, sizeof(PrimaryIndex), 1, fp);

}

static void printManga(Manga manga) {
    printf("\n\nisbn = %s\n", manga.isbn);
    printf("title = %s\n", manga.title);
    printf("author = %s\n", manga.author);
    printf("startYear = %d\n", manga.startYear);
    printf("endYear = %d\n", manga.endYear);
    printf("gender = %s\n", manga.gender);
    printf("magazine = %s\n", manga.magazine);
    printf("editor = %s\n", manga.editor);
    printf("editionYear = %d\n", manga.editionYear);
    printf("totalVolumes = %d\n", manga.totalVolumes);
    printf("purchasedVolumes = %d\n", manga.purchasedVolumes);

}


void addManga(int n) {
    // trocar por escrever do inicio
    Manga manga = readMangaFromInput();

    if (fileExist()) {
        printManga(manga);
        FILE *fp = fopen(REGISTERSFILE, "a");
        writeMangaInFile(manga, fp);
        printf("\n\nTESTE %s\n\n", manga.isbn);
        fclose(fp);
    }
    else {
        printManga(manga);
        FILE *fp = fopen(REGISTERSFILE, "w");
        writeMangaInFile(manga, fp);
        printf("TESTEEEEEEEEE\n\n");
        fclose(fp);
    }
    // adicionar ao arquivo de indices primarios:
    printf("adicionei o arquivo\n");
    PrimaryIndex pi;
    strcpy(pi.isbn, manga.isbn);
    pi.offset = n * 180;
        
    if (PFfileExist()) {
        // vai receber PI
        FILE *fp = fopen(PRIMARYINDEXFILE, "a");
        PFwriteIndex(fp, pi, n);
        fclose(fp);
    }
    else {
        FILE *fp = fopen(PRIMARYINDEXFILE, "w");
        PFsimpleWriteIndex(fp, pi, n);
        fclose(fp);
    }
    
}

static Manga readMangaFromFile(FILE* fp) {
    Manga manga;
    fread(&manga, sizeof(Manga), 1, fp);
    return manga;
}

void searchManga() {


    FILE *fp = fopen(REGISTERSFILE, "r");


    Manga manga = readMangaFromFile(fp);
    printf("\n\narquivo existia, eu li o manga %s", manga.title);


    fseek(fp, 180, SEEK_SET);

    manga = readMangaFromFile(fp);        
    printf("\n\narquivo existia, eu li o manga %s", manga.title);
    fclose(fp);

}
