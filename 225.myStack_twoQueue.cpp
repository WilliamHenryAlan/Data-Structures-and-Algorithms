/*
请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。

实现 MyStack 类：

    void push(int x) 将元素 x 压入栈顶。
    int pop() 移除并返回栈顶元素。
    int top() 返回栈顶元素。
    boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。

 

注意：

    你只能使用队列的基本操作 —— 也就是 push to back、peek/pop from front、size 和 is empty 这些操作。
    你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。

*/
#include <iostream>
#include <queue>
class MyStack {
public:
    std::queue<int> InQueue,OutQueue;
    MyStack() {

    }
    
    void push(int x) {
        InQueue.push(x);
    }
    
    int pop() {
        int len = InQueue.size()-1;
        for (int i = 0;i < len;i++) {
            OutQueue.push(InQueue.front());
            InQueue.pop();
        }
        int ret = InQueue.front();
        InQueue.pop();
        InQueue = OutQueue;
        while (!OutQueue.empty()) {
            OutQueue.pop();
        }
        // while (!OutQueue.empty()) {
        //     InQueue.push(OutQueue.front());
        //     OutQueue.pop();
        // }
        return ret;
    }

    
    int top() {
        int temp = pop();
        push(temp);
        return temp;
        //return InQueue.back();
    }
    
    bool empty() {
        return InQueue.empty();
    }
};
int main() {
    MyStack S;
    S.push(1);
    S.push(2);
    S.push(3);
    std::cout << S.pop() << std::endl;
}

