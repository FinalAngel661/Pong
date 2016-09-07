
#include "sfwdraw.h"
#include <iostream>
#include <conio.h>
#include "GameManager.h"

void main()
{
	int width = 800, height = 600;

	sfw::initContext(width,height,"NSFW Draw");


	sfw::setBackgroundColor(CYAN);
	
	Player myPlayer;
	myPlayer.Tries = 2;

	Player PlayerMovement;

	ScoreandTime Time;

	Boundary drawBound;
	Ball drawBall;

	unsigned r = sfw::loadTextureMap("./res/Boundary.png");

	while (sfw::stepContext())
	{
		
		PlayerMovement.PlayerMovement();
		drawBound.drawBound();
		drawBall.drawBall();
	}
	sfw::termContext();
}