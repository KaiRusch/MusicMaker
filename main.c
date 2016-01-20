#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "notes.h"

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

void clear()
{
  if(root != NULL)
    {
      NoteNode *tempPtr = root->next;
      free(root);
      root = tempPtr;
      clear();
      root = NULL;
    }
}

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
  return ((int)(deltaHeight(amplitude,frequency)*time))%amplitude;
}

void play(float length)
{
  for(int time = 0; time < length*8000; time++)
    {
      char amplitude = 0;

      NoteNode *currentNode = root;

      while(currentNode != NULL)
	{
	  amplitude += note(time,currentNode->frequency / 100, 30);
	  currentNode = currentNode->next;
	}
      
      *(musicBuffer + totalTime) = amplitude;
      totalTime++;
    }
}

int pause(float length)
{
  for(int time = 0; time < 8000*length; time++)
    {
      *(musicBuffer + totalTime) = 0;
      totalTime++;
    }
}

void aquarter_note()
{
  play(0.49);
  pause(0.01);
}

void aeighth_note()
{
  play(0.25);
  pause(0.01);
}

void asixteenth_note()
{
  play(0.115);
  pause(0.01);
}

void half_note(int frequency)
{
  add_note(frequency);
  play(0.99);
  delete_note(frequency);
  play(0.01);
}

void quarter_note(int frequency)
{
  add_note(frequency);
  play(0.49);
  delete_note(frequency);
  play(0.01);
}
void eighth_note(int frequency)
{
  add_note(frequency);
  play(0.24);
  delete_note(frequency);
  play(0.01);
}
void sixteenth_note(int frequency)
{
  add_note(frequency);
  play(0.115);
  delete_note(frequency);
  play(0.01);
}
void dotted_eighth_note(int frequency)
{
  add_note(frequency);
  play(0.365);
  delete_note(frequency);
  play(0.01);
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
  quarter_note(G4);
  quarter_note(G4);
  quarter_note(G4);
  dotted_eighth_note(DS4);
  sixteenth_note(AS4);
  quarter_note(G4);
  dotted_eighth_note(DS4);
  sixteenth_note(AS4);
  half_note(G4);
  quarter_note(D5);
  quarter_note(D5);
  quarter_note(D5);
  dotted_eighth_note(DS5);
  sixteenth_note(AS4);
  quarter_note(FS4);
  dotted_eighth_note(DS4);
  sixteenth_note(AS4);
  half_note(G4);
  quarter_note(G5);
  dotted_eighth_note(G4);
  sixteenth_note(G4);
  quarter_note(G5);
  dotted_eighth_note(FS5);
  sixteenth_note(F5);  
  sixteenth_note(E5);
  sixteenth_note(DS5);
  eighth_note(E5);
  pause(0.25);
  eighth_note(GS4);
  quarter_note(CS5);
  dotted_eighth_note(C5);
  sixteenth_note(B4);
  sixteenth_note(AS4);
  sixteenth_note(A4);
  eighth_note(AS4);
  pause(0.25);
  eighth_note(DS4);
  quarter_note(G4);
  dotted_eighth_note(DS4);
  sixteenth_note(G4);
  quarter_note(AS4);
  dotted_eighth_note(G4);
  sixteenth_note(AS4);
  half_note(D5);
   quarter_note(G5);
  dotted_eighth_note(G4);
  sixteenth_note(G4);
  quarter_note(G5);
  dotted_eighth_note(FS5);
  sixteenth_note(F5);  
  sixteenth_note(E5);
  sixteenth_note(DS5);
  eighth_note(E5);
  pause(0.25);
  eighth_note(GS4);
  quarter_note(CS5);
  dotted_eighth_note(C5);
  sixteenth_note(B4);
  sixteenth_note(AS4);
  sixteenth_note(A4);
  eighth_note(AS4);
  pause(0.25);
  eighth_note(DS4);
  quarter_note(G4);
  dotted_eighth_note(DS4);
  sixteenth_note(G4);
  quarter_note(AS4);
  dotted_eighth_note(G4);
  sixteenth_note(AS4);
  half_note(G4);


  FILE *musicFile =  fopen("out.wav","w");
  fwrite(headerBuffer, sizeof(char), bytesOfMusic + 44, musicFile);
  fclose(musicFile);

  free(headerBuffer);
  
  return 0;
}
