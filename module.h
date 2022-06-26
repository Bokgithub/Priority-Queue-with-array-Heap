#ifdef WIN32

#endif
#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PERSON_NUM 7
#define MAX_SIZE 100

typedef struct _workload {
  int remains;
  int mins;
} workload;

typedef struct _sched {
  char person[PERSON_NUM];
  workload wl[PERSON_NUM];
} schedule;


// given.c
schedule* readTxt(char *input);

// Fill up these 3 functions
void makeInitialSchedule(schedule *sc, char *queue);
char doJob(schedule *sc, char *queue);
void modifySchedule(schedule *sc, char *queue, char person);


// Add your functions
int Switch(int a, schedule* sc, char* queue);
void Heaping(schedule* sc, char* queue);