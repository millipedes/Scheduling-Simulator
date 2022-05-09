# :tropical_fish: CPU Simulator
For a much more deatiled explanation of what this project is/does, please see
the `documentation/` directory, particularly the report.pdf file and the
comments among the code.
## :trophy: Project Description/Goal
This project was designed to give users an interface to experiment with
scheduling algorithms.

This is a subject that personally I am interested in but have found no other
solution than to make a full new environment.  I read the manual for the linux
kernel sceheduler and attempted to just see how deeply in the code base the CFS
scheduler was. Turns out pretty deep (13+ source files and a bunch of instances
of it elsewhere with several data parameters going in and out to keep track of).
It is close to being acceptable for testing because of the ability of processes
to inherit a scheduling attribute from its parent process (i.e. have
systemd/runit/etc. just put a different scheduling algorithm on pid 1) but this
doesn't work as porting scheduling algorithm specific data across branches would
be a nightmare. I also attempted to look at the BSD kernel scheduler but got
even less far in that endevour. Thus I have written a toy environment with easy
extensibility by the user to test whatever scheduling algorithm they wish.


## :floppy_disk: Installation
Technically just a binary creation. Assuming your system has:
- GNU Make
- gcc
Then you can make the project by:
```
$ git clone https://github.com/millipedes/Scheduling-Simulator.git
$ cd Scheduling-Simulator/
$ mkdir bin
$ make
```
Which will generate a binary. To conduct different tests, I would suggest
checking out the write_data.c file, particularly the conduct_test function.

:microscope: Encouraged Extensibility
The following parameters can be verified and the results can be observed:
- MAX_NG_PROCS - The maximum number of new processes generated for each time
  quantum.
- MAX_PROC_WORK - The maximum amount of work that a process can be asigned until
  its completion.
- MEM_PROP - The proportion of IO to MEMORY related processes. This feature is
  still experimental and has no effect.
- P_LIST_INITIAL_SIZE - The initial size of the process list.
- THREAD_NO - The number of threads that each CPU has.
- THREAD_WORK - The amount of work that each thread performs in a given time
  quantum.

