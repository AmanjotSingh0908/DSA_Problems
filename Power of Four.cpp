#include <iostream>
using namespace std;

bool isPowerOfFour(int n){
    if(n<=0){
        return false;
    }
    if((n & (n-1)) != 0){
        return false;
    }
    return (n & 0x55555555) == n;

}

int main(){
    isPowerOfFour(16);

    return 0;
}