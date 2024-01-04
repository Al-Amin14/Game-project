#include<iostream>
#include "iGraphics.h"
using namespace std;
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
#define screenWidth 1000
#define screenHight 600
#define jumplim 552
#define supra 552
int x = 0;
int y = 0;
int musicOn = true;
int r = 255;
int g = 255;
int b = 255;
int a;
char demon[6][100] = { "run\\run1.bmp", "run\\run2.bmp", "run\\run3.bmp", "run\\run4.bmp", "run\\run5.bmp", "run\\run6.bmp"};

char demon_stand[15] = "run\\stand.bmp";

char jump_up[3][100] = {"jump\\jump_up1.bmp", "jump\\jump_up2.bmp", "jump\\jump_up3.bmp" };
char jump_down[3][100] = {"jump\\jump_down1.bmp", "jump\\jump_down2.bmp", "jump\\jump_down3.bmp" };
int demon_cordX = 0;
int demon_cordY = 0;
int demon_ind = 0;

bool standposs = true;
int standcounter = 0;

bool jumpdown = false;
bool jumpup = false;
int ind_jm_up = 0;
int ind_jm_dw = 0;
int demon_jump_cord_x = 0;

char demon_sp1[2][30] = { "run\\sp1.bmp", "run\\sp2.bmp"};
char demon_sp2[3][30] = { "run\\sp3.bmp", "run\\sp4.bmp", "run\\sp5.bmp" };
char dem_pow[4][30] = { "run\\bum1.bmp", "run\\bum2.bmp", "run\\bum3.bmp", "run\\bum4.bmp" };

bool demon_supra = false,demon_spup=false;
int  supra1= 0,supra2=0,demon_Y=0;




bool fl = true;

bool dem_pow1 = false;
int pow_ind = 0,pow_x=200;

char dem_sur[6][30] = { "run\\pic1.bmp", "run\\pic2.bmp", "run\\pic3.bmp", "run\\pic4.bmp", "run\\pic5.bmp", "run\\pic6.bmp" };
bool dem_sur1 = false;
int dem_ind = 0, dem_sur_x=200;

char sur_sock[3][30] = { "run\\pic7.bmp", "run\\pic8.bmp", "run\\pic9.bmp"};
bool sur_sock_fl = false;
int sur_sock1 = 0;

char over_jump[4][300] = { "run\\dig1.bmp", "run\\dig2.bmp", "run\\dig3.bmp", "run\\dig4.bmp"};
bool over_jump1 = false;
int over_jump_ind = 0;


char over_dowm[4][30] = { "run\\dig5.bmp", "run\\dig6.bmp", "run\\dig7.bmp", "run\\dig8.bmp" };
bool over_down1 = false;
int over_dowm_jm = 0;


char power_b[8][30] = { "run\\pob1.bmp", "run\\pob2.bmp", "run\\pob3.bmp", "run\\pob4.bmp", "run\\pob5.bmp", "run\\pob6.bmp","run\\pob7.bmp","run\\pob8.bmp" };
char power_b2[5][30] = { "run\\po1.bmp", "run\\po2.bmp", "run\\po3.bmp", "run\\po6.bmp","run\\po7.bmp" };
bool power_bb = false,power_bb_first=false;
int power_bb_ind = 0,power_bb_ind2=0,ind_cord_x=120;

