#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
  int data;
  struct node *next;
  struct node *prev;
};

struct node *head = (struct node*)malloc(sizeof(struct node));

void ins_beg(int v){
  struct node *new_node = (struct node*)malloc(sizeof(struct node));
  if (new_node == NULL)
  {
      cout<<"Overflow";
      return;
  }
  else{
    new_node->data = v;
    new_node->prev = NULL;
    if(head == NULL){
        new_node->next = NULL;
        head = new_node;
    }
    else{
        head->prev=new_node;
        new_node->next = head;
        head = new_node;
    }
  }
}

void ins_after_node(int value, int an){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    struct node *ptr = (struct node*)malloc(sizeof(struct node));    
    struct node *t = (struct node*)malloc(sizeof(struct node));    
    if(an < 1)
    {
        cout<<"\nan should be >= 1.";
    }
    else if (an == 1)
    {
        ins_beg(value);
    }
    else
    {
        t = head;
        // node *new_node = (node*)malloc(sizeof(node));
        new_node->data = value;

        for (int i = 0; i < (an - 1); i++) {
            t = t->next;
        }

        if (t == NULL) {
            printf("\nThis position is too far\n");
            return;
        }
        new_node->next = t->next;
        new_node->prev = t;
        t->next = new_node;

    }
}

void ins_end(int v){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    new_node->data = v;
    new_node->next = NULL;
    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    new_node->prev = ptr;
    ptr->next = new_node;    
}

void del_beg(){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t = head;
    ptr = t->next;
    ptr->prev = NULL;
    head = ptr;
    free(t);
}

void del_node_no(int node_no){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));    
    struct node *t = (struct node*)malloc(sizeof(struct node));    
    if(node_no < 1)
    {
        cout<<"\nan should be >= 1.";
    }
    else if (node_no == 1)
    {
        del_beg();
    }
    else
    {
        ptr = head;
        // node *new_node = (node*)malloc(sizeof(node));

        for (int i = 0; i < (node_no - 1); i++) {
            ptr = ptr->next;
        }

        if (ptr == NULL) {
            printf("\nThis position is too far\n");
            return;
        }

        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
    }

}

void del_end(){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));    
    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->prev->next=NULL;
    free(ptr);
}

void displaydll(){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr = head;
    if (ptr == NULL){
        cout << "Linked list empty";
    }
    else{
        while(ptr != NULL){
            cout<<ptr->prev<<"-"<<ptr->data<<"-"<<ptr->next<<endl;
            ptr = ptr->next;
        }
    }
}

int main(){
    head = NULL;
    ins_beg(10);
    ins_beg(20);
    ins_beg(30);
    ins_after_node(99, 2);
    ins_end(69);
    displaydll();
    del_beg();
    cout<<"Deleted?"<<endl;
    displaydll();
    del_node_no(2);
    cout<<"Deleted?"<<endl;
    displaydll();
    del_end();
    cout<<"Deleted?"<<endl;
    displaydll();
    return 0;
}