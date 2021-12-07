#include <iostream>
#include <ctime>
#include <string>

using namespace std;

bool nottoplay(){
    string Agreement = "";
    for(;;){
        cin >> Agreement;
        if (Agreement=="Yes"||Agreement=="yes"){
        break;
        }else if (Agreement=="No"||Agreement=="no"){
            return true;
        }else{
            cout << "Please enter yes or no" << endl;
        }
    }
    return false;
}

bool playing(){
    int NumberToGuess, Answer, triedfor=0;
    time_t t;
    srand((unsigned) time(&t));
    Answer = rand() % 100;
    cout << "Enter your number" << endl;
    cin >> NumberToGuess;
    for (; Answer!=NumberToGuess&&triedfor<10; triedfor++){
        if (Answer>NumberToGuess) {
            cout << "Answer is larger than your number, try a bigger value" << endl;
        }else {
            cout << "Answer is smaller than your number, try a smaller value" << endl;
        }
        cin >> NumberToGuess;
    }
    if (Answer==NumberToGuess){
        cout << "You won congraculations" << endl;
        cout << "You guessed right on " << triedfor << " attempt" << endl;
    }else{
        cout << "Sadly you lost, the answer was" << Answer << endl;
    }
    cout << "Do you want to play again?" << endl ;
    return true;
}

int main(){
    cout << "Programm generated a number between 0 and 100, would you try to guess it?" << endl ;
    for(;;){
        if (nottoplay()){
            return 0;
        }
        playing();
    }
}