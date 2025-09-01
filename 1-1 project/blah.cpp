#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
#include<string>
#include "iGraphics.h"
#define screenWidth 1000
#define screenHeight 1000

int mposx,  mposy;
char str[1000];
int indexNumber=0;
int indexnumber2=0;


struct buttonCordinate
{
    int x;
    int y;
} bCordinate[3];




char bc[1][20]= {"background1.bmp"};
char button[10][15]= {"save icon.bmp","edit icon.bmp","file icon.bmp"};

int fontSizeState=-1;
int colorState=-1;
int editorState=-1;
char fileName[20];
char ch[1000];
int saveState=-1;
int openState=-1;
int fileNum=0;
char a[7][100];
char str5[1000];
char str4[1000];

void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        for(int i=0; i<3; i++)
        {
            if(mx>=bCordinate[i].x && mx<=bCordinate[i].x+64 && my>=bCordinate[i].y && my<=bCordinate[i].y+64)
            {
                if(i == 0) // save button clicked
                {


                    editorState=0;
                    saveState=-1;
                }



                editorState=i;

                if(i==1)
                {
                    FILE *fp;
                    fp = fopen("file.txt", "w");
                    if(fp != NULL)
                    {
                        fputs(str, fp);
                        fclose(fp);
                    }
                }
            }
        }
        if(editorState==0)//save
        {

            if((mx>=820 && mx<=915) && (my>=970 && my<=1000))
            {
                editorState=-1;
            }
            else
            {

            }
        }

        if (editorState == 1)//edit
        {
            /*if(fontSizeState!=0 || fontSizeState==1 || colorState==0 || colorState==1 || colorState==2 && (mx>=820 && mx<=915) && (my>=970 && my<=1000))
            {
                   editorState=1;



            }
            else */if((mx>=820 && mx<=915) && (my>=970 && my<=1000))
            {
                editorState=-1;
            }
            if((mx>=100 && mx<=170) && (my>=715 && my<=770))
            {
                fontSizeState=0;

            }
            if((mx>=100 && mx<=180) && (my>=609 && my<=654))
            {
                fontSizeState=1;
            }
            if((mx>=100 && mx<=220) && (my>=390 && my<=435))
            {
                colorState=0;
            }
            if((mx>=85 && mx<=250) && (my>=280 && my<=330))
            {
                colorState=1;
            }
            if((mx>=100 && mx<=222) && (my>=180 && my<=225))
            {
                colorState=2;
            }
        }
        if(editorState==2)
        {
            if((mx>=820 && mx<=915) && (my>=970 && my<=1000))
            {
                editorState=-1;
            }
            openState=0;
            if(openState==0)
            {
                if((mx>=150 && mx<=250) && (my>=750 && my<=780))
                {
                    fileNum=1;
                }
                if((mx>=150 && mx<=250) && (my>=665 && my<=685))
                {
                    fileNum=2;
                }
                if((mx>=150 && mx<=250) && (my>=570 && my<=585))
                {
                    fileNum=3;
                }
                if((mx>=150 && mx<=250) && (my>=465 && my<=495))
                {
                    fileNum=4;
                }
                if((mx>=150 && mx<=250) && (my>=380 && my<=400))
                {
                    fileNum=5;
                }
                if((mx>=150 && mx<=250) && (my>=285 && my<=300))
                {
                    fileNum=6;
                }
            }


        }


    }
    /*int x=mx;
    int y=my;
    printf("x=%d,y=%d\n",x,y);*/
}

void iMouseMove(int mx, int my)
{

    //place your codes here

}


