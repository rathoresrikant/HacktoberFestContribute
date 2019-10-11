#include <iostream>
#include <vector>

/*
    Example:
    Input:
    {1, 0, 3, 2, 0, 4}
    Output:
    {1, 3, 2, 4, 0, 0}
*/

void moveZeroes(vector<int>& vIntegers) {
    int iK = 0;
    for (int i = 0; i < vIntegers.size(); i++){
            if (vIntegers[i]){
                swap(vIntegers[iK++], vIntegers[i]);
            }
    }
}

int main(){
    /*
    here or in any other function we should declare a vector
    and call our moveZeroes function to modify our vector the way we want
    */
}