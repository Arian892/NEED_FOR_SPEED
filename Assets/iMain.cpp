# include "iGraphics.h"
#include<windows.h>
#include<string.h>
#include<iostream>
#define N rand()%290 + 375
#define N2 740
#define N3 1140
#define N4 1540
#define N5 1940
#define N6 2340
#define N7 2740
#define N8 3140
#define R2 -2400
#define R3 -2000
#define R4 -1600
#define R5 -1200
#define R6 -800
#define R7 -400
#define R8 0
#define BEGINNER 20
#define STANDARD 30
#define PROFESSIONAL 40
#define carsound "racing_sound.wav"
#define carcrash "car_crash1.wav"
#define A 525
#define B 130

int input = 0 ;
int main_sound=1 ;
int crash=0 ;
int racing =0 ;
int p2= N, q2=N2;
int p3= N, q3=N3;
int p4= N, q4=N4;
int p5= N, q5=N5;
int p6= N, q6=N6;
int p7= N, q7=N7;
int p8= N, q8=N8;
int score=0 ;
char scoreshow [50];
int gameover=0 ;
int gameresume=1 ;
char Entryname[50];
int Indexname =0 ;
char Fname[50];
char Fscore[50];


int car_h=110,car_w=53 ;
int i,j;
int a=A,b=B ;
int dy=BEGINNER;



int play=0 ;
int ypos[19];
char render[19][20]={"img 01.BMP","img 02.BMP","img 03.BMP","img 04.BMP",
    "img 05.BMP","img 06.BMP","img 07.BMP","img 08.BMP","img 09.BMP","img 10.BMP","img 11.BMP",
    "img 12.BMP","img 13.BMP","img 14.BMP","img 15.BMP","img 16.BMP","img 17.BMP","img 18.BMP","img 19.BMP"};

typedef struct {
    int Sscore;
    char Sname[50];
} player ;

player info [6];


void ChangeFile ()
{
    sprintf(Fscore,"%i",score);
    FILE * fp1 = fopen ("highname.txt","a");
    FILE * fp2 = fopen("highscore.txt","a");
    fprintf(fp1,"%s\n",Fname);
    fprintf(fp2,"%s\n",Fscore);
    fclose(fp1);
    fclose(fp2);
}

void sorthighscore ()
{
    for (i=0 ; i<6 ; i++)
    {
        for (j=i+1 ; j<6 ; j++ )
        {
            if (info[i].Sscore < info[j].Sscore)
            {
                int temp1=info[i].Sscore;
                info[i].Sscore = info[j].Sscore ;
                info[j].Sscore = temp1 ;
                char temp2[20];
                strcpy(temp2,info[i].Sname);
                strcpy (info[i].Sname, info[j].Sname);
                strcpy (info[j].Sname,temp2);
            }
        }
    }
}

void sethighscore ()
{
    FILE * f1 = fopen ("highname.txt","r");
    FILE * f2 = fopen ("highscore.txt","r");

    for (int i=0 ; i<6 ; i++)
    {
        if (f1 != NULL && f2 != NULL)
        {
            fscanf(f1,"%s",info[i].Sname);
            fscanf(f2,"%d",&info[i].Sscore);
        }
    }

    sorthighscore ;

    fclose(f1);
    fclose (f2);

    FILE * f3 = fopen ("highname.txt","w");
    FILE * f4 = fopen ("highscore.txt","w");

    for (int i=0 ; i<5 ; i++)
    {
        fprintf(f3,"%s\n",info[i].Sname);
        fprintf(f4,"%d\n",info[i].Sscore);
    }

    fclose (f3);
    fclose (f4);

}
 void Highscoreshow()
 {
     FILE * f1 =fopen ("highname.txt","r");
     FILE * f2 =fopen ("highscore.txt","r");

     for (int i=0 ; i<5 ; i++)
     {
         if (f1 != NULL && f2 != NULL)
         {
             fscanf(f1,"%s",info[i].Sname);
             fscanf(f2,"%d",&info[i].Sscore);

         }
     }
     fclose (f1);
     fclose (f2);

 }
