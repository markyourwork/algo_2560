#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std; 

class MindGame 
{
// constructor that is passed n and m and init the code object 
// init the code randonmly 
// generateCode(); 
// checkCorrect(); + checkIncorrect(); + member functions 

    public:

    MindGame(int n, int m); 

    //determine if the game has been one
    bool winCond=false;

    //determine what round of guessing we are on
    int guessNum = 1;  

    //right position right number
    int rightPosrightNum(); 
    
    //right number wrong position
    int wrongPosrightNum();
    
    void guessCodeVerify(); 
    
    //takes in user input to populate the guessCode vector
    void inputGuess();
    
    //prints a given vector; usful for debugging
    void printCode(vector<int> code);
    
    // the given length of the codes
    int length; 

    vector<int> masterCode;
    //the randomly generated Master Code
    vector<int> guessCode; 
    //the user-inputed guess of the Master Code

    private: 

     // the max of the range to generate values for the codes; from 0 to range -1
    int range;
   
    void generateMasterCode(); 

};



MindGame::MindGame(int y, int z)
// constructor 
// initialize the secreat code, length, range
// resize guess code vector size 

{
    length = y; 
    range = z;
    generateMasterCode();
    cout << "The secret code: ";
    printCode(masterCode);
    cout<<"\n";
    //guessCode.resize(y);
} // end of constructor 

void MindGame::printCode(vector <int> c0de)
//prints a given code, useful for debugging
{
    for(int i=0; i<c0de.size(); i++)
        cout<<c0de[i]<<", ";
}

void MindGame::inputGuess()
//populates the guessCode vector with values the user inputs
{
    cout<<"Input your guess 1 digit at a time, followed by an enter:\n";
    int input;
    while (guessCode.size() < masterCode.size())
    {
        cin >> input;
        guessCode.push_back(input);
    }
    //printCode(guessCode);
    //for bebugging
}

void MindGame::generateMasterCode() 
// generate the secret code 
{ 
    srand(time(NULL)); 

        for (int i = 1; i <= length; i++)
        { 
            masterCode.push_back(rand()% range);
        } 
    printCode(masterCode);
}

//COME BACK TO BELOW FX
int MindGame::rightPosrightNum()
// returns how many digits are in the correct position
{
    int count = 0; 
    for (int i=0; i < masterCode.size(); i++)
    {
        if (guessCode[i] == masterCode[i]){
            count++;
        } 
    }
    return count; 
}


// creates temporary vectors to pass the secret and guess vector to so the original

// values are not alterd and then passes the temporary vectors and returns how many

// digits are in the incorrect position

//come back to this
int MindGame::wrongPosrightNum()
{
vector<int> copyMasterCode = masterCode;
sort( copyMasterCode.begin(), copyMasterCode.end() );
//^ in order for the uniquq()fx to work properly, the vector must first be ordered, here it is ordered with sort

copyMasterCode.erase( unique( copyMasterCode.begin(), copyMasterCode.end() ), copyMasterCode.end() );
//^ removes all duplicate values and sets copyMasterCode to a vector of just the unique numbers in the Master Code
//cout<<"\nCopyMasterCode post sorting ";
//printCode(copyMasterCode);
//cout<<"\n";
int count =0;
for(int i=0; i < guessCode.size(); i++){

    for(int j=0; j < copyMasterCode.size(); j++){
        //cout<<guessCode[i]<<" compared to "<< copyMasterCode[j]<<"\n";
        if(guessCode[i]==copyMasterCode[j]){
            //cout<<"Count increased by 1\n";
            count++;
            break;
        }
    }
}
//this will double count numbers in the right position and right number so those need to be subtracted from the total
//cout<<"Total Count "<<count<<" decreased by "<<rightPosrightNum();
return count-rightPosrightNum();
}// end checkIncorrect

void MindGame::guessCodeVerify()
// passes the guess vector to checkCorrect and checkIncorrect functions 
{
    //cout << "The number of digits in the correct position " << checkCorrect(guessCode) << endl; 
    //cout << "The number of digits in the incorrect position " << checkIncorrect(guessCode) << endl; 

}