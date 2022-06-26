#include "module.h"

schedule *readTxt(char *input) {
  FILE *fp = fopen(input, "r");
  char buf[255];
  char *tok;
  int idx = 0;

  schedule *sc = malloc(sizeof(schedule));

  while (fgets(buf, 255, fp) != NULL) {
    tok = strtok(buf, " ");
    sc->person[idx] = *tok;

    tok = strtok(NULL, " ");
    sc->wl[idx].remains = atoi(tok);

    tok = strtok(NULL, " ");
    sc->wl[idx].mins = atoi(tok);

    idx++;
  }

  fclose(fp);
  return sc;
}