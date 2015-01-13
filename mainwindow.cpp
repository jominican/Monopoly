
#include "mainwindow.h"

MainWindow::MainWindow() {
  setGeometry( 800, 800, 800, 800 );

  //Display the board in the central widget
  centralWidget = new GameBoard();//instatiating centralWidget
  setCentralWidget( centralWidget );

	counter=0;
	playerChoice[0] = false;//player choice boolean array
	playerChoice[1] = false;
	playerChoice[2] = false;
	playerChoice[3] = false;

  //Create the 4 players
  players[0] = new Players( "P1" );//allocating 4 players. Although not all 4 players will be used, the players not playing will not be updated
	players[0]->setMoney(5000);
  players[1] = new Players( "P2" );
	players[1]->setMoney(5000);
  players[2] = new Players( "P3" );
	players[2]->setMoney(5000);
  players[3] = new Players( "P4" );
	players[3]->setMoney(5000);

  //Player 1 is at the bottom. 2 at the left. 3 on top. 4 on the right
  //Create the GUIPlayers
 	guiPlayers[0] = new GUIPlayerVertical( players[0], players[1], players[2], players[3] );
  //guiPlayers[1] = new GUIPlayerVertical( players[1] );
  //guiPlayers[2] = new GUIPlayerHorizontal( players[2] );
 // guiPlayers[3] = new GUIPlayerVertical( players[3] );

  //addDockWidget( Qt::BottomDockWidgetArea, guiPlayers[0] );
	addDockWidget( Qt::LeftDockWidgetArea, guiPlayers[0] );//adding dockwidget
  //addDockWidget( Qt::TopDockWidgetArea, guiPlayers[2] );
  //addDockWidget( Qt::RightDockWidgetArea, guiPlayers[3] );



	srand(time(0));

	//instatiating the various Qpixmap
	dice[0] = new QPixmap("dice1.png");//dice image
	dice[1] = new QPixmap("dice2.png");//dice image
	dice[2] = new QPixmap("dice3.png");//dice image
	dice[3] = new QPixmap("dice4.png");//dice image
	dice[4] = new QPixmap("dice5.png");//dice image
	dice[5] = new QPixmap("dice6.png");//dice image

	//card[0] = new QPixmap("chance1.png");
	//card[1] = new QPixmap("chance2.png");
	card[0] = new QPixmap("chance3.png");
	card[1] = new QPixmap("chance4.png");
	card[2] = new QPixmap("chance5.png");
	card[3] = new QPixmap("chance6.png");
	card[4] = new QPixmap("chance7.png");
	card[5] = new QPixmap("chance8.png");
	card[6] = new QPixmap("chance9.png");
	card[7] = new QPixmap("chance10.png");
	card[8] = new QPixmap("chance_face_down.png");

	//card1[0] = new QPixmap("chance1.png");
	//card1[1] = new QPixmap("chance2.png");
	card1[0] = new QPixmap("comm1.png");
	card1[1] = new QPixmap("comm2.png");
	card1[2] = new QPixmap("comm3.png");
	card1[3] = new QPixmap("comm4.png");
	card1[4] = new QPixmap("comm5.png");
	card1[5] = new QPixmap("comm6.png");
	card1[6] = new QPixmap("comm7.png");
	card1[7] = new QPixmap("comm8.png");
	card1[8] = new QPixmap("community_face_down.png");

	//instantating the various pushbuttons
  cardDeckButton = new QPushButton( this );
	cardDeckButton->setIcon(*card[8]);
  cardDeckButton->setIconSize( QSize(132, 207) );
  cardDeckButton->setGeometry( 175, 100, 132, 207);
	connect( cardDeckButton, SIGNAL(clicked()), this, SLOT(chooseCard()));
	isFaceDown = false;
  cardDeckButton1 = new QPushButton( this );
	cardDeckButton1->setIcon(*card1[8]);
  cardDeckButton1->setIconSize( QSize(132, 207) );
  cardDeckButton1->setGeometry( 450, 100, 132, 207);
	connect( cardDeckButton1, SIGNAL(clicked()), this, SLOT(chooseCard1()));
	isFaceDown1 = false;
	
	numPlayers[0] = new QPushButton( this );
  numPlayers[0]->setIconSize( QSize(20, 20) );
  numPlayers[0]->setGeometry( 150, 320, 20, 20);
	connect( numPlayers[0], SIGNAL(clicked()), this, SLOT(playerOne()));

	numPlayers[1] = new QPushButton( this );
  numPlayers[1]->setIconSize( QSize(20, 20) );
  numPlayers[1]->setGeometry( 175, 320, 20, 20);
	connect( numPlayers[1], SIGNAL(clicked()), this, SLOT(playerTwo()));

	numPlayers[2] = new QPushButton( this );
  numPlayers[2]->setIconSize( QSize(20, 20) );
  numPlayers[2]->setGeometry( 200, 320, 20, 20);
	connect( numPlayers[2], SIGNAL(clicked()), this, SLOT(playerThree()));

	numPlayers[3] = new QPushButton( this );
  numPlayers[3]->setIconSize( QSize(20, 20) );
  numPlayers[3]->setGeometry( 225, 320, 20, 20);
	connect( numPlayers[3], SIGNAL(clicked()), this, SLOT(playerFour()));


	numLabel[0]= new QLabel( this );
	numLabel[0]->setText("P1");
	numLabel[0]->setGeometry(150, 340, 20, 20);

	numLabel[0]= new QLabel( this );
	numLabel[0]->setText("P2");
	numLabel[0]->setGeometry(175, 340, 20, 20);

	numLabel[0]= new QLabel( this );
	numLabel[0]->setText("P3");
	numLabel[0]->setGeometry(200, 340, 20, 20);

	numLabel[0]= new QLabel( this );
	numLabel[0]->setText("P4");
	numLabel[0]->setGeometry(225, 340, 20, 20);

  diceButton[0] = new QPushButton( this );
  diceButton[0]->setIcon( *dice[0] );
  diceButton[0]->setIconSize( QSize(100, 100) );
  diceButton[0]->setGeometry( 175, 400, 100, 100);
	connect( diceButton[0], SIGNAL(clicked()), this, SLOT(randomNum()));
	//connect( diceButton[0], SIGNAL(clicked()), this, SLOT(payMoney()));
	//cout<<a<<endl;

  diceButton[1] = new QPushButton( this );
  diceButton[1]->setIcon( *dice[0] );
  diceButton[1]->setIconSize( QSize(100, 100) );
  diceButton[1]->setGeometry( 280, 400, 100, 100);
	connect( diceButton[1], SIGNAL(clicked()), this, SLOT(randomNum1()));

  diceButton[2] = new QPushButton( this );
  diceButton[2]->setIcon( *dice[0] );
  diceButton[2]->setIconSize( QSize(100, 100) );
  diceButton[2]->setGeometry( 385, 400, 100, 100);
	connect( diceButton[2], SIGNAL(clicked()), this, SLOT(randomNum2()));

  diceButton[3] = new QPushButton( this );
  diceButton[3]->setIcon( *dice[0] );
  diceButton[3]->setIconSize( QSize(100, 100) );
  diceButton[3]->setGeometry( 490, 400, 100, 100);
	connect( diceButton[3], SIGNAL(clicked()), this, SLOT(randomNum3()));

  diceButton[0]->setEnabled(false );
  diceButton[1]->setEnabled(false );
  diceButton[2]->setEnabled(false );
  diceButton[3]->setEnabled(false );

	numPlayers[4] = new QPushButton( this );
  numPlayers[4]->setText( "Resign" );
  numPlayers[4]->setIconSize( QSize(100, 20) );
  numPlayers[4]->setGeometry( 275, 320, 100, 20);
	connect( numPlayers[4], SIGNAL(clicked()), this, SLOT(resign()));


  //connect( diceButton, SIGNAL(clicked()), this, SLOT(addMoney(players[0])));
  //isDice = true;
	QSignalMapper *signalMapper = new QSignalMapper(this);
	//connect(signalMapper, SIGNAL(mapped(int)), this, SIGNAL(payMoney(int)))

	//more pixmap
	piece[0] = new QPixmap("piece1.png");//piece 0
	selectPiece[0] = new QPushButton( this );
	selectPiece[0]->setIcon( *piece[0] );
  selectPiece[0]->setIconSize( QSize(19, 26) );
  selectPiece[0]->setGeometry( 320, 350, 19, 26);

	piece[1] = new QPixmap("piece2.png");//piece 1
	selectPiece[1] = new QPushButton( this );
	selectPiece[1]->setIcon( *piece[1] );
  selectPiece[1]->setIconSize( QSize(19, 26) );
  selectPiece[1]->setGeometry( 350, 350, 19, 26);

	piece[2] = new QPixmap("piece3.png");//piece 2
	selectPiece[2] = new QPushButton( this );
	selectPiece[2]->setIcon( *piece[2] );
  selectPiece[2]->setIconSize( QSize(19, 26) );
  selectPiece[2]->setGeometry( 380, 350, 19, 26);

	piece[3] = new QPixmap("piece4.png");//piece 3
	selectPiece[3] = new QPushButton( this );
	selectPiece[3]->setIcon( *piece[3] );
  selectPiece[3]->setIconSize( QSize(19, 26) );
  selectPiece[3]->setGeometry( 410, 350, 19, 26);

	piece[4] = new QPixmap("piece5.png");// piece 4
	selectPiece[4] = new QPushButton( this );
	selectPiece[4]->setIcon( *piece[4] );
  selectPiece[4]->setIconSize( QSize(19, 26) );
  selectPiece[4]->setGeometry( 440, 350, 19, 26);

	piece[5] = new QPixmap("piece6.png");// piece 5
	selectPiece[5] = new QPushButton( this );
	selectPiece[5]->setIcon( *piece[5] );
  selectPiece[5]->setIconSize( QSize(19, 26) );
  selectPiece[5]->setGeometry( 470, 350, 19, 26);

	piece[6] = new QPixmap("piece7.png");// piece 6
	selectPiece[6] = new QPushButton( this );
	selectPiece[6]->setIcon( *piece[6] );
  selectPiece[6]->setIconSize( QSize(19, 26) );
  selectPiece[6]->setGeometry( 500, 350, 19, 26);

	piece[7] = new QPixmap("piece8.png");// piece 7
	selectPiece[7] = new QPushButton( this );
	selectPiece[7]->setIcon( *piece[7] );
  selectPiece[7]->setIconSize( QSize(19, 26) );
  selectPiece[7]->setGeometry( 530, 350, 19, 26);

	piece[8] = new QPixmap("piece9.png");// piece 8
	selectPiece[8] = new QPushButton( this );
	selectPiece[8]->setIcon( *piece[8] );
  selectPiece[8]->setIconSize( QSize(19, 26) );
  selectPiece[8]->setGeometry( 560, 350, 19, 26);

	piece[9] = new QPixmap("piece10.png");// piece 9
	selectPiece[9] = new QPushButton( this );
	selectPiece[9]->setIcon( *piece[9] );
  selectPiece[9]->setIconSize( QSize(19, 26) );
  selectPiece[9]->setGeometry( 580, 350, 19, 26);

	for (int x=0; x<10; x++){
		//connect(diceButton[x], SIGNAL(clicked()), signalMapper, SLOT(map()));
		connect(selectPiece[x], SIGNAL(clicked()), signalMapper, SLOT(map()));
		signalMapper->setMapping(selectPiece[x],x);
	}
	connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(choosePlayer(int)));

	//setting the pixel location to xpos and ypos array of 40
	xpos[0] = 87; xpos[1] = 87; xpos[2] = 87; xpos[3] = 87; xpos[4] = 87; xpos[5] = 87; xpos[6] = 87; xpos[7] = 87; xpos[8] = 87; xpos[9] = 87; 
	xpos[10] = 141; xpos[11] = 195; xpos[12] = 249; xpos[13] = 303; xpos[14] = 357; xpos[15] = 411; xpos[16] = 465; xpos[17] = 519; xpos[18] = 573; xpos[19] = 627; 
	xpos[20] = 627; xpos[21] = 627; xpos[22] = 627; xpos[23] = 627; xpos[24] = 627; xpos[25] = 627; xpos[26] = 627; xpos[27] = 627; xpos[28] = 627; xpos[29] = 627; 
	xpos[30] = 573; xpos[31] = 519; xpos[32] = 465; xpos[33] = 411; xpos[34] = 357; xpos[35] = 303; xpos[36] = 249; xpos[37] = 195; xpos[38] = 141; xpos[39] = 87; 

	ypos[0] = 513; ypos[1] = 459; ypos[2] = 405; ypos[3] = 351; ypos[4] = 297; ypos[5] = 243; ypos[6] = 189; ypos[7] = 135; ypos[8] = 81; ypos[9] = 27; 
	ypos[10] = 27; ypos[11] = 27; ypos[12] = 27; ypos[13] = 27; ypos[14] = 27; ypos[15] = 27; ypos[16] = 27; ypos[17] = 27; ypos[18] = 27; ypos[19] = 27; 
	ypos[20] = 81; ypos[21] = 135; ypos[22] = 189; ypos[23] = 243; ypos[24] = 297; ypos[25] = 351; ypos[26] = 405; ypos[27] = 459; ypos[28] = 513; ypos[29] = 567; 
	ypos[30] = 567; ypos[31] = 567; ypos[32] = 567; ypos[33] = 567; ypos[34] = 567; ypos[35] = 567; ypos[36] = 567; ypos[37] = 567; ypos[38] = 567; ypos[39] = 567; 

					cardDeckButton->setEnabled( false); 

					cardDeckButton1->setEnabled( false); 

	for (int x=0; x<11; x++){
		upgrade[x] = -1;
		upgradeCount[x] = 1;
	}

}

