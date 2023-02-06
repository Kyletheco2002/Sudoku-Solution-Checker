#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

//checks if the given sudoku solution has exactly 9 rows and 9 columns
bool is9X9grid (const vector <vector <int>> &sudokuBoard){

 if (sudokuBoard.size() == 9){
        for (int i = 0; i < 9; i++){
            if (sudokuBoard[i].size() == 9)
            {
                continue;
            } else {
                return false;
            }
        }
        return true;
 } else {
    return false;
 }
}

/*
bool elementChecking is inspired from source code in Stack Overflow
Link: https://stackoverflow.com/questions/571394/how-to-find-out-if-an-item-is-present-in-a-stdvector
Authors: SaladHead, Anselmo GPP, MSN
Authors' Profile Links (respectively):
https://stackoverflow.com/users/13751755/saladhead,
https://stackoverflow.com/users/8684057/anselmo-gpp,
https://stackoverflow.com/users/6210/msn
License: https://creativecommons.org/licenses/by-sa/4.0/
[Minor changes were made, code was slightly modified to fit its intended use, it is put in a for loop where it will return false if an element is not found]
*/

//checks if the group of numbers contains the numbers 1-9
bool elementChecking (const vector <int> &group){

    for (int i = 1; i <= 9; i++ ){
        if ( find(group.begin(), group.end(), i) != group.end()){
            continue;
        } else {
            return false;
        }
    }
return true;
}

//checks if the sudoku solution is valid
bool isValidSudokuSolution (const vector <vector <int>> &sudokuBoard){

    if (is9X9grid(sudokuBoard) != true){
        return false;
    }

    //checking by row
    for (unsigned int z = 0; z < sudokuBoard.size(); z++) {
        bool verify = elementChecking(sudokuBoard[z]);
        if (verify != true){
            return false;
        }
    }

    //checking by column
    for (unsigned int z = 0; z < sudokuBoard.size(); z++) {
        vector <int> column = {};
        for (unsigned int i = 0; i < sudokuBoard.size(); i++){
            column.push_back(sudokuBoard[i][z]);
        }
        bool verify = elementChecking(column);
        if (verify != true){
            return false;
        }
    }

    //checking by 3X3 squares
    for (int i = 0; i < 9; i = i+3){
        for (int j = 0; j < 9; j = j+3){
            vector <int> ThreeByThree = {};
            for (int row_index = j; row_index < j+3; row_index++){
                for (int col_index = i; col_index < i+3; col_index++) {
                    ThreeByThree.push_back(sudokuBoard[row_index][col_index]);
                }
            }
            bool verify = elementChecking(ThreeByThree);
            if (verify != true){
                return false;
            }
        }
    }

return true;
}

int main()
{
    /*
    test case is from Stack Overflow
    Link: https://stackoverflow.com/questions/5484629/check-if-sudoku-solution-is-valid
    Author/Writer: byenga
    Author/Writer's Profile Link:
    https://stackoverflow.com/users/4656343/byenga
    License: https://creativecommons.org/licenses/by-sa/3.0/
    [Minor changes were made, 2d character array was switched into a 2d integer vector]
    */

    vector <vector <int>> sudokuBoard = {{8,3,5,4,1,6,9,2,7},
                                         {2,9,6,8,5,7,4,3,1},
                                         {4,1,7,2,9,3,6,5,8},
                                         {5,6,9,1,3,4,7,8,2},
                                         {1,2,3,6,7,8,5,4,9},
                                         {7,4,8,5,2,9,1,6,3},
                                         {6,5,2,7,8,1,3,9,4},
                                         {9,8,1,3,4,5,2,7,6},
                                         {3,7,4,9,6,2,8,1,5}};


    cout << "The inputted sudoku solution is valid. Is this true or false?" << endl << endl;
    cout << boolalpha << isValidSudokuSolution(sudokuBoard) << endl;

    return 0;
}
