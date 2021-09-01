#ifndef MST_H
#define MST_H
#include "graph.h"


class MST : public Graph
{
private:
    double weight;
public:
    MST(Graph & g) {
        MakeMST(g);
    }



    void MakeMST(Graph & g) {
         weight = 0.0;

        // Achtung: alle Markierungen auf Basis von Graph g

        // Alle Knoten übertragen und Markierung auf false setzen
        for (int v = g.FirstVertex(); v != -1; v = g.NextVertex(v)) {
            InsertVertex(v, g.GetVertexName(v));
            g.SetVisited(v, false);
        }


        int v_0 = g.FirstVertex(); // Startknoten v_0;
        g.SetVisited(v_0, true); // markiere v_0 als besucht

        for (int i = 0; i < g.GetNumVertices() - 1; i++) {
            int v = -1;
            int w = -1;

            int min_gewicht = INT_MAX;
            for(int k = 0; k < maxNodes; k++) {
                for(int j = 0; j < maxNodes; j++) {
                    if(g.arc[k][j] < min_gewicht)
                        if((g.vertecies[k].getVisited() == true && g.vertecies[j].getVisited() == false)) {
                            min_gewicht = g.arc[k][j];
                            w = j;
                            v = k;
                        }
               }
            }

            // W‰hle eine Kante {v,w}, deren Gewicht minimal ist und die einen bereits markierten Knoten v mit einem noch unmarkierten Knoten w verbindet.
            weight += min_gewicht;
            g.SetVisited(w, true); // markiere w als besucht

            InsertArc(v, w, g.GetArc(v, w));

        }
            ausgabe(weight);
        }

    void ausgabe(int value) {
        cout << "Das Gesamtgewicht betraegt " << value << endl;
    }
    };

#endif // MST_H
