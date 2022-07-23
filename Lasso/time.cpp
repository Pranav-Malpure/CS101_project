#include<simplecpp>
#include "lasso.h"
using namespace simplecpp;
main_program {
	float timeRemaining = 20; //for time countdown
	for(int i=19;i>=0;i--){ 
		Text Timecount1(PLAY_X_START+360,PLAY_Y_HEIGHT+25,timeRemaining);
		timeRemaining=i;
		wait(1); 
	}

}