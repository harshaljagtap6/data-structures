#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
  int data;
  struct node *next;
};

struct node *head = (struct node*)malloc(sizeof(struct node));

void insert_beg(int v){
  struct node *ptr = (struct node*)malloc(sizeof(struct node));  
  ptr->data=v;
  ptr->next=head;
  head = ptr;
  cout<<v<<" inserted"<<endl;
}

void insert_end(int v){
  struct node *new_node = (struct node*)malloc(sizeof(struct node));  
  new_node->data=v;
  new_node->next=NULL;
  struct node *ptr = (struct node*)malloc(sizeof(struct node));  
  ptr = head;
  while(ptr->next!=NULL)
  {
    ptr = ptr->next;
  }
  ptr->next = new_node;
  cout<<v<<" inserted"<<endl;
}

void display(){
  struct node *ptr = (struct node*)malloc(sizeof(struct node));  
  ptr = head;
  if (ptr == NULL){
    cout<<"No nodes"<<endl;
  }
  else{
    while(ptr!=NULL)
    {
      cout<<ptr->data<<"|"<<ptr->next<<" "<<endl;
      ptr = ptr->next;
    }
  }
}

int main()
{
  head = NULL;
  display();
  insert_beg(10);
  display();
  insert_end(20);
  display();
  insert_end(30);
  display();
}