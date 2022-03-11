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

void ins_bet(int v, int after_node){
  struct node *new_node = (struct node*)malloc(sizeof(struct node));
  struct node *ptr = (struct node*)malloc(sizeof(struct node));
  struct node *t = (struct node*)malloc(sizeof(struct node));
  ptr = head;
  new_node->data=v;
  int node_counter = 0;
  while (node_counter != after_node-1)
  {
    ptr = ptr->next;
    node_counter++;
  }
  t = ptr;
  new_node->next = ptr->next;
  ptr->next = new_node;
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

void del_beg(){
  struct node *ptr = (struct node*)malloc(sizeof(struct node));
  ptr = head;
  head = head->next;
  free(ptr);
  cout<<"deleted beginninig "<<endl;
}


void del_node(int after_node){
  struct node *ptr = (struct node*)malloc(sizeof(struct node));
  struct node *t = (struct node*)malloc(sizeof(struct node));
  ptr = head;
  int node_counter = 0;
  while (node_counter != after_node-1)
  {
    t = ptr;
    ptr = ptr->next;
    node_counter++;
  }
  cout<<ptr->data<<" deleted"<<endl;
  t->next = ptr->next;
  free(ptr);
}
void del_end(){
  struct node *ptr = (struct node*)malloc(sizeof(struct node));
  struct node *t = (struct node*)malloc(sizeof(struct node));
  ptr = head;
  while(ptr->next != NULL)
  {
    t = ptr;
    ptr = ptr->next;
  }
  t->next = NULL;
  cout<<ptr->data<<"deleted ";
  free(ptr);
}

void display(){
  cout<<endl;
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
  cout<<endl;
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
  ins_bet(91, 1);
  display();
  ins_bet(92, 2);
  display();
  ins_bet(93, 3);
  display();
  del_beg();
  display();
  del_node(2);
  display();
  del_node(3);
  display();
  del_end();
  display();
}
