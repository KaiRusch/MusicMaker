#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

char *musicBuffer;
int totalTime = 0;


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
      *(musicBuffer + totalTime) = 0;
      totalTime++;
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
      *(musicBuffer + totalTime) = note(time,50.0f);
      totalTime++;
    }
}

int main()
{

  int bytesOfMusic = 8000*50;

  char *headerBuffer = malloc((44 + bytesOfMusic)*sizeof(char));
  headerBuffer[0] = 'R';
  headerBuffer[1] = 'I';
  headerBuffer[2] = 'F';
  headerBuffer[3] = 'F';
  *((uint32_t *) (headerBuffer + 4)) = 40 + bytesOfMusic; // INSERT SIZE HERE LATER
  headerBuffer[8] = 'W';
  headerBuffer[9] = 'A';
  headerBuffer[10] = 'V';
  headerBuffer[11] = 'E';
  headerBuffer[12] = 'f';
  headerBuffer[13] = 'm';
  headerBuffer[14] = 't';
  headerBuffer[15] = ' ';
  *((uint32_t *) (headerBuffer + 16)) = 16;
  *((uint16_t *) (headerBuffer + 20)) = 1;
  *((uint16_t *) (headerBuffer + 22)) = 1;
  *((uint32_t *) (headerBuffer + 24)) = 8000;
  *((uint32_t *) (headerBuffer + 28)) = 8000;
  *((uint16_t *) (headerBuffer + 32)) = 1;
  *((uint16_t *) (headerBuffer + 34)) = 8;
  headerBuffer[36] = 'd';
  headerBuffer[37] = 'a';
  headerBuffer[38] = 't';
  headerBuffer[39] = 'a';
  *((uint32_t *) (headerBuffer + 40)) = bytesOfMusic; //CALCULATE SIZE HERE

  musicBuffer = headerBuffer + 44;

  
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


  FILE *musicFile =  fopen("out.wav","w");
  fwrite(headerBuffer, sizeof(char), bytesOfMusic + 44, musicFile);
  fclose(musicFile);

  free(headerBuffer);
  
  return 0;
}
