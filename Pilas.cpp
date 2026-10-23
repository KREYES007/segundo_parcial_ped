#include<iostream>
#include<stack>

void RemoveConsecutiveDuplicates(std::stack<int>& values){
    std::stack<int> tempStack;

    if (!values.empty()) {
        tempStack.push(values.top());
        values.pop();
    }

    while (!values.empty()) {
        int currentValue = values.top();
        values.pop();

        if (currentValue != tempStack.top()) {
            tempStack.push(currentValue);
        }
    }

    while (!tempStack.empty()) {
        values.push(tempStack.top());
        tempStack.pop();
    }
}

int main() {
    std::stack<int> values;
    values.push(4);
    values.push(4);
    values.push(6);
    values.push(4);
    values.push(4);
    values.push(9);

    RemoveConsecutiveDuplicates(values);

    std::cout << "Pila resultante: ";
    while (!values.empty()) {
        std::cout << values.top() << " ";
        values.pop();
    }
    
    return 0;
}