void MainWindow::payMoney(int n)//paymoney to players, calls on addmoney
{
 for (int x=0; x<4; x++){
	players[x]->addMoney(n);
	//cout<<"ASDfasdf";
	//cout<<players[x]->getMoney();
	}
	guiPlayers[0]->callLabel();
}

void MainWindow::buyHouse(QPushButton* n )//buying a house function by checking the pixel location of player piece
{	
				
				if ( (n->y() == 27 || n->y() == 567 || n->y() == 2 || n->y() == 542) && !(n->x() == 87 && n->y() == 567) ){
						QMessageBox::information( 
							this, 
							tr("Unowned Property!"), 
							tr("They Player Must Buy the Property for The Listed Price") );
							if (n->x() == 87 || n->x() == 107){
								if(upgrade[0] != -1 ){
									QMessageBox::information( 
									this, 
									tr("Upgraded Property!"), 
									tr("They Player Must Pay More Upgraded Property!") );
									players[a]->subtractMoney(	upgradeCount[0]*100);
								}
							players[a]->subtractMoney(100);
							upgrade[0] = a;
							upgradeCount[0]++;
							}
							else if(n->x() == 141 || n->x() == 161){	
								if(upgrade[1] != -1 ){
									QMessageBox::information( 
									this, 
									tr("Upgraded Property!"), 
									tr("They Player Must Pay More Upgraded Property!") );
									players[a]->subtractMoney(	upgradeCount[1]*150);
								}
							players[a]->subtractMoney(150);
							upgrade[1] = a;
							upgradeCount[1]++;
							}
							else if(n->x() == 195 || n->x() == 215){
								if(upgrade[2] != -1 ){
									QMessageBox::information( 
									this, 
									tr("Upgraded Property!"), 
									tr("They Player Must Pay More Upgraded Property!") );
									players[a]->subtractMoney(	upgradeCount[2]*200);
								}
							players[a]->subtractMoney(200);
							upgrade[2] = a;
							upgradeCount[2]++;
							}
							else if(n->x() == 249 || n->x() == 269){
								if(upgrade[3] != -1 ){
									QMessageBox::information( 
									this, 
									tr("Upgraded Property!"), 
									tr("They Player Must Pay More Upgraded Property!") );
									players[a]->subtractMoney(	upgradeCount[3]*250);
								}
							players[a]->subtractMoney(250);
							upgrade[3] = a;
							upgradeCount[3]++;
							}
							else if(n->x() == 303 || n->x() == 323){
								if(upgrade[4] != -1 ){
									QMessageBox::information( 
									this, 
									tr("Upgraded Property!"), 
									tr("They Player Must Pay More Upgraded Property!") );
									players[a]->subtractMoney(	upgradeCount[4]*300);
								}
							players[a]->subtractMoney(300);
							upgrade[4] = a;
							upgradeCount[4]++;
							}
							else if(n->x() == 357 || n->x() == 377){
								if(upgrade[5] != -1 ){
									QMessageBox::information( 
									this, 
									tr("Upgraded Property!"), 
									tr("They Player Must Pay More Upgraded Property!") );
									players[a]->subtractMoney(	upgradeCount[5]*350);
								}
							players[a]->subtractMoney(350);
							upgrade[5] = a;
							upgradeCount[5]++;
							}
							else if(n->x() == 411 || n->x() == 431){
								if(upgrade[6] != -1 ){
									QMessageBox::information( 
									this, 
									tr("Upgraded Property!"), 
									tr("They Player Must Pay More Upgraded Property!") );
									players[a]->subtractMoney(	upgradeCount[6]*400);
								}
							players[a]->subtractMoney(400);
							upgrade[6] = a;
							upgradeCount[6]++;
							}
							else if(n->x() == 465 || n->x() == 485){
								if(upgrade[7] != -1 ){
									QMessageBox::information( 
									this, 
									tr("Upgraded Property!"), 
									tr("They Player Must Pay More Upgraded Property!") );
									players[a]->subtractMoney(	upgradeCount[7]*450);
								}
							players[a]->subtractMoney(450);
							upgrade[7] = a;
							upgradeCount[7]++;
							}
							else if(n->x() == 519 || n->x() == 539){
								if(upgrade[8] != -1 ){
									QMessageBox::information( 
									this, 
									tr("Upgraded Property!"), 
									tr("They Player Must Pay More Upgraded Property!") );
									players[a]->subtractMoney(	upgradeCount[8]*500);
								}
							players[a]->subtractMoney(500);
							upgrade[8] = a;
							upgradeCount[8]++;
							}
							else if(n->x() == 573 || n->x() == 593){
								if(upgrade[9] != -1 ){
									QMessageBox::information( 
									this, 
									tr("Upgraded Property!"), 
									tr("They Player Must Pay More Upgraded Property!") );
									players[a]->subtractMoney(	upgradeCount[9]*550);
								}
							players[a]->subtractMoney(550);
							upgrade[9] = a;
							upgradeCount[9]++;
							}
							else if(n->x() == 627 || n->x() == 647){
								if(upgrade[10] != -1 ){
									QMessageBox::information( 
									this, 
									tr("Upgraded Property!"), 
									tr("They Player Must Pay More Upgraded Property!") );
									players[a]->subtractMoney(	upgradeCount[10]*600);
								}
							players[a]->subtractMoney(600);
							upgrade[10] = a;
							upgradeCount[10]++;
							}


							guiPlayers[0]->callLabel();

									}

}

