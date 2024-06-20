#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <sstream>
#include <vector>

using namespace std;

class Manga {
    public:
    string isbn;
    string title;
    string autor;
    int bgYear;
    int fnYear;
    string genre;
    string magazine;
    string editor;
    int editionYear;
    int totalVol;
    int adqVol;
    array<int, 120> volList;

    Manga() = default;
    Manga(string isbn, string title, string autor, int bgYear, int fnYear, string genre, string magazine,
    string editor, int editionYear, int totalVol, int adqVol, array<int, 120> volList) : isbn(isbn), title(title), autor(autor), bgYear(bgYear), fnYear(fnYear), genre(genre), magazine(magazine), editor(editor), editionYear(editionYear), totalVol(totalVol), adqVol(adqVol), volList(volList) {}

};

class mangaManager {
private:
Manga manga;

public:
void addManga(Manga &manga, int rrn){
    
    if (rrn > 0) {
        ofstream mangaFile ("mangas.txt", ios::app);
        if (mangaFile.is_open()){
            mangaFile << manga.isbn << '|' << manga.title << '|' << manga.autor << '|' << manga.bgYear << '|' << manga.fnYear << '|' << manga.genre << '|' << 
            manga.magazine << '|' << manga.editor << '|' << manga.editionYear << '|' << manga.totalVol << '|' << manga.adqVol << '|';
            for (int i = 0; i < manga.adqVol; i++) {
                mangaFile << manga.volList[i];
                if (i != manga.adqVol-1) {
                    mangaFile << ", ";
                }   
            }
        mangaFile << "|\n";
        }
    mangaFile.close();
    }

    else {
        ofstream mangaFile ("mangas.txt");
        if (mangaFile.is_open()){
            mangaFile << manga.isbn << '|' << manga.title << '|' << manga.autor << '|' << manga.bgYear << '|' << manga.fnYear << '|' << manga.genre << '|' << 
            manga.magazine << '|' << manga.editor << '|' << manga.editionYear << '|' << manga.totalVol << '|' << manga.adqVol << '|';
            for (int i = 0; i < manga.adqVol; i++) {
                mangaFile << manga.volList[i];
                if (i != manga.adqVol-1) {
                    mangaFile << ", ";
                }   
            }
        mangaFile << "|\n";
        }
    mangaFile.close();
    }    
}

void savePrimaryIndex(Manga &manga, int rrn) {
   if (rrn > 0) {
    ofstream pIndex ("mangaPrimaryIndex.txt", ios::app);
    if (pIndex.is_open()) {
        pIndex << manga.isbn << "|" << rrn << "|" << "\n";
        }
    pIndex.close();
   }

   else {
    ofstream pIndex ("mangaPrimaryIndex.txt");
    if (pIndex.is_open()) {
        pIndex << manga.isbn << "|" << rrn << "|" << "\n";
        }
    pIndex.close();
   } 
}

void saveSecondaryIndex(Manga &manga, int rrn) {
   if (rrn > 0) {
    ofstream sIndex ("mangaSecondaryIndex.txt", ios::app);
    if (sIndex.is_open()) {
        sIndex << manga.title << manga.isbn << "\n";
        }
    sIndex.close();
    }

    else {
    ofstream sIndex ("mangaSecondaryIndex.txt");
    if (sIndex.is_open()) {
        sIndex << manga.title << manga.isbn << "\n";
        }
    sIndex.close();
    }
}

void showManga(){
string isbn, title, autor, genre, magazine, editor, bgYear, fnYear, editionYear, totalVol, adqVol, volList;
string line;
ifstream mangaStream("mangas.txt");
    if(!mangaStream.is_open()){
        return;
    }

    while (getline(mangaStream, line)) {
        std::stringstream ss(line);
        getline(ss, isbn, '|');
        getline(ss, title, '|');
        getline(ss, autor, '|');
        getline(ss, bgYear, '|');
        getline(ss, fnYear, '|');
        getline(ss, genre, '|');
        getline(ss, magazine, '|');
        getline(ss, editor, '|');
        getline(ss, editionYear, '|');
        getline(ss, totalVol, '|');
        getline(ss, adqVol, '|');
        getline(ss, volList, '|');

    cout << "\nISBN: " << isbn << "\nTitulo: " << title << "\nAutor(es): " << autor << "\nAno de inicio: " << bgYear << "\nAno de fim: " << fnYear << "\nGenero: " << genre << "\nRevista: " <<
    magazine << "\nEditora: " << editor << "\nAno da edicao: " << editionYear << "\nQuantidade total de volumes: " << totalVol << "\nQuantidade de volumes adquiridos: " << adqVol << 
    "\nLista de volumes adquiridos: " << volList << "\n\n";

    }
    
    mangaStream.close();    
    }

void listMangas(){
string line, title, temp;
int i = 1;
ifstream mangaStream("mangas.txt");
    if (mangaStream.is_open()) {
        while (getline(mangaStream, line)){
            std::stringstream ss(line);
            getline(ss, temp, '|');
            getline(ss, title, '|');
            getline(ss, temp, '|');
            getline(ss, temp, '|');
            getline(ss, temp, '|');
            getline(ss, temp, '|');
            getline(ss, temp, '|');
            getline(ss, temp, '|');
            getline(ss, temp, '|');
            getline(ss, temp, '|');
            getline(ss, temp, '|');
            getline(ss, temp, '|');

            cout << i << ". " << title << '\n';
            i++;
        }
    }
            cout << '\n';

mangaStream.close(); 
}

string searchManga(string title) {
string line;
ifstream secIndex;
    secIndex.open("mangaSecondaryIndex.txt");
        if (!secIndex.is_open()) {
            return "Erro";
        }
    while (getline(secIndex, line)) {    
        if (line.find(title) == 0) {
            line.erase(0, line.find_last_of(title)+1);
            secIndex.close();
            return line;
        }   
    }
return " ";
}

int findRRN(string isbn){
int rrn;
string line, strRrn;
ifstream primIndex;
    primIndex.open("mangaPrimaryIndex.txt");
        if (!primIndex.is_open()) {
            return -1;
        }
    while (getline(primIndex, line)) {    
        std::stringstream ss(line);
        if (line.find(isbn) == 0) {
            getline(ss, strRrn, '|');
            getline(ss, strRrn, '|');
            rrn = stoi(strRrn);
            //cout << rrn << '\n';
            primIndex.close();           
            return rrn;
        }   
    }
return 0;
}

vector<string> copyMangas(){
ifstream mangaFile;
vector<string> lines;
string line;
    mangaFile.open("mangas.txt");
    if (mangaFile.is_open()) {
        while (getline(mangaFile, line)) {
            lines.push_back(line);
        }
    }  

    mangaFile.close();

return lines;
}

vector<string> copypIndex(){
ifstream pIndex;
vector<string> lines;
string line;
    pIndex.open("mangaPrimaryIndex.txt");
    if (pIndex.is_open()) {
        while (getline(pIndex, line)) {
            lines.push_back(line);
        }
    }  

    pIndex.close();

return lines;
}

vector<string> copysIndex(){
ifstream sIndex;
vector<string> lines;
string line;
    sIndex.open("mangaSecondaryIndex.txt");
    if (sIndex.is_open()) {
        while (getline(sIndex, line)) {
            lines.push_back(line);
        }
    }  

    sIndex.close();

return lines;
}



void deleteManga(int rrn){
string line;
vector<string> copym = copyMangas();
vector<string> copyp = copypIndex();
vector<string> copys = copysIndex();
ofstream mangaFile("mangas.txt");
ofstream pIndex("mangaPrimaryIndex.txt");
ofstream sIndex("mangaSecondaryIndex.txt");
    if (mangaFile.is_open() && pIndex.is_open() && sIndex.is_open()) {
        for (int i = 0; i < copym.size(); i++) {
            if (i != rrn) {
                mangaFile << copym[i] << '\n';
                sIndex << copys[i] << '\n'; 
            }
            if (i != rrn && i < rrn) {
                pIndex << copyp[i] << '\n';
            }
            else if(i != rrn && i > rrn){
                copyp[i].erase(copyp[i].find_first_of('|')+1, copyp[i].find_last_of('|'));
                pIndex << copyp[i] << i-1 << '|' << '\n';
            }
            
        }
    }

   mangaFile.close();
   pIndex.close();
   sIndex.close();
   cout << "Operacao concluida com sucesso!\n"; 

return;
}

void editManga(Manga &manga, int rrn){
string line;
vector<string> copym = copyMangas();
vector<string> copyp = copypIndex();
vector<string> copys = copysIndex();
ofstream mangaFile("mangas.txt");
ofstream pIndex("mangaPrimaryIndex.txt");
ofstream sIndex("mangaSecondaryIndex.txt");
    if (mangaFile.is_open() && pIndex.is_open() && sIndex.is_open()) {
        for (int i = 0; i < copym.size(); i++) {
            if (i != rrn) {
                mangaFile << copym[i] << '\n';
                pIndex << copyp[i] << '\n';
                sIndex << copys[i] << '\n'; 
            }

            else {
                mangaFile << manga.isbn << '|' << manga.title << '|' << manga.autor << '|' << manga.bgYear << '|' << manga.fnYear << '|' << manga.genre << '|' << 
                manga.magazine << '|' << manga.editor << '|' << manga.editionYear << '|' << manga.totalVol << '|' << manga.adqVol << '|';
                for (int i = 0; i < manga.adqVol; i++) {
                    mangaFile << manga.volList[i];
                    if (i != manga.adqVol-1) {
                        mangaFile << ", ";
                    }   
                }
                mangaFile << "|\n";

                pIndex << manga.isbn << "|" << rrn << "|" << "\n";
                sIndex << manga.title << manga.isbn << "\n";
            }
        }
    }

   mangaFile.close();
   pIndex.close();
   sIndex.close();
   cout << "Operacao concluida com sucesso!\n"; 

return;
}

};

