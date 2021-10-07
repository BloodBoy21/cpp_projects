//
// Created by death on 03/10/2021.
//
#include <iostream>

using namespace std;

string uint32_to_ip(uint32_t ip) {
    int address[4];
    int cByte= 0;
    char buffer[30];
    for (int i = 24; i >= 0; i -= 8) {
        int addressByte=0;
        if (i == 0)addressByte = ip & 0xff;
        else addressByte = (ip >> i) & 0xff;
        address[cByte] = addressByte;
        cByte++;
    }
    sprintf(buffer,"%d.%d.%d.%d",address[0],address[1],address[2],address[3]);
    return string (buffer);
}

int main() {
   cout<< uint32_to_ip(2149583361);
    return 0;
}