void MainWindow::resign()// resigning the game
{
	/*int arr[4] = {players[0]->getMoney(), players[1]->getMoney(), players[2]->getMoney(), players[3]->getMoney()};
	int temp;

	for (int k = 1; k < 4; k++)
		for (int i = 0; i <3 - k; i++)
		     if (arr[i] > arr[i+1]){
		        temp = arr[i];
		        arr[i] = arr[i+1];
		      	arr[i+1] = temp;
		    	} 
		}
	}*/

	QMessageBox::information( 
    this, 
    tr("GAME OVER!"), 
    tr("A Player Has Chosen to Resign..The Player With The Most Remaining Money Wins") );
		close();
}

void MainWindow::drawCard( QPushButton* n )//drawing chance card 
{ 
				if ((n->x() == 87 && n->y() == 297) || (n->x() == 87 && n->y() == 135) || (n->x() == 107 && n->y() == 297) || (n->x() == 107 && n->y() == 135) || (n->x() == 87 && n->y() == 272) || (n->x() == 87 && n->y() == 110) || (n->x() == 107 && n->y() == 272) || (n->x() == 107 && n->y() == 110) ){
	QMessageBox::information( 
    this, 
    tr("Draw Card!"), 
    tr("The Player May Draw A Community Chest Card!") );
			cardDeckButton1->setEnabled( true); 
				}

}



