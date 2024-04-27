#include <iostream>
#include <deque>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool check_if_sells_mango(const string &name){
    char last_el = name[name.size()-1];
    return last_el=='m';
}

string BFS (unordered_map<string,vector<string>> &ppl){
    deque<string> name_order;
    //Push all the neighbours of "me"
    name_order.insert(name_order.end(),ppl["me"].begin(),ppl["me"].end());


    //Pick one neighbour
    //Check if he/she is selling mangoes
    //If yes -> return name
    //else Push all of his/her neighbours
    
    while(name_order.size()){
        string name = name_order.front();
        name_order.pop_front();
        if(check_if_sells_mango(name)){
            return name;
        }
        else{
            name_order.insert(name_order.end(),ppl[name].begin(),ppl[name].end());
        }
    }
    return "no seller was found";
}

int main(){
    unordered_map<string,vector<string>> ppl = {
        {"me",{"clare","alice","bob"}},
        {"bob",{"anuj","peggy"}},
        {"alice",{"peggy"}},
        {"clare",{"jhonny","tom"}},

    };
    string found_name = BFS(ppl);
    cout<<found_name;

    return 0;
}