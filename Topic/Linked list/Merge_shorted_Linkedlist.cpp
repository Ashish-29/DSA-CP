#include<bits\stdc++.h>
using namespace std;

class node {
public:
   int data;
   node *next;
   node(int da) { data=da; next=NULL; }
}; 

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

node* merge (node* h1,node* h2){
    if(h1==NULL) return h2;
    else if(h2==NULL) return h1;
    
    node *pt3,*newhead;

    if(h1->data < h2->data){
    pt3=h1;newhead=h1;h1=h1->next;}
    else{pt3=h2;newhead=h2;h2=h2->next;}

    while(h1!=NULL && h2!=NULL){
        if(h1->data < h2->data){
        pt3->next=h1;h1=h1->next;}
        else{pt3->next=h2;h2=h2->next;}
        pt3=pt3->next;
    }

    if (h1!=NULL) pt3->next=h1;
    else if (h2!=NULL) pt3->next=h2;
    
    return newhead;
}

node* Recursive_Merge(node* h1,node* h2){
    if(h1==NULL) return h2;
    else if(h2==NULL) return h1;
  
    node* newhead;
    if(h1->data < h2->data){
    newhead=h1;newhead->next=Recursive_Merge(h1->next,h2);}
    else{newhead=h2;newhead->next=Recursive_Merge(h1,h2->next);}

    return newhead;
}

int main(){
   node *h1=NULL;
   node *h2=NULL;

   int arr1[]={2,5,9,22,45};
   int arr2[]={1,14};

   for(int i=0;i<5;i++) Insert_At_last(arr1[i],h1);
   for(int i=0;i<2;i++) Insert_At_last(arr2[i],h2);
   
   display(h1);
   display(h2);
   node* h4=Recursive_Merge(h1,h2);
   display(h4);

   return 0;
}
