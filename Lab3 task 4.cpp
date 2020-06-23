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
    string str[15];
    int N = 0;
    ifstream red;
    red.open("File.txt");
    if (!red.is_open())
        cout << "Файл не существует!" << endl;
    else {
        while (!red.eof()) {
            str[N] = " ";
            getline(red, str[N]);
            cout << str[N] << endl;

            N++;
        }
        cout << endl << "Файл был открыт и данные загружены" << endl;
    }
    red.close();
    ofstream taz;
    taz.open("File.txt", ofstream::app);
    if (!taz.is_open()) { //Ошибка если файл не удалось открыть
        cout << "Ошибка!" << endl;
    }
    else {
        taz << endl;
        for (int i = 0; i < N--; i++) {
            taz << setw(50) << str[i];
            taz << endl;
        }
    }
    red.close();
    return 0;

}

