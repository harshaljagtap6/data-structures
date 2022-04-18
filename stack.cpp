#include<iostream>
using namespace std;
int s[1000], top = -1, n=5;

void pop(){
    if (top == -1){
        cout<<"Underflow";
        return;
    }
    else{
        top--;
    }
}

void push(int v){
    if (top == n-1){
        cout<<"Overflow";
        return;
    }
    else{
        top++;
        s[top]=v;
    }

}

void display_top(){
    if (top == -1){
        cout<<"Underflow";
        return;
    }
    else{
        cout<<"Top :"<<s[top];
    }        
}

int main(){    
    push(10);
    push(20);
    push(30);
    display_top();
    pop();
    display_top();
    return 0;
}