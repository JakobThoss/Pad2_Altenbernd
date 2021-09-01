#ifndef GRAPH_H
#define GRAPH_H
#include <cstdlib>
#include <string>
#include <climits>
#include <limits>
#include <iostream>

using namespace std;

const double MAXFLOAT = numeric_limits<float>::max();

const double noArc = MAXFLOAT;
const double INFINITY = MAXFLOAT;
const int maxNodes = 25;

class Graph {
private:
    class Vertex {
    private:
        string value;
        bool living;
        int ordnungszahl;
        bool visited;
        int degree;
        int gewicht;

    public:
        Vertex() {
            value =" ";
            living = false;
            ordnungszahl = 0;
            degree = 0;
            visited = false;
            gewicht = 0;
        }

        string getValue() const {
            return value;
        }
        void setValue(const string &p_value){
            value = p_value;
        }

        bool getLiving() const {
            return living;
        }
        void setLiving(bool value) {
            living = value;
        }

        int getOrdnungszahl() {
            return ordnungszahl;
        }
        void setOrdnungszahl(int value) {
            ordnungszahl = value;
        }
        bool getVisited() {
            return visited;
        }
        void setVisited(bool value) {
            visited = value;
        }
        int getDegree() {
            return degree;
        }
        void setDegree(int value) {
            degree = value;
        }
        int getGewicht() {
            return gewicht;
        }
        void setGewicht(int value) {
            gewicht = value;
        }


    };
    protected:
    int numvertices; // Anzahl der Knoten eines Graphen
    int numarcs;



public:
    Vertex vertecies[maxNodes];
    double arc[maxNodes][maxNodes];

    Graph() {

        numarcs = 0;
        numvertices = 0;
        for(int i = 0; i < maxNodes; i++) {
            for(int j = 0; j < maxNodes; j++) {
                arc[i][j] = noArc;
            }
        }
    }

    // Operationen auf einem Graphen:

    void InsertVertex(int m, const string & s) { // f¸gt neuen Knoten m mit Markierung m ein
        if(m >= maxNodes || m < 0) {
            throw invalid_argument("kein Insert mehr moeglich");
        }
        if(vertecies[m].getLiving() == true) {
            throw invalid_argument("knoten existiert bereits");
        }

        vertecies[m].setValue(s);
        vertecies[m].setLiving(true);
        numvertices++;
    }
    void InsertArc(int v, int w, double weight) { // f¸gt neue Kante (v,w) mit Gewicht weight ein
        if(vertecies[v].getLiving() == false && vertecies[w].getLiving() == false) {
            throw invalid_argument("Knoten existiert nicht 1");
        }
        if((v < 0 || v >= maxNodes) || (w < 0 || w >= maxNodes)) {
            throw invalid_argument("Knoten existiert nicht 2");
        }
        arc[v][w] = weight;
        arc[w][v] = weight;
        vertecies[v].setDegree(vertecies[v].getDegree() + 1);
        vertecies[w].setDegree(vertecies[w].getDegree() + 1);
        numarcs++;
    }

    int FirstVertex() { // Erster Knoten des Graphen
        int index = 0;
        while(index <= maxNodes) {
            if(vertecies[index].getLiving() == true) {
                return index;
            } else {
                index++;
            }
        }
        return -1;
    }
    int NextVertex(int n) { // n‰chster Knoten nach n (-1 wenn keiner existiert)
        int index = n + 1;
        while(index <= maxNodes) {
            if(vertecies[index].getLiving() == true) {
                return index;
            } else {
                index++;

            }
        }
        return -1;
    }

   bool IsArc(int v, int w) { // existiert Kante (v,w)?
        if(v < 0 || v >= maxNodes || w < 0 || w >=maxNodes) {
            throw invalid_argument("Wrong");
        } if(arc[v][w] != noArc)
            return true;
        return false;
    }

    double GetArc(int v, int w) { // gibt Kantenbewertung  von (v,w) zur¸ck
        return arc[v][w];
    }
    int FirstArc(int v) { // Erste Kante des Knoten v des Graphen
        int index = v + 1;
        while(index <= maxNodes) {
            if(vertecies[index].getLiving() == true){
                return index;
            } else {
                index++;
            }
        }
        return -1;
    }

    int NextArc(int v, int n) { // n‰chste Kante des Knotens v nach n (-1 wenn keiner existiert)
        int index = v;
        int index2 = n + 1;
        while(arc[index][index2] == noArc) {
            index2++;
            if(index2 >= maxNodes){
                 return -1;
            }
            }
        return index2;

    }

    int GetNumVertices() { // Anzahl der Knoten
        return numvertices;

    }

    void PrintGraph() {
            int v = FirstVertex();
            while (v != -1)
            {
                cout << "Knoten: " <<  vertecies[v].getValue() << endl;
                cout << "Zu folgenden Knoten existiert eine Verbindung: "<<endl;

                int n = FirstArc(v);
                while(n != -1) {
                    cout << vertecies[n].getValue() << " (Gewicht: " << arc[v][n] << ")" <<endl;
                    n = NextArc(v,n);
                }
                cout << "\n";
                v = NextVertex(v);
            }

        }

    int min_distance(int dist[], bool sptSet[]) { // Startknoten v_0

        int min = INT_MAX;
        int min_index;

        for(int v = 0; v < maxNodes; v++) {
            if(sptSet[v] == false && dist[v] <= min) {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }

    void dijkstra(int start, int ziel) {
        int dist [maxNodes];
        bool sptset[maxNodes];

        for(int i = 0; i < maxNodes; i++) {
            dist[i] = INT_MAX;
            sptset[i] = false;
        }
        dist[start] = 0;

        for(int count = 0; count < maxNodes; count++) {
            int u = min_distance(dist,sptset);

            sptset[u] = true;

            for(int v = 0; v < maxNodes; v++) {
                if(!sptset[v] && IsArc(u,v) && dist[u] != INT_MAX && dist[u] + GetArc(u,v) < dist[v]) {
                    dist[v] = dist[u] + GetArc(u,v);
                }
            }
        }
        cout << "Distanz: " << dist[ziel] << endl;
    }

    string GetVertexName(int i) {
        return vertecies[i].getValue();
    }
    void SetVisited(int v, bool w) {
        vertecies[v].setVisited(w);
    }



};



#endif // GRAPH_H
