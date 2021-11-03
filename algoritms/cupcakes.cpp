//
// Created by death on 14/10/2021.
//
#include <iostream>
#include <string>

using namespace std;

void to_number_list(string data, int *list) {
    int address = 0;
    string currentNum = "";
    for (auto &c: data) {
        if (c != ' ') {
            currentNum += c;
        } else {
            list[address] = stoi(currentNum);
            address++;
            currentNum = "";
        }
    }
    list[address] = stoi(currentNum);
}

int sum_list(int start, int end, int list[]) {
    int sum = 0;
    for (int i = start; i <= end; i++) {
        sum += list[i];
    }
    return sum;
}

void check_happiness(int listSize, int cupcakes[]) {
    int maxSum = sum_list(0, listSize - 1, cupcakes);
    for (int i = 0; i < listSize - 1; i++) {
        for (int j = listSize - 2; j >= 0; j--) {
            int sum = sum_list(i, j, cupcakes);
            int sum2 = sum_list(i+1,j+1,cupcakes);
            if (sum > maxSum||sum2 > maxSum) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    int caseN = 0;
    cin >> caseN;
    for (int i = 0; i < caseN; i++) {
        string caseListS = "";
        int caseLen = 0;
        cin >> caseLen;
        int caseList[caseLen+1];
        cin.ignore();
        getline(cin, caseListS);
        to_number_list(caseListS, (int *) &caseList);
        check_happiness(caseLen, caseList);
    }
    return 0;
}