void iKeyboard(unsigned char key)
{
    if(editorState==-1)
    {
        if(key != '\b')
        {
            str[indexNumber]=key;

            str[indexNumber+1]='\0';
            indexNumber++;


        }
        else
        {
            if(indexNumber>=0)
            {
                str[indexNumber-1]='\0';
                indexNumber--;
                if(indexNumber<0)
                {
                    indexNumber=0;
                }
            }

        }
    }
    if(editorState==0)
    {

        if(saveState==0)
        {
            if(key!=13)
            {
                fileName[indexnumber2]=key;

                indexnumber2++;
            }

            else
            {
                char txt[5]=".txt";
                int j=0;
                for (int i=indexnumber2+1; txt[j]!='0'; i++)
                {
                    fileName[i]=txt[j];
                    j++;
                }
                FILE *fp;
                fp = fopen(fileName, "w"); // open the file for writing
                if(fp != NULL)
                {
                    fputs(str, fp); // write the text to the file
                    fclose(fp);
                }
                saveState=0;


                fp = fopen(fileName, "r");
                if(fp != NULL)

                {
                    for(int i = 0; i < 1000; i++)
                    {
                        str4[i] = fgetc(fp);
                    }
                    fclose(fp);
                }
                FILE *fp2;
                char *comma=",";
                fp2 = fopen("filename.txt", "a");
                if(fp2 != NULL)
                {
                    fputs(fileName, fp2);
                    fputs(comma,fp2);
                    fclose(fp2);
                }
            }

        }
    }
}



void iSpecialKeyboard(unsigned char key)
{

}

