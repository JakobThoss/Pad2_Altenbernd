#include "graph.h"

int main() {


    Graph G, H;



    // Graph aufbauen *

    // Knoten:

    G.InsertNode(0, "Besprechen", 4);
    G.InsertNode(1, "Zeichnen", 14);
    G.InsertNode(2, "Einmessen", 1);
    G.InsertNode(3, "Genehmigen", 21);
    G.InsertNode(4, "Angebot Fundament", 7);
    G.InsertNode(5, "Angebot Rohbau", 14);
    G.InsertNode(6, "Fundament", 5);
    G.InsertNode(7, "Rohbau", 20);

    // Kanten:

    G.InsertArc(0,1);

    G.InsertArc(1,2);
    G.InsertArc(1,3);
    G.InsertArc(1,4);
    G.InsertArc(1,5);

    G.InsertArc(2,6);
    G.InsertArc(3,6);
    G.InsertArc(4,6);
    G.InsertArc(5,7);

    G.InsertArc(6,7);

    // Menue: **
    int c = -1;

    while (c != 9) {

    cout << "\nMenue" << endl;
    cout << " 1: Aktuelles Projekt ausgeben" << endl;
    cout << " 2: Neues Projekt" << endl;
    cout << " 3: Aktuelles Projekt löschen" << endl;
    cout << " 4: Projekt wechseln" << endl;
    cout << " 5: Reihenfolge planen" << endl;
    cout << " 6: Mindestlaufzeit" << endl;
    cout << " 9: ENDE" << endl;

    cin >> c;
    printf("\033c");

    switch (c) {
    case 1: {
        G.Bfs(0);
        break;
    }

    case 2: // Neues Projekt -- Aufgabe 2
        // hier ergänzen
        break;

    case 3: { // Aktuelles Projekt löschen -- Aufgabe 2
        // hier ergänzen
        G.reset();
        break;
    }

    case 4:  {
        Graph temp = G;
        G = H;
        H = temp;
        break;
    }

    case 5:  {// Reihenfolge planen -- Aufgabe 3
        // hier ergänzen
        G.TopSort();
        G.Bfs(0);
        }
        break;

    case 6: // Mindestlaufzeit-- Aufgabe 4
        // hier ergänzen
        G.findlongestPath();
        break;

    case 9: // Ende
            return (EXIT_SUCCESS);
        break;
    }
  }

    return (EXIT_SUCCESS);
}




