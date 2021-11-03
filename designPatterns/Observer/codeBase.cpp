//
// Created by death on 23/10/2021.
//

#include <iostream>
#include <list>

using namespace std;

//Class father to observers
class IObserver {
public:
    virtual ~IObserver() {};

    virtual void Update(const string &message_from_subject) = 0;
};

class ISubject {
public:
    virtual ~ISubject() {};

    virtual void Attach(IObserver *observer) = 0;

    virtual void Detatch(IObserver *observer) = 0;

    virtual void Notify() = 0;
};

class Subject : public ISubject {
public:
    virtual ~Subject() {
        cout << "Goodbye subject " << endl;
    }

    void Attach(IObserver *observer) override {
        list_observer.push_back(observer);
    }

    void Detatch(IObserver *observer) override {
        list_observer.remove(observer);
    }

    void Notify() override {
        list<IObserver *>::iterator iterator = list_observer.begin();
        HowManyObserver();
        while (iterator != list_observer.end()) {
            (*iterator)->Update(message_);
            ++iterator;
        }
    }

    void CreateMessage(string message = "Empty") {
        this->message_ = message;
        Notify();
    }

    void HowManyObserver() {
        cout << "There are " << list_observer.size() << " observers in the list" << endl;
    }

    void newProduct() {
        this->message_ = "New  product on the market";
        Notify();
        cout << "Alert sent" << endl;
    }

private:
    list<IObserver *> list_observer;
    string message_;
};

class Observer : public IObserver {
public:
    Observer(Subject &subject) : subject_(subject) {
        this->subject_.Attach(this);
        this->number_ = Observer::static_number_++;
        cout << "Hi i'm the observer " << this->number_ << endl;
    }

    virtual ~Observer() {
        cout << "Goodbye i was the observer " << this->number_ << endl;
    }

    void Update(const string &message_from_subject) override {
        message_from_subject_ = message_from_subject;
        PrintInfo();
    }

    void RemoveFromTheList() {
        subject_.Detatch(this);
        cout << "Observer " << number_ << " removed from the list" << endl;
    }

    void PrintInfo() {
        cout << "Observer " << this->number_ << " there is a new message: " << this->message_from_subject_ << endl;
    }

private:
    string message_from_subject_;
    Subject &subject_;
    static int static_number_;
    int number_;
};

int Observer::static_number_ = 0;

int main() {
    auto *subject = new Subject;
    auto *observer1 = new Observer(*subject);
    auto *observer2 = new Observer(*subject);
    auto *observer3 = new Observer(*subject);
    subject->CreateMessage("SEXOOO");
    observer3->RemoveFromTheList();
    delete observer1;
    auto *observer4 = new Observer(*subject);
    subject->newProduct();
    delete subject;
    return 0;
}