void MainWindow::drawCard1( QPushButton* n)//drawing community chest card
{
				if ((n->x() == 627 && n->y() == 135) ||( n->x() == 627 && n->y() == 297) || (n->x() == 647 && n->y() == 135) ||( n->x() == 647 && n->y() == 297) || (n->x() == 627 && n->y() == 110) ||( n->x() == 627 && n->y() == 272) || (n->x() == 647 && n->y() == 110) ||( n->x() == 647 && n->y() == 272)) {
	QMessageBox::information( 
    this, 
    tr("Draw Card!"), 
    tr("The Player May Draw A Chance Card!") );
			cardDeckButton->setEnabled( true); 
				}

}

void MainWindow::goRandom( QPushButton *n)//go to a random space function
{

		int	cardNum;
		cardNum= rand()%40;


				if ((n->x() == 87 && n->y() == 513) || (n->x() == 87 && n->y() == 405) || (n->x() == 87 && n->y() == 243) || (n->x() == 627 && n->y() == 243) || (n->x() == 627 && n->y() == 405) || (n->x() == 627 && n->y() == 513) || (n->x() == 107 && n->y() == 513) || (n->x() == 107 && n->y() == 405) || (n->x() == 107 && n->y() == 243) || (n->x() == 647 && n->y() == 243) || (n->x() == 647 && n->y() == 405) || (n->x() == 647 && n->y() == 513) || (n->x() == 87 && n->y() == 488) || (n->x() == 87 && n->y() == 380) || (n->x() == 87 && n->y() == 218) || (n->x() == 627 && n->y() == 218) || (n->x() == 627 && n->y() == 380) || (n->x() == 627 && n->y() == 488) || (n->x() == 107 && n->y() == 488) || (n->x() == 107 && n->y() == 380) || (n->x() == 107 && n->y() == 218) || (n->x() == 647 && n->y() == 218) || (n->x() == 647 && n->y() == 380) || (n->x() == 647 && n->y() == 488) ){
	QMessageBox::information( 
    this, 
    tr("Random!"), 
    tr("The Player Will Now Be Teleported Randomly!") );
				currentPos[a] = cardNum ;
					if (a ==0){
						n->setGeometry(xpos[cardNum], ypos[cardNum], 19,26);//change for different players
					}
					else if (a ==1){
						n->setGeometry(xpos[cardNum]+20, ypos[cardNum], 19,26);//change for different players
					}
					else if (a ==2){
						n->setGeometry(xpos[cardNum], ypos[cardNum]-25, 19,26);//change for different players
					}
					else{
						n->setGeometry(xpos[cardNum]+20, ypos[cardNum]-25, 19,26);//change for different players
					}
				}


}

