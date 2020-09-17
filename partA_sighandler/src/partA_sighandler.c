#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/* Function Declaration */
void signalAction(int);

/* Variable Declaration */
volatile sig_atomic_t usr1Happened = 0;

int main(void) {

	printf("PID = %d : Running...\n", getpid());

	// loop until signal from QNX Neutrino sent
	do {
		// execute function when kill -s SIGUSR1 PID received
		signal(SIGUSR1, signalAction);
	} while(usr1Happened == 0);

	return EXIT_SUCCESS;
}

/*
 * Function executes on kill command with -s SIGUSR PID .
 * Will not execute with only kill PID
 */
void signalAction(int signalNumber) {
	if(signalNumber == SIGUSR1) {
		printf("PID = %d : Received USR1...\n", getpid());
		printf("PID = %d : Exiting...\n", getpid());
		usr1Happened = 1;
	}
}
