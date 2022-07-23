#include "coin.h"
#include "lasso.h"

void Coin::initCoin() {
  coin_start_x = (PLAY_X_START+WINDOW_X)/2;
  coin_start_y = PLAY_Y_HEIGHT;
  coin_circle.reset(coin_start_x, coin_start_y, COIN_SIZE);
  coin_circle.setColor(COLOR("gold"));
  coin_circle.setFill(true);
  addPart(&coin_circle);
}

void Coin::destroyinitCoin() {
  coin_circle.moveTo(1000,1000);
}

void Coin::destroyinitCoin1(){
	coin_circle.moveTo(1000,100);
}

void Coin::initCoin1(){
  coin_start_x = (PLAY_X_START+WINDOW_X)/2;
  coin_start_y = PLAY_Y_HEIGHT;
  coin_circle.reset(coin_start_x, coin_start_y, COIN_SIZE);
  coin_circle.setColor(COLOR("orange"));
  coin_circle.setFill(true);
  addPart(&coin_circle);

}

void Coin::resetCoin() {
  double coin_speed = COIN_SPEED;
  double coin_angle_deg = COIN_ANGLE_DEG;
  coin_ax = 0;
  coin_ay = COIN_G;
  bool paused = true, rtheta = true;
  reset_all(coin_start_x, coin_start_y, coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);
}

void Coin::resetCoin1() {
  double coin_speed = COIN_SPEED;
  double coin_angle_deg = COIN_ANGLE_DEG*1.25;
  coin_ax = 0;
  coin_ay = COIN_G*2.5;
  bool paused = true, rtheta = true;
  reset_all(coin_start_x + 250, coin_start_y, coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);
}

void Coin::resetCoin2() {
  double coin_speed = COIN_SPEED*1.2;
  double coin_angle_deg = COIN_ANGLE_DEG*0.75;
  coin_ax = 0;
  coin_ay = COIN_G*2.5;
  bool paused = true, rtheta = true;
  reset_all(coin_start_x - 125, coin_start_y, coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);
}

void Coin::resetCoin3() {
  double coin_speed = COIN_SPEED*1.5;
  double coin_angle_deg = COIN_ANGLE_DEG*2;
  coin_ax = 0;
  coin_ay = COIN_G*3.1;
  bool paused = true, rtheta = true;
  reset_all(coin_start_x + 350, coin_start_y - 400, coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);
}

void Coin::resetCoin4() {
  double coin_speed = COIN_SPEED*1.6;
  double coin_angle_deg = COIN_ANGLE_DEG*3.15;
  coin_ax = 0;
  coin_ay = -COIN_G*2.75;
  bool paused = true, rtheta = true;
  reset_all(PLAY_X_START+65, 0, coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);
}




