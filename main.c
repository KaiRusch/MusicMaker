#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


char *musicBuffer;
int totalTime = 0;

typedef struct Note_Node
{
  int frequency;
  struct Note_Node * next;
} NoteNode;

NoteNode *root = NULL;

void add_note(int frequency)
{
  NoteNode *note = (NoteNode *)malloc(sizeof(NoteNode));
  note->next = root;
  note->frequency = frequency;
  root = note;
  return;
};

void delete_note(int frequency)
{
  if(root == NULL)
    {
      return;
    }
  else if(root->frequency == frequency)
    {
      NoteNode *tempPtr = root->next;
      free(root);
      root = tempPtr;
      return;
    }

  NoteNode *currentNode = root;

  while(currentNode != NULL)
    {
      if(currentNode->next == NULL)
	{
	  return;
	}
      else if(currentNode->next->frequency == frequency)
	{
	  NoteNode *tempPtr = currentNode->next->next;
	  free(currentNode->next);
	  currentNode->next = tempPtr;
	  return;
	}
      else
	{
	  currentNode = currentNode->next;
	}
    }
  return;
}

float deltaHeight(float amplitude, float frequency)
{
  return amplitude/(8000.0f/frequency);
}

int note(int time, float frequency, int amplitude)
{
  int preMod = (int)((float)time*deltaHeight(amplitude,frequency));
  return preMod%amplitude;
}

void play(float length)
{
  for(int time = 0; time < length*8000; time++)
    {
      char amplitude = 0;

      NoteNode *currentNode = root;

      while(currentNode != NULL)
	{
	  amplitude += note(time,currentNode->frequency / 100, 20);
	  currentNode = currentNode->next;
	}
      
      *(musicBuffer + totalTime) = amplitude;
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
 

  /* INSERT MUSIC HERE */

  
  /*  
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
  play_note(1,g4);*/


  FILE *musicFile =  fopen("out.wav","w");
  fwrite(headerBuffer, sizeof(char), bytesOfMusic + 44, musicFile);
  fclose(musicFile);

  free(headerBuffer);
  
  return 0;
}
