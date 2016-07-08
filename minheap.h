#ifndef MINHEAP_H
#define MINHEAP_H

#include <QVector>
#include <iostream>
#include <QDebug>
using namespace std;

struct Node{
    QChar value;
    qint16 weight;
    Node* left;Node* right;
    Node(){
        left = NULL;right=NULL;
    }
    Node(QChar a,qint16 b){
        value = a;weight =b;
        left = NULL;right=NULL;
    }
    Node(qint16 b){
        weight =b;
        left = NULL;right=NULL;
    }
};

class MinHeap
{
public:
    MinHeap(int length);
   // ~MinHeap();
    void insert(Node* node);
    Node* reMini();
    bool isEmpty();
    void display();

private:
    Node** heap;
    qint16 num;
    int maxLength;
    void siftDown(int start,int end);
    void createHeap();
    void siftUp(int start);
};

#endif // MINHEAP_H