void MainWindow::checkLoss()
{
		for (int x=0; x<4; x++){
			if (players[x]->getMoney() < 0){
					QMessageBox::information( 
		  this, 
		  tr("GAME OVER!"), 
		  tr("A Player Has Chosen to Resign..The Player With The Most Remaining Money Wins") );
			close();
			}
		}

}

void MainWindow::randomNum()//randomNum generator for player 1 dice
{
		if (playerChoice[0] == false){
			return;
		}	
		int	cardNum;
		cardNum= rand()%6;
		//Show the face up card
		for (int x=0; x<6; x++){
			if ( cardNum == x) {
				diceButton[0]->setIcon( *dice[x] );
				diceButton[0]->setEnabled( true);
			} 
		}
	
				currentPos[0] = currentPos[0] + cardNum +1;
				if (currentPos[0] > 39)
				{
					currentPos[0] = currentPos[0] - 40;
				}
				a=0;
				selectPiece[p[0]]->setGeometry(xpos[currentPos[0]], ypos[currentPos[0]], 19,26);
		players[0]->addMoney(500);
		drawCard(selectPiece[p[0]]);
		drawCard1(selectPiece[p[0]]);
		goRandom(selectPiece[p[0]]);
		buyHouse(selectPiece[p[0]]);
		checkLoss();

}