void iDraw()
{
	iClear();
	iShowBMP(0, 0, "image\\back_gr_gm.bmp");
	if (jumpup){
			iShowBMP2(demon_cordX, demon_cordY + demon_jump_cord_x, jump_up[ind_jm_up], 0);
		}
		if(jumpdown){
			cout << "This is from the jump cord " << ind_jm_dw << endl;
			iShowBMP2(demon_cordX, demon_cordY + demon_jump_cord_x, jump_down[ind_jm_dw], 0);
		}
	if (fl){
			if (!standposs){
				iShowBMP2(demon_cordX, demon_cordY, demon[demon_ind], 0);
			}
		}
	if (standposs){
			iShowBMP2(demon_cordX, demon_cordY, demon_stand, 0);
	}
	if (demon_supra){
		if (demon_spup){
			iShowBMP2(demon_cordX, demon_cordY + demon_jump_cord_x, demon_sp1[supra1], 0);
			}
		else
		{
			iShowBMP2(demon_cordX, demon_cordY + demon_jump_cord_x, demon_sp2[supra2], 0);
		}
	}
	if (dem_pow1){
		iShowBMP2(demon_cordX+pow_x, 0, dem_pow[pow_ind], 0);
	}
	if (dem_sur1){
		iShowBMP2(demon_cordX, demon_cordY,dem_sur[dem_ind],0);
	}
	if (sur_sock_fl){
		iShowBMP2(demon_cordX +dem_sur_x, demon_cordY,sur_sock[sur_sock1],0);
	}
	if (over_jump1){
		iShowBMP2(demon_cordX, demon_cordY + demon_jump_cord_x , over_jump[over_jump_ind], 0);
	}
	if (over_down1){
		iShowBMP2(demon_cordX, demon_cordY + demon_jump_cord_x, over_dowm[over_dowm_jm], 0);
	}
	if (power_bb){
		if (power_bb_first)
			iShowBMP2(demon_cordX, demon_cordY, power_b[power_bb_ind], 0);
		else
			iShowBMP2(demon_cordX+ind_cord_x, demon_cordY, power_b2[power_bb_ind2], 0);
	}
}

 
/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{
	x = mx - 120;
	y = mx - 20;
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{
	/*
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		x = mx - 150;
		y = my - 20;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		r = 255;
		b = 0;
		g = 0;
	}
	*/
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/

void iKeyboard(unsigned char key)
{
	if (key == 'w')
	{
		y += 10;
	}
	else if (key == 's'){
		y -= 10;
	}
	else if (key == 'a'){
		x -= 10;
	}
	if (key == 'v'){
		if (!power_bb){
			power_bb = true;
			power_bb_first = true;
			fl = false;
			standposs = false;
		}
	}
	if (key == 'r'){
		if (!over_jump1){
			over_jump1 = true;
			fl = false;
			standposs = false;
		}
	}
	if (key == 'g'){
		if (!dem_sur1){
			fl = false;
			standposs = false;
			dem_sur1 = true;
		}
	}
	if (key == ' '){
		if (!jumpup){
			jumpup = true;
			over_jump1 = false;
			fl = false;
			standposs = false;
		}
	}
	if (key == 'b'){
		if (!demon_supra){
			demon_spup = true;
			demon_supra = true;
			fl = false;
			standposs = false;
	    } 
    }
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/

void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_RIGHT)
	{

		demon_cordX += 100;

		demon_ind++;
		if (demon_ind >= 6)
			demon_ind = 0;

		standposs = false;

	}
	else if (key == GLUT_KEY_LEFT)
	{
		demon_cordX -= 50;
		
		demon_ind-- ;
		if (demon_ind < 0)
			demon_ind = 5;

		standposs = false;
	}
	else if (key == GLUT_KEY_DOWN)
	{

	}
	else if (key == GLUT_KEY_UP){
		iShowBMP2(demon_cordX, demon_cordY + 100, jump_up[2], 0);
	}
	else if (key = GLUT_KEY_INSERT){
		r = 255;
		g = 0;
		b = 0;
	}
	else if (key == GLUT_KEY_HOME){
		r = 0;
		g = 0;
		b = 255;
	}
}
void change(){
	if (power_bb){
		if (power_bb_first){
			power_bb_ind++;
		}
		else{
			ind_cord_x+= 120;
			power_bb_ind2++;
		}
	}
	if (jumpup){
		standposs = false;
		ind_jm_up++;
		demon_jump_cord_x += 184;
	}
	if (jumpdown){
		standposs = false;
		ind_jm_dw++;
		demon_jump_cord_x -= 184;
	}
	if (over_jump1){
		demon_jump_cord_x += 138;
		standposs = false;
		fl = false;
		over_jump_ind++;
	}
	if (over_down1){
		demon_jump_cord_x -= 138;
		standposs = false;
		fl = false;
		over_dowm_jm++;
	}
	if (dem_sur1){
		standposs = false;
		dem_ind++;
	}
	if (sur_sock_fl){
		standposs = false;
		sur_sock1++;
		dem_sur_x += 300;
	}
	if (dem_pow1){
		standposs = false;
		pow_ind++;
		pow_x += 250;
	}
	demon_ind++;
	if (demon_ind >= 6)
		demon_ind = 0;

	if (demon_supra){
		fl = false;
		standposs = false;
		if (demon_spup)
		{
			supra1++;
		}
		else{
			supra2++;
		}
	}

	

	if (supra1 >= 2){
		demon_spup = false;
		supra1 = 0;
	}
	if (supra2 >= 3){
		fl = true;
		standposs = true;
		dem_pow1 = true;
		demon_supra = false;
		supra2 = 0;
		jumpup = false;
	}
	if (pow_ind >= 4){
		dem_pow1 = false;
		pow_ind = 0;
		pow_x = 200;
	}
	if (dem_ind>=6){
		dem_ind = 0;
		dem_sur1 = false;
		sur_sock_fl = true;
	}
	if (sur_sock1 >= 3){
		fl = true;
		standposs = true;
		sur_sock1 = 0;
		dem_sur_x = 200;
		sur_sock_fl = false;
	}
	if (over_jump_ind >= 4){
		over_jump_ind=0;
		over_jump1 = false;
		over_down1 = true;
		demon_jump_cord_x -= 138;
	}
	if (over_dowm_jm >= 4){
		fl = true;
		standposs = true;
		over_dowm_jm = 0;
		over_down1 = false;
		demon_jump_cord_x = 0;
	}
	if (ind_jm_up >= 3){
		demon_jump_cord_x -= 184;
		ind_jm_up = 0;
		jumpup = false;
		jumpdown = true;
	}
	if (ind_jm_dw >= 3){
		fl = true;
		standposs = true;
		ind_jm_dw = 0;
		jumpdown = false;
		demon_jump_cord_x = 0;
	}
	if (power_bb_ind >= 8){
		power_bb_ind = 0;
		power_bb_first = false;
	}
	if (power_bb_ind2 >= 5){
		ind_cord_x = 120;
		power_bb = false;
		power_bb_ind2 = 0;
		standposs = true;
	}

}
int main()
{
	iSetTimer(100,change);
	iInitialize(1200, 800, "hills");
	///updated see the documentations
	iStart();
	return 0;
}