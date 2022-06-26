#include "module.h"

int main() {
  // array for implementing priority queue
  char *queue = calloc(MAX_SIZE, sizeof(char));
  schedule *sc = readTxt("input.txt");

  makeInitialSchedule(sc, queue);

  char person;
  while (queue[1] != '\0') { // NULL

    person = doJob(sc, queue);
    if (sc->wl[person - 'A'].remains > 0)
      printf("%c has done the job. %d minutes left.\n", person,
             sc->wl[person - 'A'].remains);
    else
      printf("%c has finally done the job.\n", person);
    modifySchedule(sc, queue, person);

    // printf("                  %c: %d\n", queue[1], priority(sc, queue[1]));
    // printf("        %c: %d                %c: %d\n", queue[2],
    //        priority(sc, queue[2]), queue[3], priority(sc, queue[3]));
    // printf("%c: %d      %c: %d      %c: %d        %c: %d\n", queue[4],
    //        priority(sc, queue[4]), queue[5], priority(sc, queue[5]), queue[6],
    //        priority(sc, queue[6]), queue[7], priority(sc, queue[7]));

    // printf("\n\n\n\n\n");
  }

  free(sc);
  free(queue);
  return 0;
}