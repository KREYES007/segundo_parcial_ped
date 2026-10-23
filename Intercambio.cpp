#include<iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;
};
void SwapAdjacentPairs(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* current = head;
    Node* newHead = head->next;

    while (current != nullptr && current->next != nullptr) {
        Node* nextNode = current->next;
        Node* nextNextNode = nextNode->next;

        nextNode->prev = current->prev;
        if (current->prev != nullptr) {
            current->prev->next = nextNode;
        }

        current->next = nextNextNode;
        if (nextNextNode != nullptr) {
            nextNextNode->prev = current;
        }

        nextNode->next = current;
        current->prev = nextNode;

        current = nextNextNode;
    }

    head = newHead;
}

int main() {
    Node* head = new Node{10, nullptr, nullptr};
    Node* second = new Node{20, nullptr, head};
    Node* third = new Node{30, nullptr, second};
    Node* fourth = new Node{40, nullptr, third};

    head->next = second;
    second->next = third;
    third->next = fourth;

    std::cout << "original: ";
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    SwapAdjacentPairs(head);

    std::cout << "despues: ";
    current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }

    return 0;
}