int collision(int x1, int y1) {
    int left1 = x1;
    int right1 = x1 + car_w ;
    int bottom1 = y1;
    int top1 = y1 + car_h;
    int left2 = a;
    int right2 = a +car_w ;
    int bottom2 = b;
    int top2 = b + car_h ;
    if (right1 >= left2 && left1 <= right2 && top1 >= bottom2 && bottom1 <= top2){

        return 1;
    }

     else {

        return 0;
    }
}

void car2 ()
{
   q2=q2-dy ;
   if (q2 <= R2)
   {
       q2=N2;
       p2= N ;

   }
}
void car3()
{
   q3=q3-dy ;
   if (q3 <= R3)

   {
       q3=N3;
       p3= N ;

   }
}
void car4()
{
   q4=q4-dy ;
   if (q4 <= R4)
   {
       q4=N4;
       p4= N ;

   }
}
void car5()
{
   q5=q5-dy ;
   if (q5 <= R5)
   {
       q5=N5;
       p5= N ;

   }
}
void car6()
{
   q6=q6-dy ;
   if (q6 <= R6)
   {
       q6=N6;
       p6= N ;

   }
}
void car7()
{
   q7=q7-dy ;
   if (q7 <= R7)
   {
       q7=N7;
       p7= N ;

   }
}
void car8()
{
   q8=q8-dy ;
   if (q8 <= R8)
   {
       q8=N8;
       p8= N ;

   }
}
void scorefunction ()
{
    score++;
}


void show ()
{
    for (i=0 ; i<19 ; i++)
    {
        ypos[i] -= 36;
    }
    for (i=0 ; i<19; i++)
    {
        if (ypos[i]<36 )
        {
           ypos[i]=689;
        }
    }

}

void yposf()
{
    int i,j;
    for (i=0,j=0 ; i<36 ; i++)
    {
        ypos[i]=j;
        j+=36 ;
    }
}



