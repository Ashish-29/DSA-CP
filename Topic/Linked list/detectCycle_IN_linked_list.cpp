#include<bits\stdc++.h>
using namespace std;

class node {
public:
   int data;
   node *next;
   node(int da) { data=da; next=NULL; }
}; 

void Insert_At_start(int a,node* &head){
   node *n= new node(a);
   n->next=head;
   head=n;
}

void Insert_At_last(int a,node* &head){
   node* n= new node(a);
   if (head==NULL) {head=n;return;}

   node* temp=head;
   while (temp->next!=NULL) temp=temp->next;
   temp->next=n;
}

void display (node* head){
   while (head!=NULL) {
      cout<<head->data<<"->";
      head=head->next;
   }
   cout<<"NULL"<<endl;
}

void makeCycle(int pos,node* head){
    node* startcycle;
    node* temp=head;
    int count=1;
    while(temp->next!=NULL){
        if (count==pos) startcycle=temp;
        temp=temp->next;
        count++;
    }
    temp->next=startcycle;
}

bool detectCycle(node* head){
   node* sl=head;
   node* fa=head;
   while(fa!=NULL && fa->next!=NULL){
      fa=fa->next->next;
      sl=sl->next;
      if(fa==sl) return true;
   }
   return false;
}

void removeCycle (node* head){
   //After detect cycle, we come here
   node* sl=head;
   node* fa=head;
   do{
      fa=fa->next->next;
      sl=sl->next;
   }while(fa!=sl);

   fa=head;
   while(fa->next!=sl->next){
      fa=fa->next;
      sl=sl->next;
   }
   sl->next=NULL;
}

int main(){
   node *h1=NULL;

   Insert_At_start(4,h1);
   Insert_At_last(5,h1);
   Insert_At_last(6,h1);
   Insert_At_last(7,h1);
   Insert_At_last(8,h1);
   Insert_At_start(3,h1);
   Insert_At_start(2,h1);
   
   display(h1);
   makeCycle(4,h1);
   cout<<detectCycle(h1)<<endl;

   removeCycle (h1);
   cout<<detectCycle(h1)<<endl;
   display(h1);
   
   return 0;
}