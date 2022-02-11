#include <bits/stdc++.h>
using namespace std;

class Queue{
    int Size;
    int *arr;
    int start;
    int end;
    int curr_size;

  public:
    Queue(){
        start = -1;
        end = -1;
        curr_size=0;
        Size = 1000;
        arr = new int[Size];
    }

    void push(int x) {                       //enqueue
        if(curr_size!=Size) {
            if(curr_size==0) start++;
            end++;
            end%=Size;
            arr[end] = x; 
            curr_size++;
        }
        else cout<<"Queue Overflow\n";
    }
    int pop() {                              //dequeue
        if(curr_size) {
            int el=arr[start];
            start++;
            start%=Size;
            curr_size--;
            if(!curr_size) start=end=-1;
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
        else return arr[start];
    }
    int back(){                              
        if(curr_size==0){
            cout<<"Queue is empty\n";
            return -1;
        }
        else return arr[end];
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