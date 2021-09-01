#ifndef VERTEX_H
#define VERTEX_H
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


class Vertex
{
    int nummer;
    static int counter;

    Vertex * left;

    string value;

    Vertex * right;


public:
    Vertex(Vertex * p_left = nullptr, const string & p_value = "", Vertex * p_right = nullptr)
     : nummer(counter++), left(p_left), value(p_value), right(p_right) {}

    string getValue() const;
    Vertex *getLeft() const;
    void setLeft(Vertex *value);
    Vertex *getRight() const;
    void setRight(Vertex *value);
    int getNummer() const;
    void setNummer(int value);
    static int getCounter();
    static void setCounter(int value);
};



#endif // VERTEX_H
