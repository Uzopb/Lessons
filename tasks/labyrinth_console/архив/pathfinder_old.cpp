#include "pathfinder.h"
#include <vector>
#include<queue>

using namespace std;

char **PathFinder::find_path(char **matrix, int row, int col)
{
    PathFinder start, point;
    int graph[row*10][col*10];  //матрица смежности
    int distance[100];    //кратчайший путь
    int vizited_node[100]; //посещенные вершины
    int temp, min_index, min;
    int start_index = 0, k = 1;
    vector<int> start_node;
    vector<int> finish_node;
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};

    //Определение координат начальной и конечной точек
//    for (int i = 0; i < row; i++) {
//        for (int j = 0; j < col; j++) {
//            switch (matrix[i][j]) {
//                case 'S':
//                    graph[i][j] = 0;
//                    break;
//                case 'E':
//                    graph[i][j] = 1000;
//                    break;
//                case '0':
//                    graph[i][j] = k++;
//            }
//            cout << graph[i][j];
//        }
//    }

    //обход вершин
//    queue<int> q;

//    q.push(start);
//    for (int i = start_node[0]; i < row; i++) {
//        for (int j = start_node[1]; j < col; j++) {


//        }
//    }


    //восстанавливаем путь из стэка с помощью проверки предка по матрице смежности
    vector<int> true_path;
    int prev_edge = temp_path.top(); //берем последнюю вершину перед выходом
    temp_path.pop();
    true_path.push_back(prev_edge);

    while (!temp_path.empty()) {
        int prev_true_path = prev_edge;
        int prev_edge = temp_path.top(); //берем последнюю вершину перед выходом
        temp_path.pop();

        if (matrix_adj[prev_edge][prev_true_path] == 1) {
            true_path.push_back(prev_edge);
        }
    }

    cout << endl;
    for (size_t i = 0; i < true_path.size(); i++) {
        cout << true_path[i] << " ";
    }







