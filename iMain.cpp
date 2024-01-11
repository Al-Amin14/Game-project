#include<iostream>
#include "iGraphics.h"
using namespace std;
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
#define screenWidth 1000
#define screenHight 600
#define jumplim 552
#define supra 552
#define lower_sp 15
#define upper_sp 8
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

char vanish_bp[8][30] = { "run\\bp1.bmp", "run\\bp2.bmp", "run\\bp3.bmp", "run\\bp4.bmp", "run\\bp5.bmp", "run\\bp6.bmp", "run\\bp7.bmp", "run\\bp8.bmp"};
char vanish_bp_po[6][30] = { "run\\bp9.bmp", "run\\bp10.bmp", "run\\bp11.bmp", "run\\bp12.bmp", "run\\bp13.bmp", "run\\bp14.bmp" };
bool vanish_bp_fl = false,vanish_bp_fl_1=false;
int vanish_ind1 = 0, vanish_ind2 = 0, vanish_cord_x = 120;

char fb_arr[6][30] = { "run\\fb1.bmp","run\\fb2.bmp", "run\\fb3.bmp", "run\\fb4.bmp", "run\\fb5.bmp", "run\\fb6.bmp" };
char fb_arr2[3][30] = { "run\\fb7.bmp", "run\\fb8.bmp", "run\\fb9.bmp" };
bool fb_arr_fl = false,fb_arr_fl_sr=false;
int ind_fb1 = 0, ind_fb2 = 0,fb_cord_x=200;

char leg_p[5][30] = { "lgp\\lgp1.bmp", "lgp\\lgp2.bmp", "lgp\\lgp3.bmp", "lgp\\lgp4.bmp", "lgp\\lgp5.bmp" };
char leg_p_b[7][30] = { "lgp\\lgpb1.bmp", "lgp\\lgpb2.bmp", "lgp\\lgpb3.bmp", "lgp\\lgpb4.bmp", "lgp\\lgpb5.bmp", "lgp\\lgpb6.bmp", "lgp\\lgpb7.bmp"};
bool leg_p_fl = false, leg_p_fl_1 = false;
int leg_p_ind0 = 0, leg_p_ind2 = 0, lg_cordx = 120;

char thunder_power[4][30] = { "lgp\\th1.bmp", "lgp\\th2.bmp", "lgp\\th3.bmp", "lgp\\th4.bmp"};
char thunder_power_sr[3][30] = { "lgp\\th7.bmp", "lgp\\th6.bmp", "lgp\\th5.bmp"};
bool thunder_fl = false, thunder_fl_1 = false;
int th_ind_1 = 0, th_ind_2 = 0,th_cordx=30;

char thunder_power1[4][30] = { "lgp\\th8.bmp", "lgp\\th9.bmp", "lgp\\th10.bmp", "lgp\\th11.bmp" };
char thunder_power_sr1[6][30] = { "lgp\\th12.bmp", "lgp\\th13.bmp", "lgp\\th14.bmp","lgp\\th15.bmp","lgp\\th16.bmp","lgp\\th17.bmp" };
bool thunder_fl1 = false, thunder_fl_11 = false;
int th_ind_11 = 0, th_ind_22 = 0, th_cordx_1 = 30;


char blade_po[13][30] = { "lgp\\bl_p1.bmp", "lgp\\bl_p2.bmp", "lgp\\bl_p3.bmp", "lgp\\bl_p4.bmp", "lgp\\bl_p5.bmp", "lgp\\bl_p6.bmp", "lgp\\bl_p7.bmp", "lgp\\bl_p8.bmp", "lgp\\bl_p9.bmp", "lgp\\bl_p10.bmp", "lgp\\bl_p11.bmp", "lgp\\bl_p12.bmp", "lgp\\bl_p13.bmp"};
bool blade_pl_fl = false;
int ind_blade_pl = 0;

bool backer = true, back_ran = false;

float x_cord_b= 0.0,x_cord_lo_b=0.0;

