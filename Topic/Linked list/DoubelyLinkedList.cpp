#include<bits\stdc++.h>
using namespace std;

class node {
public:
   int data;
   node *next;
   node *prev;
   node(int da) { data=da; next=NULL; prev=NULL; }
}; 

void insert_At_head(int val,node* &head){
    node* n=new node(val);
    if(head==NULL){head=n;return;}
    n->next=head;
    head->prev=n;
    head=n;
}

void insert_At_tail(int val,node* &head){
    node* n=new node(val);
    if(head==NULL){head=n;return;}
    node* temp=head;
    while(temp->next!=NULL)temp=temp->next;
    temp->next=n;
    n->prev=temp;
}

void display(node* head){
    while(head!=NULL){
        cout<<head->data<<"<=>";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}

void delete_At_head(node* &head){
    if(head==NULL) return;
    else {
        node* todelete=head;
        if(head->next!=NULL) head->next->prev=NULL;
        head=head->next;
        delete todelete;
    }
}

void deletenode(int val,node* &head){
    if(head==NULL) return;
    else if (head->data==val){
        delete_At_head(head);
        return;
    }       

    node* temp=head->next;
    while(temp!=NULL){
        if(temp->data==val){
            temp->prev->next=temp->next;
            if(temp->next!=NULL)temp->next->prev=temp->prev;
            delete temp;
            return;
        }
        temp=temp->next;
    }
}

int main (){
    node *h1=NULL;

   insert_At_head(4,h1);
   insert_At_tail(5,h1);
   insert_At_tail(6,h1);
   insert_At_tail(7,h1);
   insert_At_tail(8,h1);
   insert_At_head(3,h1);
   insert_At_head(2,h1);
   
   display(h1);
   deletenode(4,h1);
   display(h1);
   
   return 0;
}