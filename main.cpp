#include<iostream>
using namespace std;

const int SIZE = 9;

void printBoard(char box[]);
int checkWin(int win, char box[]);

int main(){
	char ready;

	char box[SIZE] = {'1','2','3','4','5','6','7','8','9'};

	int  win = 0 ;
	int  pnum = 1 ;
	int boxnum;
	int i = 0;

	//print rules
	cout<<"\n"<<"TIC TAC TOE"<<endl<<endl;

	printBoard(box);


	cout<<"\nRules:"<<endl;
	cout<<"Pick a box number when prompted."<<endl;

	//r u ready
	cout<<"Press letter 'R' if ready to begin."<<endl;
	cin >>ready;

	if(ready == 'r' || ready == 'R'){
            cout<<endl<<"LET THE GAMES BEGIN!!"<<endl<<endl;
	}else {
		return 1;
	}

	//players enter number
	do{
		cout<< "Player "<<pnum<<", enter a box number : ";
		cin>> boxnum;
		if(boxnum>=1&&boxnum<=9){
			if (pnum == 1){
                int b = boxnum-1;
                if(box[b]!='X'&&box[b]!='O'){
                    box[b]='X';
                }else{
                    cout <<"Look that box is occupied"<<endl;
                    pnum--;
                    i--;
                }
				printBoard(box);
				pnum++;
				i++;

            }else if(pnum==2){
                int b = boxnum-1;
                if(box[b]!='X'&&box[b]!='O'){
                    box[b]='O';
                }else{
                    cout <<"Look that box is occupied"<<endl;
                    pnum++;
                    i--;
                }

				printBoard(box);
				pnum--;
				i++;

			}else{
			cout <<"ERROR";
			}

		}else{
			cout <<"Enter number between 1 and 9.";
		}

		//check to see who won
		if(i>=3&& i< 9){
            win = checkWin(win, box);
		}
        //sets winner to draw if its the end of the game
		if(i==9){
			win = 2;
		}

	}while (win==0);

    //updates the player number
	if(pnum==1){
		pnum++;
	}else{
		pnum--;
	}
    //tells who won
	if(win==2){
		cout<<"Draw"<<endl;
		return 2;
	}else {
		cout<<"The winner is : Player "<<pnum<<endl;
	}

	return 0;
}
//this function prints the board
void printBoard(char box[9]){

    cout<<"  "<<box[0]<<" |  "<<box[1]<<" |  "<<box[2]<<" "<<endl;
	cout<<"----|----|----"<<endl;
	cout<<"  "<<box[3]<<" |  "<<box[4]<<" |  "<<box[5]<<" "<<endl;
	cout<<"----|----|----"<<endl;
	cout<<"  "<<box[6]<<" |  "<<box[7]<<" |  "<<box[8]<<" "<<endl<<endl;

}
//this function checks if anyone has won
int checkWin(int win, char box[]){
    if(box[0]==box[1]&&box[1]==box[2]){
        win=1;
    }else if(box[3]==box[4]&&box[4]==box[5]){
        win=1;
    }else if(box[6]==box[7]&&box[7]==box[8]){
        win=1;
    }else if(box[0]==box[3]&&box[3]==box[6]){
        win=1;
    }else if(box[1]==box[4]&&box[4]==box[7]){
        win=1;
    }else if(box[2]==box[5]&&box[5]==box[8]){
        win=1;
    }else if(box[0]==box[4]&&box[4]==box[8]){
        win=1;
    }else if(box[2]==box[4]&&box[4]==box[6]){
        win=1;
    }else {
        win=0;
    }
    return win;
}
