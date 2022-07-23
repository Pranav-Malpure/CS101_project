#include <simplecpp>
#include <string>
#include "MovingObject.h"
#include "lasso.h"
#include "coin.h"


using namespace simplecpp;

main_program {
  initCanvas("Lasso", WINDOW_X, WINDOW_Y);

  int stepCount = 0;
  float stepTime = STEP_TIME;
  float runTime = -1; // sec; -ve means infinite
  float currTime = 0;
  int livesRemainingInt; //Will be used later, to count the number of lives remaining...

  // Draw lasso at start position
  double release_speed = INIT_RELEASE_SPEED; // m/s
  double release_angle_deg = INIT_RELEASE_ANGLE_DEG; // degrees
  double lasso_ax = 0;
  double lasso_ay = LASSO_G;
  bool paused = true;
  bool rtheta = true;
  Lasso lasso(release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);

  Line b1(0, PLAY_Y_HEIGHT, WINDOW_X, PLAY_Y_HEIGHT);
  b1.setColor(COLOR("green"));
  Line b2(PLAY_X_START, 0, PLAY_X_START, WINDOW_Y);
  b2.setColor(COLOR("green"));

  Text HelpMenu(650,25,"Press H to know Controls"); //for displaying instruction to open helpbox
  HelpMenu.setColor(COLOR(184,134,11));
 
  string msg1("Cmd: _");
  Text charPressed(PLAY_X_START+50, PLAY_Y_HEIGHT+20, msg1);
  char coinScoreStr[256];
  sprintf(coinScoreStr, "Coins: %d", lasso.getNumCoins());
  Text coinScore(PLAY_X_START+50, PLAY_Y_HEIGHT+50, coinScoreStr);

  char LivesRemainingStr[256];    //For keeping track of no. of livs remaining
  sprintf(LivesRemainingStr, "Lives: %d", lasso.getLivesRemaining());
  Text LivesRemaining(PLAY_X_START+310, PLAY_Y_HEIGHT+20, LivesRemainingStr);


  Text Level1(400,300,"LEVEL-1");
  Level1.setColor(COLOR(128,0,128));
  Rectangle Rlevel1(400,300,textWidth("LEVEL-1")+4,30);
  wait(1.5);
  Level1.hide();
  Rlevel1.hide();


  paused = true; rtheta = true;
  double coin_speed = COIN_SPEED;
  double coin_angle_deg = COIN_ANGLE_DEG;
  double coin_ax = 0;
  double coin_ay = COIN_G;
  Coin coin(coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);
  coin.initCoin();

  // After every COIN_GAP sec, make the coin jump
  double last_coin_jump_end = 0;

  // When t is pressed, throw lasso
  // If lasso within range, make coin stick
  // When y is pressed, yank lasso
  // When l is pressed, loop lasso
  // When q is pressed, quit

//                                        ....LEVEL-1 CODES.....

  for(;;) {

    if((runTime > 0) && (currTime > runTime)) { break; }

    XEvent e;
    bool pendingEv = checkEvent(e); 
    if(pendingEv) {
      char c = charFromEvent(e);
      msg1[msg1.length()-1] = c;
      charPressed.setMessage(msg1);
      switch(c) {
      case 't':
	lasso.unpause();
	break;
      case 'y':
	lasso.yank();
	break;
      case 'l':
	lasso.loopit();
	lasso.check_for_coin(&coin);
	wait(STEP_TIME*5);
	break;
      case '[':
	if(lasso.isPaused()) { lasso.addAngle(-RELEASE_ANGLE_STEP_DEG);	}
	break;
      case ']':
	if(lasso.isPaused()) { lasso.addAngle(+RELEASE_ANGLE_STEP_DEG); }
	break;
      case '-':
	if(lasso.isPaused()) { lasso.addSpeed(-RELEASE_SPEED_STEP); }
	break;
      case '=':
	if(lasso.isPaused()) { lasso.addSpeed(+RELEASE_SPEED_STEP); }
	break;
      case 'h':              //For helpbox
  helpbox HELPBOX;    
  HELPBOX.openMenu();
  break;       
      case 'q':
	exit(0);
      default:
	break;
      }
    }


    lasso.nextStep(stepTime);

    coin.nextStep(stepTime);
    if(coin.isPaused()) {
      if((currTime-last_coin_jump_end) >= COIN_GAP) {
	      coin.unpause();
      }
    }

    if(coin.getYPos() > PLAY_Y_HEIGHT) {
      coin.resetCoin();
      last_coin_jump_end = currTime;
    }

    sprintf(coinScoreStr, "Coins: %d", lasso.getNumCoins());
    coinScore.setMessage(coinScoreStr);
    
    sprintf(LivesRemainingStr, "Lives: %d", lasso.getLivesRemaining());  //This is for displaying how many lives are left
    LivesRemaining.setMessage(LivesRemainingStr);

    stepCount++;
    currTime += stepTime;
    wait(stepTime);

    int totalScore = lasso.getNumCoins();
    livesRemainingInt = lasso.getLivesRemaining();    //This is for getting the value of how many lives are left into an int

    if( livesRemainingInt == 0){                          // THIS IS FOR CHECKING IF LIVES ARE LEFT OR NOT
      Text gameover(400,300,"GAME OVER");
      gameover.setColor(COLOR(30,144,255));
      Rectangle Gameover(400,300,textWidth("GAME OVER")+4,30);
      wait(1.2);
      exit(0);
    }

    if( totalScore >= 3 ){coin.destroyinitCoin();break;}


  } // End for(;;)

//                                ....START OF LEVEL-2 CODES....

  Text Level2(400,300,"LEVEL-2");
  Level2.setColor(COLOR(128,0,128));
  Rectangle Rlevel2(400,300,textWidth("LEVEL-2")+4,30);
  wait(2.2);
  Level2.hide();
  Rlevel2.hide();

  paused = true; rtheta = true;
  coin_speed = COIN_SPEED;
  coin_angle_deg = COIN_ANGLE_DEG*1.25;
  coin_ax = 0;
  coin_ay = COIN_G*3;
  Coin coin1(coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);
  coin.initCoin1();

  for(;;) {

    srand((unsigned) time(0));       // for choosing a random number, will be used later...
    int randomnumber = rand()%4;

    if((runTime > 0) && (currTime > runTime)) { break; }

    XEvent e;
    bool pendingEv = checkEvent(e); 
    if(pendingEv) {
      char c = charFromEvent(e);
      msg1[msg1.length()-1] = c;
      charPressed.setMessage(msg1);
      switch(c) {
      case 't':
  lasso.unpause();
  break;
      case 'y':
  if(randomnumber==1){ lasso.yank1();}
  if(randomnumber == 0){ lasso.yank2();}
  if(randomnumber == 2){ lasso.yank3();}
  if(randomnumber == 3){lasso.yank4();}
  break;
      case 'l':
  lasso.loopit();
  lasso.check_for_coin(&coin);
  wait(STEP_TIME*5);
  break;
      case '[':
  if(lasso.isPaused()) { lasso.addAngle(-RELEASE_ANGLE_STEP_DEG); }
  break;
      case ']':
  if(lasso.isPaused()) { lasso.addAngle(+RELEASE_ANGLE_STEP_DEG); }
  break;
      case '-':
  if(lasso.isPaused()) { lasso.addSpeed(-RELEASE_SPEED_STEP); }
  break;
      case '=':
  if(lasso.isPaused()) { lasso.addSpeed(+RELEASE_SPEED_STEP); }
  break;
      case 'h':              //For helpbox
  helpbox HELPBOX;    
  HELPBOX.openMenu();
  break;       
      case 'q':
  exit(0);
      default:
  break;
      }
    }

    lasso.nextStep(stepTime);
    coin.nextStep(stepTime);
    if(coin.isPaused()) {
      if((currTime-last_coin_jump_end) >= COIN_GAP) {
        coin.unpause();
      }
    }
    
    if(coin.getYPos() > PLAY_Y_HEIGHT || coin.getYPos() < 0) {
      if(randomnumber == 1){ coin.resetCoin1();}
      if(randomnumber == 0){ coin.resetCoin2();}
      if(randomnumber == 2){ coin.resetCoin3();}
      if(randomnumber == 3){coin.resetCoin4();}
      last_coin_jump_end = currTime;
    }

    sprintf(coinScoreStr, "Coins: %d", lasso.getNumCoins());
    coinScore.setMessage(coinScoreStr);

    sprintf(LivesRemainingStr, "Lives: %d", lasso.getLivesRemaining());
    LivesRemaining.setMessage(LivesRemainingStr);

    stepCount++;
    currTime += stepTime;
    wait(stepTime);

    int totalScore = lasso.getNumCoins();
    livesRemainingInt = lasso.getLivesRemaining();    //This is for getting the value of how many lives are left into an int


    if( livesRemainingInt == 0){
      Text gameover(400,300,"GAME OVER");
      gameover.setColor(COLOR(30,144,255));
      Rectangle Gameover(400,300,textWidth("GAME OVER")+4,30);
      wait(1.5);
      exit(0);
	} 
    if( totalScore >= 10){
	 	Text YouWin(400,300,"!! YOU WON !!");							 //For ending the game once total
	 	YouWin.setColor(COLOR("Gold"));									 //coins collected are 10
	 	Rectangle YouWinRect(400,300,textWidth("!! YOU WIN !!")+15,30);
	 	YouWinRect.setColor(COLOR("Red"));
	 	coin.destroyinitCoin1();
	 	wait(3);
	 	exit(0);
 	}

  }// End of for loop

  wait(3);

} // End main_program
