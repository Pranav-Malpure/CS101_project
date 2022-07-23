#ifndef __LASSO_H__
#define __LASSO_H__

#include "MovingObject.h"
#include "coin.h"

//#define WINDOW_X 1200
//#define WINDOW_Y 960
#define WINDOW_X 800
#define WINDOW_Y 600

#define STEP_TIME 0.05

#define PLAY_X_START 100
#define PLAY_Y_START 0
#define PLAY_X_WIDTH (WINDOW_X-PLAY_X_START)
#define PLAY_Y_HEIGHT (WINDOW_Y-100)

#define LASSO_X_OFFSET 100
#define LASSO_Y_HEIGHT 100
#define LASSO_BAND_LENGTH LASSO_X_OFFSET
#define LASSO_THICKNESS 5

#define COIN_GAP 1

#define RELEASE_ANGLE_STEP_DEG 5
#define MIN_RELEASE_ANGLE_DEG 0
#define MAX_RELEASE_ANGLE_DEG (360-RELEASE_ANGLE_STEP_DEG)
#define INIT_RELEASE_ANGLE_DEG 45

#define RELEASE_SPEED_STEP 20
#define MIN_RELEASE_SPEED 0
#define MAX_RELEASE_SPEED 200
#define INIT_RELEASE_SPEED 100

#define COIN_SPEED 120
#define COIN_ANGLE_DEG 90

#define LASSO_G 30
#define COIN_G 30

#define LASSO_SIZE 10
#define LASSO_RADIUS 50
#define COIN_SIZE 5

class timer{
    public:

  timer(){
  float timeRemaining = 20; //for time countdown
  for(int i=19;i>=0;i--){ 
    Text Timecount1(PLAY_X_START+360,PLAY_Y_HEIGHT+25,timeRemaining);
    timeRemaining=i;
    wait(1); 
  }
}
};


class Lasso : public MovingObject {
  double lasso_start_x;
  double lasso_start_y;
  double release_speed;
  double release_angle_deg;
  double lasso_ax;
  double lasso_ay;

  // Moving parts
  Circle lasso_circle;
  Circle lasso_loop;

  // Non-moving parts
  Line lasso_line;
  Line lasso_band;

  // State info
  bool lasso_looped;
  Coin *the_coin;
  int num_coins;
  int lives_remaining=5;

  void initLasso();
 public:
 Lasso(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta){
    release_speed = speed;
    release_angle_deg = angle_deg;
    lasso_ax = argax;
    lasso_ay = argay;
    initLasso();
  }

  void draw_lasso_band();
  void yank();
  void yank1();
  void yank2();
  void yank3();
  void yank4();
  void loopit();
  void addAngle(double angle_deg);
  void addSpeed(double speed);

  void nextStep(double t);
  void nextStep1(double t1);
  void check_for_coin(Coin *coin);
  int getNumCoins() { return num_coins;}

  int getLivesRemaining(){ return lives_remaining;} 
}; // End class lasso

class helpbox{ //This class is for helpbox(controls panel)
    public:
    void openMenu(){
    
      Rectangle ControlsTextRect(400,300,700,500);
      ControlsTextRect.setColor(COLOR(244,164,96));
      ControlsTextRect.setFill(true);
      Text ControlsHelp1(400,100,"Throw the lasso -> T");
      Text ControlsHelp2(400,150,"Yank the lasso -> Y");
      Text ControlsHelp3(400,200,"Add Speed -> =");  
      Text ControlsHelp4(400,250,"Lessen Speed of lasso -> -");
      Text ControlsHelp5(400,300,"Change Throwing angles of lasso -> [,]");
      Text ControlsHelp6(400,350,"Quit Game -> Q");
      Text ControlsHelp7(400,400,"This Help Menu -> H");
      Text ControlsHelp8(400,450,"This helpbox will disappear in 10 seconds");
      ControlsHelp8.setColor(COLOR(255,69,0));
      wait(10);     
  }
};
#endif
