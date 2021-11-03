//
// Created by death on 23/10/2021.
//

#include "main.h"
#include <iostream>

using namespace std;

class Singleton {
private:
    string name;
protected:
    Singleton(string);

    static Singleton *_Singleton;
public:
    static Singleton *get_instance(string);

    Singleton(const Singleton &) = delete;

    void operator=(const Singleton &) = delete;

    string get_name() {
        return name;
    }
};

Singleton *Singleton::_Singleton = nullptr;

Singleton::Singleton(string _name) {
    name = _name;
}

Singleton *Singleton::get_instance(string _name) {
    if (_Singleton == nullptr)_Singleton = new Singleton(_name);
    return _Singleton;
}


int main() {
    Singleton *s = Singleton::get_instance("Alan");
    Singleton *w = Singleton::get_instance("Manuel");
    cout<<"S_NAME:"<<s->get_name()<<endl;
    cout<<"W_NAME:"<<w->get_name()<<endl;
    return 0;
}