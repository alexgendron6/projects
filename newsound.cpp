
#include "newsound.h"

using namespace std;

Note::Note()
{
 
}

Note::Note(int notes, int f, int dur, int del)
{
 frequency=f;
 duration=dur;
 time_delay=del;
 note=notes;
}

int Note::getf()
{
  return frequency;
}
int Note::getdel()
{
  return time_delay;
}
int Note::getdur()
{
  return duration;
}
int Note::getnote()
{
  return note;
}

/*
const Note& Note::operator=(const Note& j)
{
  if(&j != this)
  {
    for(int i = 0; i<4; i++)
    {
      ptr[i]=j[i];
    }
  }
  return *this;
}

int Note::operator[](int sub) const//overloaded subscript operator (nonconstant objects)
{
  
  if (sub < 0 || sub >= 4) //check if subscript position, in the array, exists
  {
    return 0;
  }
  return ptr[sub]; //returns the int within that position of the array
}

*/

Note::~Note()
{
  
}
  