void MainWindow::randomNum1()//randomNum generator player 2 dice
{
		if (playerChoice[1] == false){
			return;
		}		
		int	cardNum;
		cardNum= rand()%6;
		//Show the face up card
		for (int x=0; x<6; x++){
			if ( cardNum == x) {
				diceButton[1]->setIcon( *dice[x] );
			diceButton[1]->setEnabled( true); 
			} 
		}

				currentPos[1] = currentPos[1] + cardNum +1;
				if (currentPos[1] > 39)
				{
					currentPos[1] = currentPos[1] - 40;
				}
				a=1;
				selectPiece[p[1]]->setGeometry(xpos[currentPos[1]]+20, ypos[currentPos[1]], 19,26);
		players[1]->addMoney(500);
			drawCard(selectPiece[p[1]]);
		drawCard1(selectPiece[p[1]]);
		goRandom(selectPiece[p[1]]);
		buyHouse(selectPiece[p[1]]);
		checkLoss();

}


void MainWindow::randomNum2()//randomNum generator player 3 dice
{
		if (playerChoice[2] == false){
			return;
		}	
		int	cardNum;
		cardNum= rand()%6;
		//Show the face up card
		for (int x=0; x<6; x++){
			if ( cardNum == x) {
				diceButton[2]->setIcon( *dice[x] );
			diceButton[2]->setEnabled( true); 
			} 
		}
				currentPos[2] = currentPos[2] + cardNum +1;
				if (currentPos[2] > 39)
				{
					currentPos[2] = currentPos[2] - 40;
				}
				a=2;
				selectPiece[p[2]]->setGeometry(xpos[currentPos[2]], ypos[currentPos[2]]-25, 19,26);
		players[2]->addMoney(500);
		drawCard(selectPiece[p[2]]);
		drawCard1(selectPiece[p[2]]);
		goRandom(selectPiece[p[2]]);
		buyHouse(selectPiece[p[2]]);
		checkLoss();
}


