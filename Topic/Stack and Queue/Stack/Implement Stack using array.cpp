#include <bits/stdc++.h>
using namespace std;

class Stack{
    int Size;
    int *arr;
    int Top;

  public:
    Stack(){
        Top = -1;
        Size = 1000;
        arr = new int[Size];
    }

    void push(int x) {
        if(Top+1!=Size) arr[++Top] = x;
        else cout<<"Stack Overflow\n";
    }
    int pop() {
        if(Top!=-1) return arr[Top--];
        else {
            cout<<"Stack Underflow\n";
            return -1;
        }
    }
    int top() {
        if(Top==-1) {
            cout<<"Stack is empty\n";
            return -1;
        }
        else return arr[Top];
    }
    int size() {return Top + 1;}
    bool empty(){return (Top==-1);}

};

int main(){
    Stack s;
    
    s.push(6);
    s.push(3);
    s.push(7);

    cout << "Top of stack is before deleting any element " << s.top() << endl;
    cout << "Size of stack before deleting any element " << s.size() << endl;
    cout << "The element deleted is " << s.pop() << endl;
    cout << "Size of stack after deleting an element " << s.size() << endl;
    cout << "Top of stack after deleting an element " << s.top() << endl;

    return 0;
}