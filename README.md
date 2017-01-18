# FCFS-Simulator
This programming project is to simulate a few CPU scheduling policies
in C/C++ program to implement a simulator.The simulator selects a task to
run from ready queue based on the FCFS scheduling algorithm. Since the project
intends to simulate a CPU scheduler, so it does not require any actual process
creation or execution. When a task is scheduled, the simulator will simply print
out what task is selected to run at a time. It outputs the way similar to Gantt
chart style.

The simulator first reads task information from
input file and stores all data in a data structure. Then it starts simulating one
scheduling algorithm in a time-driven manner. At each time unit (or slot), it
adds any newly arrived task(s) into the ready queue and calls a specific 
scheduler algorithm in order to select appropriate task from ready queue. When
a task is chosen to run, the simulator prints out a message indicating what
process ID is chosen to execute for this time slot. If no task is running (i.e.
empty ready queue), it prints out an “idle” message. Before advancing to the
next time unit, the simulator should update all necessary changes in task and
ready queue status 
