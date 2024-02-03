#include<iostream>
#include<string.h>
#include "iGraphics.h"
#include "bitmap_loader.h"
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
int hbp_move=15;
int ene_3_count = 25;
bool die_enem = false;
int die_ind = 0;
int count_die_cnt = 0;

int player_life_ind = 0;
int game_ind = 0;
bool winner_show = false;
bool hiper_power1 = false;
bool hiper_power_2 = false;
int hbp_ind = 0;
int hbp_ball_ind = 0;
//-------------------------------------------------------Scorring part ---------------------------------------------------------------------------
bool play_ground = false;
char str1[40];
bool take_name = false;
int len=0;
bool high_score_page = false;
void showChar()
{
	iSetColor(255, 0, 0);
	iText(680,600, "Enter your name", GLUT_BITMAP_TIMES_ROMAN_24);
	iRectangle(660, 530, 220, 30);
	iText(670, 540, str1, GLUT_BITMAP_HELVETICA_18);

}
typedef struct Player Player;

struct Player{
	char name[30];
	int score = 0;
	Player()
	{
		;
	}
	Player(char *_name, int _score)
	{
		strcpy(name, _name);
		score = _score;
	}
};
typedef struct sorting
{
	char ch[30];
	int sc;
} sorts;

void sort_stru(sorting o1[], int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		for (int j = i + 1; j < cnt; j++)
		{
			if (o1[i].sc < o1[j].sc)
			{
				sorting temp = o1[i];
				o1[i] = o1[j];
				o1[j] = temp;
			}
		}
	}
}
Player o1;
void high_page_sorting(){
	FILE *fp = fopen("high_score.txt", "a");
	fprintf(fp, "%s %d\n", o1.name, o1.score);
	fclose(fp);
}
void showing_score_page(){
	int z;
	FILE *fp = fopen("high_score.txt", "r");
	char chs[30];
	int cnt = 0;
	while (fscanf(fp, "%s%d", &chs, &z) != EOF)
	{
		cnt++;
	}
	sorts o2[100];
	fclose(fp);
	fp = fopen("high_score.txt", "r");
	for (int i = 0; i < cnt; i++)
	{
		fscanf(fp, "%s%d", &chs, &z);
		strcpy(o2[i].ch, chs);
		o2[i].sc = z;
	}
	fclose(fp);
	fp = fopen("high_score.txt", "r");
	sort_stru(o2, cnt);
	int x=cnt;
	if (cnt>7){
		x = 7;
	}
	for (int i = 0; i <x; i++)
	{
		char name[2][30];
		fprintf(fp, "%s %d\n", o2[i].ch, o2[i].sc);
		sprintf(name[0], "%s",o2[i].ch );
		sprintf(name[1], "%d", o2[i].sc);
		iSetColor(255,255,0);
		iText(700, 550 - 50 * i, name[0], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(900, 550 - 50 * i, name[1], GLUT_BITMAP_TIMES_ROMAN_24);
	}
	fclose(fp);
}
char point[1000];
void showing_score(){
	
	iShowBMP2(975, 720,"bci\\scoring.bmp",0);
	iShowBMP2(1000, 745, "bci\\s1.bmp", 0);
	iSetColor(0,0,0);
	iText(1125, 755, ":", GLUT_BITMAP_TIMES_ROMAN_24);
	sprintf_s(point, "%d", o1.score);
	iText(1142, 755, point, GLUT_BITMAP_TIMES_ROMAN_24);
}
void takeinput(unsigned char key){
	if (key == 'p'){
		exit(0);
	}
	if (key == '\r'){
		strcpy(o1.name, str1);
		high_page_sorting();
		high_score_page = true;
	}
	else if (key == '\b'){
		if (len <= 0){
			len = 0;
		}
		else
			len--;
		str1[len] = '\0';
	}
	else{
		str1[len] = key;
		len++;
		if (len > 15){
			len = 15;
		}str1[len] = '\0';
	}
}
//-------------------------------------------------------Scoring End------------------------------------------------------------------------------



char hbp_sho[8][30] = { "lgp\\hbp1.bmp", "lgp\\hbp2.bmp", "lgp\\hbp3.bmp", "lgp\\hbp4.bmp", "lgp\\hbp5.bmp", "lgp\\hbp6.bmp", "lgp\\hbp7.bmp", "lgp\\hbp8.bmp"};
char hbp_sho_ball[4][30] = { "lgp\\hbp9.bmp", "lgp\\hbp10.bmp", "lgp\\hbp11.bmp", "lgp\\hbp12.bmp"};
char main_die_showing[8][30] = { "bci\\main_die1.bmp", "bci\\main_die2.bmp", "bci\\main_die3.bmp", "bci\\main_die4.bmp", "bci\\main_die5.bmp", "bci\\main_die6.bmp", "bci\\main_die7.bmp", "bci\\main_die8.bmp"};
char die_showing[10][30] = { "bci\\ene_die1.bmp", "bci\\ene_die2.bmp", "bci\\ene_die3.bmp", "bci\\ene_die4.bmp", "bci\\ene_die5.bmp", "bci\\ene_die6.bmp", "bci\\ene_die7.bmp", "bci\\ene_die8.bmp", "bci\\ene_die9.bmp", "bci\\ene_die10.bmp"};
char lifing[28][30] = { "bci\\life1.bmp", "bci\\life2.bmp", "bci\\life3.bmp", "bci\\life4.bmp", "bci\\life5.bmp", "bci\\life6.bmp", "bci\\life7.bmp", "bci\\life8.bmp", "bci\\life9.bmp", "bci\\life10.bmp", "bci\\life11.bmp", "bci\\life12.bmp", "bci\\life13.bmp", "bci\\life14.bmp", "bci\\life15.bmp", "bci\\life16.bmp", "bci\\life17.bmp", "bci\\life18.bmp", "bci\\life19.bmp", "bci\\life20.bmp", "bci\\life21.bmp", "bci\\life22.bmp", "bci\\life23.bmp", "bci\\life24.bmp", "bci\\life25.bmp", "bci\\life26.bmp", "bci\\life27.bmp", "bci\\life28.bmp"};
char demon[6][100] = { "run\\run1.bmp", "run\\run2.bmp", "run\\run3.bmp", "run\\run4.bmp", "run\\run5.bmp", "run\\run6.bmp"};

char demon_stand[15] = "run\\stand.bmp";

char jump_up[3][100] = {"jump\\jump_up1.bmp", "jump\\jump_up2.bmp", "jump\\jump_up3.bmp" };
char jump_down[3][100] = {"jump\\jump_down1.bmp", "jump\\jump_down2.bmp", "jump\\jump_down3.bmp" };
int demon_cordX = 0;
int demon_cordY = 0;
int demon_ind = 0;
int fir_ene_cnt= 0;
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

bool show_enemy_flag = false;

bool show_third_flag = false;

bool show_main_flag = false;

int show_enemy_cnt = 0;
int show_thire_cnt = 0;
int show_main_cnt = 0;
bool backer = true, back_ran = false;

float x_cord_b= 0.0,x_cord_lo_b=0.0;

int cnt1 = 0;
int cnt2 = 0;
int cnt3 = 0;
int cnt4 = 0;
int cnt5 = 0;
bool level_st_2 = false;
bool level_st_1 = false;
bool instruction_page = false;
bool homepage =true;
bool musicon_home = true;
bool music_game = false;
int cnt = 0;

// ----------------------------------------------------------------------------th_ene_3-------------------------------------------------------------------------
typedef struct ene_third ene_third;
struct ene_third{
	int x = 1390, y, ind;
	bool fl = true;
};
ene_third obj5;
char ene_third_sh[5][30] = { "bci\\th_ene_1.bmp", "bci\\th_ene_2.bmp", "bci\\th_ene_3.bmp", "bci\\th_ene_4.bmp","bci\\th_ene_5.bmp" };
typedef struct ene_third_balls{
	int x;
	int y;
	bool fl;
}ene_third_balls;
ene_third_balls obj6;
int enemy_ball_3 = 0;
char ch_ene_dr[1][30] = { "bci\\th_ene_6.bmp" };
//-------------------th_en_end-------------------
struct enemy_1{
	int enemy_cord_x = 0;
	int enemy_cord_y = 0;
	int enemy_ind = 0;
	bool enemy_show;
};

enemy_1 ene[3];
char enem[4][30] = { "bci\\fir1.bmp", "bci\\fir2.bmp", "bci\\fir3.bmp", "bci\\fir4.bmp"};

bool boom = true;

//***********************************************************************collition part *************************************************************************************
int x_sh, y_sh;
void enemy_1_show(){
	for (int i = 0; i < 3; i++){
		if (ene[i].enemy_show == false){
			iShowBMP2(x_sh, y_sh, "bci\\boom1.bmp", 0);
			x_sh -= 1.5;
			continue;
		}
		int cn = demon_jump_cord_x + 270;
		if (ene[i].enemy_show && blade_pl_fl == true && (((ene[i].enemy_cord_x - demon_cordX) <= 100 && (ene[i].enemy_cord_x - demon_cordX) >= -150) || (demon_cordX - ene[i].enemy_cord_x) >= -200) && (ene[i].enemy_cord_y >= 0 && ene[i].enemy_cord_y <= 350)){
			show_enemy_cnt++;
			o1.score += 4;
			x_sh = ene[i].enemy_cord_x;
			y_sh = ene[i].enemy_cord_y;
			ene[i].enemy_show = false;
		}
		else if (ene[i].enemy_show && fb_arr_fl_sr == false && fb_arr_fl == true && ((ene[i].enemy_cord_x - fb_cord_x - demon_cordX - 150) <= 30 && (ene[i].enemy_cord_x - fb_cord_x) >= -200 || (fb_cord_x + demon_cordX - ene[i].enemy_cord_x) >= -200) && (ene[i].enemy_cord_y >= 0 && ene[i].enemy_cord_y <= 350)){
			show_enemy_cnt++;
			o1.score += 4;
			x_sh = ene[i].enemy_cord_x;
			y_sh = ene[i].enemy_cord_y;
			ene[i].enemy_show = false;
		}
		else if (ene[i].enemy_show && leg_p_fl_1 == false && leg_p_fl == true && ((ene[i].enemy_cord_x - lg_cordx - demon_cordX - 150) <= 30 && (ene[i].enemy_cord_x - lg_cordx) >= -200 || (lg_cordx + demon_cordX - ene[i].enemy_cord_x) >= -200) && (ene[i].enemy_cord_y >= 0 && ene[i].enemy_cord_y <= 450)){
			show_enemy_cnt++;
			o1.score += 4;
			x_sh = ene[i].enemy_cord_x;
			y_sh = ene[i].enemy_cord_y;
			ene[i].enemy_show = false;
		}
		else if (ene[i].enemy_show && thunder_fl_11 == false && thunder_fl1 == true && ((ene[i].enemy_cord_x - th_cordx_1 - demon_cordX - 150) <= 30 && (ene[i].enemy_cord_x - th_cordx_1) >= -200 || (th_cordx_1 + demon_cordX - ene[i].enemy_cord_x) >= -200) && (ene[i].enemy_cord_y >= 0 && ene[i].enemy_cord_y <= 800)){
			show_enemy_cnt++;
			o1.score += 4;
			x_sh = ene[i].enemy_cord_x;
			y_sh = ene[i].enemy_cord_y;
			ene[i].enemy_show = false;
		}
		else if (ene[i].enemy_show && power_bb_first == false && power_bb == true && ((ene[i].enemy_cord_x - ind_cord_x-demon_cordX-200) <= 30 && (ene[i].enemy_cord_x - ind_cord_x-demon_cordX) >= -200 || (ind_cord_x+demon_cordX - ene[i].enemy_cord_x) >= -200) && (ene[i].enemy_cord_y >= 0 && ene[i].enemy_cord_y <= 600)){
			o1.score += 4;
			show_enemy_cnt++;
			x_sh = ene[i].enemy_cord_x;
			y_sh = ene[i].enemy_cord_y;
			ene[i].enemy_show = false;
		}
		else if (ene[i].enemy_show && vanish_bp_fl_1 == false && vanish_bp_fl == true && ((ene[i].enemy_cord_x - vanish_cord_x - demon_cordX - 150) <= 30 && (ene[i].enemy_cord_x - vanish_cord_x) >= -200 || (vanish_cord_x + demon_cordX - ene[i].enemy_cord_x) >= -100) && (ene[i].enemy_cord_y >= 0 && ene[i].enemy_cord_y <= 500)){
			show_enemy_cnt++;
			o1.score += 4;
			x_sh = ene[i].enemy_cord_x;
			y_sh = ene[i].enemy_cord_y;
			ene[i].enemy_show = false;
		}
		else if (ene[i].enemy_show && thunder_fl_1 == false && thunder_fl == true && ((((ene[i].enemy_cord_x - th_cordx - demon_cordX - 150)) <= 900 || (th_cordx - ene[i].enemy_cord_x) >= 900)) && (ene[i].enemy_cord_y >= 0 && ene[i].enemy_cord_y <= 500)){
			show_enemy_cnt++;
			o1.score += 4;
			x_sh = ene[i].enemy_cord_x;
			y_sh = ene[i].enemy_cord_y;
			ene[i].enemy_show = false;
		}
		else if (ene[i].enemy_show && jumpup == false && jumpdown == false && sur_sock_fl==true && (((ene[i].enemy_cord_x - dem_sur_x - demon_cordX - 150) <= 30 && (ene[i].enemy_cord_x - dem_sur_x) >= -250) || (dem_sur_x + demon_cordX - ene[i].enemy_cord_x) >= 10) && (ene[i].enemy_cord_y >= 0 && ene[i].enemy_cord_y <= 280)){
			show_enemy_cnt++; 
			o1.score += 4;
			x_sh = ene[i].enemy_cord_x;
			y_sh = ene[i].enemy_cord_y;
			ene[i].enemy_show = false;
		}
		else if (ene[i].enemy_show && jumpup == false && jumpdown == false && ((ene[i].enemy_cord_x - demon_cordX) <= 30 && (ene[i].enemy_cord_x - demon_cordX) >= -150) && (ene[i].enemy_cord_y>0 && ene[i].enemy_cord_y < 270)){
			fir_ene_cnt++;
			mciSendString("play collition_with_power.wav", NULL, 0, NULL);
			x_sh = ene[i].enemy_cord_x;
			y_sh = ene[i].enemy_cord_y;
			ene[i].enemy_show = false;
		}
		else if (ene[i].enemy_show && (over_jump1 || over_down1 || jumpdown || jumpup) && ((ene[i].enemy_cord_x - demon_cordX) <= 30 && (ene[i].enemy_cord_x - demon_cordX) >= -150) && (ene[i].enemy_cord_y>demon_jump_cord_x && ene[i].enemy_cord_y <cn)){
			mciSendString("play collition_with_power.wav", NULL, 0, NULL);
			if (jumpup || jumpdown)
				fir_ene_cnt++;
			x_sh = ene[i].enemy_cord_x;
			y_sh = ene[i].enemy_cord_y;
			
			ene[i].enemy_show = false;
		}
		else if (ene[i].enemy_show && dem_ind == 3 && ((((ene[i].enemy_cord_x - pow_x-demon_cordX-150) <= 30 && (ene[i].enemy_cord_x - pow_x) >= -300) || (pow_x + demon_cordX - ene[i].enemy_cord_x) >= -70)) && (ene[i].enemy_cord_y >= 0 && ene[i].enemy_cord_y <= 520))
		{
			o1.score += 4;
			show_enemy_cnt++;
			x_sh = ene[i].enemy_cord_x;
			y_sh = ene[i].enemy_cord_y;

			ene[i].enemy_show = false;
		}
		else if (ene[i].enemy_show && hiper_power1 && hiper_power_2 == false && ((((ene[i].enemy_cord_x - hbp_move - demon_cordX - 500) <= 30 && (ene[i].enemy_cord_x - hbp_move - demon_cordX) >= -500) || (hbp_move +demon_cordX+300 - ene[i].enemy_cord_x) >= -70)) && (ene[i].enemy_cord_y >= 0 && ene[i].enemy_cord_y <= 350))
		{
			o1.score += 4;
			show_enemy_cnt++;
			x_sh = ene[i].enemy_cord_x;
			y_sh = ene[i].enemy_cord_y;

			ene[i].enemy_show = false;
		}
		else if (ene[i].enemy_show && dem_pow1 && (((ene[i].enemy_cord_x - pow_x - demon_cordX - 110) <= 30 && (ene[i].enemy_cord_x - pow_x) >= -250) || (demon_cordX + pow_x - ene[i].enemy_cord_x) >= -70) && (ene[i].enemy_cord_y >= 0 && ene[i].enemy_cord_y <= 400))
		{
			o1.score += 4;
			show_enemy_cnt++;
			x_sh = ene[i].enemy_cord_x;
			y_sh = ene[i].enemy_cord_y;

			ene[i].enemy_show = false;
		}
		if (ene[i].enemy_show)
			iShowBMP2(ene[i].enemy_cord_x, ene[i].enemy_cord_y, enem[ene[i].enemy_ind], 0);
		}
}

//*********************************************************************End collitin part *************************************************************************************

char run_back[6][30] = { "bci\\rb1.bmp", "bci\\rb2.bmp", "bci\\rb3.bmp", "bci\\rb4.bmp", "bci\\rb5.bmp", "bci\\rb6.bmp" };
bool rum_back_fl = false;
int run_back_ind = 0;
bool run_forward = false;

//------------------------For main enemy--------------
typedef struct main_enemy{
	int x = 1290;
	int y;
	int ind;
	bool fl=true;
}main_enemy;
char main_en_mv[5][30] = { "bci\\main_en1.bmp", "bci\\main_en2.bmp", "bci\\main_en3.bmp", "bci\\main_en4.bmp", "bci\\main_en5.bmp"};
main_enemy obj3[1];
typedef struct main_ball_fi{
	int x;
	int y;
	int ind;
	bool fl = false;
}main_ball_fi;
main_ball_fi obj4[1];
char main_en_ball[5][30] ={ "bci\\main_f1.bmp","bci\\main_f2.bmp", "bci\\main_f3.bmp", "bci\\main_f4.bmp", "bci\\main_f5.bmp" };
int enemy_ball_2_m = 0;
//-------------------End Main enemy------------------

typedef struct enemey_2{
	int x=1390;
	int y;
	int ind;
	bool fl = true;
}enemy_2;
char ene_2[4][30] = { "bci\\emy1.bmp", "bci\\emy2.bmp", "bci\\emy3.bmp", "bci\\emy4.bmp"};
enemey_2 obj1[1];

typedef struct enemy_ball enemy_ball;
struct enemy_ball{
	int x;
	int y;
	int ind;
	bool bl = false;
};
int enemy_ball_2 = 0;
enemy_ball obj2[1];

char ene_fir_ball_2[3][30] = { "bci\\emy_ball_1.bmp", "bci\\emy_ball_2.bmp","bci\\emy_ball_3.bmp" };

//-------------------------------------------------------enemy 2nd collition -------------------------------------------------
char enemy_life_second[6][30] = { "bci\\first_ene_life1.bmp", "bci\\first_ene_life2.bmp", "bci\\first_ene_life3.bmp", "bci\\first_ene_life4.bmp", "bci\\first_ene_life5.bmp", "bci\\first_ene_life6.bmp"};
void show_enemy(){
	if (obj1[0].fl == true){
		iShowBMP2(obj1[0].x, obj1[0].y+190, enemy_life_second[show_thire_cnt], 0);
		iShowBMP2(obj1[0].x, obj1[0].y, ene_2[obj1[0].ind], 0);
		if (dem_pow1 && (obj1[0].x - pow_x - demon_cordX - 150 <= 30 && (obj1[0].x - pow_x - demon_cordX >= -200) || (pow_x + demon_cordX - obj1[0].x) >= 150) && (obj1[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj1[0].y <= demon_cordY + demon_jump_cord_x + 500))
		{
			o1.score += 10;
			show_thire_cnt++;
			obj1[0].fl = false;
			obj1[0].ind = 0;
        
		}
		else if (dem_pow1 && (obj1[0].x - pow_x - demon_cordX - 150 <= 30 && (obj1[0].x - pow_x - demon_cordX >= -200) || (pow_x + demon_cordX - obj1[0].x) >= 150) && (obj1[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj1[0].y <= demon_cordY + demon_jump_cord_x + 500))
		{
			o1.score += 10;
			show_thire_cnt++;
			obj1[0].fl = false;
			obj1[0].ind = 0;
        
		}
		else if (sur_sock_fl && ((((obj1[0].x - dem_sur_x - demon_cordX - 150) <= 30 && (obj1[0].x - dem_sur_x - demon_cordX) >= -100) || (dem_sur_x + demon_cordX - obj1[0].x) >= 100)) && (obj1[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj1[0].y <= demon_cordY + demon_jump_cord_x + 400)){
			show_thire_cnt++; 
			o1.score += 10;
			obj1[0].fl = false;
			obj1[0].ind = 0;

		}
		else if (sur_sock_fl && ((((obj1[0].x - dem_sur_x - demon_cordX - 150) <= 30 && (obj1[0].x - dem_sur_x - demon_cordX) >= -100) || (dem_sur_x + demon_cordX - obj1[0].x) >= 100)) && (obj1[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj1[0].y <= demon_cordY + demon_jump_cord_x + 400)){
			show_thire_cnt++; 
			o1.score += 10;
			obj1[0].fl = false;
			obj1[0].ind = 0;
        
		}
        
		else if ((over_jump1 || over_down1) && (obj1[0].x - demon_cordX - 150 <= 50 && obj1[0].x - demon_cordX >= 20 || demon_cordX - obj1[0].x >= 30) && (obj1[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj1[0].y <= demon_cordY + demon_jump_cord_x + 300)){
			show_thire_cnt++; 
			o1.score += 10;
			obj1[0].fl = false;
			obj1[0].ind = 0;

		}
		else if (thunder_fl_1 == false && thunder_fl == true && ((((obj1[0].x - th_cordx-demon_cordX)) <= 930 || (th_cordx+demon_cordX - obj1[0].x) >=0)) && (obj1[0].y >= 0 && obj1[0].y <= 500)){
			show_thire_cnt++;
			o1.score += 10;
			obj1[0].fl = false;
			obj1[0].ind = 0;

		}
		else if (vanish_bp_fl_1 == false && vanish_bp_fl == true && ((obj1[0].x - vanish_cord_x - demon_cordX - 150) <= 30 && (obj1[0].x - vanish_cord_x - demon_cordX) >= -100 || (vanish_cord_x + demon_cordX - obj1[0].x) >= 0) && (obj1[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj1[0].y <= demon_cordY + demon_jump_cord_x + 500)){
			show_thire_cnt++;
			o1.score += 10;
			obj1[0].fl = false;
			obj1[0].ind = 0;

		}
		else if (power_bb == true && power_bb_first == false && (((obj1[0].x - ind_cord_x - demon_cordX - 300) <= 30 && (obj1[0].x - ind_cord_x - demon_cordX) >= -500 || (ind_cord_x + demon_cordX - obj1[0].x) >= 0)) && (obj1[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj1[0].y <= demon_cordY + demon_jump_cord_x + 650)){
			show_thire_cnt++;
			o1.score += 10;
			obj1[0].fl = false;
			obj1[0].ind = 0;

		}
		else if (thunder_fl_11 == false && thunder_fl1 == true && ((obj1[0].x - th_cordx_1 - demon_cordX - 200) <= 30 && (obj1[0].x - th_cordx_1 - demon_cordX) >= -200 || (th_cordx_1 + demon_cordX - obj1[0].x) >= 0) && (obj1[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj1[0].y <= demon_cordY + demon_jump_cord_x + 650)){
			show_thire_cnt++;
			o1.score += 10;
			obj1[0].fl = false;
			obj1[0].ind = 0;

		}
		else if (leg_p_fl_1 == false && leg_p_fl == true && ((obj1[0].x - lg_cordx - demon_cordX - 150) <= 30 && (obj1[0].x - lg_cordx - demon_cordX) >= -200 || (lg_cordx + demon_cordX + 100 - obj1[0].x) >= 0) && (obj1[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj1[0].y <= demon_cordY + demon_jump_cord_x + 470)){
			show_thire_cnt++;
			o1.score += 10;
			obj1[0].fl = false;
			obj1[0].ind = 0;

		}
		else if (fb_arr_fl_sr == false && fb_arr_fl == true && ((obj1[0].x - fb_cord_x - demon_cordX - 150) <= 30 && (obj1[0].x - fb_cord_x - demon_cordX) >= -200 || (fb_cord_x + demon_cordX - obj1[0].x) >= 0) && (obj1[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj1[0].y <= demon_cordY + demon_jump_cord_x + 350)){
			show_thire_cnt++;
			o1.score += 10;
			obj1[0].fl = false;
			obj1[0].ind = 0;

		}
		else if (blade_pl_fl == true && (((obj1[0].x - demon_cordX - 100) <= 30 && (obj1[0].x - demon_cordX) >= -150) || (demon_cordX - obj1[0].x) >= 0) && (obj1[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj1[0].y <= demon_cordY + demon_jump_cord_x + 390)){
			show_thire_cnt++;
			o1.score += 10;
			obj1[0].fl = false;
			obj1[0].ind = 0;
		}
		else if (hiper_power_2 == false && hiper_power1 == true && ((obj1[0].x - hbp_move - demon_cordX - 500) <= 30 && (obj1[0].x - hbp_move - demon_cordX) >= -400 || (hbp_move + demon_cordX - obj1[0].x) >= 0) && (obj1[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj1[0].y <= demon_cordY + demon_jump_cord_x + 350)){
			show_thire_cnt++;
			o1.score += 10;
			obj1[0].fl = false;
			obj1[0].ind = 0;

		}
	}
	else if (obj2[0].bl){
		obj2[0].x = obj1[0].x;
		obj2[0].y = obj1[0].y;
		enemy_ball_2 -= 22;
		obj2[0].x += enemy_ball_2;
		iShowBMP2(obj2[0].x, obj2[0].y, ene_fir_ball_2[obj2[0].ind], 0);
		if ((obj2[0].x - demon_cordX -30<= 30 && obj2[0].x - demon_cordX >=-100) && (obj2[0].y >= demon_cordY + demon_jump_cord_x-30 && obj2[0].y <= demon_cordY + demon_jump_cord_x + 250)){
			game_ind++;
			obj2[0].bl = false;
		}
		else if (dem_pow1 && (obj2[0].x - pow_x - demon_cordX - 150 <= 30 && (obj2[0].x - pow_x - demon_cordX >= -200) || (pow_x + demon_cordX - obj2[0].x) >= 150) && (obj2[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj2[0].y <= demon_cordY + demon_jump_cord_x + 500))
		{
			o1.score += 4;
			obj2[0].bl = false;
		}
		else if (dem_pow1 && (obj2[0].x - pow_x - demon_cordX - 150 <= 30 && (obj2[0].x - pow_x - demon_cordX >= -200) || (pow_x + demon_cordX - obj2[0].x) >= 150) && (obj2[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj2[0].y <= demon_cordY + demon_jump_cord_x + 500))
		{
			o1.score += 4;
			obj2[0].bl = false;
		}
		else if (sur_sock_fl && ((((obj2[0].x - dem_sur_x - demon_cordX - 150) <= 30 && (obj2[0].x - dem_sur_x - demon_cordX) >= -100) || (dem_sur_x + demon_cordX - obj2[0].x) >= 100)) && (obj2[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj2[0].y <= demon_cordY + demon_jump_cord_x + 400)){
			obj2[0].bl = false;
			o1.score += 4;
		}
		else if (sur_sock_fl && ((((obj2[0].x - dem_sur_x - demon_cordX - 150) <= 30 && (obj2[0].x - dem_sur_x - demon_cordX) >= -100) || (dem_sur_x + demon_cordX - obj2[0].x) >= 100)) && (obj2[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj2[0].y <= demon_cordY + demon_jump_cord_x + 400)){
			obj2[0].bl = false;
			o1.score += 4;
		}
		
		else if ((over_jump1 || over_down1) && (obj2[0].x - demon_cordX - 150 <= 50 && obj2[0].x - demon_cordX >= 20 || demon_cordX - obj2[0].x >= 30) && (obj2[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj2[0].y <= demon_cordY + demon_jump_cord_x + 300)){
			obj2[0].bl = false;
			o1.score += 4;
		}
		else if (thunder_fl_1 == false && thunder_fl == true && ((((obj2[0].x - th_cordx-demon_cordX)) <= 900 || (th_cordx - obj2[0].x) >=- 900)) && (obj2[0].y >= 0 && obj2[0].y <= 500)){
			obj2[0].bl = false;
			o1.score += 4;
		}
		else if (vanish_bp_fl_1 == false && vanish_bp_fl == true && ((obj2[0].x - vanish_cord_x - demon_cordX - 150) <= 30 && (obj2[0].x - vanish_cord_x - demon_cordX) >= -100 || (vanish_cord_x + demon_cordX - obj2[0].x) >= 0) && (obj2[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj2[0].y <= demon_cordY + demon_jump_cord_x + 500)){
			obj2[0].bl = false;
			o1.score += 4;
		}
		else if (power_bb==true && power_bb_first==false && (((obj2[0].x - ind_cord_x - demon_cordX-300) <= 30 && (obj2[0].x - ind_cord_x - demon_cordX) >= -500 || (ind_cord_x + demon_cordX - obj2[0].x) >= 0)) && (obj2[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj2[0].y <= demon_cordY + demon_jump_cord_x + 650)){
			game_ind++;
			obj2[0].bl = false;
			o1.score += 4;
		}
		else if (thunder_fl_11 == false && thunder_fl1 == true && ((obj2[0].x - th_cordx_1-demon_cordX-200) <= 30 && (obj2[0].x - th_cordx_1-demon_cordX) >= -200 || (th_cordx_1 + demon_cordX - obj2[0].x) >=0) && (obj2[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj2[0].y <= demon_cordY + demon_jump_cord_x + 650)){
			obj2[0].bl = false;
			o1.score += 4;
		}
		else if (leg_p_fl_1 == false && leg_p_fl == true && ((obj2[0].x - lg_cordx - demon_cordX - 150) <= 30 && (obj2[0].x - lg_cordx - demon_cordX) >= -200 || (lg_cordx + demon_cordX +100- obj2[0].x) >=0) && (obj2[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj2[0].y <= demon_cordY + demon_jump_cord_x +470)){
			obj2[0].bl = false;
			o1.score += 4;
		}
		else if (fb_arr_fl_sr == false && fb_arr_fl == true && ((obj2[0].x - fb_cord_x-demon_cordX-150) <= 30 && (obj2[0].x - fb_cord_x-demon_cordX) >= -200 || (fb_cord_x + demon_cordX - obj2[0].x) >= 0) && (obj2[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj2[0].y <= demon_cordY + demon_jump_cord_x + 350)){
			obj2[0].bl = false;
			o1.score += 4;
		}
		else if (blade_pl_fl == true && (((obj2[0].x - demon_cordX - 100) <= 30 && (obj2[0].x - demon_cordX) >= -150) || (demon_cordX - obj2[0].x) >= 0) && (obj2[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj2[0].y <= demon_cordY + demon_jump_cord_x + 390)){
			obj2[0].bl = false;
			o1.score += 4;
		}
		else if (hiper_power_2 == false && hiper_power1 == true && ((obj2[0].x - hbp_move - demon_cordX - 500) <= 30 && (obj2[0].x - hbp_move - demon_cordX) >= -400 || (hbp_move + demon_cordX - obj2[0].x) >= 0) && (obj2[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj2[0].y <= demon_cordY + demon_jump_cord_x + 350)){
			obj2[0].bl = false;
			o1.score += 4;
		}
		}
}

//----------------------------------------------------end ene2 end collition part--------------------------------


//---------------------------------------------------Start of Mani enemy collition -------------------------------------
char main_life_ene[9][30] = { "lgp\\main1.bmp", "lgp\\main2.bmp", "lgp\\main3.bmp", "lgp\\main4.bmp", "lgp\\main5.bmp", "lgp\\main6.bmp", "lgp\\main7.bmp", "lgp\\main8.bmp", "lgp\\main9.bmp"};
int main_life_ene_cnt = 0;
void show_main_en(){
	if (obj3[0].fl == true){
		if (main_life_ene_cnt<=8)
		iShowBMP2(obj3[0].x, obj3[0].y+398, main_life_ene[main_life_ene_cnt], 0);
		iShowBMP2(obj3[0].x, obj3[0].y, main_en_mv[obj3[0].ind], 0);

		if (dem_pow1 && (obj3[0].x - pow_x - demon_cordX - 150 <= 30 && (obj3[0].x - pow_x - demon_cordX >= -200) || (pow_x + demon_cordX - obj3[0].x) >= 150) && (obj3[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj3[0].y <= demon_cordY + demon_jump_cord_x + 500))
		{
			o1.score += 30;
			main_life_ene_cnt++;
			obj3[0].fl = false;
			obj3[0].ind = 0;

		}
		
		else if (sur_sock_fl && ((((obj3[0].x - dem_sur_x - demon_cordX - 150) <= 30 && (obj3[0].x - dem_sur_x - demon_cordX) >= -100) || (dem_sur_x + demon_cordX - obj3[0].x) >= 100)) && (obj3[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj3[0].y <= demon_cordY + demon_jump_cord_x + 400)){
			main_life_ene_cnt++;
			o1.score += 30;
			obj3[0].fl = false;
			obj3[0].ind = 0;

		}
		else if (sur_sock_fl && ((((obj3[0].x - dem_sur_x - demon_cordX - 150) <= 30 && (obj3[0].x - dem_sur_x - demon_cordX) >= -100) || (dem_sur_x + demon_cordX - obj3[0].x) >= 100)) && (obj3[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj3[0].y <= demon_cordY + demon_jump_cord_x + 400)){
			main_life_ene_cnt++;
			o1.score += 30;
			obj3[0].fl = false;
			obj3[0].ind = 0;

		}

		else if ((over_jump1 || over_down1) && (obj3[0].x - demon_cordX - 150 <= 50 && obj3[0].x - demon_cordX >= 20 || demon_cordX - obj3[0].x >= 30) && (obj3[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj3[0].y <= demon_cordY + demon_jump_cord_x + 300)){
			main_life_ene_cnt++;
			o1.score += 30;
			obj3[0].fl = false;
			obj3[0].ind = 0;

		}
		else if (thunder_fl_1 == false && thunder_fl == true && ((((obj3[0].x - th_cordx-demon_cordX)) <= 900 || (th_cordx+demon_cordX - obj3[0].x) >= -900)) && (obj3[0].y >= 0 && obj3[0].y <= 500)){
			main_life_ene_cnt++;
			o1.score += 30;
			obj3[0].fl = false;
			obj3[0].ind = 0;

		}
		else if (vanish_bp_fl_1 == false && vanish_bp_fl == true && ((obj3[0].x - vanish_cord_x - demon_cordX - 150) <= 30 && (obj3[0].x - vanish_cord_x - demon_cordX) >= -100 || (vanish_cord_x + demon_cordX - obj3[0].x) >= 0) && (obj3[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj3[0].y <= demon_cordY + demon_jump_cord_x + 500)){
			main_life_ene_cnt++;
			o1.score += 30;
			obj3[0].fl = false;
			obj3[0].ind = 0;

		}
		else if (power_bb == true && power_bb_first == false && (((obj3[0].x - ind_cord_x - demon_cordX - 300) <= 30 && (obj3[0].x - ind_cord_x - demon_cordX) >= -500 || (ind_cord_x + demon_cordX - obj3[0].x) >= 0)) && (obj3[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj3[0].y <= demon_cordY + demon_jump_cord_x + 650)){
			main_life_ene_cnt++;
			o1.score += 30;
			obj3[0].fl = false;
			obj3[0].ind = 0;

		}
		else if (thunder_fl_11 == false && thunder_fl1 == true && ((obj3[0].x - th_cordx_1 - demon_cordX - 200) <= 30 && (obj3[0].x - th_cordx_1 - demon_cordX) >= -200 || (th_cordx_1 + demon_cordX - obj3[0].x) >= 0) && (obj3[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj3[0].y <= demon_cordY + demon_jump_cord_x + 650)){
			main_life_ene_cnt++;
			o1.score += 30;
			obj3[0].fl = false;
			obj3[0].ind = 0;

		}
		else if (leg_p_fl_1 == false && leg_p_fl == true && ((obj3[0].x - lg_cordx - demon_cordX - 150) <= 30 && (obj3[0].x - lg_cordx - demon_cordX) >= -200 || (lg_cordx + demon_cordX + 100 - obj3[0].x) >= 0) && (obj3[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj3[0].y <= demon_cordY + demon_jump_cord_x + 470)){
			main_life_ene_cnt++;
			o1.score += 30;
			obj3[0].fl = false;
			obj3[0].ind = 0;

		}
		else if (fb_arr_fl_sr == false && fb_arr_fl == true && ((obj3[0].x - fb_cord_x - demon_cordX - 150) <= 30 && (obj3[0].x - fb_cord_x - demon_cordX) >= -200 || (fb_cord_x + demon_cordX - obj3[0].x) >= 0) && (obj3[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj3[0].y <= demon_cordY + demon_jump_cord_x + 350)){
			main_life_ene_cnt++;
			o1.score += 30;
			obj3[0].fl = false;
			obj3[0].ind = 0;

		}
		else if (blade_pl_fl == true && (((obj3[0].x - demon_cordX - 100) <= 30 && (obj3[0].x - demon_cordX) >= -150) || (demon_cordX - obj3[0].x) >= 0) && (obj3[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj3[0].y <= demon_cordY + demon_jump_cord_x + 390)){
			main_life_ene_cnt++;
				o1.score += 30;;
			obj3[0].fl = false;
			obj3[0].ind = 0;

		}
		else if (hiper_power_2 == false && hiper_power1 == true && ((obj3[0].x - hbp_move - demon_cordX - 500) <= 30 && (obj3[0].x - hbp_move - demon_cordX) >= -400 || (hbp_move + demon_cordX - obj3[0].x) >= 0) && (obj3[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj3[0].y <= demon_cordY + demon_jump_cord_x + 350)){
			main_life_ene_cnt++;
			o1.score += 30;
			obj3[0].fl = false;
			obj3[0].ind = 0;

		}

	}
	else if (obj4[0].fl){
		obj4[0].x = obj3[0].x;
		obj4[0].y = obj3[0].y;
		enemy_ball_2_m -= 22;
		obj4[0].x += enemy_ball_2_m;
		iShowBMP2(obj4[0].x , obj4[0].y, main_en_ball[obj4[0].ind], 0);
		if ((obj4[0].x - demon_cordX-30 <= 30 && obj4[0].x - demon_cordX >=-100) && (obj4[0].y >= demon_cordY + demon_jump_cord_x-30 && obj4[0].y <= demon_cordY + demon_jump_cord_x + 250)){
			game_ind += 3;
			obj4[0].fl = false;
		}
		else if ( dem_pow1 &&(obj4[0].x - pow_x-demon_cordX -150<= 30 && (obj4[0].x - pow_x-demon_cordX >= -200) || (pow_x+demon_cordX-obj4[0].x)>=150 ) && (obj4[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj4[0].y <= demon_cordY + demon_jump_cord_x + 500))
		{
			o1.score += 4;
			obj4[0].fl = false;
		}
		else if (dem_pow1 && (obj4[0].x - pow_x - demon_cordX -150<= 30 && (obj4[0].x - pow_x - demon_cordX >= -200) || (pow_x + demon_cordX - obj4[0].x) >= 150) && (obj4[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj4[0].y <= demon_cordY + demon_jump_cord_x + 500))
		{
			o1.score += 4;
			obj4[0].fl = false;
		}
		else if (sur_sock_fl && ((((obj4[0].x - dem_sur_x - demon_cordX-150) <= 30 && (obj4[0].x - dem_sur_x - demon_cordX) >= -100) || (dem_sur_x + demon_cordX - obj4[0].x) >= 100)) && (obj4[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj4[0].y <= demon_cordY + demon_jump_cord_x + 400)){
			o1.score += 4;
			obj4[0].fl = false;
		}
		else if (sur_sock_fl && ((((obj4[0].x - dem_sur_x - demon_cordX - 150) <= 30 && (obj4[0].x - dem_sur_x - demon_cordX) >= -100) || (dem_sur_x + demon_cordX - obj4[0].x) >= 100)) && (obj4[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj4[0].y <= demon_cordY + demon_jump_cord_x + 400)){
			o1.score += 4;
			obj4[0].fl = false;
		}
		
		else if ((over_jump1 || over_down1) && (obj4[0].x - demon_cordX - 150 <= 50 && obj4[0].x - demon_cordX >= 20 || demon_cordX - obj4[0].x >= 30) && (obj4[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj4[0].y <= demon_cordY + demon_jump_cord_x + 300)){
			if (over_jump1==false && over_down1==false)
			o1.score += 4;
			obj4[0].fl = false;
		}
		else if ( thunder_fl_1 == false && thunder_fl == true && ((((obj4[0].x - th_cordx-demon_cordX)) <= 900 || (th_cordx+demon_cordX - obj4[0].x) >= -900)) && (obj4[0].y >= 0 && obj4[0].y <= 500)){
			o1.score += 4;
			obj4[0].fl = false;
		}
		else if (vanish_bp_fl_1 == false && vanish_bp_fl == true && ((obj4[0].x - vanish_cord_x - demon_cordX - 150) <= 30 && (obj4[0].x - vanish_cord_x - demon_cordX) >= -100 || (vanish_cord_x + demon_cordX - obj4[0].x) >= 0) && (obj4[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj4[0].y <= demon_cordY + demon_jump_cord_x + 500)){
			o1.score += 4;
			obj4[0].fl = false;
		}
		else if (power_bb==true && power_bb_first==false && (((obj4[0].x - ind_cord_x - demon_cordX-300) <= 30 && (obj4[0].x - ind_cord_x - demon_cordX) >= -500 || (ind_cord_x + demon_cordX - obj4[0].x) >= 0)) && (obj4[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj4[0].y <= demon_cordY + demon_jump_cord_x + 650)){
			o1.score += 4;
			obj4[0].fl = false;
		}
		else if (thunder_fl_11 == false && thunder_fl1 == true && ((obj4[0].x - th_cordx_1-demon_cordX-200) <= 30 && (obj4[0].x - th_cordx_1-demon_cordX) >= -200 || (th_cordx_1 + demon_cordX - obj4[0].x) >=0) && (obj4[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj4[0].y <= demon_cordY + demon_jump_cord_x + 650)){
			o1.score += 4;
			obj4[0].fl = false;
		}
		else if (leg_p_fl_1 == false && leg_p_fl == true && ((obj4[0].x - lg_cordx - demon_cordX - 150) <= 30 && (obj4[0].x - lg_cordx - demon_cordX) >= -200 || (lg_cordx + demon_cordX +100- obj4[0].x) >=0) && (obj4[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj4[0].y <= demon_cordY + demon_jump_cord_x +470)){
			o1.score += 4;
			obj4[0].fl = false;
		}
		else if (fb_arr_fl_sr == false && fb_arr_fl == true && ((obj4[0].x - fb_cord_x-demon_cordX-150) <= 30 && (obj4[0].x - fb_cord_x-demon_cordX) >= -200 || (fb_cord_x + demon_cordX - obj4[0].x) >= 0) && (obj4[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj4[0].y <= demon_cordY + demon_jump_cord_x + 350)){
			o1.score += 4;
			obj4[0].fl = false;
		}
		else if (blade_pl_fl == true && (((obj4[0].x - demon_cordX - 100) <= 30 && (obj4[0].x - demon_cordX) >= -150) || (demon_cordX - obj4[0].x) >= 0) && (obj4[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj4[0].y <= demon_cordY + demon_jump_cord_x + 390)){
			o1.score += 4;
			obj4[0].fl = false;
		}
		else if (hiper_power_2 == false && hiper_power1 == true && ((obj4[0].x - hbp_move - demon_cordX - 500) <= 30 && (obj4[0].x - hbp_move - demon_cordX) >= -400 || (hbp_move + demon_cordX - obj4[0].x) >= 0) && (obj4[0].y >= demon_cordY + demon_jump_cord_x - 30 && obj4[0].y <= demon_cordY + demon_jump_cord_x + 350)){
			o1.score += 4;
			obj4[0].fl = false;
		}
	}   
}
//______________________________________________________________End of Main ene collition ___________________________________________________________-----------------


//______________________________________________________________Star of 3 ene collition_______________________________________________________________________

char thrid_life[9][30] = { "bci\\third1.bmp", "bci\\third2.bmp", "bci\\third3.bmp", "bci\\third4.bmp", "bci\\third5.bmp", "bci\\third6.bmp", "bci\\third7.bmp", "bci\\third8.bmp", "bci\\third9.bmp"};

bool thrid_coll = false;
void show_third_en(){
	if (obj5.fl){
		if (show_main_cnt<=8)
		iShowBMP2(obj5.x, obj5.y + 220, thrid_life[show_main_cnt], 0);
		iShowBMP2(obj5.x, obj5.y, ene_third_sh[obj5.ind], 0);
		if (dem_pow1 && (obj3[0].x - pow_x - demon_cordX - 150 <= 30 && (obj5.x - pow_x - demon_cordX >= -200) || (pow_x + demon_cordX - obj5.x) >= 150) && (obj5.y >= demon_cordY + demon_jump_cord_x - 30 && obj5.y <= demon_cordY + demon_jump_cord_x + 500))
		{
			o1.score += 20;
			show_main_cnt++;
			obj5.fl = false;
			obj5.ind = 0;
			thrid_coll = true;
		}
		else if (dem_pow1 && (obj5.x - pow_x - demon_cordX - 150 <= 30 && (obj5.x - pow_x - demon_cordX >= -200) || (pow_x + demon_cordX - obj5.x) >= 150) && (obj5.y >= demon_cordY + demon_jump_cord_x - 30 && obj5.y <= demon_cordY + demon_jump_cord_x + 500))
		{
			o1.score += 20;
			show_main_cnt++;
			obj5.fl = false;
			obj5.ind = 0;
			thrid_coll = true;
		}
		else if (sur_sock_fl && ((((obj5.x - dem_sur_x - demon_cordX - 150) <= 30 && (obj5.x - dem_sur_x - demon_cordX) >= -100) || (dem_sur_x + demon_cordX - obj5.x) >= 100)) && (obj5.y >= demon_cordY + demon_jump_cord_x - 30 && obj5.y <= demon_cordY + demon_jump_cord_x + 400)){
			show_main_cnt++;
			o1.score += 20;
			obj5.fl = false;
			obj5.ind = 0;
			thrid_coll = true;
		}
		else if (sur_sock_fl && ((((obj5.x - dem_sur_x - demon_cordX - 150) <= 30 && (obj5.x - dem_sur_x - demon_cordX) >= -100) || (dem_sur_x + demon_cordX - obj5.x) >= 100)) && (obj5.y >= demon_cordY + demon_jump_cord_x - 30 && obj5.y <= demon_cordY + demon_jump_cord_x + 400)){
			show_main_cnt++;
			o1.score += 20;
			obj5.fl = false;
			obj5.ind = 0;
			thrid_coll = true;
		}

		else if ((over_jump1 || over_down1) && (obj5.x - demon_cordX - 150 <= 50 && obj5.x - demon_cordX >= 20 || demon_cordX - obj5.x >= 30) && (obj5.y >= demon_cordY + demon_jump_cord_x - 30 && obj5.y <= demon_cordY + demon_jump_cord_x + 300)){
			show_main_cnt++;
			obj5.fl = false;
			o1.score += 20;
			obj5.ind = 0;
			thrid_coll = true;
		}
		else if (thunder_fl_1 == false && thunder_fl == true && ((((obj5.x - th_cordx-demon_cordX)) <= 900 || (th_cordx+demon_cordX - obj5.x) >=-900)) && (obj5.y >= 0 && obj5.y <= 500)){
			show_main_cnt++;
			o1.score += 20;
			obj5.fl = false;
			obj5.ind = 0;
			thrid_coll = true;
		}
		else if (vanish_bp_fl_1 == false && vanish_bp_fl == true && ((obj5.x - vanish_cord_x - demon_cordX - 150) <= 30 && (obj5.x - vanish_cord_x - demon_cordX) >= -100 || (vanish_cord_x + demon_cordX - obj5.x) >= 0) && (obj5.y >= demon_cordY + demon_jump_cord_x - 30 && obj5.y <= demon_cordY + demon_jump_cord_x + 500)){
			show_main_cnt++;
			obj5.fl = false;
			o1.score += 20;
			obj5.ind = 0;
			thrid_coll = true;
		}
		else if (power_bb == true && power_bb_first == false && (((obj5.x - ind_cord_x - demon_cordX - 300) <= 30 && (obj5.x - ind_cord_x - demon_cordX) >= -500 || (ind_cord_x + demon_cordX - obj5.x) >= 0)) && (obj5.y >= demon_cordY + demon_jump_cord_x - 30 && obj5.y <= demon_cordY + demon_jump_cord_x + 650)){
			show_main_cnt++;
			o1.score += 20;
			obj5.fl = false;
			obj5.ind = 0;
			thrid_coll = true;
		}
		else if (thunder_fl_11 == false && thunder_fl1 == true && ((obj5.x - th_cordx_1 - demon_cordX - 200) <= 30 && (obj5.x - th_cordx_1 - demon_cordX) >= -200 || (th_cordx_1 + demon_cordX - obj5.x) >= 0) && (obj5.y >= demon_cordY + demon_jump_cord_x - 30 && obj5.y <= demon_cordY + demon_jump_cord_x + 650)){
			show_main_cnt++;
			obj5.fl = false;
			o1.score += 20;
			obj5.ind = 0;
			thrid_coll = true;
		}
		else if (leg_p_fl_1 == false && leg_p_fl == true && ((obj5.x - lg_cordx - demon_cordX - 150) <= 30 && (obj5.x - lg_cordx - demon_cordX) >= -200 || (lg_cordx + demon_cordX + 100 - obj5.x) >= 0) && (obj5.y >= demon_cordY + demon_jump_cord_x - 30 && obj5.y <= demon_cordY + demon_jump_cord_x + 470)){
			show_main_cnt++;
			obj5.fl = false;
			obj5.ind = 0;
			o1.score += 20;
			thrid_coll = true;
		}
		else if (fb_arr_fl_sr == false && fb_arr_fl == true && ((obj5.x - fb_cord_x - demon_cordX - 150) <= 30 && (obj5.x - fb_cord_x - demon_cordX) >= -200 || (fb_cord_x + demon_cordX - obj5.x) >= 0) && (obj5.y >= demon_cordY + demon_jump_cord_x - 30 && obj5.y <= demon_cordY + demon_jump_cord_x + 350)){
			show_main_cnt++;
			obj5.fl = false;
			o1.score += 20;
			obj5.ind = 0;
			thrid_coll = true;
		}
		else if (blade_pl_fl == true && (((obj5.x - demon_cordX - 100) <= 30 && (obj5.x - demon_cordX) >= -150) || (demon_cordX - obj5.x) >= 0) && (obj5.y >= demon_cordY + demon_jump_cord_x - 30 && obj5.y <= demon_cordY + demon_jump_cord_x + 390)){
			show_main_cnt++;
			o1.score += 20;
			obj5.fl = false;
			obj5.ind = 0; 
			o1.score += 20;
			thrid_coll = true;
		}
		else if (blade_pl_fl == true && (((obj5.x - demon_cordX - 100) <= 30 && (obj5.x - demon_cordX) >= -150) || (demon_cordX - obj5.x) >= 0) && (obj5.y >= demon_cordY + demon_jump_cord_x - 30 && obj5.y <= demon_cordY + demon_jump_cord_x + 390)){
			show_main_cnt++;
			obj5.fl = false;
			obj5.ind = 0;
			o1.score += 20;
			thrid_coll = true;
		}
		else if (hiper_power_2 == false && hiper_power1 == true && ((obj5.x - hbp_move - demon_cordX - 500) <= 30 && (obj5.x - hbp_move - demon_cordX) >= -400 || (hbp_move + demon_cordX - obj5.x) >= 0) && (obj5.y >= demon_cordY + demon_jump_cord_x - 30 && obj5.y <= demon_cordY + demon_jump_cord_x + 350))
		{
			show_main_cnt++;
			obj5.fl = false;
			o1.score += 20;
			obj5.ind = 0;
			thrid_coll = true;
		}

	}
	else if (obj6.fl){
		obj6.x = obj5.x;
		obj6.y = obj5.y;
		enemy_ball_3 -= 22;
		obj6.x += enemy_ball_3;
		iShowBMP2(obj6.x, obj6.y, ch_ene_dr[0], 0);
		if ((obj6.x - demon_cordX-30 <= 30 && obj6.x - demon_cordX >= -100) && (obj6.y >= demon_cordY + demon_jump_cord_x - 30 && obj6.y <= demon_cordY + demon_jump_cord_x + 250)){
			game_ind+=2;
			obj6.fl = false;
			thrid_coll = true;
		}
		else if (dem_pow1 && (obj6.x - pow_x - demon_cordX -150<= 30 && (obj6.x - pow_x - demon_cordX >= -200) || (pow_x + demon_cordX - obj6.x) >= 150) && (obj6.y >= demon_cordY + demon_jump_cord_x - 30 && obj6.y <= demon_cordY + demon_jump_cord_x + 500))
		{
			o1.score += 4;
			obj6.fl = false;
			thrid_coll = true;
		}
		else if (sur_sock_fl && ((((obj6.x - dem_sur_x - demon_cordX-150) <= 30 && (obj6.x - dem_sur_x - demon_cordX) >= -100) || (dem_sur_x + demon_cordX - obj6.x) >= 100)) && (obj6.y >= demon_cordY + demon_jump_cord_x - 30 && obj6.y <= demon_cordY + demon_jump_cord_x + 400)){
			obj6.fl = false;
			o1.score += 4;
			thrid_coll = true;
		}
		else if (sur_sock_fl && ((((obj6.x - dem_sur_x - demon_cordX-150) <= 30 && (obj6.x - dem_sur_x - demon_cordX) >= -100) || (dem_sur_x + demon_cordX - obj6.x) >= 100)) && (obj6.y >= demon_cordY + demon_jump_cord_x - 30 && obj6.y <= demon_cordY + demon_jump_cord_x + 400)){
			obj6.fl = false;
			o1.score += 4;
			thrid_coll = true;
		}

		else if ((over_jump1 || over_down1) && (obj6.x - demon_cordX-150 <= 50 && obj6.x - demon_cordX >= 20 || demon_cordX - obj6.x >= 30) && (obj6.y >= demon_cordY + demon_jump_cord_x - 30 && obj6.y <= demon_cordY + demon_jump_cord_x + 300)){
			obj6.fl = false;
			thrid_coll = true;
			o1.score += 4;
		}
		else if (thunder_fl_1 == false && thunder_fl == true && ((((obj6.x - th_cordx-demon_cordX)) <= 900 || (th_cordx - obj6.x) >= -900)) && (obj6.y >= 0 && obj6.y <= 500)){
			obj6.fl = false;
			thrid_coll = true;
			o1.score += 4;
		}
		else if (vanish_bp_fl_1 == false && vanish_bp_fl == true && ((obj6.x - vanish_cord_x - demon_cordX-150) <= 30 && (obj6.x - vanish_cord_x - demon_cordX) >= -100 || (vanish_cord_x + demon_cordX - obj6.x) >= 0) && (obj6.y >= demon_cordY + demon_jump_cord_x - 30 && obj6.y <= demon_cordY + demon_jump_cord_x + 500)){
			obj6.fl = false;
			o1.score += 4;
			thrid_coll = true;
		}

		else if (power_bb == true && power_bb_first == false && (((obj6.x - ind_cord_x - demon_cordX - 300) <= 30 && (obj6.x - ind_cord_x - demon_cordX) >= -500 || (ind_cord_x + demon_cordX - obj6.x) >= 0)) && (obj6.y >= demon_cordY + demon_jump_cord_x - 30 && obj6.y <= demon_cordY + demon_jump_cord_x + 650)){
			obj6.fl = false;
			thrid_coll = true;
			o1.score += 4;
		}
		else if (thunder_fl_11 == false && thunder_fl1 == true && ((obj6.x - th_cordx_1 - demon_cordX - 200) <= 30 && (obj6.x - th_cordx_1 - demon_cordX) >= -200 || (th_cordx_1 + demon_cordX - obj6.x) >= 0) && (obj6.y >= demon_cordY + demon_jump_cord_x - 30 && obj6.y <= demon_cordY + demon_jump_cord_x + 650)){
			obj6.fl = false;
			thrid_coll = true;
			o1.score += 4;
		}
		else if (leg_p_fl_1 == false && leg_p_fl == true && ((obj6.x - lg_cordx - demon_cordX - 150) <= 30 && (obj6.x - lg_cordx - demon_cordX) >= -200 || (lg_cordx + demon_cordX + 100 - obj6.x) >= 0) && (obj6.y >= demon_cordY + demon_jump_cord_x - 30 && obj6.y <= demon_cordY + demon_jump_cord_x + 470)){
			obj6.fl = false;
			thrid_coll = true;
			o1.score += 4;
		}
		else if (fb_arr_fl_sr == false && fb_arr_fl == true && ((obj6.x - fb_cord_x - demon_cordX - 150) <= 30 && (obj6.x - fb_cord_x - demon_cordX) >= -200 || (fb_cord_x + demon_cordX - obj6.x) >= 0) && (obj6.y >= demon_cordY + demon_jump_cord_x - 30 && obj6.y <= demon_cordY + demon_jump_cord_x + 350)){
			obj6.fl = false;
			o1.score += 4;
			thrid_coll = true;
		}
		else if (blade_pl_fl == true && (((obj6.x - demon_cordX - 100) <= 30 && (obj6.x - demon_cordX) >= -150) || (demon_cordX - obj6.x) >= 0) && (obj6.y >= demon_cordY + demon_jump_cord_x - 30 && obj6.y <= demon_cordY + demon_jump_cord_x + 390)){
			obj6.fl = false;
			o1.score += 4;
			thrid_coll = true;
		}
		else if (hiper_power_2 == false && hiper_power1 == true && ((obj6.x - hbp_move - demon_cordX - 500) <= 30 && (obj6.x - hbp_move - demon_cordX) >= -400 || (hbp_move + demon_cordX - obj6.x) >= 0) && (obj6.y >= demon_cordY + demon_jump_cord_x - 30 && obj6.y <= demon_cordY + demon_jump_cord_x + 350)){
			obj6.fl = false;
			o1.score += 4;
			thrid_coll = true;
		}
	}
}

//______________________________________________________________End of 3 ene collition_______________________________________________________________________
bool die_flag = false;
bool end_page = false;
void takeinput(unsigned key){
	if (key == 'p'){
		exit(0);
	}
	if (key == '\r'){
		strcpy(o1.name, str1);
		high_page_sorting();
		high_score_page = true;
	}
	else if (key=='\b'){
		if (len <= 0){
			len = 0;
		}
        else
		   len--;
		str1[len] = '\0';
	}
	else{
		str1[len] = key;
		len++;
		if(len > 15){
			len = 15;
		}str1[len] = '\0';
	}
}
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
	else if (instruction_page)
			iShowBMP(0, 0, "bci\\instruction.bmp");
	else if(high_score_page){
		iShowBMP(0,0, "bci\\high_page.bmp");
		showing_score_page();
	}
	else if (level_st_1){
		iShowBMP(0, 0, "bci\\level1.bmp");
	}
	else if (level_st_2){
		iShowBMP(0, 0, "bci\\level2.bmp");
	}
	else if (die_flag){
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
		iShowBMP2(demon_cordX, demon_cordY, main_die_showing[player_life_ind], 0);
	}
	else if (end_page){
		iShowBMP2(0, 0, "bci\\end_page.bmp", 0);
	}
	else if (take_name){
		iSetColor(128, 128, 128);
		iFilledRectangle(630,340 ,300, 300);
		showChar();
	}
	else if (winner_show){
		iShowBMP(0, 0, "bci\\winner.bmp");
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
			if (!standposs && run_forward){
				iShowBMP2(demon_cordX, demon_cordY, demon[demon_ind], 0);
			}
			else if (!standposs && rum_back_fl){
				iShowBMP2(demon_cordX, demon_cordY, run_back[run_back_ind], 0);
			}
		}
		if (standposs){
			iShowBMP2(demon_cordX, demon_cordY, demon_stand, 0);
		}
		//--------------------------------------------------- supper power start -----------------------------------------------------------------------
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
				iShowBMP2(demon_cordX, demon_cordY, thunder_power[th_ind_1], 0);
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
		if (hiper_power1){
			if (hiper_power_2)
			iShowBMP2(demon_cordX, demon_cordY + demon_jump_cord_x, hbp_sho[hbp_ind], 0);
			else
			{
				hbp_move += 23;
				iShowBMP2(demon_cordX + hbp_move, demon_cordY + demon_jump_cord_x, hbp_sho_ball[hbp_ball_ind], 0);
			}
		}
		//-------------------------------------------- Super power end ----- ---------------------------------------------------------------------------------
		showing_score();

		if (die_enem){
			iShowBMP2(1370, 0, die_showing[die_ind], 0);
		}
		enemy_1_show();
		for (int j = 0; j < 3; j++){
			ene[j].enemy_cord_x -= 10;
		}
		if (show_enemy_flag && show_third_flag == false){
			show_enemy(); 
			iShowBMP2(700, 700, "bci\\level1_game.bmp", 0);
		}
		else if (show_third_flag && show_enemy_flag==false){
			show_third_en();
			iShowBMP2(700, 650, "bci\\level2_game.bmp", 0);
		}
		else if (show_main_flag){
			show_main_en();
			iShowBMP2(700, 650, "bci\\level3_game.bmp", 0);
		}
		if (game_ind<=27)
		iShowBMP2(30,700,lifing[game_ind],0);
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
		play_ground = true;
		musicon_home = false;
		music_play_game();
	}
	if (play_ground == false && homepage == true && (mx >= 752 && mx <= 1122) && (my >= 471 && my <= 577)){
		PlaySound("bci\\click_sound.wav", NULL, SND_ASYNC);
		homepage = false;
		instruction_page = true;
		cnt3=0;
	}
	if (play_ground == false && instruction_page == true && (mx >= 570 && mx <= 847) && (my >= 23 && my <= 95)){
		PlaySound("bci\\click_sound.wav", NULL, SND_ASYNC);
		instruction_page = false;
		homepage = true;
		cnt4=0;
	}
	if (play_ground == false && homepage == true && (mx >= 752 && mx <= 1122) && (my >= 319 && my <= 405)){
		PlaySound("bci\\click_sound.wav", NULL, SND_ASYNC);
		homepage = false;
		high_score_page = true;
		cnt5=0;
	}
	if (play_ground == false && homepage == false && high_score_page == true && (mx >= 1131 && mx <= 1423) && (my > 85 && my <= 223)){
		PlaySound("bci\\click_sound.wav", NULL, SND_ASYNC);
		high_score_page = false;
		homepage = true;
		cnt4=0;
	}
	if (play_ground == false && homepage == true && (mx >= 752 && mx <= 1122) && (my >= 151 && my <= 254)){
		PlaySound("bci\\click_sound.wav", NULL, SND_ASYNC);
		homepage = false;
		level_st_1= true;
		cnt2=0;
	}
	if (play_ground == false && homepage == false && (mx >= 1150 && mx <= 1418) && (my >= 44 && my <= 132)){
		PlaySound("bci\\click_sound.wav", NULL, SND_ASYNC);
		level_st_1 = false;
		level_st_2 = true;
		cnt1=0;
	}
	
	if (play_ground == false && homepage == false && level_st_1 == false && (mx >= 601 && mx <= 853) && (my >= 107 && my <= 204)){
		PlaySound("bci\\click_sound.wav", NULL, SND_ASYNC);
		level_st_2 = false;
		level_st_1 = true;
		cnt2=0;
	}
	if (play_ground == false && homepage == false && level_st_1 == true && (mx >= 101 && mx <= 308) && (my >= 46 && my <= 131)){
		PlaySound("bci\\click_sound.wav", NULL, SND_ASYNC);
		level_st_1 = false;
		homepage = true;
		cnt4=0;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		cout <<mx<<"  "<<my<<endl;
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
	if (take_name){
		takeinput(key);
	}
	if (key == 'p'){
		//fl = true;
		standposs = true;
	}
	if (key == 'a'){
		if (!blade_pl_fl){
			mciSendString("play a.mp3", NULL, 0, 0);
			blade_pl_fl = true;
			fl = false;
			standposs = false;
		}
	}
	if (key == 'd'){
		if (!thunder_fl1 && show_enemy_flag==false){
			mciSendString("play thundre_power.wav", NULL, 0,0);
			thunder_fl1 = true;
			thunder_fl_11 = true;
			fl = false;
			standposs = false;
		}
	}
	if (key == 'e'){
		if (!thunder_fl){
			mciSendString("play electric.mp3", NULL, 0, 0);
			thunder_fl = true;
			thunder_fl_1 = true;
			fl = false;
			standposs = false;
		}
	}
	if (key == 'w')
	{
		if (!leg_p_fl){
			mciSendString("play w.wav",NULL,0,0);
			leg_p_fl = true;
			leg_p_fl_1 = true;
			fl = false;
			standposs = false;
		}
	}
	if (key == 's'){
		if (!fb_arr_fl){
			mciSendString("play a.mp3", NULL, 0, 0);
			fb_arr_fl = true;
			fb_arr_fl_sr = true;
			fl = false;
			standposs = false;
		}
	}
	if (key == 'f'){
		if (!vanish_bp_fl){
			mciSendString("play f.wav", NULL, 0, 0);
			vanish_bp_fl = true;
			vanish_bp_fl_1 = true;
			fl = false;
			standposs = false;
		}
	}
	if (key == 'v'){
		if (!power_bb){
			mciSendString("play v.mp3", NULL, 0, 0);
			power_bb = true;
			power_bb_first = true;
			fl = false;
			standposs = false;
		}
	}
	if (key == 'r'){
		if (!over_jump1){
			mciSendString("play r.wav",NULL,0,0);
			over_jump1 = true;
			fl = false;
			standposs = false;
		}
	}
	if (key == 'g'){
		if (!dem_sur1){
			mciSendString("play g.wav",NULL,0,0);
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
			mciSendString("play b.wav",NULL,0,0);
			demon_spup = true;
			demon_supra = true;
			fl = false;
			standposs = false;
		}
	}
	if (key == 'h'){
		if (!hiper_power1){
			mciSendString("play hiper_sonic.mp3", NULL, 0, 0);
			standposs = false;
			fl = false;
			hiper_power1 = true;
			hiper_power_2 = true;
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
		run_forward = true;
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
		rum_back_fl = true;
		run_forward = false;
		demon_cordX -= 100;
		
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
void dieing(){
	if (die_flag){
		player_life_ind++;
	}
	if (player_life_ind >=8){
		end_page = true;
		play_ground = false;
		player_life_ind = 0;
		die_flag = false;
	}
}
bool hyper_balls = false;
int take_iput_name = 0;
void change(){
	if (end_page){
		take_iput_name++;
	}
	if (take_iput_name >= 25){
		take_name = true;
		end_page = false;
		take_iput_name = 0;
	}
	if (fir_ene_cnt >= 4){
		fir_ene_cnt = 0;
		if (game_ind <= 26)
		game_ind+=2;
	}
	if (main_life_ene_cnt >= 9){
		winner_show = true;
	}
	if (game_ind >= 27){
		die_flag = true;
		game_ind = 0;
	}
	if (show_main_cnt >= 9){
		show_main_flag = true;
		show_third_flag = false;
	}
	if (show_enemy_cnt >= 5 && show_enemy_flag == false && show_third_flag == false && show_main_flag==false){
		show_enemy_flag = true;
	}
	if (show_thire_cnt >= 6 && show_enemy_flag == true && die_enem == false && show_third_flag == false && show_main_flag == false){
		die_enem = true;
		show_enemy_flag = false;
		show_third_flag = true;
	}
	if (die_enem){
		die_ind++;
	}if (die_ind >= 10){
		die_enem = false;
		die_ind = 0;
		show_third_flag = true;
		show_enemy_flag = false;
	}
	ene[0].enemy_ind++;
	ene[1].enemy_ind++;
	ene[2].enemy_ind++;
	for (int i = 0; i < 3; i++){
		if (ene[i].enemy_ind >= 4){
			ene[i].enemy_ind=0;
		}
	}

	if (rum_back_fl){
		run_back_ind++;
	}
	for (int i = 0; i < 3; i++){
		if (ene[i].enemy_cord_x <=0){
			ene[i].enemy_show = true;
			ene[i].enemy_cord_x = 1700+(500*i);
		ene[i].enemy_cord_y =(rand() % 650)+(rand()%50);
		}
	}
	if (level_st_2 == true){
		cnt1++;
	}
	if (cnt1 == 3){
		PlaySound("bci\\home.wav", NULL,SND_ASYNC);
	}
	if (level_st_1 == true){
		cnt2++;
	}
	if (cnt2 == 3){
		PlaySound("bci\\home.wav", NULL, SND_ASYNC);
	}
	if (instruction_page == true){
		cnt3++;
	}
	if (cnt3 == 3){
		PlaySound("bci\\home.wav", NULL, SND_ASYNC);
	}
	if (homepage == true){
		cnt4++;
	}
	if (cnt4 == 4){
		PlaySound("bci\\home.wav", NULL, SND_ASYNC);
	}
	if (high_score_page == true){
		cnt5++;
	}
	if (cnt5 == 3){
		PlaySound("bci\\home.wav", NULL, SND_ASYNC);
	}
	if (homepage == false && instruction_page == false && high_score_page == false && level_st_1 == false && level_st_2 == false){
		cnt++;
	}
	if (blade_pl_fl){
		standposs = false;
		fl = false;
		jumpup = false;
		ind_blade_pl++;
	}
	if (thunder_fl1){
		fl = false;
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
		fl = false;
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
			cout << "Print " << ind_cord_x << endl;
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
		cout << "print " << ind_cord_x << endl;
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
	if (cnt == 4){
		cout << "Playing music" << endl;
		PlaySound("bci\\game.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	if (run_back_ind >= 6){
		run_back_ind = 0;
	}
	if (hbp_ind >= 7){
		hbp_ind = 0;
		hiper_power_2 = false;
		hyper_balls = true;
	}
	if (hyper_balls){
		hbp_ball_ind++;
	}
	if (hbp_ball_ind>=4){
    	fl = true;
		hbp_move = 15;
		hiper_power1 = false;
		hiper_power_2 = false;
		hyper_balls = false;
		hbp_ball_ind = 0;
	}
}

void showing_eme(){
	for (int i = 0; i <3; i++){
		ene[i].enemy_cord_x = 1700+(500*i);
		ene[i].enemy_cord_y = rand() % 650;
		ene[i].enemy_show = true;
	}
}
void ene_main_fix(){
	obj3[0].y = rand() % 750;
}
void ene_2_fix(){
	obj1[0].y = rand() % 750;
}
void emy_2_cha(){
	//if (fl_second){
		if (obj1[0].fl == true){
			obj1[0].ind++;
			if (obj1[0].ind >= 4){
				obj2[0].bl = true;
				obj1[0].fl = false;
				obj2[0].ind = 0;
				obj1[0].ind = 0;
			}
		}
		else{
			obj2[0].ind++;
			if (obj2[0].ind >= 3){
				obj1[0].fl = true;
				enemy_ball_2 = 0;
				obj2[0].ind = 0;
				obj1[0].y = rand() % 570;
				obj2[0].bl = false;
			}
		}
	//}
}

void emy_main_cha(){
	if (obj3[0].fl == true){
		obj3[0].ind++;
		if (obj3[0].ind >= 4){
			obj4[0].fl = true;
			obj3[0].fl = false;
			obj4[0].ind = 0;
			obj3[0].ind = 0;
		}
	}
	else{
		obj4[0].ind+=2;
		if (obj4[0].ind >= 3){
			obj3[0].fl = true;
			enemy_ball_2_m = 0;
			obj4[0].ind = 0;
			obj3[0].y = rand() % 450;
			obj4[0].fl = false;
		}
	}
}

void emy_3_cha(){
	if (obj5.fl == true){
		obj5.ind++;
		if (obj5.ind >= 5){
			thrid_coll = false;
			obj6.fl = true;
			obj5.fl = false;
			obj5.ind = 0;
		}
	}
	else{
		if (enemy_ball_3<-1400 || thrid_coll){
			obj5.fl = true;
			enemy_ball_3 = 0;
			obj5.y = rand() % 500;
			obj6.fl = false;
		}
	}
}
void hiper_fire_b(){
	if (hiper_power_2){
		hbp_ind++;
	}
}
int main()
{
	ene_main_fix();
	ene_2_fix();
	showing_eme();
	iSetTimer(200, change);
	iSetTimer(500, emy_2_cha);
	iSetTimer(400, emy_main_cha);
	iSetTimer(300, emy_3_cha);
	iSetTimer(700,dieing);
	iSetTimer(200,hiper_fire_b);
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