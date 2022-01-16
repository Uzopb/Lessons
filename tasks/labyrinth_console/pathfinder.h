#ifndef PATHFINDER_H
#define PATHFINDER_H


class PathFinder
{
public:

    char **find_path(char **matrix, int row, int col);

    char **matrix_path;

    int x, y;   //x - row, y - col

};

#endif // PATHFINDER_H
