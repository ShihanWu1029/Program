#include <bits/stdc++.h>
using namespace std;

void Editor(){

}
void Filer(){

}
bool Statement=false;;
int main(){
    ios::sync_with_stdio(false);
    Target: ;
    cout<<"-- IWD File Type --\n";
    //Choose Input Type
    cout<<"Already have a file?(y/n): ";
    char YorN;
    cin>>YorN;
    if(YorN=='y' || YorN=='Y'){
        Editor();
    }else if(YorN=='n' || YorN=='N'){
        Filer();
    }else{
        if(!Statement){
            cout<<"Choose a input type, please.\n";
            Statement=true;
            goto Target;
        }
    }
}