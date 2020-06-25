#include <iomanip>
#include <fstream>
#include <Windows.h>
#include <iostream>
using namespace std;
int Number;

struct state {
    string name, capital, language;
    double population;
    int area;
    string currency, political_system, president;
};

void Menu() { //Меню выбора функций
    cout << "Меню ввода:\n"
        << "(0) - Выход\n"
        << "(1) - Сохранить данные в бинарном виде \n"
        << "(2) - Считать данные с файла\n"
        << "(3) - Удаление выбранного элемента\n"
        << "(4) - Добавление элемента\n"
        << "Ввод - ";
    cin >> Number;
}

void Safe(state* (&states), int& N) {
    ofstream taz;
    taz.open("File.txt");
    if (!taz.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
    }
    else {
        cout << "Файл открыт" << endl;
        for (int i = 0; i < N; i++) {
            taz.write((char*)&states[i], sizeof(state));
        }
    }
    taz.close();
}

void vivod(state* (&states), int& N) { //Обычный вывод всех данных по порядку

    cout << setiosflags(ios::left);
    cout << setw(10) << "#" << setw(10) << "Страна" << setw(16) << "Город" << setw(16) << "Язык " << setw(16) << "Население " << setw(16) << "Площадь " << setw(20) << "Денежная единица" << setw(20) << "Политическая система " << setw(15) << "Президент" << endl;
    for (int i = 0; i < N; i++) {

        cout << setw(10) << i + 1;
        cout << setw(10) << states[i].name;
        cout << setw(16) << states[i].capital;
        cout << setw(16) << states[i].language;
        cout << setw(16) << states[i].population;
        cout << setw(16) << states[i].area;
        cout << setw(20) << states[i].currency;
        cout << setw(20) << states[i].political_system;
        cout << setw(16) << states[i].president;
        cout << endl;

    }
}

void Dowload(state* (&states), int& N) {
    int i = 0;
    state pn;
    ifstream taz;
    taz.open("File.txt");
    if (!taz.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
    }
    else {
        while (taz.read((char*)&pn, sizeof(state))) {
            i++; //Узнать сколько памяти выделять под структуру
        }
    }
    taz.close();
    N = i;
    states = new state[N];//Выделение памяти
    i = 0;

    taz.open("File.txt");
    if (!taz.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
    }
    else {
        cout << "Файл открыт" << endl;
        while (taz.read((char*)&pn, sizeof(state))) {
            states[i] = pn;//Запись из файла в структуру
            i++;
        }
    }
    taz.close();
    vivod(states, N);
}

void Delete(state* (&states), int& N)
{
    system("cls");
    int n;
    cout << "Введите номер колонки от 1 до " << N << " который нужно удалить: ";
    cin >> n;
    system("cls");
    n--; // массив начинается с нуля, значит -1
    if (n >= 0 && n < N) {// Проверяем на наличие введённого элемента
        state* TempArr = new state[N];// Временный массив
        for (int i = 0; i < N; i++)
            TempArr[i] = states[i];  // Скопировали элементы из основного массива в временный
        N--; // Уменьшаем кол-во
        states = new state[N];
        int j = 0;
        for (int i = 0; i <= N; i++) { // Записываем в основной массив только те элементы
            if (i != n) { // Которые не равны n
                states[j] = TempArr[i];
                j++;
            }

        }
        delete[] TempArr; // Очищаем память
        cout << "Данные удалены успешно!" << endl;
    }
    else cout << "Номер введён неверно!" << endl;

    system("pause");
    system("cls");
}

void V_vod(state* (&states), int& N) //Ввод данных
{
    int i = N;

    state* TempArr = new state[N];
    for (int a = 0; a < i; a++) { //Копируем данные во временный массив
        TempArr[a] = states[a];
    }

    N++;
    states = new state[N];//Расширяем динамический массив
    for (int a = 0; a < i; a++) { //Записываем старые данные в новый расширенный массив 
        states[a] = TempArr[a];
    }
    delete[]TempArr; //Освобождаем память
    cout << "Страна" << endl;
    cin >> states[i].name;
    cout << "Город" << endl;
    cin >> states[i].capital;
    cout << "Язык" << endl;
    cin >> states[i].language;
    cout << "Население" << endl;
    cin >> states[i].population;
    cout << "Площадь" << endl;
    cin >> states[i].area;
    cout << "Денежная единица" << endl;
    cin >> states[i].currency;
    cout << "Политическая система" << endl;
    cin >> states[i].political_system;
    cout << "Президент" << endl;
    cin >> states[i].president;
    ofstream taz;
    taz.open("File.txt", ofstream::app); //Дополнение "ofstream::app" позволяет дописывать записи, без изменения старых
    if (!taz.is_open()) {
        cout << "Ошибка!" << endl;
    }
    else {
        taz.write((char*)&states[i], sizeof(state));
    }
    cout << endl;
    taz.close();
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N = 2;
    state* states = new state[N]{
{"Belarus", "Minsk", "Belarusian", 9.485, 207595, "Beloryski_rubl", "President", "Lykashenko"},
{"Rossia", "Moskov", "Russian", 144.5, 17100000, "Russki_rubl", "Federativ", "Putin"},
    };
    Safe(states, N);
    Menu();
    while (Number != 0) {
        switch (Number)
        {
        case 1:
            Safe(states, N);
            Menu();
            break;
        case 2:
            Dowload(states, N);
            Menu();
            break;
        case 3:
            Delete(states, N);
            Safe(states, N);
            Menu();
            break;
        case 4:
            V_vod(states, N);
            Menu();
            break;
        default:
            cout << "Ошибка" << endl;
            Menu();
            break;
        }
    }
    return 0;
    delete[] states;
}
