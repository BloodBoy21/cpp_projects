//
// Created by death on 03/11/2021.
//
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node *next;

    explicit Node(int _data, Node *_next = nullptr) {
        data = _data;
        next = _next;
    }
};

class LinkedList {
private:
    vector<Node *> orderList = {};
    Node *head = nullptr;
    bool removeFlag = false;
public:
    void push_back(int data) {
        auto node = new Node(data);
        if (head == nullptr) {
            head = node;
        } else {
            auto currentNode = head;
            while (currentNode->next) {
                currentNode = currentNode->next;
            }
            currentNode->next = node;
        }
        if (!removeFlag)orderList.push_back(node);
    }

    void push_front(int data) {
        auto currentNode = new Node(data);
        if (head == nullptr) head = currentNode;
        else {
            auto fullNode = head;
            head = currentNode;
            head->next = fullNode;
        }
        orderList.insert(orderList.begin(), currentNode);
    }

    void remove(int position) {
        try {
           if(position < 0 || position >= orderList.size()) throw runtime_error("Index out of range");
            orderList.erase(position + orderList.begin());
            head = nullptr;
            removeFlag = true;
            for (auto node: orderList) {
                node->next = nullptr;
                push_back(node->data);
            }
            removeFlag = false;
        }
        catch (const std::exception &e) {
            cout<<e.what();
        }
    }

    void print() {
        auto currentNode = head;
        while (currentNode != nullptr) {
            cout << currentNode->data << "=>";
            currentNode = currentNode->next;
        }
        cout << endl;
    }
};

int main() {
    auto ll = new LinkedList();
    ll->remove(10);
    return 0;
}