void iDraw()
{
    iClear();

    if(editorState==-1)
    {
        iShowBMP(0,0,"background1.bmp");

        for(int i=0; i<3; i++)
        {
            iShowBMP2(bCordinate[i].x,bCordinate[i].y,button[i],255);
        }
        iText(20,800,str,GLUT_BITMAP_TIMES_ROMAN_24);
    }
    else if(editorState==0)
    {

        saveState=0;
        if(saveState==0)
        {
            iShowBMP(0,0,"Save.bmp");
            iText(445,770,fileName,GLUT_BITMAP_TIMES_ROMAN_24);
            iText(160,735,str4,GLUT_BITMAP_HELVETICA_18);
        }

    }

    else if(editorState==1)//edit
    {
        iShowBMP(0,0,"Edit.bmp");
        if(fontSizeState==0)
        {
            iShowBMP(0,0,"editbackground.bmp");
            FILE *fp;
            fp = fopen("file.txt", "r");
            if(fp != NULL)

            {
                for(int i = 0; i < 1000; i++)
                {
                    ch[i] = fgetc(fp);
                }
                fclose(fp);
            }

            iText(0,850,ch,GLUT_BITMAP_TIMES_ROMAN_24);
        }
        if(fontSizeState==1)
        {
            iShowBMP(0,0,"editbackground.bmp");
            FILE *fp;
            fp = fopen("file.txt", "r");
            if(fp != NULL)

            {
                for(int i = 0; i < 1000; i++)
                {
                    ch[i] = fgetc(fp);
                }
                fclose(fp);
            }

            iText(0,850,ch,GLUT_BITMAP_TIMES_ROMAN_10);
        }
        if(colorState==0)
        {
            iShowBMP(0,0,"editbackground.bmp");
            FILE *fp;
            fp = fopen("file.txt", "r");
            if(fp != NULL)

            {
                for(int i = 0; i < 1000; i++)
                {
                    ch[i] = fgetc(fp);
                }
                fclose(fp);
            }
            iSetColor(255,0,0);
            iText(0,850,ch,GLUT_BITMAP_TIMES_ROMAN_24);
        }
        if(colorState==1)
        {
            iShowBMP(0,0,"editbackground.bmp");
            FILE *fp;
            fp = fopen("file.txt", "r");
            if(fp != NULL)

            {
                for(int i = 0; i < 1000; i++)
                {
                    ch[i] = fgetc(fp);
                }
                fclose(fp);
            }
            iSetColor(0,255,0);
            iText(0,850,ch,GLUT_BITMAP_TIMES_ROMAN_24);

        }
        if(colorState==2)
        {
            iShowBMP(0,0,"editbackground.bmp");
            FILE *fp;
            fp = fopen("file.txt", "r");
            if(fp != NULL)

            {
                for(int i = 0; i < 1000; i++)
                {
                    ch[i] = fgetc(fp);
                }
                fclose(fp);
            }
            iSetColor(0,0,255);
            iText(0,850,ch,GLUT_BITMAP_TIMES_ROMAN_24);

        }


    }
    else if(editorState==2)//open
    {
        if(openState==0)
        {
            iShowBMP(0,0,"OPEN.bmp");
            FILE *fp2;
            fp2 = fopen("filename.txt", "r");
            if(fp2 != NULL)

            {
                char line[200];
                while(fgets(line,sizeof(line),fp2))
                {
                    char *token;
                    token= strtok(line,",");
                    int y=750;
                    int index=0;
                    while(token!=NULL)
                    {
                        //a[index++]=token;
                        strcpy(a[index++],token);
                        iText(150,y,token,GLUT_BITMAP_TIMES_ROMAN_24);
                        token=strtok(NULL,",");
                        y-=100;
                        if(index==7)break;
                    }
                }

            }
        }

        //openState++;
        char txt[5]=".txt";
        if(fileNum==1)
        {

            iShowBMP(0,0,"OPEN.bmp");
            FILE *fp3=fopen(a[0],"r");
            if(fp3 != NULL)

            {
                for(int i = 0; i < 1000; i++)
                {
                    str5[i] = fgetc(fp3);
                }
                fclose(fp3);
            }
            iText(150,750,a[0],GLUT_BITMAP_TIMES_ROMAN_24);
            iText(150,700,str5,GLUT_BITMAP_TIMES_ROMAN_24);
        }
        if(fileNum==2)
        {


            iShowBMP(0,0,"OPEN.bmp");
            FILE *fp3=fopen(a[1],"r");
            if(fp3 != NULL)

            {
                for(int i = 0; i < 1000; i++)
                {
                    str5[i] = fgetc(fp3);
                }
                fclose(fp3);
            }
            iText(150,750,a[1],GLUT_BITMAP_TIMES_ROMAN_24);
            iText(150,700,str5,GLUT_BITMAP_TIMES_ROMAN_24);
        }
         if(fileNum==3)
        {


            iShowBMP(0,0,"OPEN.bmp");
            FILE *fp3=fopen(a[2],"r");
            if(fp3 != NULL)

            {
                for(int i = 0; i < 1000; i++)
                {
                    str5[i] = fgetc(fp3);
                }
                fclose(fp3);
            }
            iText(150,750,a[2],GLUT_BITMAP_TIMES_ROMAN_24);
            iText(150,700,str5,GLUT_BITMAP_TIMES_ROMAN_24);
        }
        if(fileNum==4)
        {


            iShowBMP(0,0,"OPEN.bmp");
            FILE *fp3=fopen(a[3],"r");
            if(fp3 != NULL)

            {
                for(int i = 0; i < 1000; i++)
                {
                    str5[i] = fgetc(fp3);
                }
                fclose(fp3);
            }
            iText(150,750,a[3],GLUT_BITMAP_TIMES_ROMAN_24);
            iText(150,700,str5,GLUT_BITMAP_TIMES_ROMAN_24);
        }
        if(fileNum==5)
        {


            iShowBMP(0,0,"OPEN.bmp");
            FILE *fp3=fopen(a[4],"r");
            if(fp3 != NULL)

            {
                for(int i = 0; i < 1000; i++)
                {
                    str5[i] = fgetc(fp3);
                }
                fclose(fp3);
            }
            iText(150,750,a[4],GLUT_BITMAP_TIMES_ROMAN_24);
            iText(150,700,str5,GLUT_BITMAP_TIMES_ROMAN_24);
        }
        if(fileNum==6)
        {


            iShowBMP(0,0,"OPEN.bmp");
            FILE *fp3=fopen(a[5],"r");
            if(fp3 != NULL)

            {
                for(int i = 0; i < 1000; i++)
                {
                    str5[i] = fgetc(fp3);
                }
                fclose(fp3);
            }
            iText(150,750,a[5],GLUT_BITMAP_TIMES_ROMAN_24);
            iText(150,700,str5,GLUT_BITMAP_TIMES_ROMAN_24);
        }
    }


}


void iPassiveMouseMove(int mx,int my)
{
    //place your code here



}



int main()
{

    int sum =100;
    for (int i=2; i>=0; i--)
    {
        bCordinate[i].x=sum;
        bCordinate[i].y=930;
        sum+=100;
    }


    //iSetTimer(1000, printDebug);

    iInitialize(screenWidth, screenHeight, "Notepad");

    return 0;
}
