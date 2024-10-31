#include <iostream>
using namespace std;
int balance = 0;
void showbalance(){
    cout<<"BALANCE = "<<balance<<"\n";
}
void deposit(int b){
    balance= b + balance;
    cout<<"AMOUNT DEPOSITED = "<<b<<"\n";
    cout<<"TOTAL BALANCE = "<<balance<<"\n";
}
void withdraw(int c){
    if(c <= balance){
    balance-=c;
    cout<<"AMOUNT withdrawn = "<<c<<endl;
    cout<<"TOTAL BALANCE = "<<balance<<endl;}
    else{
        cout<<"INSUFFICIANT BALANCE";
    }
}

int main(){
    int a,b,c;
    cout<<"*******welcome*******"<<endl;
    cout<<"Enter the value\n";
    do
    {
    cout<<" 1. showbalance "<<endl;
    cout<<" 2. deposit"<<endl;
    cout<<" 3. withdraw"<<endl;
    cout<<" 4. exit"<<endl;
    cin>>a;
    switch (a)
    {
    case 1: showbalance();
        break;
    case 2: cout<<"Enter the amount\n";
        cin>>b;
        deposit(b);
        break;
    case 3: cout<<"Enter the amount to withdraw\n";
        cin>>c;
        withdraw(c);
        break;
    case 4: cout<<"******THANK YOU*******\n";
    default:
        cout<<"**************************";
        break;
    }} while (a != 4);
return 0;
}