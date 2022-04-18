#include<iostream>
using namespace std;
int rear = -1, front = -1, q[100], n = 5;

void enqueue(int v){
    if (rear == n-1){
        cout<<"Queue full\n";
        return;
    }
    else{
        if (front == -1){
            rear = 0;
            front = 0;
            q[rear] = v;
        }
        else{
            rear++;
            q[rear]=v;
        }
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        cout<<"Underflow\n";
        return;
    }
    else{
        if (rear == front)  
        {
            rear = -1;
            front = -1;
        }
        else{
            front ++;
        }
        
    }
}

void display(){
    if(front == -1 && rear == -1){
        cout<<"Underflow\n";
        return;
    }
    else{
        for (int i = front; i <= rear; i++)
        {
            cout<<q[i]<<"-";
        }
        cout<<endl;
    }
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    enqueue(60);
    display();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    display();
    dequeue();
    display();
    return 0;
}