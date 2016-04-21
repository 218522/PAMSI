#include "AssocTab.h"
#include <string>
#include<iostream>
using namespace std;

void AssocTab::set_table_size(int n){
    this->table[n];
}
// Reads first letter from name and returns hash
int AssocTab::uncode(string key){
    string alphabet = "abcdefghijklmnopqrstuvwxyz!";
    const char* alphabet_by_letter = alphabet.c_str();
    const char* key_by_letter = key.c_str();
    int i;
    for(i=0;(alphabet_by_letter[i]!=key_by_letter[0])&&i<(alphabet.size()-1);i++){}
        if(i==13){
            cout<<"Name error, cant read first letter"<<endl;
            cout<<"Can read only big letters"<<endl;
            i=13;
        }
        if(i%2==0){
            return i/2;
        }
        else{
            i=(i-1)/2;
            return i;
        }
}
// Adds new elements to table[] buckets
void AssocTab::add(element n_element){
    int hash = uncode(n_element.name);
    table[hash].add(1,n_element.name,n_element.value);
    cout<<n_element.name<<" added to bucket #"<<hash<<endl;
}

int AssocTab::how_many_elements_in_bucket(int bucket_number){
    return table[bucket_number].size();
}

int AssocTab::how_many_elements(){
    int sum = 0;
    for(int i=0;i<13;i++){
        cout<<"Bucket #"<<i<<"  Elements: "<<how_many_elements_in_bucket(i)<<endl;
    }
    for(int i=0;i<13;i++){
        sum+=how_many_elements_in_bucket(i);
    }
    cout<<"Elements at all: "<<sum<<endl;
}

void AssocTab::find_by_name(std::string name){
    int hash = uncode(name);
    cout<<"___FIND LOG___"<<endl;
    if(table[hash].first!=0){
        table[hash].find_in_list(name);
    }
    else
        cout<<"No bucket defined by that hash"<<endl;
}
