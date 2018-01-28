#include "newsound.h"
// anodes
int row[] = {6,7,8,9,10,11};
// cathodes
int col[] = {2,3,4,5};
//buzzer
int buzz = 13;
//buttons
int but1=0;
int but2=1;
int but3=12;



Note A(0,660,100, 150);
Note B(0,660,100,300);
Note C(0,660,100, 300);
Note D(1,510,100, 100);
Note E(0,660,100,300);
Note FF(2,770,100,300);
Note G(3,380,100,575);
Note H(4,510,100,450);
Note I(0,380,100,400);
Note J(1,320,100,500);
Note K(2,440,100,300);
Note L(3,480,80,330);
Note M(4,450,100,150);
Note N(5,430,100,300);
Note O(0,380,100,200);
Note P(1,660,80,200);
Note Q(2,760,50,150);
Note R(3,860,100,300);
Note S(0,700,80,150);
Note T(1,760,50,350);
Note U(0,660,80,300);
Note V(2,520,80,150);
Note W(3,580,80,150);
Note X(0,480,80,500);
Note Y(1,510,100,450);
Note Z(2,380,100,400);
Note AA(3,320,100,500);
Note BB(4,440,100,300);
Note CC(5,480,80,330);
Note DD(6,450,100,150);
Note EE(7,430,100,300);
Note FFF(8,380,100,200);
Note GG(0,660,80,200);
Note HH(2,760,50,150);
Note II(1,860,100,300);
Note JJ(3,700,80,150);
Note KK(4,760,50,350);
Note LL(5,660,80,300);
Note MM(0,520,80,150);
Note NN(1,580,80,150);
Note OO(2,480,80,500);
Note PP(6,500,100,300);
Note QQ(4,760,100,100);
Note RR(0,720,100,150);
Note SS1(2,680,100,150);
Note TT(3,620,150,300);
Note UU(4,650,150,300);
Note VV(0,380,100,150);
Note WW(9,430,100,150);
Note XX(2,500,100,300);
Note YY(3,430,100,150);
Note ZZ(0,500,100,100);
Note AAA(5,570,100,220);
Note BBB(1,500,100,300);
Note CCC(4,760,100,100);
Note DDD(0,720,100,150);
Note EEE(1,680,100,150);
Note FFFF(6,620,150,300);
Note GGG (8,650,200,300);
Note HHH(0,1020,80,300);
Note III(1,1020,80,150);
Note JJJ(2,1020,80,300);
Note KKK(3,380,100,300);
Note LLL(5,500,100,300);
Note MMM(7,760,100,100);
Note NNN(2,720,100,150);
Note OOO(3,680,100,150);
Note PPP(0,620,150,300);
Note QQQ(6,650,150,300);
Note RRR(9,380,100,150);
Note SSS(3,430,100,150);
Note TTT(0,500,100,300);
Note UUU(4,430,100,150);
Note VVV(5,500,100,100);
Note WWW(6,570,100,420);
Note XXX(7,585,100,450);
Note YYY(8,550,100,420);
Note ZZZ(9,500,100,360);




Note MarioSong[78]={A,B,C,D,E,FF,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,AA,BB,CC,DD,EE,FFF,GG,HH,II,JJ,KK,LL,MM,NN,OO,PP,QQ,RR,SS1,TT,UU,VV,WW,XX,YY,ZZ,AAA,BBB,CCC,DDD,EEE,FFFF,GGG,HHH,III,JJJ,KKK,LLL,MMM,NNN,OOO,PPP,QQQ,RRR,SSS,TTT,UUU,VVV,WWW,XXX,YYY,ZZZ};



void setup()
{
  
  for (int i=0;i<6;i++)
  {
    pinMode(row[i], OUTPUT);
  } 
  for (int i=0;i<4;i++)
  {
    pinMode(col[i], OUTPUT);
  }
  for(int i=0;i<6;i++)
  {
    for(int j=0;j<4;j++)
    { 
      LEDOff(i,j);
    }
  }
  pinMode(buzz, OUTPUT);
  pinMode(but1, INPUT);
  pinMode(but2, INPUT);
  pinMode(but3, INPUT);
  pinMode(A5, INPUT);
  
}


