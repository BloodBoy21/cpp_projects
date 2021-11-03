//
// Created by death on 28/10/2021.
//
#include <iostream>
#include<list>
#include <string>
#include <sstream>

using namespace std;

typedef struct {
    string name;
    int available;
    int price;
} productS;

class IObserver {
public:
    virtual ~IObserver() {};

    virtual void update(const string &_message) {};
};

class ISubject {
public:
    virtual ~ISubject() {};

    virtual void attach(IObserver *observer) = 0;

    virtual void detatch(IObserver *observer) = 0;

    virtual void notify() = 0;
};

class Store : public ISubject {
private:
    list<IObserver *> clients;
    string message;
    list<productS> items;
public:
    virtual  ~Store() {
        cout << "Store section deleted" << endl;
    }

    void attach(IObserver *client) override {
        clients.push_back(client);
    }

    void detatch(IObserver *client) override {
        clients.remove(client);
    }

    void notify() override {
        list<IObserver *>::iterator iterator = clients.begin();
        while (iterator != clients.end()) {
            (*iterator)->update(message);
            ++iterator;
        }
    }

    void create_update(string _message = "Empty") {
        this->message = move(_message);
        notify();
        cout << "Update sent" << endl;
    }

    void add_product(productS product) {
        ostringstream s;
        items.push_back(product);
        s << "Product:" << product.name << "\nPrice:" << product.price << "\nAvailable:" << product.available << endl;
        string productInfo = s.str();
        s.clear();
        create_update(productInfo);
    }

};

class Client : public IObserver {
private:
    string newInfo;
    Store &store;
public:
    Client(Store &_store) : store(_store) {
        this->store.attach(this);
        cout << "New Client" << endl;
    };

    virtual ~Client() {
        cout << "Client deleted" << endl;
    }

    void update(const string &_message) override {
        newInfo = _message;
        cout<<"New updates from the store"<<endl;
        cout << newInfo << endl;
    }
};

int main() {
    auto *electronics = new Store;
    auto *client1 = new Client(*electronics);
    electronics->add_product({"Lenovo idepad 100", 100, 5000});
    delete client1;
    return 0;
}