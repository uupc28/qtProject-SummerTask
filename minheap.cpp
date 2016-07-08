#include "minheap.h"
using namespace std;
MinHeap::MinHeap(int length)
{
    heap = new Node*[length+1];
    maxLength = length;
    num = 0;
}

void MinHeap::display()
{
   qDebug()<<"display:";
    for(int i=1;i<=num;i++)
        qDebug()<<heap[i]->weight;
}

void MinHeap::insert(Node* node)
{
    num++;
    heap[num] = node;
    siftUp(num);
}

bool MinHeap::isEmpty()
{
    return num==0?1:0;
}

Node* MinHeap::reMini()
{
    swap(heap[1],heap[num]);
   num--;
   siftDown(1,num);
   return heap[num+1];
}
/*MinHeap::~MinHeap()
{
    for(int i=0;i<=maxLength;i++)
    {
        delete heap[i];
    }
    delete heap;
}*/

void MinHeap::siftDown(int start, int end)
{
    int i=start,j=i*2;
    heap[0]=heap[i];
    while (j<=end)
    {
        if(j<end&&heap[j]->weight>heap[j+1]->weight)  j++;
        if(heap[0]->weight<=heap[j]->weight) break;
        else
        {
            heap[i]=heap[j];
            i=j;
            j*=2;
        }

    }
    heap[i]=heap[0];
}

void MinHeap::siftUp(int start)
{
    int j=start,i=j/2;
    heap[0]=heap[j];
    while(j>0)
    {
        if(heap[i]->weight<heap[0]->weight)  break;
        else
        {
            heap[j]=heap[i];
            j=i;
            i/=2;
        }
    }
    heap[j]=heap[0];
}