void MainWindow::randomNum3()//randomNum generator player 4 dice
{
		if (playerChoice[3] == false){
			return;
		}		
		int	cardNum;
		cardNum= rand()%6;
		//Show the face up card
		for (int x=0; x<6; x++){
			if ( cardNum == x) {
				diceButton[3]->setIcon( *dice[x] );
			diceButton[3]->setEnabled( true); 
			} 
		}

				currentPos[3] = currentPos[3] + cardNum +1;
				if (currentPos[3] > 39)
				{
					currentPos[3] = currentPos[3] - 40;
				}
				a=3;
				selectPiece[p[3]]->setGeometry(xpos[currentPos[3]]+20, ypos[currentPos[3]]-25, 19,26);
		players[3]->addMoney(500);
			drawCard(selectPiece[p[3]]);
		drawCard1(selectPiece[p[3]]);
		goRandom(selectPiece[p[3]]);
		buyHouse(selectPiece[p[3]]);
		checkLoss();
}


void MainWindow::chooseCard()//drawing the card for chance pile
{
		int	cardNum;
		cardNum= rand()%8;
		//Show the face up card
		if (isFaceDown){
			for (int x=0; x<8; x++){
				if ( cardNum == x) {
					cardDeckButton->setIcon( *card[x] );
					cardDeckButton->setEnabled( true); 
						players[a]->subtractMoney((x+1)*100);
						//cout<<players[a]->getMoney();
						guiPlayers[0]->callLabel();
					isFaceDown = false;
				} 
			}
		}
		else {
		  cardDeckButton->setIcon( *card[8] );
			cardDeckButton->setEnabled( false); 
		  isFaceDown = true;
		}
}

void MainWindow::chooseCard1()//drawing the card for commmunity chest deck
{
		int	cardNum;
		cardNum= rand()%8;
		//Show the face up card
		if (isFaceDown1){
			for (int x=0; x<8; x++){
				if ( cardNum == x) {
					cardDeckButton1->setIcon( *card1[x] );
					cardDeckButton1->setEnabled( true); 
						players[a]->addMoney((x+1)*100);
						//cout<<players[a]->getMoney();
						guiPlayers[0]->callLabel();
					isFaceDown1 = false;
				} 
			}
		}
		else {
		  cardDeckButton1->setIcon( *card1[8] );
			cardDeckButton1->setEnabled( false);
		  isFaceDown1 = true;
		}

}

