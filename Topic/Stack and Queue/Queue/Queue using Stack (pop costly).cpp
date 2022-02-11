#include <stack>
class Queue {
    // Define the data members(if any) here.
    stack<int> s1,s2;
    
    public:
    Queue() {
        // Initialize your data structure here.
        
    }

    void enQueue(int val) {                        //O(1)
        // Implement the enqueue() function.
        s1.push(val);
    }

    int deQueue() {                               //O(1) or O(n)
        // Implement the dequeue() function.
        if(s1.empty() && s2.empty()) return -1;
        if(s2.empty()) {
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int el=s2.top();
        s2.pop();
        return el;
    }

    int peek() {                                //O(1) or O(n)
        // Implement the peek() function here.
        if(s1.empty() && s2.empty()) return -1;
        if(s2.empty()) {
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int el=s2.top();
        return el;
    }

    bool isEmpty() {                             //O(1)
        // Implement the isEmpty() function here.
        return (s1.size()+s2.size()==0);
    }
};