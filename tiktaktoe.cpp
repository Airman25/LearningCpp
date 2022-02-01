#include <iostream >
using namespace std;

void Print_Array(int *a, int N, int M)
{
    for(int i=0; i<N*M; i++)
    {   
        //cout << *(a+i) << " ";
        if (*(a+i)==0){
                cout << "[ ]";
            }else if (*(a+i)==1) {
                cout << "[x]";
            }else{
                cout << "[o]";
            }
        if ((i+1)%M==0) cout << endl;
    }
    cout << endl;
}

void Add_to_array(int *a, int &x, int &y, bool &XnotO){
    if ((*(a+x-1+(3*(y-1)))!=0)|| x>3 || y>3){ //x-1+(3*(y-1))
        cout << "Invalid coordinates " << *(a+x-1+(3*(y-1))) << endl;
    }else{
        if (XnotO){
            *(a+x-1+(3*(y-1)))=1;
            XnotO=false;
                    
        }else{
            *(a+x-1+(3*(y-1)))=2; //
            XnotO=true;
        }
    }
}

void CheckCollum(int *a, bool &won){
    //collums
    for (int i=0; i<3; i++){
        if (*(a+i)==*(a+i+3) && *(a+i)==*(a+i+6) && *(a+i)!=0){
            //cout << "Collum! " << S[i];
            won = true;
            break;
        }
    }
}

void CheckRow(int *a, bool &won){
    //rows
    for (int i=0; i<3; i++){
        if (*(a+(i*3))==*(a+(i*3)+1) && *(a+(i*3))==*(a+(i*3)+2) && *(a+(i*3))!=0){
            //cout << "Row! " << S[i];
            won = true;
            break;
        }
    }
            
}

void CheckDiagonal(int *a, bool &won){
    //diagonals
    for (int i=0; i<2; i++){
        if (*(a+(i*2))==*(a+4) && *(a+(i*2))==*(a+8-(i*2)) && *(a+(i*2))!=0){
            //cout << "Diagonal! " << S[i];
            won = true;
            break;
        }
    }
}

void CheckTie(int *a, bool &tie){
    for (int i=0; i<9; i++){
        //cout << "Check for 0: " << S[i];
        if (*(a+i)==0){
            break;
        }
        if (i==8){
            if (*(a+i)!=0){
                tie = true;
                break;
            }
        }
    }
}

bool LogicRow(int *a, int row, int skipit){
    bool found = false;
    for (int i=0; i<3;i++){
        if (*(a+i+((row-1)*3))==1){
            return false;
        }
        if (*(a+i+((row-1)*3))==2 && i!=skipit-1){
            found = true;
        }
    }
    if(found){
        return true;
    }
    return false;
}

bool LogicCollum(int *a, int collum, int skipit){
    bool found = false;
    for (int i=0; i<3;i++){
        if (*(a+(i*3)+collum-1)==1){
            return false;
        }
        if (*(a+(i*3)+collum-1)==2 && i!=skipit-1){
            found = true;
        }
    }
    if(found){
        return true;
    }
    return false;
}

void FindTheLogic(int *a, int &x, int &y){
    if (*(a+4)==0 && *(a)==0 && *(a+2)==0 && *(a+6)==0 && *(a+8)==0){
        x=2;
        y=2;
        return;
    }
        //priority  to check for the program to first fill rows with x not o
        for (int i2=1; i2<3; i2++){
            //row check
            for (int i=0; i<3; i++){
                if ( *(a+(i*3)+1)==*(a+(i*3)+2) && *(a+(i*3))==0 && *(a+(i*3)+1)==i2){
                    x = 1;
                    y = i+1;
                    return;
                }
                if ( *(a+(i*3))==*(a+(i*3)+2) && *(a+(i*3)+1)==0 && *(a+(i*3))==i2){
                    x = 2;
                    y = i+1;
                    return;
                }
                if (*(a+(i*3))==*(a+(i*3)+1) && *(a+(i*3)+2)==0 && *(a+(i*3))==i2){
                    x = 3;
                    y = i+1;
                    return;
                }
            }
            //collum check
            for (int i=0; i<3; i++){
                if (*(a+i+6)==*(a+i+3) && *(a+i)==0 && *(a+i+6)==i2){
                    x = i+1;
                    y = 1;
                    return;
                }
                if (*(a+i)==*(a+i+6) && *(a+i+3)==0 && *(a+i)==i2){
                    x = i+1;
                    y = 2;
                    return;
                }
                if (*(a+i)==*(a+i+3) && *(a+i+6)==0 && *(a+i)==i2){
                    x = i+1;
                    y = 3;
                    return;
                }
            }
            //diagonal check
            for (int i=0; i<2; i++){
                if (*(a+(i*2))==*(a+4) && *(a+8-(i*2))==0 && *(a+(i*2))==i2){
                    x = 3-(i*2);
                    y = 3;
                    return;
                }
                if (*(a+(i*2))==*(a+8-(i*2)) && *(a+4)==0 && *(a+(i*2))==i2){
                    x = 2;
                    y = 2;
                    return;
                }
                if (*(a+4)==*(a+8-(i*2)) && *(a+(i*2))==0 && *(a+4)==i2){
                    x = 1+(i*2);
                    y = 1;
                    return;
                }
            }
        }
        //random - it was the way it did initially, but I won once, so I need to make it think 1 turn forward
        /*
        for (int i=0; i<9; i++){
            //cout << "Check for 0: " << S[i];
            if (*(a+i)==0){
                x = 1+(i%3);
                y = 1+(i/3);
                return;
            }
        }
        */

       

       //1 turn forward
       //diagonal place is the best in case center is not free, because you could go 2 sides
        for(int i2=1;i2<4;i2++){//all collums
            for(int i=1; i<4;i++){ //all row
                if(LogicRow(a,i2, i) && LogicCollum(a, i, i2)){
                    x=i;
                    y=i2;
                    return;
                }
            }
        }
        
        //if the first turn is diagonal it is very hard to handle, because if we place in the middle, there is a strategy for player-me to always win
        //if it is the first turn then we just place it in the opposite direction
        if(*(a)==2 && *(a+8)==0){
            x = 3;
            y = 3;
            return;
        }
        if(*(a)==0 && *(a+8)==2){
            x = 1;
            y = 1;
            return;
        }
        if(*(a+2)==2 && *(a+6)==0){
            x = 1;
            y = 3;
            return;
        }
        if(*(a+2)==0 && *(a+6)==2){
            x = 3;
            y = 1;
            return;
        }
        //the second turn when player placed in the middle
        //just return 1 of the free diagonal places
        if(*(a)==0){
            x=1;
            y=1;
            return;
        }
        if(*(a+2)==0){
            x=3;
            y=1;
            return;
        }
        if(*(a+6)==0){
            x=1;
            y=3;
            return;
        }
        if(*(a+8)==0){
            x=3;
            y=3;
            return;
        }
}

