#include <QApplication>

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "mainwindow.h"
//#include "mainwindow1.h"

using namespace std;


int main(int argv, char* argc[])
{
		//opening mainwindow1
		//QApplication app( argv, argc );
		//MainWindow1 mw1;
		//mw1.show();
		
		QApplication app( argv, argc );
		MainWindow mw;
		mw.show();
		


//Dont really use any of these functions and code, instead the majority of the code will be implemented in mainwindow.cpp
/*int randomNum()//randomNum generator
{
	srand(time(0));
	int	cardNum;
	cardNum= rand()%10;
	return cardNum;
}

int randomSpace()//randomCard generator
{
	srand(time(0));
	int	spaceNum;
	spaceNum= rand()%39;
	return spaceNum;
}


int main(int argv, char* argc[])
{
		QApplication app( argv, argc );
		MainWindow mw;
		mw.show();

		//declaration of global variables
		int num = 10;
		string pieces[num];
		
		int numPlayers; 
		MoveAction cardMove[2];
		Bank cardMoney[8];
		Bank money; 
		MoneyAction a;
		GotoAction gt; 
		House h; 
		Cards cards[10];
		bool play = true; 

		Cards cards1[10];
		//bool rolling = false;
				bool sale[21] = {false}; 
				int pl[21];

		char yes; 
//setting the 10 pieces
		pieces[0] = "*" ;
		pieces[1] = "@" ;
		pieces[2] = "^" ;
		pieces[3] = "%" ;
		pieces[4] = "$" ;
		pieces[5] = "#" ;
		pieces[6] = "!" ;
		pieces[7] = "?" ;
		pieces[8] = "+" ;
		pieces[9] = "=" ;
//setting the cards
		cards[0].setName("Move Forward 2 Spaces"); //moveAction
		cards[1].setName("Move Forward 1 Spaces"); //moveAction
		cards[2].setName("Pay $100 to Bank");
		cards[3].setName("Pay $200 to Bank");
		cards[4].setName("Pay $300 to Bank");
		cards[5].setName("Pay $400 to Bank");
		cards[6].setName("Pay $500 from Bank");
		cards[7].setName("Pay $600 from Bank");
		cards[8].setName("Pay $700 from Bank");
		cards[9].setName("Pay $800 from Bank");

		cards1[0].setName("Move Forward 2 Spaces"); //moveAction
		cards1[1].setName("Move Forward 1 Spaces"); //moveAction
		cards1[2].setName("Gain $100 to Bank");
		cards1[3].setName("Gain $200 to Bank");
		cards1[4].setName("Gain $300 to Bank");
		cards1[5].setName("Gain $400 to Bank");
		cards1[6].setName("Gain $500 from Bank");
		cards1[7].setName("Gain $600 from Bank");
		cards1[8].setName("Gain $700 from Bank");
		cards1[9].setName("Gain $800 from Bank");

//initializing the gameboard


		GameBoard g;
		 //rules
		cout<<"Rules:: This game is similar to an actual Monopoly game where players will go around the board buying properties, upgrading properties, drawing cards, and landing on spaces that teleports you random places. One thing to note that this is speed Monopoly where all the properties are on the top and bottom row and the rent increases by a lot when a house is bought/upgraded. All the money transfering and displaying bought/upgraded properties will be updated AFTER all players have gone 1 round. Also, each player will receive $100 every round from the bank. Once a player's money drops $600, a warning message will be displayed asking the player if he wants to resign. Once a player's money drops below $0, the game will end. The game will end when a player resign as well. As soon as one player resigns or loses due to negative money, whoever has the most money at that time will be declared the winner. In this game, a player is not forced to buy/upgrade a property every time. If after a player buy/upgrade a property has no money left, he will automatically lose."<<endl<<endl;
		string temp[10];
		
		for (int k=0; k<10; k++)
		{
			temp[k] = pieces[k];
		}
		
		int flag=0;
		//int flag2=0;
		int choice; 
		//int temp[numPlayers];
		while (flag == 0){//prompting the user for player numbers
			cout<<"Enter The Number of Players between 2 to 4: ";
			cin>>numPlayers;
			if(cin.fail()){
				cout<<"You did not enter an integer. Please Restart "<<endl;
				exit(0);
			}

			if (numPlayers > 1 && numPlayers < 5){
				cout<<"Enter a proper number of players"<<endl;
				flag = 1; 
			}
		}

			Players* players = new Players[numPlayers];//dynamically allocating the number of players

			/*for (int r=0; r<16; r++){
				houses[r].setNumHouse();
			}
		bool* bought[21];
		for (int x=0; x<21; x++){
			bought[x] = new bool[numPlayers]();
		}   
		
		for (int x=0; x<numPlayers; x++)
		{
			//while (flag2 == 0){
			cout<<"Here are the pieces...DO NOT SELECT THE SAME PIECE OR GAME WILL START OVER"<<endl;
				for (int y=0; y<num; y++)//making sure the subsequent player do not choose the same piece, if they do, program will end
				{
					cout<<"("<<y<<")"<<pieces[y]<<"  ";
				}

				cout<<"Select the piece for player "<<x+1<<endl;
				cin>>choice; 
				//start over if players pick a piece that has already been taken
				while (choice > num-1)
				{
					cout<<"This piece has been taken already. Start over and pick new pieces"<<endl;
					exit(0);
				}

				cout<<"Player "<<x+1<<" selected "<<players[x].setName(pieces[choice])<<endl;//using setName to give player the piece
				
				for (int a=choice; a<num-1; a++)
				{
					pieces[a] = pieces[a+1];
				}
				pieces[num-1] = "TAKEN";
				num--;
			
		}
			
	cout<<endl<<endl<<endl;


	//g.choosePlayers();
	for (int x=0; x<numPlayers; x++){//set the starting positions of the players
		players[x].setPosition();
		players[x].setMoney(5000);
		cout<<"Player "<<x+1<<" has $"<<players[x].getMoney()<<endl;
	}
	money.setBank(10000000);//setting the bank money
	//printing the board
	g.printTopRow(g.getSpaces(), g.getAction(), 9, numPlayers, players, a, gt, h);
	g.printOtherRow(g.getSpaces(), g.getAction(), 8, numPlayers, players, a, gt, h);
	g.printOtherRow(g.getSpaces(), g.getAction(), 7, numPlayers, players, a, gt, h);
	g.printOtherRow(g.getSpaces(), g.getAction(), 6, numPlayers, players, a, gt, h);
	g.printOtherRow(g.getSpaces(), g.getAction(), 5, numPlayers, players, a, gt, h);
	g.printOtherRow(g.getSpaces(), g.getAction(), 4, numPlayers, players, a, gt, h);
	g.printOtherRow(g.getSpaces(), g.getAction(), 3, numPlayers, players, a, gt, h);
	g.printOtherRow(g.getSpaces(), g.getAction(), 2, numPlayers, players, a, gt, h);
	g.printOtherRow(g.getSpaces(), g.getAction(), 1, numPlayers, players, a, gt, h);
	g.printOtherRow(g.getSpaces(), g.getAction(), 0, numPlayers, players, a, gt, h);
	g.printBottomRow(g.getSpaces(), g.getAction(), 39, numPlayers, players, a, gt, h);

	//int ll=0;
	while (play)//print the board as long as every player has money. Runs 5 times for now since i havent implemented money
	{
		for (int z=0; z<numPlayers; z++){
			cout<<"Player "<<z+1<<" has $"<<players[z].getMoney()<<endl;
		}
		for (int y=0; y<numPlayers; y++){
			//while (!rolling){
				cout<<"Does Player "<<y+1<<" Wish to Roll the Dice? (y/n) "<<endl;//asking the player to roll dice
				cin>>yes;
				if (yes == 'y'){
					cout<<"Player "<<y+1;
					players[y].movePosition();
					//rolling = true; 
					
				//}
				}
			//print the board
			g.printTopRow(g.getSpaces(), g.getAction(), 9, numPlayers, players, a, gt, h);
			g.printOtherRow(g.getSpaces(), g.getAction(), 8, numPlayers, players, a, gt, h );
			g.printOtherRow(g.getSpaces(), g.getAction(), 7, numPlayers, players, a, gt, h );
			g.printOtherRow(g.getSpaces(), g.getAction(), 6, numPlayers, players, a, gt, h );
			g.printOtherRow(g.getSpaces(), g.getAction(), 5, numPlayers, players, a, gt, h );
			g.printOtherRow(g.getSpaces(), g.getAction(), 4, numPlayers, players, a, gt, h );
			g.printOtherRow(g.getSpaces(), g.getAction(), 3, numPlayers, players, a, gt, h );
			g.printOtherRow(g.getSpaces(), g.getAction(), 2, numPlayers, players, a, gt, h );
			g.printOtherRow(g.getSpaces(), g.getAction(), 1, numPlayers, players, a, gt, h );
			g.printOtherRow(g.getSpaces(), g.getAction(), 0, numPlayers, players, a, gt, h );
			g.printBottomRow(g.getSpaces(), g.getAction(), 39, numPlayers, players, a, gt, h);

			players[y].addMoney(100); //add $100 to each player

			//check if player is on space 9-19, 29-38 so the player can build and upgrade the class
			if (g.onSpace(9, numPlayers ,players,y)){
				
				char reply; 
				
				if (!sale[0]){//buying a house
					cout<<"Do You Wish to Buy A House for $100? (y/n) "<<endl;
					cin>>reply; 
					if (reply == 'y')
					{
						cardMoney[9].payBank(players[y], 100);
						sale[0] = true;
						bought[0][y] = true;
						pl[0] = y+1; 
						g.getSpaces()[9]->buildHouse(y);
						//g.getSpaces()[9]->checkOwner(y);
					}
				}
				else{
					if (bought[0][y]){//upgrading a house
						cout<<"Do You Wish to Upgrade 1 More House for $100? "<<endl;
						cin>>reply;
						if (reply == 'y')
						{
							g.getSpaces()[9]->buildHouse(y);
						}

					}
					else if (!bought[0][y]){
						cout<<"You Must Pay $"<<2*g.getSpaces()[9]->numHouse()*100<<" to Player "<<pl[0]<<"!!!!"<<endl;
						a.payMoney(players[pl[0]], players[y], 2*g.getSpaces()[9]->numHouse()*100);
					}
				}
						
			}

			if (g.onSpace(10, numPlayers ,players,y)){
				
				char reply;
				
				if (!sale[1]){
					cout<<"Do You Wish to Buy A House for $150? (y/n) "<<endl;
					cin>>reply; 
					if (reply == 'y')
					{
						cardMoney[10].payBank(players[y], 150);
						sale[1] = true;
						bought[1][y] = true;
						pl[1] = y+1; 
						g.getSpaces()[10]->buildHouse(y);
					}
				}
				else{
					if (bought[1][y]){
						cout<<"Do You Wish to Upgrade 1 More House for $150? "<<endl;
						cin>>reply;
						if (reply == 'y')
						{
							g.getSpaces()[10]->buildHouse(y);
						}
					}
					else {
						cout<<"You Must Pay $"<<2*g.getSpaces()[10]->numHouse()*150<<" to Player "<<pl[1]<<"!!!!"<<endl;
						a.payMoney(players[pl[1]], players[y], 2*g.getSpaces()[10]->numHouse()*150);
					}
				}
						
			}

			if (g.onSpace(11, numPlayers ,players,y)){
				
				char reply;
				
				if (!sale[2]){
					cout<<"Do You Wish to Buy A House for $200? (y/n) "<<endl;
					cin>>reply; 
					if (reply == 'y')
					{
						cardMoney[9].payBank(players[y], 200);
						sale[2] = true;
						bought[2][y] = true;
						pl[2] =y+1;  
						g.getSpaces()[11]->buildHouse(y);
					}
				}
				else{
					if (bought[2][y]){
						cout<<"Do You Wish to Upgrade 1 More House for $200? "<<endl;
						cin>>reply;
						if (reply == 'y')
						{
							g.getSpaces()[11]->buildHouse(y);
						}
					}
					else {
						cout<<"You Must Pay $"<<2*g.getSpaces()[11]->numHouse()*200<<" to Player "<<pl[2]<<"!!!!"<<endl;
						a.payMoney(players[pl[2]], players[y], 2*g.getSpaces()[11]->numHouse()*200);
					}
				}
						
			}

			if (g.onSpace(12, numPlayers ,players,y)){
				
				char reply;

				if (!sale[3]){
					cout<<"Do You Wish to Buy A House for $250? (y/n) "<<endl;
					cin>>reply; 
					if (reply == 'y')
					{
						cardMoney[9].payBank(players[y], 250);
						sale[3] = true;
						bought[3][y] = true;
						pl[3] = y+1;  
						g.getSpaces()[12]->buildHouse(y);
					}
				}
				else{
					if (bought[3][y]){
						cout<<"Do You Wish to Upgrade 1 More House for $250? "<<endl;
						cin>>reply;
						if (reply == 'y')
						{
							g.getSpaces()[12]->buildHouse(y);
						}
					}
					else {
						cout<<"You Must Pay $"<<2*g.getSpaces()[12]->numHouse()*250<<" to Player "<<pl[3]<<"!!!!"<<endl;
						a.payMoney(players[pl[3]], players[y], 2*g.getSpaces()[12]->numHouse()*250);
					}
				}
						
			}

			if (g.onSpace(13, numPlayers ,players,y)){
				
				char reply;

				
				if (!sale[4]){
					cout<<"Do You Wish to Buy A House for $300? (y/n) "<<endl;
					cin>>reply; 
					if (reply == 'y')
					{
						cardMoney[9].payBank(players[y], 300);
						sale[4] = true;
						bought[4][y] = true;
						pl[4] = y+1;  
						g.getSpaces()[11]->buildHouse(y);
					}
				}
				else{
					if (bought[4][y]){
						cout<<"Do You Wish to Upgrade 1 More House for $300? "<<endl;
						cin>>reply;
						if (reply == 'y')
						{
							g.getSpaces()[13]->buildHouse(y);
						}
					}
					else {
						cout<<"You Must Pay $"<<2*g.getSpaces()[13]->numHouse()*300<<" to Player "<<pl[4]<<"!!!!"<<endl;
						a.payMoney(players[pl[4]], players[y], 2*g.getSpaces()[13]->numHouse()*300);
					}
				}
						
			}

			if (g.onSpace(14, numPlayers ,players,y)){
				
				char reply;

				
				if (!sale[5]){
					cout<<"Do You Wish to Buy A House for $350? (y/n) "<<endl;
					cin>>reply; 
					if (reply == 'y')
					{
						cardMoney[9].payBank(players[y], 350);
						sale[5] = true;
						bought[5][y] = true;
						pl[5] = y+1;  
						g.getSpaces()[14]->buildHouse(y);
					}
				}
				else{
					if (bought[5][y]){
						cout<<"Do You Wish to Upgrade 1 More House for $350? "<<endl;
						cin>>reply;
						if (reply == 'y')
						{
							g.getSpaces()[14]->buildHouse(y);
						}
					}
					else {
						cout<<"You Must Pay $"<<2*g.getSpaces()[14]->numHouse()*350<<" to Player "<<pl[5]<<"!!!!"<<endl;
						a.payMoney(players[pl[5]], players[y], 2*g.getSpaces()[14]->numHouse()*350);
					}
				}
						
			}

			if (g.onSpace(15, numPlayers ,players,y)){
				
				char reply; 
				
				if (!sale[6]){
					cout<<"Do You Wish to Buy A House for $400? (y/n) "<<endl;
					cin>>reply; 
					if (reply == 'y')
					{
						cardMoney[9].payBank(players[y], 400);
						sale[6] = true;
						bought[6][y] = true;
						pl[6] = y+1;  
						g.getSpaces()[15]->buildHouse(y);
					}
				}
				else{
					if (bought[6][y]){
						cout<<"Do You Wish to Upgrade 1 More House for $400? "<<endl;
						cin>>reply;
						if (reply == 'y')
						{
							g.getSpaces()[15]->buildHouse(y);
						}
					}
					else {
						cout<<"You Must Pay $"<<2*g.getSpaces()[15]->numHouse()*400<<" to Player "<<pl[6]<<"!!!!"<<endl;
						a.payMoney(players[pl[6]], players[y], 2*g.getSpaces()[15]->numHouse()*400);
					}
				}
						
			}

			if (g.onSpace(16, numPlayers ,players,y)){
				
				char reply;
				
				if (!sale[7]){
					cout<<"Do You Wish to Buy A House for $450? (y/n) "<<endl;
					cin>>reply; 
					if (reply == 'y')
					{
						cardMoney[9].payBank(players[y], 450);
						sale[7] = true;
						bought[7][y] = true;
						pl[7] = y+1; 
						g.getSpaces()[16]->buildHouse(y);
					}
				}
				else{
					if (bought[7][y]){
						cout<<"Do You Wish to Upgrade 1 More House for $450? "<<endl;
						cin>>reply;
						if (reply == 'y')
						{
							g.getSpaces()[16]->buildHouse(y);
						}
					}
					else {
						cout<<"You Must Pay $"<<2*g.getSpaces()[16]->numHouse()*450<<" to Player "<<pl[7]<<"!!!!"<<endl;
						a.payMoney(players[pl[7]], players[y], 2*g.getSpaces()[16]->numHouse()*450);
					}
				}
						
			}

			if (g.onSpace(17, numPlayers ,players,y)){
				
				char reply;
				
				if (!sale[8]){
					cout<<"Do You Wish to Buy A House for $500? (y/n) "<<endl;
					cin>>reply; 
					if (reply == 'y')
					{
						cardMoney[9].payBank(players[y], 500);
						sale[8] = true;
						bought[8][y] = true;
						pl[8] = y+1; 
						g.getSpaces()[17]->buildHouse(y);
					}
				}
				else{
					if (bought[8][y]){
						cout<<"Do You Wish to Upgrade 1 More House for $500? "<<endl;
						cin>>reply;
						if (reply == 'y')
						{
							g.getSpaces()[17]->buildHouse(y);
						}
					}
					else {
						cout<<"You Must Pay $"<<2*g.getSpaces()[17]->numHouse()*500<<" to Player "<<pl[8]<<"!!!!"<<endl;
						a.payMoney(players[pl[8]], players[y], 2*g.getSpaces()[17]->numHouse()*500);
					}
				}
						
			}

			if (g.onSpace(18, numPlayers ,players,y)){
				
				char reply;

				if (!sale[9]){
					cout<<"Do You Wish to Buy A House for $550? (y/n) "<<endl;
					cin>>reply; 
					if (reply == 'y')
					{
						cardMoney[9].payBank(players[y], 550);
						sale[9] = true;
						bought[9][y] = true;
						pl[9] = y+1; 
						g.getSpaces()[18]->buildHouse(y);
					}
				}
				else{
					if (bought[9][y]){
						cout<<"Do You Wish to Upgrade 1 More House for $550? "<<endl;
						cin>>reply;
						if (reply == 'y')
						{
							g.getSpaces()[18]->buildHouse(y);
						}
					}
					else {
						cout<<"You Must Pay $"<<2*g.getSpaces()[18]->numHouse()*550<<" to Player "<<pl[9]<<"!!!!"<<endl;
						a.payMoney(players[pl[9]], players[y], 2*g.getSpaces()[18]->numHouse()*550);
					}
				}
						
			}

			if (g.onSpace(19, numPlayers ,players,y)){
				
				char reply;

				
				if (!sale[10]){
					cout<<"Do You Wish to Buy A House for $600? (y/n) "<<endl;
					cin>>reply; 
					if (reply == 'y')
					{
						cardMoney[19].payBank(players[y], 600);
						sale[10] = true;
						bought[10][y] = true;
						pl[10] = y+1; 
						g.getSpaces()[19]->buildHouse(y);
					}
				}
				else{
					if (bought[10][y]){
						cout<<"Do You Wish to Upgrade 1 More House for $600? "<<endl;
						cin>>reply;
						if (reply == 'y')
						{
							g.getSpaces()[19]->buildHouse(y);
						}
					}
					else {
						cout<<"You Must Pay $"<<2*g.getSpaces()[19]->numHouse()*600<<" to Player "<<pl[10]<<"!!!!"<<endl;
						a.payMoney(players[pl[10]], players[y], 2*g.getSpaces()[19]->numHouse()*600);
					}
				}
						
			}

			if (g.onSpace(29, numPlayers ,players,y)){
				
				char reply;
				
				if (!sale[11]){
					cout<<"Do You Wish to Buy A House for $100? (y/n) "<<endl;
					cin>>reply; 
					if (reply == 'y')
					{
						cardMoney[9].payBank(players[y], 100);
						sale[11] = true;
						bought[11][y] = true;
						pl[11] = y+1;  
						g.getSpaces()[29]->buildHouse(y);
					}
				}
				else{
					if (bought[11][y]){
						cout<<"Do You Wish to Upgrade 1 More House for $100? "<<endl;
						cin>>reply;
						if (reply == 'y')
						{
							g.getSpaces()[29]->buildHouse(y);
						}
					}
					else {
						cout<<"You Must Pay $"<<2*g.getSpaces()[29]->numHouse()*100<<" to Player "<<pl[11]<<"!!!!"<<endl;
						a.payMoney(players[pl[11]], players[y], 2*g.getSpaces()[29]->numHouse()*100);
					}
				}
						
			}

			if (g.onSpace(30, numPlayers ,players,y)){
				
				char reply;
				
				if (!sale[12]){
					cout<<"Do You Wish to Buy A House for $150? (y/n) "<<endl;
					cin>>reply; 
					if (reply == 'y')
					{
						cardMoney[30].payBank(players[y], 150);
						sale[12] = true;
						bought[12][y] = true;
						pl[12] = y+1; 
						g.getSpaces()[10]->buildHouse(y);
					}
				}
				else{
					if (bought[12][y]){
						cout<<"Do You Wish to Upgrade 1 More House for $150? "<<endl;
						cin>>reply;
						if (reply == 'y')
						{
							g.getSpaces()[30]->buildHouse(y);
						}
					}
					else {
						cout<<"You Must Pay $"<<2*g.getSpaces()[30]->numHouse()*150<<" to Player "<<pl[12]<<"!!!!"<<endl;
						a.payMoney(players[pl[12]], players[y], 2*g.getSpaces()[30]->numHouse()*150);
					}
				}
						
			}

			if (g.onSpace(31, numPlayers ,players,y)){
				
				char reply;
				
				if (!sale[13]){
					cout<<"Do You Wish to Buy A House for $200? (y/n) "<<endl;
					cin>>reply; 
					if (reply == 'y')
					{
						cardMoney[9].payBank(players[y], 200);
						sale[13] = true;
						bought[13][y] = true;
						pl[13] = y+1; 
						g.getSpaces()[31]->buildHouse(y);
					}
				}
				else{
					if (bought[13][y]){
						cout<<"Do You Wish to Upgrade 1 More House for $200? "<<endl;
						cin>>reply;
						if (reply == 'y')
						{
							g.getSpaces()[31]->buildHouse(y);
						}
					}
					else {
						cout<<"You Must Pay $"<<2*g.getSpaces()[31]->numHouse()*200<<" to Player "<<pl[13]<<"!!!!"<<endl;
						a.payMoney(players[pl[13]], players[y], 2*g.getSpaces()[31]->numHouse()*200);
					}
				}
						
			}

			if (g.onSpace(32, numPlayers ,players,y)){
				
				char reply;

				if (!sale[14]){
					cout<<"Do You Wish to Buy A House for $250? (y/n) "<<endl;
					cin>>reply; 
					if (reply == 'y')
					{
						cardMoney[9].payBank(players[y], 250);
						sale[14] = true;
						bought[14][y] = true;
						pl[14] = y+1; 
						g.getSpaces()[32]->buildHouse(y);
					}
				}
				else{
					if (bought[14][y]){
						cout<<"Do You Wish to Upgrade 1 More House for $250? "<<endl;
						cin>>reply;
						if (reply == 'y')
						{
							g.getSpaces()[32]->buildHouse(y);
						}
					}
					else {
						cout<<"You Must Pay $"<<2*g.getSpaces()[32]->numHouse()*250<<" to Player "<<pl[14]<<"!!!!"<<endl;
						a.payMoney(players[pl[14]], players[y], 2*g.getSpaces()[32]->numHouse()*250);
					}
				}
						
			}

			if (g.onSpace(33, numPlayers ,players,y)){
				
				char reply;

				
				if (!sale[15]){
					cout<<"Do You Wish to Buy A House for $300? (y/n) "<<endl;
					cin>>reply; 
					if (reply == 'y')
					{
						cardMoney[9].payBank(players[y], 300);
						sale[15] = true;
						bought[15][y] = true;
						pl[15] = y+1; 
						g.getSpaces()[33]->buildHouse(y);
					}
				}
				else{
					if (bought[15][y]){
						cout<<"Do You Wish to Upgrade 1 More House for $300? "<<endl;
						cin>>reply;
						if (reply == 'y')
						{
							g.getSpaces()[33]->buildHouse(y);
						}
					}
					else {
						cout<<"You Must Pay $"<<2*g.getSpaces()[33]->numHouse()*300<<" to Player "<<pl[15]<<"!!!!"<<endl;
						a.payMoney(players[pl[15]], players[y], 2*g.getSpaces()[33]->numHouse()*300);
					}
				}
						
			}

			if (g.onSpace(34, numPlayers ,players,y)){
				
				char reply;

				
				if (!sale[16]){
					cout<<"Do You Wish to Buy A House for $350? (y/n) "<<endl;
					cin>>reply; 
					if (reply == 'y')
					{
						cardMoney[9].payBank(players[y], 350);
						sale[16] = true;
						bought[16][y] = true;
						pl[16] = y+1; 
						g.getSpaces()[34]->buildHouse(y);
					}
				}
				else{
					if (bought[16][y]){
						cout<<"Do You Wish to Upgrade 1 More House for $350? "<<endl;
						cin>>reply;
						if (reply == 'y')
						{
							g.getSpaces()[34]->buildHouse(y);
						}
					}
					else {
						cout<<"You Must Pay $"<<2*g.getSpaces()[34]->numHouse()*350<<" to Player "<<pl[16]<<"!!!!"<<endl;
						a.payMoney(players[pl[16]], players[y], 2*g.getSpaces()[34]->numHouse()*350);
					}
				}
						
			}

			if (g.onSpace(35, numPlayers ,players,y)){
				
				char reply; 
				
				if (!sale[17]){
					cout<<"Do You Wish to Buy A House for $400? (y/n) "<<endl;
					cin>>reply; 
					if (reply == 'y')
					{
						cardMoney[9].payBank(players[y], 400);
						sale[17] = true;
						bought[17][y] = true;
						pl[17] = y+1; 
						g.getSpaces()[35]->buildHouse(y);
					}
				}
				else{
					if (bought[17][y]){
						cout<<"Do You Wish to Upgrade 1 More House for $400? "<<endl;
						cin>>reply;
						if (reply == 'y')
						{
							g.getSpaces()[35]->buildHouse(y);
						}
					}
					else {
						cout<<"You Must Pay $"<<2*g.getSpaces()[35]->numHouse()*400<<" to Player "<<pl[17]<<"!!!!"<<endl;
						a.payMoney(players[pl[17]], players[y], 2*g.getSpaces()[35]->numHouse()*400);
					}
				}
						
			}

			if (g.onSpace(36, numPlayers ,players,y)){
				
				char reply;
				
				if (!sale[18]){
					cout<<"Do You Wish to Buy A House for $450? (y/n) "<<endl;
					cin>>reply; 
					if (reply == 'y')
					{
						cardMoney[9].payBank(players[y], 450);
						sale[18] = true;
						bought[18][y] = true;
						pl[18] = y+1; 
						g.getSpaces()[36]->buildHouse(y);
					}
				}
				else{
					if (bought[18][y]){
						cout<<"Do You Wish to Upgrade 1 More House for $450? "<<endl;
						cin>>reply;
						if (reply == 'y')
						{
							g.getSpaces()[36]->buildHouse(y);
						}
					}
					else {
						cout<<"You Must Pay $"<<2*g.getSpaces()[36]->numHouse()*450<<" to Player "<<pl[18]<<"!!!!"<<endl;
						a.payMoney(players[pl[18]], players[y], 2*g.getSpaces()[36]->numHouse()*450);
					}
				}
						
			}

			if (g.onSpace(37, numPlayers ,players,y)){
				
				char reply;
				
				if (!sale[19]){
					cout<<"Do You Wish to Buy A House for $500? (y/n) "<<endl;
					cin>>reply; 
					if (reply == 'y')
					{
						cardMoney[9].payBank(players[y], 500);
						sale[19] = true;
						bought[19][y] = true;
						pl[19] = y+1; 
						g.getSpaces()[37]->buildHouse(y);
					}
				}
				else{
					if (bought[19][y]){
						cout<<"Do You Wish to Upgrade 1 More House for $500? "<<endl;
						cin>>reply;
						if (reply == 'y')
						{
							g.getSpaces()[37]->buildHouse(y);
						}
					}
					else {
						cout<<"You Must Pay $"<<2*g.getSpaces()[37]->numHouse()*500<<" to Player "<<pl[19]<<"!!!!"<<endl;
						a.payMoney(players[pl[19]], players[y], 2*g.getSpaces()[37]->numHouse()*500);
					}
				}
						
			}

			if (g.onSpace(38, numPlayers ,players,y)){
				
				char reply;

				if (!sale[20]){
					cout<<"Do You Wish to Buy A House for $550? (y/n) "<<endl;
					cin>>reply; 
					if (reply == 'y')
					{
						cardMoney[9].payBank(players[y], 550);
						sale[20] = true;
						bought[20][y] = true;
						pl[20] = y+1; 
						g.getSpaces()[38]->buildHouse(y);
					}
				}
				else{
					if (bought[20][y]){
						cout<<"Do You Wish to Upgrade 1 More House for $550? "<<endl;
						cin>>reply;
						if (reply == 'y')
						{
							g.getSpaces()[38]->buildHouse(y);
						}
					}
					else {
						cout<<"You Must Pay $"<<2*g.getSpaces()[38]->numHouse()*550<<"to Player "<<pl[20]<<"!!!!"<<endl;
						a.payMoney(players[pl[20]], players[y], 2*g.getSpaces()[38]->numHouse()*550);
					}
				}
						
			}


			//check if player is on space 0, 23, 26, 28 to teleport a player to random space
			if (g.onSpace(0, numPlayers ,players,y) || g.onSpace(2, numPlayers ,players,y) || g.onSpace(5, numPlayers ,players,y) || g.onSpace(23, numPlayers ,players,y) || g.onSpace(26, numPlayers ,players,y) || g.onSpace(28, numPlayers ,players,y)){//Move Forward Random Spaces
			
				gt.executeAction(players[y], randomSpace());
				cout<<"Player Will Now Be Teleported to "<<g.getSpaces()[randomSpace()]->getName()<<endl;
			}

			if (g.onSpace(19, numPlayers ,players,y)){//Free Parking
				cardMoney[9].payPlayer(players[y], 200);
			}
			//check if player is on space 21, 24 to draw
			if (g.onSpace(21, numPlayers ,players,y) || g.onSpace(24, numPlayers ,players,y)){//Draw Cards and Card Actions
				cards[randomNum()].printCard();
				if (randomNum() == 0){
						cardMove[0].executeAction(players[y],2);
				}
				else if (randomNum() == 1){
						cardMove[1].executeAction(players[y],1);
				}
				else if (randomNum() == 2){
						cardMoney[0].payBank(players[y], 100);
				}
				else if (randomNum() == 3){
						cardMoney[1].payBank(players[y], 200);
				}
				else if (randomNum() == 4){
						cardMoney[2].payBank(players[y], 300);
				}
				else if (randomNum() == 5){
						cardMoney[3].payBank(players[y], 400);
				}
				else if (randomNum() == 6){
						cardMoney[4].payBank(players[y], 500);
				}
				else if (randomNum() == 7){
						cardMoney[5].payBank(players[y], 600);
				}
				else if (randomNum() == 8){
						cardMoney[6].payBank(players[y], 700);
				}
				else if (randomNum() == 9){
						cardMoney[7].payBank(players[y], 800);
				}

			}
			//check if player is on space 4, 7 to draw card
			if (g.onSpace(4, numPlayers ,players,y) || g.onSpace(7, numPlayers ,players,y)){//Draw Cards and Card Actions
				cards1[randomNum()].printCard1();
				if (randomNum() == 0){
						cardMove[0].executeAction(players[y],2);
				}
				else if (randomNum() == 1){
						cardMove[1].executeAction(players[y],1);
				}
				else if (randomNum() == 2){
						cardMoney[0].payPlayer(players[y], 100);
				}
				else if (randomNum() == 3){
						cardMoney[1].payPlayer(players[y], 200);
				}
				else if (randomNum() == 4){
						cardMoney[2].payPlayer(players[y], 300);
				}
				else if (randomNum() == 5){
						cardMoney[3].payPlayer(players[y], 400);
				}
				else if (randomNum() == 6){
						cardMoney[4].payPlayer(players[y], 500);
				}
				else if (randomNum() == 7){
						cardMoney[5].payPlayer(players[y], 600);
				}
				else if (randomNum() == 8){
						cardMoney[6].payPlayer(players[y], 700);
				}
				else if (randomNum() == 9){
						cardMoney[7].payPlayer(players[y], 800);
				}

			}
			//warn the player if he wants to resign when his money drops below $600
			if (players[y].getMoney()<600 && players[y].getMoney()>0){
			char reply;
				cout<<"You Are In Danger of Losing...Would You Like to Resign? (y/n)"<<endl;
				cin>>reply;
				if(reply == 'y'){
					for (int y=0; y<numPlayers; y++){
						cout<<"Player "<<y+1<<" has "<<players[y].getMoney()<<endl;
					}
					cout<<"Player with the most money now wins!"<<endl;
					exit(0);
				}
				else{
					cout<<"Good Luck!"<<endl;
					continue;
				}
			}
			//the game will end once a player loses all his money
			if (players[y].getMoney()<0){
				play = false;
				cout<<"The Game Is Over Because Player "<<y+1<<" Has No Money"<<endl; 
				/*int tempt; 
					for (int k=0; k<numPlayers; k++){
						for (int j=0; j<numPlayers-k-1; j++){	
							if (players[j].getMoney() <	 players[j+1].getMoney()){

								tempt = players[j].getMoney();
								players[j].getMoney() = players[j+1].getMoney();
								players[j+1].getMoney() = tempt;
							}
						}
					}
				for (int y=0; y<numPlayers; y++){
					cout<<"Player "<<y+1<<" has "<<players[y].getMoney()<<endl;
				}
				cout<<"Player with the most money now wins!"<<endl;
			}
		}
	}
	//deallocating the objects
	delete [] players;
	

	for (int x=0; x<21; x++){
		delete bought[x];
	}  */
	return app.exec();

}