Manga getManga();
void showMenu();

int main (){
    mangaManager manager;
    Manga manga;
    Manga newmanga;
    int option, size, mangarrn, confirm;
    int rrn = 0;
    string title;
    title.reserve(60);
    string isbn;
    isbn.reserve(19);

      do {
            showMenu();
            std::cin >> option;
            cin.ignore();
            switch (option) {
                case 1:
                manga = getManga();
                manager.addManga(manga, rrn);
                manager.savePrimaryIndex(manga, rrn);
                manager.saveSecondaryIndex(manga, rrn);
                rrn++;
                    break;
              
                case 2:
                manager.showManga();
                    break;    

                case 3:{  
                manager.listMangas();           
                cout << "Insira o titulo do manga que voce deseja editar: \n";
                cin.ignore();
                getline(cin, title);  
                isbn = manager.searchManga(title);
                mangarrn = manager.findRRN(isbn);
                newmanga = getManga();
                manager.editManga(newmanga, mangarrn);                          
                 } break;
                
                case 4:
                manager.listMangas(); 
                cout << "Insira o titulo do manga que voce deseja deletar: \n";
                cin.ignore();
                getline(cin, title);
                cout << "Voce tem certeza de que quer deletar esse manga?\n1. Sim\n2. Nao\n";
                cin >> confirm;
                switch (confirm) {
                case 1:
                isbn = manager.searchManga(title);
                mangarrn = manager.findRRN(isbn);
                manager.deleteManga(mangarrn);
                rrn--;
                    break;
                
                case 2:
                cout << "Operacao cancelada.\n";
                    break;
                }
                    break;
                
                case 5:
                    break;      

                default:
                    std::cout << "Opcao nao existe! Tente novamente \n";  
            }
       } while (option != 5);

 return 0;   
}

