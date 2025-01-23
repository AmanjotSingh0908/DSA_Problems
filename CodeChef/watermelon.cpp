#include<iostream>
#include<cmath>
using namespace std;


int main() {
    int weight;
    cin>>weight;

    if (weight > 2 && (weight%2 == 0)){
        cout<<"Yes";
    } else {
        cout<<"No";
    }

    return 0;
}