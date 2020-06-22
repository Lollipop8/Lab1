#include <iostream>
#include <Windows.h>
#include <fstream>
using namespace std;
int Number;

void Save(int* (&N), int& size) //Сохранение файла
{
    ofstream taz;
    taz.open("File.txt", ofstream::app); //Дополнение "ofstream::app" позволяет дописывать записи, без изменнения старых
    if (!taz.is_open()) {
        cout << "Ошибка!" << endl;
    }
    else {
        for (int i = 0; i < size; i++) {
            taz << N[i] << endl;
        }
    }
    taz.close();

}

void Download(int* (&N), int& size)
{
    size = 0;
    ifstream read;
    read.open("File.txt");
    if (!read.is_open())
        cout << "Файл не существует!" << endl;
    else {
        int i = 0, q;
        while (!read.eof()) {
            read >> q;
            size++;
        }
        size--;
        N = new int[size];
        read.close();
        read.open("File.txt");
        if (!read.is_open())
            cout << "Файл не существует!" << endl;
        else {
            while (!read.eof()) //Это условие на чтение целого слова(полной цифры)
            {

                if ((i + 2) % 2 == 0) {
                    read >> N[i];

                }
                if ((i + 1) % 2 == 0) {
                    read >> N[i];

                }
                i++;
            }

            cout << "Фаил был открыт и данные загружены" << endl;
        }
    }
    read.close();
}
void Sort(int* (&N), int& size) {
    int temp; // временная переменная для обмена элементов местами

    // Сортировка массива пузырьком
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (N[j] > N[j + 1]) {
                // меняем элементы местами
                temp = N[j];
                N[j] = N[j + 1];
                N[j + 1] = temp;
            }
        }
    }
}

void Get(int* (&N), int& size) {
    for (int i = 0; i < size; i++) {
        cout << N[i] << endl;
    }
}
void Menu() {
    cout << "Меню ввода:\n"
        << "(1) - Выход\n"
        << "(2) - Чтение из файла данных\n"
        << "(3) - Сортировка + Сохранение в файл\n"
        << "(4) - Вывод\n"
        << "Ввод - ";
    cin >> Number;
}

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size = 0;
    int* N = new int[size];
    Menu();
    while (Number != 1) {
        switch (Number)
        {
        case 1:
            break;
        case 2:
            system("cls");
            Download(N, size);
            Get(N, size);
            system("pause");
            system("cls");
            Menu();
            break;
        case 3:
            system("cls");
            Sort(N, size);
            Save(N, size);
            Get(N, size);
            system("pause");
            system("cls");
            Menu();
            break;
        case 4:
            system("cls");
            Get(N, size);
            system("pause");
            system("cls");
            Menu();
            break;
        default:
            cout << "Ошибка" << endl;
            Menu();
            break;
        }
    }
    delete[] N;
    return 0;
}
