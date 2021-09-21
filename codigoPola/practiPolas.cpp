#include <vector>
#include <iostream>

using namespace std;

//Write an algorithm that takes an array and moves all of the zeros to the end, preserving the order of the other elements.

vector<int> move_zeroes(vector<int> &input) {

    for (int i = 0; i < input.size(); i++ ){
        if (input[i] == 0){
           /*int temp = input[input.size()-1];
           input[input.size()-1] = input[i];
           input[i] = temp;*/
           input.erase(input.begin()+i);
           input.push_back(0);
        }
    }
    return input;
}

int main(){            //0  1  2  3  4  5  6       índices
    vector<int> input = {1, 0, 1, 2, 0, 1, 3}; //// returns {1, 1, 2, 1, 3, 0, 0}

    move_zeroes(input);

    for (int i = 0; i < input.size(); i++ ){
        cout << input[i] << ", ";
    }

    return 0;
}
