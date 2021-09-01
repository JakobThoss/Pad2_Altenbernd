#ifndef BST_H
#define BST_H
#include "btree.h"


class BST : public BTree
{ 
private:
    vector<Vertex *> vec;
public:
    BST() {
        root = nullptr;
    }

    void insert(Vertex * node,const string & data){
        if(node == nullptr) {
            root = new Vertex(nullptr,data,nullptr);
            vec.push_back(root);
            return;

        }
            if(data <= node->getValue()) {
                if(node->getLeft() == nullptr) {
                    Vertex * tmp = new Vertex(nullptr,data,nullptr);
                    node->setLeft(tmp);
                    vec.push_back(tmp);
                } else {
                insert(node->getLeft(), data);
                }
            } else {
                if(node->getRight() == nullptr) {
                   Vertex * tmp = new Vertex(nullptr,data,nullptr);
                   node->setLeft(tmp);
                   vec.push_back(tmp);
                } else {
                insert(node->getRight(),data);
                }

        }

    }
    void ausgabe() {
        for(int i = 0; i < (int) vec.size(); i++) {
            for(int j = i; j < (int) vec.size(); j++){
               if((*vec[i]).getValue() > (*vec[j]).getValue()) {
                   Vertex * temp = vec[i];
                   vec[i] = vec[j];
                   vec[j] = temp;

            }
        }
    }
        for(int i = 0; i < (int) vec.size(); i++) {
            cout << (*vec[i]).getValue() << endl;
        }
    }






};

#endif // BST_H
