#include<iostream>
#include<string>

int main() {
    std::string moves;
    std::cin>>moves;

    int position = 1;

    for(char move : moves){
        if(move == 'A'){
            if(position == 1) {
                position = 2;
            } else if(position == 2){
                position = 1;
            } 
        } else if(move == 'B') {
            if(position == 2) {
                position = 3;
            } else if(position == 3) {
                position = 2;
            }
        } else if (move == 'C') {
            if(position == 1) {
                position = 3;
            } else if(position == 3) {
                position = 1;
            }
        } 
    }

    std::cout << position <<std::endl;

    return 0;
}