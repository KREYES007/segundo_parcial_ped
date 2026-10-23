#include<iostream>


struct Node {
int data;
Node* next;
Node* prev;
};

void ReverseList(Node*& head) {
    Node* current = head;
    Node* temp = nullptr;

    while (current != nullptr) {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;
    }

    if (temp != nullptr) {
        head = temp;
    }
}


int main(){
     Node* head = new Node{10, nullptr, nullptr};
     Node* second = new Node{20, nullptr, head};
     Node* third = new Node{30, nullptr, second};
     Node* fourth = new Node{40, nullptr, third};

     head->next = second;
     second->next = third;
     third->next = fourth;

     
     std::cout << "lista original: ";
     Node* current = head;
     while (current != nullptr) {
         std::cout << current->data << " ";
         current = current->next;
     }
     

     
     ReverseList(head);

     
     std::cout << "lista reversiva: ";
     current = head;
     while (current != nullptr) {
         std::cout << current->data << " ";
         current = current->next;}

     return 0;
 }