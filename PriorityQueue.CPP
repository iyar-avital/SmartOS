#include<stdio.h>
#include<limits.h>
#define MAX 100


class PriorityQueue {
private: 
    int idx = -1;
    int pqVal[MAX];
    int pqPriority[MAX];
    int peek();

public:
    int isEmpty();
    int isFull();
    void enqueue(int data, int priority);
    int dequeue();
    void printQueue();

};


int PriorityQueue::isEmpty() {
    return idx == -1;
}

int PriorityQueue::isFull() {
    return idx == MAX - 1;
}

void PriorityQueue::enqueue(int data, int priority)
{
    if (!isFull()) {

        idx++;

        pqVal[idx] = data;
        pqPriority[idx] = priority;
    }
}

int PriorityQueue::peek()
{
    int maxPriority = INT_MAX;
    int indexPos = -1;

    for (int i = 0; i <= idx; i++) {
        if (maxPriority > pqPriority[i]) {
            maxPriority = pqPriority[i];
            indexPos = i;
        }
    }

    return indexPos;
}


int PriorityQueue::dequeue()
{
    int maxPriority = -1;
    if (!isEmpty())
    {
        int indexPos = peek();
        maxPriority = pqVal[indexPos];

        for (int i = indexPos; i < idx; i++) {
            pqVal[i] = pqVal[i + 1];
            pqPriority[i] = pqPriority[i + 1];
        }

        idx--;
    }

    return maxPriority;
}

void PriorityQueue::printQueue() {
    for (int i = 0; i <= idx; i++) {
        printf("(%d, %d)\n", pqVal[i], pqPriority[i]);
    }
}