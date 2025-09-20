#define REGISTERSFILE "registers.txt"

typedef struct {
    char isbn[40];
    char title[40];
    char author[20];
    int startYear;
    int endYear;
    char gender[20];
    char magazine[20];
    char editor[20];
    int editionYear;
    int totalVolumes;
    int purchasedVolumes;
    // total = 180 bytes
} Manga;

typedef struct {
    char isbn[40];
    int offset;
} PrimaryIndex;


void initFile();
void addManga(int n);
void searchManga();
