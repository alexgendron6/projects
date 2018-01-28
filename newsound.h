

#ifndef NOTE_H_
#define NOTE_H_

class Note
{
  protected:

    int frequency;
    int duration;
    int time_delay;
    int note;
  
  public:
    Note();
    Note(int,int,int,int);
    virtual ~Note();
    int getf();
    int getdel();
    int getdur();
    int getnote();
    //const Note& operator=(const Note&);
    //int operator[](int) const;

/*
    void setHz(int);
    int getHz();

    void setDuration(int);
    int getDuration(int);


    void operator=(const Note&);
*/
};
#endif
/*
#define NOTE_B0  660   // 0
#define NOTE_C1  510   // 1
#define NOTE_CS1 770  // 2
#define NOTE_D1  380  //3
#define NOTE_DS1 320  //4
#define NOTE_E1  440  //5
#define NOTE_F1  480   //6
#define NOTE_FS1 450   //7
#define NOTE_G1  430   //8
#define NOTE_GS1 760  //9
*/
