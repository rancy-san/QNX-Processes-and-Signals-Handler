## Processes and Signals (Interrupt Signal Handler) - PID Termination and fork()

### Requirements

QNX
Momentics IDE

### Use

QNX must be online/turned on.
Hook the QNX IP address to Momentics IDE
Compile code in Momentics IDE
Run program in Momentics, or run program in QNX.

### Description

partA_sighandler demonstrates the handling of signals sent from another program, and the partB_sigproc creates child processes which each handle signals sent by a third application.