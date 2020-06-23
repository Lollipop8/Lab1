#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <locale.h>
#include <iomanip>
using namespace std;


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string str[25];
    string str1[25];
    string text[25];
    string chisla[25];
    int Razmer[15];
    int N = 0, Size = 0;
    ifstream red;
    int h = 0, g = 0;
    red.open("File1.txt");
    if (!red.is_open())
        cout << "Файл не существует!" << endl;
    else {
        while (!red.eof()) {
            str1[N] = " ";
            getline(red, str1[N]);
            Razmer[N] = size(str1[N]);

            N++;
        }

    }
    red.close();
    N = 0;
    red.open("File1.txt");
    if (!red.is_open())
        cout << "Файл не существует!" << endl;
    else {
        int i = 0;
        while (!red.eof()) {
            str[N] = " ";
            red >> str[N];
            Size += size(str[N]);
            Size++;

            if (Size <= 32) {

                text[h] = str[N];
                h++;
            }
            else {

                chisla[g] = str[N];
                g++;
            }
            if (Razmer[i] <= Size) {
                Size = 0;
                text[h] = "n";
                h++;
                chisla[g] = "n";
                g++;

            }
            N++;
        }
        cout << endl << "Фаил был открыт и данные загружены" << endl;
    }
    red.close();

    ofstream taz;
    taz.open("File_text.txt");
    if (!taz.is_open()) { //Ошибка если файл не удалось открыть
        cout << "Ошибка!" << endl;
    }

    else {

        for (int i = 0; i < h; i++) {
            if (text[i] != "n")
                taz << text[i] << " ";
            if (text[i] == "n") {
                taz << endl;

            }
        }
    }
    taz.close();


    taz.open("File_Number.txt");
    if (!taz.is_open()) { //Ошибка если файл не удалось открыть
        cout << "Ошибка!" << endl;
    }

    else {

        for (int i = 0; i < N; i++) {
            if (chisla[i] != "n")
                taz << chisla[i] << " ";

            if (chisla[i] == "n") {
                taz << endl;

            }
        }
    }
    taz.close();
    return 0;

}