void iDraw() {
	//place your drawing codes here

	iClear();
	if (play==0)
    {
        iShowBMP(0,0,"final bg.BMP");

    }
	if (play==1)
    {
          iShowBMP(0,0,"final bg2.BMP");
	      iShowBMP(412,450+20,"Play.BMP");
	      iShowBMP(367,350+20,"High Scores.BMP");
	      iShowBMP(309,150+20,"instructions.BMP");
	      iShowBMP(450,50+20,"exit.BMP");
          iShowBMP(339,250+20,"difficulty.BMP");
    }
    if (play==21)
    {
        iShowBMP(0,0,"final bg1.bmp");
        iShowBMP(10,680,"back.bmp");
        if (input ==1)
        {
            iSetColor(0,0,0);
            iText (368,356,Entryname,GLUT_BITMAP_TIMES_ROMAN_24);
        }
    }
    if (play==2)
    {


        //iShowBMP(0,0,"final bg.BMP");
      iShowBMP(0,0,"play3bg.bmp");

      iShowBMP(375,130,"rendering.BMP");


        for (i=0 ; i<19 ; i++)
    {
        iShowBMP(375,ypos[i],render[i]);
    }


    iShowBMP2(a,b,"testing.bmp",16777215);
    iShowBMP2(p2,q2,"car2.BMP",16777215);
    iShowBMP2(p3,q3,"car3.BMP",16777215);
    iShowBMP2(p4,q4,"car4.BMP",16777215);
    iShowBMP2(p5,q5,"car5.BMP",16777215);
    iShowBMP2(p6,q6,"car6.BMP",16777215);
    iShowBMP2(p7,q7,"car7.BMP",16777215);
    iShowBMP2(p8,q8,"car8.BMP",16777215);



    //play=1 ;
    // iShowBMP2(p,q,"car3.BMP",16777215);
    iShowBMP(10,680,"back.bmp");
    iShowBMP(375,0,"play 2 demo.BMP");

   if (gameover==0)
   {
       iResumeTimer (8);
//    if (score > highscore)
//    {
//        highscore=score ;
//        save_high_score();
//
//    }
  sprintf(scoreshow, "Score: %d ", score);
    iSetColor(255,255,255);
  iText (500,60,scoreshow, GLUT_BITMAP_TIMES_ROMAN_24);
   }

    if(gameover == 0){



     if (collision(p2,q2) || collision (p3,q3) || collision (p4,q4) || collision (p5,q5) ||collision (p6,q6)
         ||collision (p7,q7)|| collision (p8,q8) || a< 367 || a>670 )
    {
        //exit(0);

    //iShowBMP(0,0,"final bg2.bmp");
      gameover = 1 ;
       if(gameover == 1){

        iPauseTimer(0);
	 iPauseTimer(1);
     iPauseTimer(2);
     iPauseTimer(3);
	 iPauseTimer(4);
	 iPauseTimer(5);
     iPauseTimer(6);
     iPauseTimer(7);
     iPauseTimer(8);
     //   PlaySound (carcrash,NULL,SND_SYNC);
            ChangeFile ();
            sethighscore();

           // gameover=0 ;
           // gameover=0 ;
//        iSetColor(255,0,0);
//        //iText(500,300,name);
    }

//     if (score > highscore) {
//            highscore = score;
//            save_high_score();
//        }

        //score =0 ;
//         racing=0 ;
//
//
//            if (racing==0)
//            {
//                PlaySound (NULL ,0,0);
//            }
//

     //   gameover = 1 ;

//        if (gameover==1)
//        {
//           iShowBMP(0,0,"gameover.bmp");
//            PlaySound (carcrash,NULL,SND_SYNC);
//            ChangeFile ();
//            sethighscore();
//            sprintf(Fscore,"%i",score);
//            iSetColor(255,255,255);
//            iText (693,225,Fscore,GLUT_BITMAP_TIMES_ROMAN_24);
//         //  score =0 ;
//
//          //  printf(" %d ",gameover);
//         //   gameover = 0 ;
//
//
//        }


    }
}
if (gameover==1)
{
    iShowBMP(0,0,"gameover.bmp");
    iShowBMP(10,680,"back.bmp");
    sprintf(Fscore,"%i",score);
    iSetColor (255,255,255);
    iFilledRectangle(325,205,350,55);
    iSetColor(0,0,0);
    iText(393,225,"YOUR SCORE IS : ",GLUT_BITMAP_TIMES_ROMAN_24);
    iText (593,225,Fscore,GLUT_BITMAP_TIMES_ROMAN_24);

}



if (gameresume==1 && gameover==0)
    {
        iShowBMP(1020,640,"pause.bmp");
        iResumeTimer (0);
        iResumeTimer (1);
        iResumeTimer (2);
        iResumeTimer (3);
        iResumeTimer (4);
        iResumeTimer (5);
        iResumeTimer (6);
        iResumeTimer (7);
        iResumeTimer (8);
//        racing=1 ;
//        if (racing==1){PlaySound (carsound,NULL,SND_LOOP |SND_ASYNC );}

  }
    if (gameresume==2 && gameover==0)
    {
     iPauseTimer(0);
	 iPauseTimer(1);
     iPauseTimer(2);
     iPauseTimer(3);
	 iPauseTimer(4);
	 iPauseTimer(5);
     iPauseTimer(6);
     iPauseTimer(7);
     iPauseTimer(8);
//      racing=0 ;
//        if (racing==0)
//        {
//    PlaySound (NULL ,0,0);
//        }

     iShowBMP(1020,640-80,"resume.bmp");
    // gameresume=3 ;


    }

    }
    if (play==3)
    {
    iShowBMP (0,0,"play3.BMP");
    iShowBMP(356,510,"beginner.BMP");
    iShowBMP(358,350,"standard.BMP");
    iShowBMP(268,190,"professional.BMP");
    iSetColor(255,255,255);
       if(dy==BEGINNER)
       {
           iFilledCircle(326,550,30,1000);
       }
     else if(dy==STANDARD)
       {
           iFilledCircle(328,390,30,1000);
       }
     else if(dy==PROFESSIONAL)
       {
           iFilledCircle(238,230,30,1000);
       }

        iShowBMP(10,680,"back.bmp");


    }
    if (play==4)
    {

     iShowBMP(0,0,"play4.BMP");
     iShowBMP2(0,0,"instructions1.BMP",16777215);
     iShowBMP(232,561,"right.BMP");
     iShowBMP(373,484,"left.BMP");
     iShowBMP(10,680,"back.bmp");
    }
    if (play==5)
    {
     iShowBMP (0,0,"play5.BMP");
     iShowBMP(10,680,"back.bmp");
     iSetColor (255,255,255);
     iFilledRectangle (310,430,220,35);
     iFilledRectangle (680,430,80,35);
     iFilledRectangle (310,380,220,35);
     iFilledRectangle (680,380,80,35);
     iFilledRectangle (310,330,220,35);
     iFilledRectangle (680,330,80,35);
     iFilledRectangle (310,280,220,35);
     iFilledRectangle (680,280,80,35);
     iFilledRectangle (310,230,220,35);
     iFilledRectangle (680,230,80,35);

     for (int i=0 ; i<5 ; i++)
     {
         char s[10];

          iSetColor (0,0,0);
          iText(380,439 - i*50 ,info[i].Sname,GLUT_BITMAP_HELVETICA_18);
          sprintf(s,"%i",info[i].Sscore);
          iText (700,439-i*50 ,s,GLUT_BITMAP_HELVETICA_18);
     }
//     sprintf(scoreshow, "High Score : %d",highscore);
//    iSetColor(255,255,255);
//    iText (478,400,scoreshow, GLUT_BITMAP_TIMES_ROMAN_24);

    }

//    if (gameresume==3)
//    {
//        iShowBMP(1020,640,"resume.bmp");
//    }

}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
	//p=mx;
	//q= my ;
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
       printf("x = %d, y= %d\n",mx,my);
		// p=mx ;
		// q=my ;

	}