void showMenu(){

    std::cout << "-------------------------------------\n";
    std::cout << "----------- MANGA MANAGER -----------\n";
    std::cout << "-------------------------------------\n";

    std::cout << "Menu: \n";
    std::cout << "1. Adicionar manga \n";
    std::cout << "2. Ver mangas \n";
    std::cout << "3. Editar manga \n";
    std::cout << "4. Deletar manga \n";
    std::cout << "5. Sair e salvar arquivo \n";

}

Manga getManga(){
    // receber inputs do usuário e retorna um manga

    string isbn, title, autor, genre, magazine, editor;
    int bgYear, fnYear, editionYear, totalVol, adqVol;
    array<int, 120> volList;

        cout << "Insira o ISBN do manga: \n";
        getline(std::cin, isbn);
        cout << "Insira o titulo do manga: \n";
        getline(std::cin, title);
        std::cout << "Insira o nome do autor (ou autores) do manga: \n";
        getline(std::cin, autor);
        std::cout << "Insira o ano de inicio do manga: \n";
        std::cin >> bgYear;
        std::cout << "Insira o ano de termino do manga (caso nao esteja finalizado, insira o ano da ultima edicao lancada): \n";
        std::cin >> fnYear;
        std::cout << "Insira o genero do manga: \n";
        std::cin.ignore();
        getline(std::cin, genre);
        std::cout << "Insira em qual revista o manga e/foi publicado: \n";
        getline(std::cin, magazine);
        std::cout << "Insira a editora do manga: \n";
        getline(std::cin, editor);
        std::cout << "Insira o ano da edicao do manga: \n";
        std::cin >> editionYear;
        std::cout << "Insira o numero total de volumes do manga: \n";
        std::cin >> totalVol;
        std::cout << "Insira quantos volumes do manga voce adquiriu: \n";
        std::cin >> adqVol;
        std::cout << "Liste o numero do(s) volume(s) do manga que voce adquiriu: \n"; 
        for (int i = 0; i < adqVol; i++) {
            cin >> volList[i];
        }
        cin.ignore();

return Manga(isbn, title, autor, bgYear, fnYear, genre, magazine, editor, editionYear, totalVol, adqVol, volList);
}