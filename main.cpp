
#include "sfwdraw.h"
#include <iostream>
#include <conio.h>

const float identity[16] = { 1,0,0,0,  0,1,0,0, 0,0,1,0, 0,0,0,1 };


struct Player
{
	float Tries = 2;
	float x = 300;


	void PlayerMovement()
	{
			if (sfw::getKey('W'))
			{
				x += 1;
			}

			sfw::drawLine(x, 100, x + 100, 100);

			if (sfw::getKey('S'))
			{

				x -= 1;
			}

			sfw::drawLine(x, 100, x - 100, 100);

			if (sfw::getKey('A'))
			{


			}

			if (sfw::getKey('D'))
			{


			}
		
	}

};


struct Obstacles
{
	float x = 300;

	void VObstacle()
	{
		sfw::drawLine(x, 100, x + 100, 100);

		sfw::drawLine(x, 100, x - 100, 100);
	
	}

};



/*
struct Ball
{


	
			sfw::drawCircle( 300,  300,  5, 
			unsigned steps = 12, unsigned tint = 0xffff00ff, 
			const float transform[16] = identity);
	
	
	


};
*/

struct Boundary
{
	int width = 800, height = 600;

	/*void drawTexture("Blue - Divider - Line", float 800, float 600,
		float width = 1, float height = 1, float angle = 0, 
		bool centered = true, unsigned index = 0, 
		unsigned int tint = WHITE, 
		const float transform[16] = identity);*/
	//sfw::loadTextureMap("./res/Blue - Divider - Line.png");
};

struct ScoreandTime
{

	void Time()
	{
		float x = 100, y = 100;
		float x2 = 500, y2 = 100;
		float counter = 0;
		float size = 400;

		while (sfw::stepContext)
		{
			counter += sfw::getDeltaTime();
			if (counter > 1.f)
			{
				counter = 0;
				size /= 2;
			}
		}

		if (sfw::getKey('W'))
			y += sfw::getDeltaTime() * 30;

		if (sfw::getKey('S'))
			y -= sfw::getDeltaTime() * 30;


		if (sfw::getKey('A'))
			y2 += sfw::getDeltaTime() * 30;

		if (sfw::getKey('D'))
			y2 -= sfw::getDeltaTime() * 30;

		sfw::drawLine(x, y, x, y + size, CYAN);
		sfw::drawLine(x2, y2, x2, y2 + size, RED);
	
	}

	void Score()
	{
		
	
	}



};

void main()
{
	int width = 800, height = 600;

	sfw::initContext(width,height,"NSFW Draw");


	/*unsigned f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned d = sfw::loadTextureMap("./res/fontmap.png",16,16);
	unsigned r = sfw::loadTextureMap("./res/background.jpg");
	unsigned u = sfw::loadTextureMap("./res/crosshair.png");*/

	/*float acc = 0;
	char c = '\0';*/

	sfw::setBackgroundColor(WHITE);
	
	Player myPlayer;
	myPlayer.Tries = 2;

	Player PlayerMovement;

	ScoreandTime Time;

	Boundary drawBound;

	unsigned r = sfw::loadTextureMap("./res/Boundary.png");

	while (sfw::stepContext())
	{
		sfw::drawCircle(300, 500, 12, 12, WHITE);

		PlayerMovement.PlayerMovement();
		
	
		sfw::drawTexture(r, 785, 50, sfw::getTextureWidth(r), sfw::getTextureHeight(r), 90, false, 0, 0x88888888);
		sfw::drawTexture(r, 5, 50, sfw::getTextureWidth(r), sfw::getTextureHeight(r), 90, false, 0, 0x88888888);
		sfw::drawTexture(r, 50, 595, sfw::getTextureWidth(r), sfw::getTextureHeight(r), 0, false, 0, 0x88888888);
		sfw::drawTexture(r, 5, 50, sfw::getTextureWidth(r), sfw::getTextureHeight(r), 0, false, 0, 0x88888888);
	}





		//sfw::drawString(f, " !\"#$%&'()*+,./-\n0123456789:;<=>?\n@ABCDEFGHIJKLMNO\nPQRSTUVWXYZ[\\]^_\n`abcdefghijklmno\npqrstuvwxyz{|}~", 0, 600, 48, 48, 0, ' ');
		//sfw::drawTexture(r, 0, 600, 800, 600, 0, false,0, 0x88888888);

		//acc += sfw::getDeltaTime();
		//sfw::drawString(d, "TIME 4 FUN", 400, 300, 48, 48, -acc*24,'\0',MAGENTA);

		//

		//sfw::drawString(d, "6", 400, 32, 24, 24);
		//sfw::drawString(d, "12", 400, 600 - 32, 24, 24);
		//sfw::drawString(d, "3", 800-32, 300, 24, 24);
		//sfw::drawString(d, "9", 32, 300, 24, 24);

		//if(sfw::getMouseButton(MOUSE_BUTTON_RIGHT))
		//	sfw::drawTexture(u, sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(u)/2.5, sfw::getTextureHeight(u)/2.5,45,true,0,0x88ffffff);
		//else sfw::drawTexture(u, sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(u)/2, sfw::getTextureHeight(u)/2);

		
		


	sfw::termContext();
}