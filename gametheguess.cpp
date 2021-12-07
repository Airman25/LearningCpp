#include <iostream>
#include <ctime>
#include <string>
#include <array>

using namespace std;

bool nottoplay(){
    string Agreement = "";
    for(;;){
        cin >> Agreement;
        if (Agreement=="Yes"||Agreement=="yes"){
        break;
        }else if (Agreement=="No"||Agreement=="no"){
            return false;
        }else{
            cout << "Please enter yes or no" << endl;
        }
    }
    return true;
}

bool GuessedAnswer(int NumberToGuess){
    string Answer;
    cout << "Is your number " << NumberToGuess << " ? (enter yes or no)" << endl;
    for(;;){
        cin >> Answer;
        if (Answer=="Yes"||Answer=="yes"){
            break;
        }else if (Answer=="No"||Answer=="no"){
            return false;
        }else{
            cout << "Please enter yes or no" << endl;
        }
    }
    return true;
}

bool TheAlgoritm(){
    bool finished;
    int NumberToGuess;

    int NumbersAlreadyTried[10];
    for (int i=0; i<(sizeof(NumbersAlreadyTried) / sizeof(NumbersAlreadyTried[0]));i++){
        NumbersAlreadyTried[i]=0;
    }

    cout << "I understand..." << endl;
    cout << "You will now play the easy version" << endl;
    time_t t;
    srand((unsigned) time(&t));
    for (int triedfor=0;triedfor<10;triedfor++){
        while (!finished){
            finished=true;
            NumberToGuess = rand() % 100;
            
            for (int i=0; i<sizeof(NumbersAlreadyTried);i++){ // sizeof(NumbersAlreadyTried[0])) = pain (I know that I could just use 10 instead...)
                if (NumberToGuess==NumbersAlreadyTried[i]){
                    finished=false;
                    break;
                }
                if (NumbersAlreadyTried[i]==0){
                    NumbersAlreadyTried[i]=NumberToGuess;
                    break;
                }
            }
        }
        finished=false;
        //cout << NumberToGuess << " " << triedfor << endl;  //this line was used for testing purpose
        if (GuessedAnswer(NumberToGuess)){
            cout << "You lost";
            return true;
        }
    }
    cout << "Congraculations you won(or cheated)";
    return true;
}

bool TheEvenHarderAlgoritm(){
    bool finished;
    int NumberToGuess=0, max=100, min;
    string Help=">";
    int NumbersAlreadyTried[10];
    for (int i=0; i<(sizeof(NumbersAlreadyTried) / sizeof(NumbersAlreadyTried[0]));i++){
        NumbersAlreadyTried[i]=0;
    }

    cout << "Hard one? " << endl;
    time_t t;
    srand((unsigned) time(&t));
    for (int triedfor=0;triedfor<10;triedfor++){ //actually easier
        if (Help=="big"||Help=="bigger"||Help==">"){
            min = NumberToGuess;
        }else if (Help=="small"||Help=="smaller"||Help=="<"){
            max = NumberToGuess;
        }else{
            cout << "I thought you were going to help, but you cheated as ";
            return false;
        }
        finished=true;
        NumberToGuess = (rand() % (max-min))+min+1;
        //cout << NumberToGuess << " " << triedfor << endl;  //this line was used for testing purpose
        if (GuessedAnswer(NumberToGuess)){
            cout << "You lost";
            return true;
        }
        cout << "Enter is your number bigger(big; bigger; >) or smaller(small; smaller; <)";
        cin >> Help;
    }
    cout << "Congraculations you won(or somehow cheated)";
    return true;
}

int main(){
    cout << "Now you imagine a number between 0 and 100, and will try to guess it" << endl ;
    cout << "Would you help computer by saying your number is less or more than the assignment value?" << endl ;
    if (nottoplay()){
        if (TheEvenHarderAlgoritm()){
            return 0;
        }
    }
    TheAlgoritm();
    return 0;
}