#ifndef VERTEX_H
#define VERTEX_H
#include <iostream>
#include <string>

using namespace std;


class Vertex
{
private:
    bool living;
    string value;
    unsigned int gewicht;
    unsigned int indegree;
    unsigned int outdegree;
    unsigned int ordnungsnummer;
    unsigned int max;
    bool isVisited;
public:
    Vertex() {
       living = false;
       value = " ";
       gewicht = 0;
       indegree = 0;
       outdegree = 0;
       ordnungsnummer = 0;
       max = gewicht;
       isVisited = false;
    }
    Vertex(const string & p_value,int p_gewicht) {
        living = false;
        value = p_value;
        gewicht = p_gewicht;
        indegree = 0;
        outdegree = 0;
        ordnungsnummer = 0;
        max = gewicht;
        isVisited = false;
    }

    void printVertex() {
        cout << "("<< ordnungsnummer << ") " << value <<" =  " << gewicht << endl;
    }

    bool getLiving() const {
        return living;
    }
    string getValue() const {
        return value;
    }
    void setLiving(bool value) {
        living = value;
    }
    unsigned int getGewicht() const{
        return gewicht;
    }
    void setGewicht(unsigned int value) {
        gewicht = value;
    }
    void setValue(const string &p_value) {
        value = p_value;
    }
    unsigned int getIndegree() const{
        return indegree;
    }
    void setIndegree(unsigned int value) {
        indegree = value;
    }
    unsigned int getOutdegree() const {
        return outdegree;
    }
    void setOutdegree(unsigned int value) {
        outdegree = value;
    }
    bool getIsVisited() const {
        return isVisited;
    }
    void setIsVisited(bool value) {
        isVisited = value;
    }
    unsigned int getOrdnungsnummer() const {
        return ordnungsnummer;
    }
    void setOrdnungsnummer(unsigned int value){
        ordnungsnummer = value;
    }
    unsigned int getMax() const {
        return max;
    }
    void setMax(unsigned int value) {
        max = value;
    }
};

#endif // VERTEX_H
