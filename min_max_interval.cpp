//
// Created by death on 03/10/2021.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Consult{
    char type;
    int index;
    int index2;
};

void min_max(vector<int>intervals,vector<Consult> tasks){
    for(auto &task:tasks){
        if(task.type=='A'){
            intervals[task.index]=task.index2;
        }else{
            vector<int> intervalsCopy;
            for(int i=task.index-1;i<=task.index2;i++){
                intervalsCopy.push_back(intervals[i]);
            }
            cout<<*min_element(intervalsCopy.begin(),intervalsCopy.end())<<" "<<*max_element(intervalsCopy.begin(),intervalsCopy.end())<<endl;
        }
    }
}


int main(){
    vector<int> data = {11, 3, 2, 4, 5, 16, 7, 18, 9, 10};
    vector<Consult> cases = {{'C',1,5},{'C',5,8}};
    min_max(data,cases);
    return 0;
}