void loop()
{
  int score= 0;
  int sum = 0;
  int listsize=78;
  
  
  //Read Sounds from list
  for(int i=0;i<listsize;i++)
  {
    int temp = ReadSound(MarioSong[i]);
    sum += temp;
  }
  sum -= 80;
  DisplayScore(sum);
  delay(7000);
  sum=0;
  
}

void DisplayScore(int score)
{
    
    if(score>0)
    {
      for(int i=0; i<4; i++)
            {
              LEDOn(5,i);
            }
    }       
    if(score>20)
    {
      for(int i=0; i<4; i++)
            {
              LEDOn(4,i);
            }
    }
    if(score>35)
    {
      for(int i=0; i<4; i++)
            {
              LEDOn(3,i);
            }
    }
    if(score>50)
    {
      for(int i=0; i<4; i++)
            {
              LEDOn(2,i);
            }
    }
    if(score>55)
    {
      for(int i=0; i<4; i++)
            {
              LEDOn(1,i);
            }
    }
    if(score>60)
    {
      for(int i=0; i<4; i++)
            {
              LEDOn(0,i);
            }
    }
  }       


int ReadSound(Note song)
{
  int score;
  int note;
  note = song.getnote();
  int note_delay;
  note_delay = song.getdel();
  int frequency;
  frequency = song.getf();
  int duration;
  duration = song.getdur();
  
  
  switch(note)
  {
    case 0: score = LEDChain(0, 0, note_delay, frequency, duration);
            break;
    case 1: score = LEDChain(1, 1, note_delay, frequency, duration);
            break;
    case 2: score = LEDChain(2, 2, note_delay, frequency, duration);
            break;
    case 3: score = LEDChain(3, 3, note_delay, frequency, duration);
            break;
    case 4: score = LEDChain(0, 1, note_delay, frequency, duration);
            break;
    case 5: score = LEDChain(0, 2, note_delay, frequency, duration);
            break;
    case 6: score = LEDChain(0, 3, note_delay, frequency, duration);
            break;
    case 7: score = LEDChain(1, 2, note_delay, frequency, duration);
            break;
    case 8: score = LEDChain(1, 3, note_delay, frequency, duration);
            break;
    case 9: score = LEDChain(2, 3, note_delay, frequency, duration);
            break;
    case 10: delay(500); //if nothing, delay before next sound check  

                                              
           
    
  }
  return score;
}

int LEDChain(int col1, int col2, int note_delay, int frequency, int duration) //light column one after the other
{
  int tempsum = 0;
  if(col1 == col2)
  {
     for(int i=0;i<6;i++)
      {
        LEDOn(i,col1);
        delay(note_delay/6);
        LEDOff(i,col1);
      }
        
        
  }
  if(col1 != col2)
  {
    for(int i=0;i<6;i++)
      {
        LEDOn(i,col1);
        LEDOn(i,col2);
        delay(note_delay/6);
        LEDOff(i,col1);
        LEDOff(i,col2);
      }
  }
  if(col1==0&&digitalRead(but1)==HIGH)
  {
    tempsum++;
  }
  if(col1==1&&digitalRead(but2)==HIGH)
  {
    tempsum++;
  }
  if(col1==2&&digitalRead(but3)==HIGH)
  {
    tempsum++;
  }
  if(col1==3&&digitalRead(A5)==HIGH)
  {
    tempsum++;
  }
  if(col2==0&&digitalRead(but1)==HIGH)
  {
    tempsum++;
  }
  if(col2==1&&digitalRead(but2)==HIGH)
  {
    tempsum++;
  }
  if(col2==2&&digitalRead(but3)==HIGH)
  {
    tempsum++;
  }
  if(col2==3&&digitalRead(A5)==HIGH)
  {
    tempsum++;
  }
  tone(buzz,frequency,duration); 
  return tempsum;
}

void LEDOff(int i, int j)//turn specific led in matrix off
{
  digitalWrite(row[i], LOW);
  digitalWrite(col[j], HIGH);
}

void LEDOn(int i, int j)//turn specific led in matrix on
{
  digitalWrite(row[i], HIGH);
  digitalWrite(col[j], LOW);
}


