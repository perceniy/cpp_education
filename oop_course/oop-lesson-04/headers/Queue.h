//
// Created by Арсений Сысоев on 2019-05-05.
//

#ifndef QUEUE_H
#define QUEUE_H

class QueueInt {
private:
    class Node {
    public:
        Node* Next;
        Node* Prev;
        int value;
        Node() {
            Next = nullptr;
            Prev = nullptr;
            value = 0;
        }
        Node(Node &copyNode) {
            Next = copyNode.Next;
            Prev = copyNode.Prev;
            value = copyNode.value;
        };
    };
    Node* qHead;
    Node* qBack;
    int qLength;
public:

    QueueInt() {
        qHead = nullptr;
        qBack = nullptr;
        qLength = 0;
    }
    void push(int val) {
            Node* newNode = new Node;
            newNode->value = val;
            newNode->Prev = qBack;
            ++qLength;
            if (qLength == 1) {
                qHead = newNode;
                qBack = newNode;
            } else {
                qBack->Next = newNode;
                qBack = newNode;
            }
    }

    int size() const { return qLength; }
    int front() { // вернуть первый элемент в очереди
        return qHead->value;
    }
    int back() const { // вернуть последний элемент в очереди
        return qBack->value;
    }
    void pop() {
        if ( qLength > 0 ) {
            qLength--;
            Node* tempNode = new Node(*qHead);
            delete qHead;
            qHead = tempNode->Next;
            delete tempNode;
        }
    }

    int pop2() {
        int resultValue = front();
        pop();
        return resultValue;
    }
};

#endif //QUEUE_H
