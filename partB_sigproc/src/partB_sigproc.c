#include <stdio.h>
#include <stdlib.h>

/* Function Declaration */
void signalAction(int);

/* Variable Declaration */
sig_atomic_t usr1Happened = 0;
int numChildren = 0;

int main(void) {
	// process id for future child
	pid_t cpid;
	// process id for parent (not getppid() or use you get QCONN)
	const pid_t ppid = getpid();

	printf("Enter the number of children:\n");

	scanf("%d", &numChildren);

	printf("\n");
	printf("PID = %d: Parent running...\n", ppid);
	// fork the process so that the code below 'fork()' is split into two
	for(int i = 0; i < numChildren; i++) {
		if(fork() == 0) {
			printf("PID = %d: Child running...\n", getpid());
			while(usr1Happened == 0) {
				// execute function when kill -s SIGUSR1 PID received
				signal(SIGUSR1, signalAction);
			}
			exit(EXIT_SUCCESS);
		}
	}

	for(int i = 0; i < numChildren; i++) {
		wait(NULL);
	}

	printf("PID = %d: Children finished, parent exiting.", ppid);
	return EXIT_SUCCESS;
}


/*
 * Function executes on kill command with -s SIGUSR PID .
 * Will not execute with only kill PID
 */
void signalAction(int signalNumber) {
	if(signalNumber == SIGUSR1) {
		usr1Happened++;
		printf("PID = %d: Child received USR1...\n", getpid());
		printf("PID = %d: Child exiting...\n", getpid());
	}
}