//    }
    if (play==1)
    {
        //if (mx >= 412 && mx <=687 && my >= 470 && my <=550)

        if (mx >= 412 && mx <=687 && my >= 470 && my <=550)
        {
            play=21 ;
        }
        else if (mx >= 450 && mx <=650 && my >= 70 && my <=150)
        {
            exit (0) ;
        }
        else if (mx >= 339 && mx <=761 && my >= 270 && my <=350)
        {
            play=3 ;
        }
        else if (mx >= 309 && mx <=791 && my >= 170 && my <=250)
        {
            play=4 ;
        }
        else if (mx >= 367 && mx <=732 && my >= 370 && my <=450)
        {
            play=5 ;
        }

    }
    if ( play==2 || play==3 || play==4 || play==5 || play==21 || gameover==1 )
    {
        if (mx>=10 && mx<=90 && my>=680)
        {
            a=A;
            q2=N2;
            p2=N ;
            q3=N3;
            p3=N ;
            q4=N4;
            p4=N ;
            q5=N5;
            p5=N ;
            q6=N6;
            p6=N ;
            q7=N7;
            p7=N ;
            q8=N8;
            p8=N ;
     iPauseTimer(0);
	 iPauseTimer(1);
     iPauseTimer(2);
     iPauseTimer(3);
	 iPauseTimer(4);
	 iPauseTimer(5);
     iPauseTimer(6);
     iPauseTimer(7);
     iPauseTimer(8);
             score=0 ;
            play=1 ;

            gameover = 0;
            gameresume=1 ;
//            racing = 0 ;
//            if (racing==0)
//            {
//                PlaySound (NULL ,0,0);
//            }


        }
    }
    if (play==0)
    {
        if(mx)
        {

            play=1 ;
        }
    }

     if (play==3)
    {
        if (mx >= 356 && mx<=744 && my >=510 && my<=590)
        {
           dy=BEGINNER;

        }
        if (mx >= 358 && mx<=742 && my >=350 && my<=430)
        {
           dy=STANDARD;
        }
        if (mx >= 268 && mx<=832 && my >=190 && my<=270)
        {
           dy=PROFESSIONAL;
        }
    }
    if (play==21)
    {
        if (mx >=828 && mx <=1100  && my >= 0 && my <=85 )
    {
            play=2 ;
            iResumeTimer(0);
            iResumeTimer(1);
            iResumeTimer(2);
            iResumeTimer(3);
            iResumeTimer(4);
            iResumeTimer(5);
            iResumeTimer(6);
            iResumeTimer(7);
             strcpy(Fname,Entryname);
                Entryname[0]='\0';
                Indexname=0;
                input =0  ;
//
//           racing =1 ;
//
//    if (racing ==1)
//    {
//        PlaySound (carsound,NULL,SND_LOOP | SND_ASYNC );
//    }

    }
      else if (mx >= 348 && mx <= 583 && my >= 344 && my <= 390 )
       {
           input= 1;

       }



    }
    if (play==2)
    {
        if (mx >= 1020 && mx <= 1080 && my >= 640 && my <= 700)
        {
          gameresume=2 ;

        }


    if (gameresume==2)
    {
        if (mx >= 1020 && mx <= 1080 && my >= 640-80 && my <= 700-80)
        {
          gameresume=1 ;

        }
    }
//
    }
