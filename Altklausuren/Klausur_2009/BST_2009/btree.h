#ifndef BTREE_H
#define BTREE_H
#include "vertex.h"
#include <queue>
#include <math.h>

class BTree
{
protected:
    Vertex * root;
public:
    BTree() {}
    BTree(BTree & b) {
        root = rekursive_copy(b.getRoot());
    }
    ~BTree() {
       rekursiv_delete(root);
    }

    Vertex * create(){
        return nullptr;
    }

    bool empty(Vertex * p_empty) {
        if(p_empty == nullptr) {
            return false;
        }
        return true;
    }

    Vertex * left(Vertex * p_links) {
        if(p_links == nullptr) {
            throw runtime_error("Nullpointer");
        }
        return p_links->getLeft();
    }

    Vertex * right(Vertex * p_rechts) {
        if(p_rechts == nullptr) {
            throw runtime_error("Nullpointer");
        }
        return p_rechts->getRight();
    }

    string value(Vertex * p_value) {
        if(p_value == nullptr) {
            throw runtime_error("Nullpointer");
        }
        return p_value->getValue();
    }

    Vertex * node(Vertex * b1, const string & t, Vertex * b2) {
        Vertex * v = new Vertex(b1,t,b2);
        return v;
    }
    void main() {
         root = node(
             node(create(),"Peter",
                node(create(), "Altenbernd", create())), "faehrt",
                    node(create(), "nach",
                        node(create(), "Darmstadt", create() )));

                            cout << endl;
                            print(root);
                            cout << endl;
                            cout << endl;
    }

    void print(Vertex * v) {
         if(v == nullptr){
             return;
         } else {
            print(v->getLeft());
            cout << v->getNummer() << ":" << v->getValue() << " " ;
            print(v->getRight());
         }
    }

    void rekursiv_delete(Vertex * v){
        if(v == nullptr) {
            return;
        } else {
            rekursiv_delete(v->getLeft());
            rekursiv_delete(v->getRight());
        }
    }

    Vertex * rekursive_copy(Vertex * v) {
        if(v == nullptr){
            return NULL;
        }

        Vertex *l,*r,*n;

        l = rekursive_copy(v->getLeft());
        r = rekursive_copy(v->getRight());
        n = new Vertex(v->getLeft(), v->getValue(), v->getRight());

        return n;

    }

    Vertex *getRoot() const {
        return root;
    }
    void setRoot(Vertex *value);
};

#endif // BTREE_H