void MainWindow::choosePlayer(int n)//the function for selecting different pieces, without any repeats or selecting the same piece. 
{

	if (		choose1== false && choose2 == false && choose3 == false && choose4 == false){
		return;
	}

	if (choose1== true && choose2 == false && choose3 == false && choose4 == false ){
	selectPiece[n]->setGeometry(87, 567, 19, 26);
	p[0]=n;
  playerChoice[0] = true;
	}
	if (choose1== false && choose2 == true && choose3 == false && choose4 == false ){
	selectPiece[n]->setGeometry(107, 567, 19, 26);
	p[1]=n;
  playerChoice[1] = true;
	}
	if (choose1== false && choose2 == false && choose3 == true && choose4 == false ){
 	selectPiece[n]->setGeometry( 87, 542, 19, 26);
	p[2]=n;
  playerChoice[2] = true;
	}
	if (choose1== false && choose2 == false && choose3 == false && choose4 == true ){
  	selectPiece[n]->setGeometry( 107, 542, 19, 26);
	p[3]=n;
  playerChoice[3] = true;
	}
	
	choose1= false; 
	choose2 = false; 
	choose3 = false ;
	 choose4 = false;

	for (int x=0; x<4; x++){
		if (playerChoice[x] == true){
			numPlayers[x]->setEnabled(false);
		}else{
				numPlayers[x]->setEnabled(true);
		}
	}
	counter++;

	if (counter >=2){
	  diceButton[0]->setEnabled(true );
  diceButton[1]->setEnabled(true );
  diceButton[2]->setEnabled(true );
  diceButton[3]->setEnabled(true );
	}
	
}

/*void MainWindow::choosePlayer2()
{
		
  	selectPiece[0]->setGeometry( 87, 567, 19, 26);
  	selectPiece[1]->setGeometry( 107, 567, 19, 26);
		//selectPiece[0]->setEnabled(false);
		//selectPiece[1]->setEnabled(false);
}

void MainWindow::choosePlayer3()
{
  	selectPiece[0]->setGeometry( 87, 567, 19, 26);
  	selectPiece[1]->setGeometry( 107, 567, 19, 26);
  	selectPiece[2]->setGeometry( 87, 542, 19, 26);
		//selectPiece[0]->setEnabled(false);
		//selectPiece[1]->setEnabled(false);
		//selectPiece[2]->setEnabled(false);

}

void MainWindow::choosePlayer4()
{
  	selectPiece[0]->setGeometry( 87, 567, 19, 26);
  	selectPiece[1]->setGeometry( 107, 567, 19, 26);
  	selectPiece[2]->setGeometry( 87, 542, 19, 26);
  	selectPiece[3]->setGeometry( 107, 542, 19, 26);
		//selectPiece[0]->setEnabled(false);
		//selectPiece[1]->setEnabled(false);
		//selectPiece[2]->setEnabled(false);
		//selectPiece[3]->setEnabled(false);
}*/
void MainWindow::playerOne()//setting player 1 button to enable
{
	choose1 = true;
	choose2 = false;
	choose3 = false;
	choose4 = false;
	numPlayers[0]->setEnabled( true);
	numPlayers[1]->setEnabled( false);
	numPlayers[2]->setEnabled( false);
	numPlayers[3]->setEnabled( false);
 	a=0;

}

void MainWindow::playerTwo()//setting player 2 button to enable
{
	choose1 = false;
	choose2 = true;
	choose3 = false;
	choose4 = false;
	numPlayers[0]->setEnabled( false);
	numPlayers[1]->setEnabled( true);
	numPlayers[2]->setEnabled( false);
	numPlayers[3]->setEnabled( false);
	a=1;
}

void MainWindow::playerThree()//setting player 3 button to enable
{
	choose1 = false;
	choose2 = false;
	choose3 = true;
	choose4 = false;
	numPlayers[0]->setEnabled( false);
	numPlayers[1]->setEnabled( false);
	numPlayers[2]->setEnabled( true);
	numPlayers[3]->setEnabled( false);
	a=2;
}

void MainWindow::playerFour()//setting player 4 button to enable
{
	choose1 = false;
	choose2 = false;
	choose3 = false;
	choose4 = true;
	numPlayers[0]->setEnabled( false);
	numPlayers[1]->setEnabled( false);
	numPlayers[2]->setEnabled( false);
	numPlayers[3]->setEnabled( true);
	a=3;
}