//    if(input==1)
//    {
//
//    }
    if (play==5)
    {
        Highscoreshow();
    }

}



void iKeyboard(unsigned char key) {
  if (input ==1)
  {
      if (key != '\b')
      {
          Entryname[Indexname]=key ;
          Indexname++;
          Entryname[Indexname]='\0';
      }
      else
      {
          if (Indexname <=0 )
             Indexname=0 ;
          else
             Indexname--;
          Entryname[Indexname]='\0';
      }
  }


}


void iSpecialKeyboard(unsigned char key) {
  if ((!(collision(p2,q2) || collision (p3,q3) || collision (p4,q4) || collision (p5,q5) ||collision (p6,q6)
         ||collision (p7,q7)|| collision (p8,q8))) && gameresume==1)

    if (key == GLUT_KEY_LEFT)
    {
        a-=15 ;
    }
    else if (key == GLUT_KEY_RIGHT)
    {
        a+=15;
    }


}





int main() {
	//place your own initialization codes here.
     iSetTimer (100,show) ;
     iSetTimer (100,car2) ;
	 iSetTimer (100,car3) ;
	 iSetTimer (100,car4) ;
	 iSetTimer (100,car5) ;
	 iSetTimer (100,car6) ;
	 iSetTimer (100,car7) ;
	 iSetTimer (100,car8) ;
	 iSetTimer (1000,scorefunction) ;


	 //iSetTimer (10,carcrash1);

	 iPauseTimer(0);
	 iPauseTimer(1);
     iPauseTimer(2);
     iPauseTimer(3);
	 iPauseTimer(4);
	 iPauseTimer(5);
     iPauseTimer(6);
     iPauseTimer(7);
     iPauseTimer(8);
//    load_high_score();

	yposf();
	//iSetTimer (1000,coun) ;

    if (main_sound==1)
    {
        PlaySound("projectsound.wav",NULL,SND_LOOP | SND_ASYNC);
    }


	iInitialize(1100,720, "Need for speed");

	return 0;
}


