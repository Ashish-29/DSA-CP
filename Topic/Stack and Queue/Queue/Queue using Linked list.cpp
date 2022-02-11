#include <bits/stdc++.h>
using namespace std;

class node{
  public:
    int val;
    node* next;
    node(int va){
        this->val=va;
        this->next=NULL;
    }
};

class Queue{
    node *start;
    node *end;
    int curr_size;

  public:
    Queue(){
        start = NULL;
        end = NULL;
        curr_size=0;
    }

    void push(int x) {                       //enqueue
        node* temp=new node(x); 
        if(curr_size==0) {start=end=temp;}
        else {end->next=temp;end=end->next;}
        curr_size++; 
    }
    int pop() {                              //dequeue
        if(curr_size) {
            node* temp=start;
            int el=temp->val;
            start=start->next;
            delete(temp);
            curr_size--;
            return el;
        }
        else {
            cout<<"Queue Underflow\n";
            return -1;
        }
    }
    int front(){                               //peek
        if(curr_size==0){
            cout<<"Queue is empty\n";
            return -1;
        }
        else return start->val;
    }
    int back(){                              
        if(curr_size==0){
            cout<<"Queue is empty\n";
            return -1;
        }
        else return end->val;
    }
    int size() {return curr_size;}
    bool empty(){return (curr_size==0);}
};

int main(){
    Queue q;

    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout<<q.front()<<" "<<q.back()<<" "<<q.size()<<" "<<q.empty()<<endl;q.pop();
    cout<<q.front()<<" "<<q.back()<<" "<<q.size()<<" "<<q.empty()<<endl;q.pop();
    cout<<q.front()<<" "<<q.back()<<" "<<q.size()<<" "<<q.empty()<<endl;q.pop();
    cout<<q.front()<<" "<<q.back()<<" "<<q.size()<<" "<<q.empty()<<endl;q.pop();
    cout<<q.front()<<" "<<q.back()<<" "<<q.size()<<" "<<q.empty()<<endl;q.pop();

    q.push(6);
    q.push(7);
    cout<<q.front()<<" "<<q.back()<<" "<<q.size()<<" "<<q.empty()<<endl;

    return 0;
}