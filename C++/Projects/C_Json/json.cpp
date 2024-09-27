#pragma once
#include <iostream>
#include <fstream>

#define basic_info
#define c_json_author "S.W."
#define c_json_version "0.0.0 alpha"
#define c_json_latest_update 20240801ll
#define c_json
#undef basic_info

//Switch Of Information Putting:
#define _putinfo 1 
//Switch Of FilePath Input
#define _filepath_from_input

using namespace std;

class _JSONFILE{
    private:
        string path;
    public:
        string getpath(){return path;}
        string setpath(string init){return path = init;}
};

void ReadJson();
void PutInfo();

int main(){
    #ifdef _putinfo
    PutInfo();
    #endif

    _JSONFILE __json;
    string filepath;
    #ifdef _filepath_from_input
    ios::sync_with_stdio(0);
    cin>>filepath;
    __json.setpath(filepath);
    #endif

    ifstream Read_From_File(__json.getpath().c_str());
        
}

void PutInfo(){
    cout<<"*******Read Json With C++*******\nAuthor: "<<c_json_author<<"\nVersion: "<<c_json_version<<"\nLatest Update: "<<to_string(c_json_latest_update)<<"\n********************************\n";
}