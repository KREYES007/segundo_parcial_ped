#include<iostream>
#include<queue>

void SeparateRequests(
std::queue<int>& requests,
std::queue<int>& priority) {

    std::queue<int> temp;

    while (!requests.empty()) {
        int currentRequest = requests.front();
        requests.pop();

        if (currentRequest % 3 == 0) {
            priority.push(currentRequest);
        } else {
            temp.push(currentRequest);
        }
    }

    
    while (!temp.empty()) {
        requests.push(temp.front());
        temp.pop();
    }
}

int main() {
    std::queue<int> requests;
    std::queue<int> priority;

    requests.push(4);
    requests.push(6);
    requests.push(9);
    requests.push(2);
    requests.push(12);
    requests.push(5);
    requests.push(7);
    requests.push(3);

    SeparateRequests(requests, priority);

    std::cout << "solicitudes: ";
    while (!requests.empty()) {
        std::cout << requests.front() << " ";
        requests.pop();
    }
    std::cout << std::endl;

    std::cout << "prioridad: ";
    while (!priority.empty()) {
        std::cout << priority.front() << " ";
        priority.pop();
    }
    std::cout << std::endl;

    return 0;
}
