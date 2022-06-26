#include "module.h"

// build_heap
void makeInitialSchedule(schedule * sc, char *queue) {
  // TODO: intialize random queue and sort in heap structure
	for (int i = 0; i < PERSON_NUM; i++)
		queue[i + 1] = sc->person[i];

	Heaping(sc, queue);

}

// insert
void modifySchedule(schedule *sc, char *queue, char person) {
  // TODO: Reschedule the job with modified time remaining
	
	

	Heaping(sc, queue);
	for (int i = 1; i <= PERSON_NUM; i++)
	{
		if (sc->wl[queue[i]-'A'].remains == 0)
			queue[i] = '\0';
	}
	/*
	printf(">>>>>>>>modified<<<<<<<<<<<");

	for (int i = 1; i < PERSON_NUM + 1; i++)
	{
		printf("\nqueue[%d] =	%c\n", i, queue[i]);
	}
	printf("\nperson=	%c\n", person);
	*/
}

// delete_max
char doJob(schedule *sc, char *queue) {
  // TODO: Dequeue and modify the time
  //dequeue and get char
	char deq = queue[1];
	int deq_remian = sc->wl[queue[1] - 'A'].remains;
	sc->wl[queue[1] - 'A'].remains=0 ;
	Heaping(sc, queue);

	//modifify the time
	sc->wl[deq - 'A'].remains = deq_remian- sc->wl[deq - 'A'].mins;
	if (sc->wl[deq - 'A'].remains < 0)
		sc->wl[deq - 'A'].remains = 0;
	return deq;
}


// Add your functions

int Switch(int a, schedule* sc, char * queue){ //a는 queue의 idx. a의 자식노드와 a를 비교하여 switch 함.
	
	int b = 2 * a;
	int c = b + 1;
	char ap = queue[a];
	int aa = sc->wl[ap - 'A'].remains;
	char bp = queue[b];
	int bb = sc->wl[bp - 'A'].remains;
	char cp = queue[c];
	int cc = sc->wl[cp - 'A'].remains;

	if (aa >= bb && aa >= cc)
		return 0;
	else {
		if (aa < bb && aa < cc)
		{
			if (bb > cc)
			{
				queue[a] = bp;
				queue[b] = ap;
			}
			else
			{
				queue[a] = cp;
				queue[c] = ap;
			}
		}
		else if (aa < bb)
		{
			queue[a] = bp;
			queue[b] = ap;
		}
		else {
			queue[a] = cp;
			queue[c] = ap;
		}
		return 1;
	}
	
}
void Heaping(schedule* sc, char* queue)
{
	for (int i = PERSON_NUM / 2; i > 0; i--)
	{
		int switched = Switch(i,sc,queue);
	
		if(switched==1)
		{
			Heaping(sc, queue);
		}
		
	}
	
}
// ex. initQueue(schedule *sc, char *queue)
// ex. buildHeap(...) ...