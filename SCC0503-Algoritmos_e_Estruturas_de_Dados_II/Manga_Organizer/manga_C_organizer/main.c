#include <stdio.h>
#include "manga.h"


void menu() {

    printf("\n\n-------------------------------------\n");
    printf("----------- MANGA MANAGER -----------\n");
    printf("-------------------------------------\n");
    printf("Menu: \n");
    printf("1. Add Manga\n");
    printf("2. See Shelf\n");
    printf("3. Edit Manga\n");
    printf("4. Delete Manga\n");
    printf("5. Quint and Save\n");

}

int select() {
    int opt;
    scanf("%d", &opt);

    
    return opt;
}


int main() {
    int isRunning = 1;
    int n = 0;

    while(isRunning) {
        menu();
        int opt = select();
        switch (opt)
        {
        case 1:
            addManga(n);
            n++;
            break;

        case 2:
            searchManga();
            break;

        default:
            break;
        }
    }

}
