#include "vertex.h"

int Vertex::counter = 1;

string Vertex::getValue() const
{
    return value;
}

Vertex *Vertex::getLeft() const
{
    return left;
}

void Vertex::setLeft(Vertex *value)
{
    left = value;
}

Vertex *Vertex::getRight() const
{
    return right;
}

void Vertex::setRight(Vertex *value)
{
    right = value;
}

int Vertex::getNummer() const
{
    return nummer;
}

void Vertex::setNummer(int value)
{
    nummer = value;
}

int Vertex::getCounter()
{
    return counter;
}

void Vertex::setCounter(int value)
{
    counter = value;
}








