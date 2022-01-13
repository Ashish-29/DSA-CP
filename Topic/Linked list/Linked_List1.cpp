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

bool search(int v,node* head){
   if (head==NULL) return false;
   while (head->next!=NULL)
   if (head->data==v) return true;
   else head=head->next;
   return false;
}

void delete_At_head(node* &head){
   if (head==NULL) return;   
   else {
      node* todelete=head;
      head=head->next;
      delete todelete;
   } 
}

void del(int v,node* &head){
   if (head==NULL) return;   
   else if (head->data==v) { delete_At_head(head); return;}   

   node* temp=head;
   while (temp->next!=NULL)
   if (temp->next->data==v) {
      node* todelete=temp->next;
      temp->next=temp->next->next;
      delete todelete;
      return;
   }
   else temp=temp->next;
}

void Simplereverse (node* &head){
   node* prv=NULL;
   node* curr=head;
   node* nxt;
   
   while (curr!=NULL) {
      nxt=curr->next;
      curr->next=prv;

      prv=curr;
      curr=nxt;
   }
   head=prv;
}

node* Recursivereverse (node* head){
   if(head==NULL || head->next==NULL) return head;
   
   node* newhead=Recursivereverse(head->next);
   head->next->next=head;
   head->next=NULL;
   return newhead;
}

node* reverseKelement(int k,node* head){ 
   node* prv=NULL;
   node* curr=head;
   node* nxt;
   
   int count=0;
   while (count<k && curr!=NULL) {
      nxt=curr->next;
      curr->next=prv;

      prv=curr;
      curr=nxt;
      count++;
   }                                       //After loop break //curr=nxt

   if(curr!=NULL)                         
   head->next=reverseKelement(k,curr);    //head->next=newhead
   return prv;                            //head=prv
}

void display (node* head){
   while (head!=NULL) {
      cout<<head->data<<"->";
      head=head->next;
   }
   cout<<"NULL"<<endl;
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

   // cout<<search(5,h1)<<endl;
   // cout<<search(10,h1)<<endl;

   display(h1);
   // del(3,h1);
   // del(7,h1);
 
   // Simplereverse(h1);
   // h1=Recursivereverse(h1);

   h1=reverseKelement(3,h1);
   display(h1);
   return 0;
}