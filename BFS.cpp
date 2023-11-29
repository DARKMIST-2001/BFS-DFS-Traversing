#include<iostream>
using namespace std;
#include<stdlib.h>

struct queue {
    int size;
    int front;
    int rear;
    int *ayan;
};

bool isEmpty(struct queue *q) {
    return (q->rear == q->front);
}

bool isFull(struct queue *q) {
    return (q->rear == q->size - 1);
}

void enqueue(struct queue *q, int x) {
    if (isFull(q)) {
        cout << "Queue is Full!" << endl;
        return;
    } else {
        q->ayan[++(q->rear)] = x;
    }
}

int dequeue(struct queue *q) {
    int y = -1;
    if (isEmpty(q)) {
        cout << "Queue is Empty!" << endl;
    } else {
        y = q->ayan[++(q->front)];
    }
    return y;
}

int main() {
    struct queue q;
    q.size = 50;
    q.front = -1;
    q.rear = -1;
    q.ayan = (int*)malloc(q.size * sizeof(int));

    int node;
    int i = 0;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int graph[7][7] = {{0, 1, 0, 1, 0, 0, 0},
                       {1, 0, 1, 0, 0, 1, 1},
                       {0, 1, 0, 1, 0, 1, 0},
                       {1, 0, 1, 0, 1, 0, 0},
                       {0, 0, 1, 1, 0, 0, 1},
                       {0, 1, 1, 0, 0, 0, 0},
                       {0, 1, 0, 0, 1, 0, 0}};

    cout << "Started from :" << i << endl;
    visited[i] = 1;
    enqueue(&q, i);

    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        cout << node << " ";

        for (int j = 0; j < 7; j++) {
            if (graph[node][j] == 1 && visited[j] == 0) {
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }

    free(q.ayan);
    return 0;
}
