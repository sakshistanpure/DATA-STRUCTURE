#include<iostream>
#include<queue>
using namespace std;

class CircularQueue 
{
    int q[5], front, rear;

public:
    CircularQueue() 
	{
        front = rear = -1;
    }

    void enqueue(int call) 
	{
        if ((rear + 1) % 5 == front) {
            cout << "Call queue is full!\n";
            return;
        }

        if (front == -1)
            front = 0;

        rear = (rear + 1) % 5;
        q[rear] = call;

        cout << "Call " << call << " added.\n";
    }

    void dequeue()
	{
        if (front == -1) {
            cout << "No normal calls waiting.\n";
            return;
        }

        cout << "Handling Call " << q[front] << endl;

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % 5;
    }
};

int main()
{
    CircularQueue calls;
    priority_queue<int> priorityCalls;

   
    calls.enqueue(101);
    calls.enqueue(102);
    calls.enqueue(103);

  
    priorityCalls.push(201);
    priorityCalls.push(203);
    priorityCalls.push(202);

    cout << "\n--- Normal Calls ---\n";
    calls.dequeue();
    calls.dequeue();

    cout << "\n--- Priority Calls ---\n";
    while (!priorityCalls.empty()) {
        cout << "Handling Priority Call "
             << priorityCalls.top() << endl;
        priorityCalls.pop();
    }

    return 0;
}

