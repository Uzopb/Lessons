#include "Labyrinth.h"
#include <string>

using namespace std;

/*
 * Размер исходного массива в файле с лабиринтом
 */
void Labyrinth::size_lab()
{
    //int row = 0, col;
    ifstream file;
    //разобраться как сделать путь относительным???
    file.open(path_to_lab);

    if (!file.is_open()) {
        cout << "File not opened\n";
    }

    //Считываем кол-во строк и их длину из файла лабиринт
    for (string str; file >> str; ) {
        this->col = str.size();
        this->row++;
    }

    file.clear();   //сброс флагов ошибок
    file.seekg(0);  // возврат в начало потока
}

/*
 * Считывание посимвольно из файла с лабиринтом
 * и запись в новый массив
 */
void Labyrinth::read_lab(char **matrix)
{
    ifstream file;
    //разобраться как сделать путь относительным???
    file.open(path_to_lab);

    if (!file.is_open()) {
        cout << "File not opened\n";
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            char in_data;
            file >> in_data;
            matrix[i][j] = in_data;
        }
    }
}

/*
 * Вывод нового массива - для отладки
 */
void Labyrinth::show_lab(char **lab)
{    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << lab[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

