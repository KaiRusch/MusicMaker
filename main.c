#include <stdio.h>
#include <stdlib.h>

float deltaHeight(float amplitude, float frequency)
{
  return amplitude/(8000.0f/frequency);
}

int note(int time, float frequency, int amplitude)
{
  int preMod = (int)((float)time*deltaHeight(amplitude,frequency));
  return preMod%amplitude;
}
void pause(float length)
{
  for(int time = 0; time < length*8000; time++)
    {
      putchar(0);
    }
}
int c4(int time, float amplitude)
{
  note(time,261.63f,amplitude);
}
int bb4(int time, float amplitude)
{
  note(time,466.16f,amplitude);
}
int b4(int time, float amplitude)
{
  note(time,493.88f,amplitude);
}
int eb4(int time, float amplitude)
{
  note(time,311.13f,amplitude);
}
int e4(int time, float amplitude)
{
  note(time,329.63f,amplitude);
}
int gb4(int time, float amplitude)
{
  note(time,369.99f,amplitude);
}
int g4(int time, float amplitude)
{
  note(time,392.00f,amplitude);
}
int gs4(int time, float amplitude)
{
  note(time,415.3f,amplitude);
}
int a4(int time, float amplitude)
{
  note(time,440.00f,amplitude);
}
int c5(int time, float amplitude)
{
  note(time,523.25f,amplitude);
}
int cs5(int time, float amplitude)
{
  note(time,554.37f,amplitude);
}
int d5(int time, float amplitude)
{
  note(time,587.33f,amplitude);
}
int eb5(int time, float amplitude)
{
  note(time,622.25f,amplitude);
}
int e5(int time, float amplitude)
{
  note(time,659.25f,amplitude);
}
int f5(int time, float amplitude)
{
  note(time,698.46f,amplitude);
}
int gb5(int time, float amplitude)
{
  note(time,739.99f,amplitude);
}
int g5(int time, float amplitude)
{
  note(time,783.99f,amplitude);
}


void play_note(float length, int (*note)(int time, float amplitude))
{
  for(int time = 0; time < length*8000; time++)
    {
      putchar(note(time,50.0f));
    }
}

int main()
{

  play_note(0.5,g4);
  pause(0.1);
  play_note(0.5,g4);
  pause(0.1);  
  play_note(0.5,g4);
  pause(0.1);
  play_note(0.3,eb4);
  pause(0.1);    
  play_note(0.15,bb4);
  pause(0.1);
  
  play_note(0.5,g4);
  pause(0.1);  
  play_note(0.3,eb4);
  pause(0.1);    
  play_note(0.15,bb4);
  pause(0.1);      
  play_note(1,g4);
  pause(0.1);
  
  play_note(0.5,d5);
  pause(0.1);      
  play_note(0.5,d5);
  pause(0.1);      
  play_note(0.5,d5);
  pause(0.1);
  play_note(0.3,eb5);
  pause(0.1);
  play_note(0.15,bb4);

  pause(0.1);
  play_note(0.5,gb4);
  pause(0.1);
  play_note(0.3,eb4);
  pause(0.1);    
  play_note(0.15,bb4);
  pause(0.1);
  play_note(1,g4);
  
  pause(0.1);
  play_note(0.5,g5);
  pause(0.1);
  play_note(0.3,g4);
  pause(0.1);
  play_note(0.15,g4);
  pause(0.1);
  play_note(0.5,g5);
  pause(0.1);
  play_note(0.3,gb5);
  pause(0.1);
  play_note(0.15,f5);

  pause(0.1);
  play_note(0.125,e5);
  pause(0.03);
  play_note(0.125,eb5);
  pause(0.03);
  play_note(0.25,e5);
  pause(0.25);
  play_note(0.25,gs4);
  pause(0.1);
  play_note(0.5,cs5);
  pause(0.1);
  play_note(0.3,c5);
  pause(0.1);
  play_note(0.15,b4);
  pause(0.1);
  
  play_note(0.125,bb4);
  pause(0.03);
  play_note(0.125,a4);  
  pause(0.03);
  play_note(0.25,bb4);
  pause(0.25);
  play_note(0.25,eb4);
  pause(0.1);
  play_note(0.5,gb4);
  pause(0.1);
  play_note(0.3,eb4);
  pause(0.1);
  play_note(0.15,gb4);
  pause(0.1);
  play_note(0.5,bb4);

  pause(0.1);
  play_note(0.3,g4);
  pause(0.1);
  play_note(0.15,bb4);
  pause(0.1);
  play_note(1,d5);

  pause(0.1);
  play_note(0.5,g5);
  pause(0.1);
  play_note(0.3,g4);
  pause(0.1);
  play_note(0.15,g4);
  pause(0.1);
  play_note(0.5,g5);
  pause(0.1);
  play_note(0.3,gb5);
  pause(0.1);
  play_note(0.15,f5);

  pause(0.1);
  play_note(0.125,e5);
  pause(0.03);
  play_note(0.125,eb5);
  pause(0.03);
  play_note(0.25,e5);
  pause(0.25);
  play_note(0.25,gs4);
  pause(0.1);
  play_note(0.5,cs5);
  pause(0.1);
  play_note(0.3,c5);
  pause(0.1);
  play_note(0.15,b4);
  pause(0.1);
  
  play_note(0.125,bb4);
  pause(0.03);
  play_note(0.125,a4);  
  pause(0.03);
  play_note(0.25,bb4);
  pause(0.25);
  play_note(0.25,eb4);
  pause(0.1);
  play_note(0.5,gb4);
  pause(0.1);
  play_note(0.3,eb4);
  pause(0.1);
  play_note(0.15,gb4);
  pause(0.1);
  
  play_note(0.5,g4);
  pause(0.1);
  play_note(0.3,eb4);
  pause(0.1);
  play_note(0.15,bb4);
  pause(0.1);
  play_note(1,g4);
  
  return 0;
}