int main()
{   
    /*
    [][][]
    [][o][]
    [][][]
    
    [x][][]
    [][o][]
    [][][]

    [x][][o]
    [][o][]
    [][][]

    [x][][o]
    [][o][]
    [x][][]

    [x][][o]
    [][o][o]
    [x][][]

    [][x][o]
    [x][o][o]
    [x][][o]
    */
    const int N = 9;
    int S[N];
    bool exit;
    while(!exit){
        for (int i=0; i<N; i++){
            S[i] = 0;
        }
        int players;
        cout << "how many players? 1 or 2?";
        cin >> players;
        while (players!=1 && players!=2)
        {
            cout << "Please, enter 1 or 2!";
            cin >> players;
        }
        bool won = false;
        bool XnotO = false;
        if (players==1){
            int Playerchoice = 2; //1=x 2=o
            while(!won){
                int x, y;
                Print_Array(S, 3, 3);
                /*
                if (Playerchoice==1){
                    if (XnotO){
                        cout << "Enter coordinates: ";
                        cin >> x >> y;
                        Add_to_array(S, x, y, XnotO);
                    }else{
                        FindTheLogic(S, x, y);
                        Add_to_array(S, x, y, XnotO);
                    }
                    */
                //}else{
                    if (!XnotO){
                        cout << "Enter coordinates: ";
                        cin >> x >> y;
                        Add_to_array(S, x, y, XnotO);
                    }else{
                        FindTheLogic(S, x, y);
                        Add_to_array(S, x, y, XnotO);
                    }
                    //Add_to_array(S, x, y, XnotO);
                //}
                CheckCollum(S, won);
                CheckRow(S, won);
                CheckDiagonal(S, won);
                if (!won){
                    bool tie;
                    CheckTie(S, tie);
                    if (tie){
                        break;
                    }
                }
            }
            Print_Array(S, 3, 3);
            if (won){
                if (XnotO){
                    cout << "O won! ";
                }else{
                    cout << "X won! ";
                } 
            }else{
                cout << "A tie! ";
            }
        }else{
            while(!won){
                int x, y;
                Print_Array(S, 3, 3);
                cout << "Enter coordinates: ";
                cin >> x >> y;
                Add_to_array(S, x, y, XnotO);
                CheckCollum(S, won);
                CheckRow(S, won);
                CheckDiagonal(S, won);
                if (!won){
                    bool tie;
                    CheckTie(S, tie);
                    if (tie){
                        break;
                    }
                }
            }
            Print_Array(S, 3, 3);
            if (won){
                if (XnotO){
                    cout << "O won! ";
                }else{
                    cout << "X won! ";
                } 
            }else{
                cout << "A tie! ";
            }
        }
        cout << endl;
        string playagain;
        cout << "Do you want to play again?" << endl ;
        cin >> playagain;
        if (!(playagain=="yes"||playagain=="y"||playagain=="Yes"||playagain=="Y"||playagain=="yes!"||playagain=="Yes!")){
            exit = true;
        }
    }
    system ("pause");
    return 0;
    //total conclusion if player turn is 1st then there is a way to always win a game no matter what
}