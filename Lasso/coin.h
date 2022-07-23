#ifndef __COIN_H__
#define __COIN_H__

#include "MovingObject.h"
#include<cstdlib>

class Coin : public MovingObject {
  double coin_start_x;
  double coin_start_y;
  double release_speed;
  double release_angle_deg;
  double coin_ax;
  double coin_ay;

  // Moving parts
  Circle coin_circle;

 public:
 Coin(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta) {
    release_speed = speed;
    release_angle_deg = angle_deg;
    coin_ax = argax;
    coin_ay = argay;
    //initCoin();
  }

  void initCoin();
  void initCoin1();
  void resetCoin();
  void resetCoin1();
  void resetCoin2();
  void resetCoin3();
  void resetCoin4();
  void destroyinitCoin();
  void destroyinitCoin1();

}; // End class Coin

#endif