bool homepage = true;
bool musicon_home = true;
bool music_game = false;
int cnt = 0;
void iDraw()
{
	iClear();
	if (homepage){
		iShowBMP(0, 0,"bci\\menu.bmp");
		iShowBMP2(780, 610, "bci\\button1.bmp",0);
		iShowBMP2(780, 450, "bci\\button2.bmp", 0);
		iShowBMP2(780, 290, "bci\\button3.bmp", 0);
		iShowBMP2(780, 130, "bci\\button4.bmp", 0);
	}
	else{
		iShowImage(x_cord_b, 194, 1700, 606, a);
		iShowImage(x_cord_b + 1700, 194, 1700, 606, a);
		iShowImage(x_cord_lo_b, 0, 1700, 194, b);
		iShowImage(x_cord_lo_b + 1700, 0, 1700, 194, b);
		if (!standposs){
			x_cord_b -= .8;
			if (x_cord_b <= -1700)
				x_cord_b = 0;
			x_cord_lo_b -= 4;
			if (x_cord_lo_b <= -1700)
				x_cord_lo_b = 0;
		}
		if (jumpup){
			iShowBMP2(demon_cordX, demon_cordY + demon_jump_cord_x, jump_up[ind_jm_up], 0);
		}
		if (jumpdown){
			iShowBMP2(demon_cordX, demon_cordY + demon_jump_cord_x, jump_down[ind_jm_dw], 0);
		}
		if (fl){
			back_ran = true;
			if (!standposs){
				iShowBMP2(demon_cordX, demon_cordY, demon[demon_ind], 0);
			}
		}
		if (standposs){
			back_ran = false;
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
			iShowBMP2(demon_cordX + pow_x, 0, dem_pow[pow_ind], 0);
		}
		if (dem_sur1){
			iShowBMP2(demon_cordX, demon_cordY, dem_sur[dem_ind], 0);
		}
		if (sur_sock_fl){
			iShowBMP2(demon_cordX + dem_sur_x, demon_cordY, sur_sock[sur_sock1], 0);
		}
		if (over_jump1){
			iShowBMP2(demon_cordX, demon_cordY + demon_jump_cord_x, over_jump[over_jump_ind], 0);
		}
		if (over_down1){
			iShowBMP2(demon_cordX, demon_cordY + demon_jump_cord_x, over_dowm[over_dowm_jm], 0);
		}
		if (power_bb){
			if (power_bb_first)
				iShowBMP2(demon_cordX, demon_cordY, power_b[power_bb_ind], 0);
			else
				iShowBMP2(demon_cordX + ind_cord_x, demon_cordY, power_b2[power_bb_ind2], 0);
		}
		if (vanish_bp_fl){
			if (vanish_bp_fl_1){
				iShowBMP2(demon_cordX, demon_cordY, vanish_bp[vanish_ind1], 0);
			}
			else{
				iShowBMP2(demon_cordX + vanish_cord_x, demon_cordY, vanish_bp_po[vanish_ind2], 0);
			}
		}
		if (fb_arr_fl){
			if (fb_arr_fl_sr){
				iShowBMP2(demon_cordX, demon_cordY, fb_arr[ind_fb1], 0);
			}
			else{
				iShowBMP2(demon_cordX + fb_cord_x, demon_cordY, fb_arr2[ind_fb2], 0);
			}
		}
		if (leg_p_fl){
			if (leg_p_fl_1){
				iShowBMP2(demon_cordX, demon_cordY + demon_jump_cord_x, leg_p[leg_p_ind0], 0);
			}
			else{
				iShowBMP2(demon_cordX + lg_cordx, demon_cordY + demon_jump_cord_x + 80, leg_p_b[leg_p_ind2], 0);
			}
		}
		if (thunder_fl){
			if (thunder_fl_1){
				iShowBMP2(demon_cordX, demon_cordY + demon_jump_cord_x, thunder_power[th_ind_1], 0);
			}
			else{
				iShowBMP2(demon_cordX + th_cordx, 0, thunder_power_sr[th_ind_2], 0);
			}
		}
		if (thunder_fl1){
			if (thunder_fl_11){
				iShowBMP2(demon_cordX, demon_cordY, thunder_power1[th_ind_11], 0);
			}
			else{
				iShowBMP2(demon_cordX + th_cordx_1, demon_cordY, thunder_power_sr1[th_ind_22], 0);
			}
		}
		if (blade_pl_fl){
			iShowBMP2(demon_cordX, demon_cordY + demon_jump_cord_x, blade_po[ind_blade_pl], 0);
		}
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
void music_play_game(){
	if (homepage){
		PlaySound("bci\\home.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	else{
		PlaySound("bci\\click_sound.wav", NULL, SND_ASYNC);
	}
}

void iMouse(int button, int state, int mx, int my)
{
	if (homepage == true && (mx >= 752 && mx <= 1122) && (my >= 644 && my <= 738)){
		homepage = false;
		musicon_home = false;
		music_play_game();
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/

void iKeyboard(unsigned char key)
{
	if (key == 'p '){
		standposs = true;
	}
	if (key == 'a'){
		if (!blade_pl_fl){
			blade_pl_fl = true;
			fl = false;
			standposs = false;
		}
	}
	if (key == 'd'){
		if (!thunder_fl1){
			thunder_fl1 = true;
			thunder_fl_11 = true;
			fl = false;
			standposs = false;
		}
	}
	if (key == 'e'){
		if (!thunder_fl){
			thunder_fl = true;
			thunder_fl_1 = true;
			fl = false;
			standposs = false;
		}
	}
	if (key == 'w')
	{
		if (!leg_p_fl){
			leg_p_fl = true;
			leg_p_fl_1 = true;
			fl = false;
			standposs = false;
		}
	}
	if (key == 's'){
		if (!fb_arr_fl){
			fb_arr_fl = true;
			fb_arr_fl_sr = true;
			fl = false;
			standposs = false;
		}
	}
	if (key == 'f'){
		if (!vanish_bp_fl){
			vanish_bp_fl = true;
			vanish_bp_fl_1 = true;
			fl = false;
			standposs = false;
		}
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
		back_ran = true;
		demon_cordX += 100;

		demon_ind++;
		if (demon_cordY + demon_cordX >= 1700)
			demon_cordX = 0;
		if (demon_ind >= 6)
			demon_ind = 0;

		standposs = false;

	}
	else if (key == GLUT_KEY_LEFT)
	{
		back_ran = true;
		demon_cordX -= 50;
		
		if (demon_cordX <= 0){
			demon_cordX = 0;
		}
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
	if (homepage == 0){
		cnt++;
	}
	if (cnt == 4){
		PlaySound("bci\\game.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	if (blade_pl_fl){
		standposs = false;
		fl = false;
		jumpup = false;
		ind_blade_pl++;
	}
	if (thunder_fl1){
		jumpup = false;
		if (thunder_fl_11){
			th_ind_11++;
		}
		else{
			th_cordx_1 += 150;
			th_ind_22++;
		}
	}
	if (thunder_fl){
		standposs = false;
		if (thunder_fl_1){
			th_ind_1++;
		}
		else{
			th_cordx += 30;
			th_ind_2++;
		}
	}
	if (leg_p_fl){
		standposs = false;
		jumpup = false;
		if (leg_p_fl_1){
			leg_p_ind0++;
		}
		else{
			lg_cordx += 120;
			leg_p_ind2++;
		}
	}
	if (fb_arr_fl){
		jumpup = false;
		if (fb_arr_fl_sr){
			ind_fb1++;
		}
		else{
			fb_cord_x += 200;
			ind_fb2++;
		}
	}
	if (vanish_bp_fl){
		jumpup = false;
		if (vanish_bp_fl_1){
			vanish_ind1++;
		}
		else{
			vanish_cord_x += 120;
			vanish_ind2++;
		}
	}
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
		jumpup = false;
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
		fl = true;
		standposs = true;
	}
	if (vanish_ind1 >= 8){
		vanish_ind1 = 0;
		vanish_bp_fl_1 = false;
	}
	if (vanish_ind2 >= 6){
		vanish_ind2 = 0;
		vanish_cord_x = 120;
		vanish_bp_fl = false;
		fl = true;
		standposs = true;
	}
	if (ind_fb1 >= 6){
		ind_fb1 = 0;
		fb_arr_fl_sr= false;
	}if (ind_fb2 >= 3){
		ind_fb2 = 0;
		fb_cord_x= 200;
		fb_arr_fl = false;
		fl = true;
		standposs = true;
	}
	if (leg_p_ind0>=5){
		leg_p_ind0 = 0;
		leg_p_fl_1 = false;
	}if (leg_p_ind2>=7){
		lg_cordx = 120;
		leg_p_fl = false;
		leg_p_ind2 = 0;
		fl = true;
		standposs = true;
	}
	if (th_ind_1 >= 4){
		th_ind_1 = 0;
		thunder_fl_1 = false;
	}if (th_ind_2 >= 3){
		th_ind_2 = 0;
		th_cordx = 30;
		thunder_fl = false;
		fl = true;
		standposs = true;
	}
	if (th_ind_11 >= 4){
		th_ind_11 = 0;
		thunder_fl_11 = false;
	}if (th_ind_22>=6){
		th_cordx_1 = 30;
		th_ind_22 = 0;
		thunder_fl1 = false;
		fl = true;
		standposs = true;
	}
	if (ind_blade_pl >= 13){
		ind_blade_pl = 0;
		blade_pl_fl = false;
		fl = true;
		standposs = true;
	}
}
int main()
{
	iSetTimer(200, change);
	iInitialize(1700, 800,"hills");
	a = iLoadImage("./bci/backgr1.jpg");
	b = iLoadImage("./bci/bg_lower.jpg");
	///updated see the documentations
	if (musicon_home){
		PlaySound("bci\\home.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	iStart();
	return 0;
}