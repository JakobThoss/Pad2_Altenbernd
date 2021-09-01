#ifndef GRAPH_H
#define GRAPH_H
#include "vertex.h"
#include <queue>

        const int maxNodes = 10;


class Graph {
private:
        int anzahlVertecies;
        int anzahlArcs;
        Vertex vertex[maxNodes];
        bool arc[maxNodes][maxNodes];
    // Operationen auf einem Graphen
    public:
        Graph() {  // Graphen generieren
            for(int i = 0; i < maxNodes; i++) {
                for(int j = 0; j < maxNodes; j++) {
                    arc[i][j] = false;
                }
            }
            anzahlVertecies = 0;
            anzahlArcs = 0;
        }
        void reset() {
            for(int i = 0; i < maxNodes; i++) {
                vertex[i].setLiving(false);
                vertex[i].setGewicht(0);
                vertex[i].setIndegree(0);
                vertex[i].setOutdegree(0);
                vertex[i].setValue("");
                for(int j = 0; j < maxNodes; j++) {
                    arc[i][j] = false;
                }
            }
            anzahlArcs = 0;
            anzahlVertecies = 0;
        }
        // fügt neuen Knoten 'm' mit Namen 's' und Gewicht 'w' ein// Graphen freigeben
        void InsertNode (int m, string s, int w) {
            if(anzahlVertecies >= maxNodes){
                throw invalid_argument("Maximale Anzahl Knoten erreicht");
            }
            if(vertex[m].getLiving() == true) {
                throw invalid_argument("Knoten existiert bereits");
            } else {
                vertex[m].setLiving(true);
                vertex[m].setValue(s);
                vertex[m].setGewicht(w);

                anzahlVertecies++;

            }

        }
        // fügt neue Kante '(v,w)' ein
        void InsertArc(int v, int w) {
            if(vertex[v].getLiving() == false || vertex[w].getLiving() == false) {
                throw invalid_argument("Knoten sind nicht am Leben");
            }
            if((v < 0 || v > maxNodes) || (w < 0 || v > maxNodes)) {
                throw invalid_argument("Knoten liegen nicht im Array");
            }

            arc[v][w] = true;
            vertex[v].setOutdegree(vertex[v].getOutdegree() + 1);
            vertex[w].setIndegree(vertex[w].getIndegree() + 1);
            anzahlArcs++;

        }


        int getFirstNode() {

            int index = 0;
            while(index < maxNodes) {
                if(vertex[index].getLiving() == true){
                    return index;
                } else {
                    index++;
                }
            }
            return -1;
        }
        int  getNextNode(int index) {
            index =  index +1;
            if(index >= maxNodes) {
                return -1;
            }
            while(index < maxNodes) {
                if(vertex[index].getLiving() == true) {
                    return index;
                } else {
                    index++;
                }
            }
                return -1;
        }
        int  getFirstNeighbor(int index) {
            int j = 0;
            while(j < maxNodes) {
                if(arc[index][j] == true) {
                    return j;
                } else {
                    j++;
                }
            }
            return -1;
        }
        int getNextneighbor(int index,int index2) {
            index2 = index2 +1;
            if(index2 >= maxNodes) {
                return -1;
            }
            while(index2 < maxNodes) {
                if(arc[index][index2] == true) {
                    return index2;
                } else {
                    index2++;
                }
            }
            return -1;
        }
        void visit(int v) {
            vertex[v].printVertex();
        }

        void setAllVisited() {
            for(int i = 0; i < maxNodes; i++) {
                vertex[i].setIsVisited(false);
            }
        }

        void Bfs(int v) {
            queue <int> q;

            if(vertex[v].getLiving() == false) {
                    cout << "Knoten existiert nicht " << endl;
                    return;
            }

            vertex[v].setIsVisited(true);
            visit(v);
            q.push(v);

            while(!q.empty()) {
                v = q.front();
                q.pop();

                int kante = getFirstNeighbor(v);
                while(kante != -1) {
                    if(vertex[kante].getIsVisited() == false) {
                        vertex[kante].setIsVisited(true);
                        visit(kante);
                        q.push(kante);
                    }

                    kante = getNextneighbor(v,kante);
                }
            }

            setAllVisited();
        }

        // Topologisches Sortieren
        void TopSort() {    // Topologisches Sortieren; g muss azyklisch sein
            queue<int> q;                    // Schlange für Auswahlkandidaten
            int dauer = 0;
            int *indegree = new int[maxNodes];
            int sortIndex = 0;                    // Sortierindex
            int v = getFirstNode();

            while (v != -1) {
                indegree[v] = vertex[v].getIndegree();        // Eingangsgrade initialisieren

                if (indegree[v] == 0) {
                    q.push(v);
                    dauer = dauer + vertex[v].getGewicht();
                }
                // Knoten mit idegree=0 in Schlange aufnehmen
                v = getNextNode(v);
            }

            while (!q.empty()) {                // Solange bis Schlange leer
                v = q.front();                // nächster Knoten aus Schlange lesen
                q.pop();                    // und aus Schlange entfernen
                vertex[v].setOrdnungsnummer(sortIndex);           // Sortierindex vom Knoten v setzen
                sortIndex++;                // Sortierindex inkrementoieren
                int w = getFirstNeighbor(v);            // erste von v ausgehende Kante (v,w)

                while (w != -1) {                // für alle Nachfolger von v
                    indegree[w]--;            // Eingangsgrad von w dekrementieren

                    if (indegree[w] == 0) {
                        q.push(w);        // Knoten mit idegree=0 in Schlange aufnehmen
                        dauer = dauer + vertex[w].getGewicht();
                    }
                    w = getNextneighbor(v,w);        // nächste Kante (v,w)
                }
            }

            cout << "Die Dauer betraegt: " << dauer << " Schritte " << endl;
        }

        void findlongestPath() {
                queue<int> q;                    // Schlange für Auswahlkandidaten
                int *indegree = new int[maxNodes];
                int sortIndex = 0;                    // Sortierindex
                int v = getFirstNode();

                while (v != -1) {
                    indegree[v] = vertex[v].getIndegree();        // Eingangsgrade initialisieren
                    if (indegree[v] == 0) {
                        vertex[v].setMax(vertex[v].getMax() + vertex[v].getMax());
                        q.push(v);

                    }
                    // Knoten mit idegree=0 in Schlange aufnehmen
                    v = getNextNode(v);
                }

                while (!q.empty()) {                // Solange bis Schlange leer
                    v = q.front();                // nächster Knoten aus Schlange lesen
                    q.pop();                    // und aus Schlange entfernen
                    vertex[v].setOrdnungsnummer(sortIndex);           // Sortierindex vom Knoten v setzen
                    sortIndex++;                // Sortierindex inkrementoieren
                    int w = getFirstNeighbor(v);            // erste von v ausgehende Kante (v,w)

                    while (w != -1) {                // für alle Nachfolger von v
                        indegree[w]--;            // Eingangsgrad von w dekrementieren

                        if(vertex[w].getMax() > (vertex[v].getMax() + vertex[w].getGewicht()))
                                                    vertex[w].setMax(vertex[w].getMax());
                                                else
                                                    vertex[w].setMax(vertex[v].getMax() + vertex[w].getGewicht());


                        if (indegree[w] == 0) {
                            q.push(w);        // Knoten mit idegree=0 in Schlange aufnehmen

                        }
                        w = getNextneighbor(v,w);        // nächste Kante (v,w)
                    }
                }
                int dauer = vertex[7].getMax();
                cout << "Die Dauer betraegt mindestens: " << dauer << " Schritte " << endl;
        }





};

#endif // GRAPH_H
