#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;
int N;
struct Klienty_banka {          
    string fio;
    int nomer;
    float summa;
    string data;
};
void Menu() {
    cout << "1) Ввод массива структур;\n"
        << "2) Вывод массива структур;\n"
        << "3) Сортировка массива структур;\n"
        << "4) Поиск в массиве структур по заданному параметру;\n"
        << "5) Изменение заданной структуры;\n"
        << "6) Удаление структуры из массива;\n"
        << "7) Вывод на экран массива структур;\n"
        << "8) Выход.\n";
    cin >> N;
}
void Set(Klienty_banka* (&Array), int& size) 
{
    if (size > 0) { 
        int i = size;
        Klienty_banka* TempArr = new Klienty_banka[size]; 
        for (int i = 0; i < size; i++)
            TempArr[i] = Array[i];
        cout << "Введите размер массива: ";
        cin >> size;
        size = size + i;
        Array = new Klienty_banka[size];
        for (int i = 0; i < size; i++)
             Array[i]=TempArr[i];
        delete[] TempArr;
        for (; i < size; i++) {
            cout << "ФИО:" << endl;
            cin >> Array[i].fio;
            cout << "Номер счета:" << endl;
            cin >> Array[i].nomer;
            cout << "Сумма на счете:" << endl;
            cin >> Array[i].summa;
            cout << "Дата:" << endl;
            cin >> Array[i].data;
            cout << endl;
        }
    }
    else 
    {
        cout << "Введите размер массива:";
        cin >> size;
        Array = new Klienty_banka[size];
        for (int i = 0; i < size ; i++) {
            cout << "ФИО:" << endl;
            cin >> Array[i].fio;
            cout << "Номер счета:" << endl;
            cin >> Array[i].nomer;
            cout << "Сумма на счете:" << endl;
            cin >> Array[i].summa;
            cout << "Дата:" << endl;
            cin >> Array[i].data;
            cout << endl;
        }
    }
    system("pause");
    system("cls");
}
void Get(Klienty_banka* (&Array), int& size) {
    cout << setiosflags(ios::left);
    cout << setw(10) << "ФИО:" << setw(16) << "Номер счета:" << setw(12) << "Сумма на счете: " << setw(15) << "Дата последнего изменения: " << endl;
    int i = 0;
    for (; i < size; i++) {
        cout << setiosflags(ios::left);
        cout << setw(10) << Array[i].fio;
        cout << setw(16) << Array[i].nomer;
        cout << setw(12) << Array[i].summa;
        cout << setw(15) << Array[i].data;
        cout << endl;
    }
    system("pause");
    system("cls");
}

void Sort1(Klienty_banka& NewArray, Klienty_banka& OldArray) {
    NewArray.fio = OldArray.fio;
    NewArray.nomer = OldArray.nomer;
    NewArray.summa = OldArray.summa;
    NewArray.data = OldArray.data;
}

void Sort(Klienty_banka* (&Array), int& size) 
{
    Klienty_banka Sort;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (Array[j].fio[0] < Array[i].fio[0]) {
                Sort1(Sort, Array[j]);
                Sort1(Array[j], Array[i]);
                Sort1(Array[i], Sort);
            }
        }
    }
}
void Search(Klienty_banka* (&Array), int& size)
{
    cout << "Поиск:\n"
        << "1) По ФИО\n"
        << "2) По номеру счета: \n";
    int m;
    cin >> m;
    if (m == 1) {
        cout << "Введите ФИО\n";
        string a;
        cin >> a;
        for (int i = 0; i < size; i++) {
            if (a == Array[i].fio) {
                cout << setiosflags(ios::left);
                cout << setw(10) << Array[i].fio;
                cout << setw(16) << Array[i].nomer;
                cout << setw(12) << Array[i].summa;
                cout << setw(15) << Array[i].data;
            }
        }
    }
    if (m == 2) {
        cout << "Введите номер счета\n";
        int a;
        cin >> a;
        for (int i = 0; i < size; i++) {
            if (a == Array[i].nomer) {
                cout << setiosflags(ios::left);
                cout << setw(10) << Array[i].fio;
                cout << setw(16) << Array[i].nomer;
                cout << setw(12) << Array[i].summa;
                cout << setw(15) << Array[i].data;
            }
        }
    }
    cout << endl;
}

void Editing(Klienty_banka* (&Array), int& size) {
    int n;
    cout << "Введите колонку которую хотите редактировать - " << endl;
    Get(Array, size);
    cin >> n;
    n--;
    if (n >= 0 && n < size) {

        system("cls");

        cout << "ФИО - ";
        cin >> Array[n].fio;
        cout << "Номер счета - ";
        cin >> Array[n].nomer;
        cout << "Сумма на счете - ";
        cin >> Array[n].summa;
        cout << "Дата - ";
        cin >> Array[n].data;
        cout << endl;
    }
    else cout << "---Неверное значение---" << endl;
}
void Delete(Klienty_banka* (&Array), int& size)
{
    system("cls");
    int n;
    cout << "Введите номер колонки от 1 до " << size << " который нужно удалить: ";
    cin >> n;
    n--; 
    if (n >= 0 && n < size) 
    {
        Klienty_banka* TempArr = new Klienty_banka[size]; 
        for (int i = 0; i < size; i++)
            TempArr[i] = Array[i]; 
        size--; 
        Array = new Klienty_banka[10];
        int j = 0;
        for (int i = 0; i <= size; i++) 
            if (i != n) { 
                Array[j] = TempArr[i];
                j++;
            }
        delete[] TempArr; 
        cout << "Данные удалены успешно!" << endl;
    }
    else cout << "Номер введён неверно!" << endl;
    system("pause");
    system("cls");
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size = 0;
    Klienty_banka* Spisok = new Klienty_banka[10];
    Menu();
    while  (N != 8) {
        switch (N)
        {
        case 1:
            system("cls");
            Set(Spisok, size);
            Menu();
            break;
        case 2:
            Get(Spisok, size);
            Menu();
            break;
        case 3:
            Sort(Spisok, size);
            system("pause");
            system("cls");
            Menu();
            break;
        case 4:
            system("cls");
            Search(Spisok, size);
            Menu();
            break;
        case 5:
            system("cls");
            Editing(Spisok, size);
            Menu();
            break;
        case 6:
            Delete(Spisok, size);
            Menu();
            break;
        case 7:
            system("cls");
            Get(Spisok, size);
            Menu();
            break;
        case 8:
            break;
        default:
            cout << "Ошибка";
            Menu();
            break;
        }
    }
    delete[] Spisok;
    return 0;
}
