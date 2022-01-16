#include "pathfinder.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

/*
 * Поиск пути методом в ширину (обход в ширину, breadth-first search)
 */
char **PathFinder::find_path(char **matrix, int row, int col)
{
    PathFinder start, point;
    queue<int> q;                               //очередь для найденных вершин
    stack<int> com_path;                        //хранение всех вершин по пути к выходу
    int graph[row][col];                        //граф
    unsigned short matrix_adj[100][100] = {0};  //матрица смежности с запасом
    bool used[row][col];                        //посещенные вершины
    bool exit_lab = false;                      //проверка наличия выхода
    int node = 2;                               //счетчик вершин начиная с 2

    //Пронумеруем все существующие вершины в лабиринте
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            switch (matrix[i][j]) {
                case 'S':
                    graph[i][j] = 1;            //начало лабиринта
                    start.x = i;
                    start.y = j;
                    break;
                case 'E':
                    graph[i][j] = -1;           //выход из лабиринта
                    break;
                case '0':
                    graph[i][j] = node++;       //счетчик вершин
                    break;
                case 'X':
                    graph[i][j] = 0;            //стены
                    break;
            }
        }
    }

    //Инициализируем матрицу смежности графа
    int dx[4]={0,0,1,-1};                       // соседние элементы от текущего по Х ...
    int dy[4]={1,-1,0,0};                       // ... по Y
    int edge, new_edge;                         //текущее ребро и найденное
    q.push(graph[start.x][start.y]);            //кладем в очередь стартовую вершину
    used[start.x][start.y] = true;              //и отмечаем посещенной

    //обход графа (поиск всех смежных вершин)
    while (!q.empty()) {                        //пока в очереди есть вершины
        edge = q.front();                       //достаем из очереди текущую вершину
        q.pop();                                //очищаем очередь
        for (int i = 1; i < row; i++) {         //запускаем поиск координат по всему ...
            for (int j = 1; j < col; j++) {     //... графу найденной вершины
                if (graph[i][j] == edge) {          // если нашли ...
                    for (int k = 0; k < 4; k++) {   //проверяем есть ли смежные вершины
                        point.x = i + dx[k];
                        point.y = j + dy[k];
                        new_edge = graph[point.x][point.y];
                        //обработка новой вершины
                        if (new_edge > 0 && !used[point.x][point.y]) {
                            used[point.x][point.y] = true;              //отмечаем посещенной
                            matrix_adj[edge][new_edge] = 1;             //отмечаем ребро в матрице смежности
                            q.push(new_edge);                           //сохраняем в очередь
                            com_path.push(new_edge);                    //сохраняем в стэк для восстановления пути
                        }
                        //найден выход, завершение поиска новых вершин
                        if (new_edge == -1) {
                            exit_lab = true;
                            cout << endl << "кратчайший путь найден!";
                            com_path.push(graph[i][j]);                 //сохраняем последнюю вершину перед выходом в стэк
                            while (!q.empty()) {                        //очищаем очередь
                                q.pop();
                            }
                            i = row;
                            j = col;
                            break;
                        }
                    }
                    i = row;
                    j = col;
                }
            }
        }
    }

    //Проверка наличия выхода из лабиринта
    if (exit_lab) {
            //восстанавление пути через проверку предка по матрице смежности
            vector<int> true_path;
            point.y = com_path.top();       //последняя вершина перед выходом - это координата Y в матрице смежности
            com_path.pop();
            true_path.push_back(point.y);   //запись реального пути

            while (!com_path.empty()) {     //пока стэк "общего" пути не пуст
                point.x = com_path.top();   //достаем по очереди вершины сохраненных путей и подставляем в координату Х
                com_path.pop();

                if (matrix_adj[point.x][point.y] == 1) {    // с помощью матрицы смежности находим из какой вершины был сделан ход
                    true_path.push_back(point.x);           // записываем в реальный путь
                    point.y = point.x;                      // перезаписываем координату Y
                }
            }
    //          Для просмотра вершин получившегося пути
    //        cout << endl << endl << "Кратчайший путь:" << endl;
    //        for (int i = true_path.size() - 1; i >= 0; i--) {
    //            cout << true_path[i] << " ";
    //        }

            //Вывод результата в лабиринте
            int k = true_path.size() - 1;
            while (!true_path.empty()) {
                for (int i = 1; i < row; i++) {
                    for (int j = 1; j < col; j++) {
                        if (graph[i][j] == true_path[k]) {
                            matrix[i][j] = '.';
                            true_path.pop_back();
                            i = row;
                            j = col;
                            k--;
                        }
                    }
                }
            }
    //иначе выхода из него нет
    } else {
        cout << endl << "Лабиринт обвалился! Возможности выйти нет!";
    }

        return this->matrix_path = matrix;
}

