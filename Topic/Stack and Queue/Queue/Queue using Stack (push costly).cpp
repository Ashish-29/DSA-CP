#include <stack>
class Queue {
    // Define the data members(if any) here.
    stack<int> s1,s2;
    
    public:

    void enQueue(int val) {                        //O(n)
        // Implement the enqueue() function.
        while(s1.size()) {s2.push(s1.top());s1.pop();}
        s1.push(val);
        while(s2.size()) {s1.push(s2.top());s2.pop();}
    }

    int deQueue() {                               //O(1)
        // Implement the dequeue() function.
        if(s1.empty()) return -1;
        int el=s1.top();
        s1.pop();
        return el;
    }

    int peek() {                                //O(1)
        // Implement the peek() function here.
        if(s1.empty()) return -1;
        return s1.top();
    }

    bool isEmpty() {                             //O(1)
        // Implement the isEmpty() function here.
        return (s1.size()==0);
    }
};