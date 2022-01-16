#ifndef LABYRINTH_H
#define LABYRINTH_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Labyrinth
{

public:
    int row = 0, col;
    string path_to_lab = "/home/igor/Qt/projects/test_labyrinth/labyrinth.txt";

    void size_lab();
    void read_lab(char **lab);
    void show_lab(char **lab);

};

#endif // LABYRINTH_H
