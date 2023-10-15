CSC322: Lab 3

CSC322: Lab 3
==================

* * *

This is your cache lab. It consists of implementing a cache simulator given various parameters, and then watching it perform under different circumstances. To make things simple, you'll only be dealing with reads.

When your simulator starts, it should take from **stdin** (so no files are opened/closed/used in the project code) input in the following format:

The first four lines contain the fundamental parameters of the cache, one per line. All four are integers:  
S  
E  
B  
m  

The next line contains the replacement policy. The only ones you need are LFU and LRU. The replacement policy will be entered as either LFU or LRU, so read three chars here.

The next two lines contains the fundamental parameters of the hardware: the hit time (h) and the miss penalty (p). Both are integers:  
h  
p  

That was the input. The runtime information follows immediately. All further lines contain integer addresses that your simulation attempts to read from main memory through the cache, one per line. The simulation stops when the "address" you read is -1.

You should output all information to **stdout** in the following format:

For each address you read (except the final -1), output a line containing the address itself (in hex form), followed by a space, followed by a single character: H for cache hit or M for cache miss.

Once you read -1, output on a single line the miss rate of the cache that you have calculated, followed by a space, followed by the total cycles spent during the simulation. Remember to complete this last output line with a newline character, then exit the simulation.

Grading policy for the homework: 5 for correct implementation of a direct-mapped cache, 5 for correct implementation of a set associative cache, 5 for correct implementation of a fully associative cache.

You should submit your source file(s) to the Blackboard dropbox. Your code should compile with the gcc on pi. If it requires any command-line parameters passed to gcc when compiling, specify them in the comment box in Blackboard when you make your submission.

**NB: you must demonstrate** your working homework to me in order to receive a grade. This must happen within a week of the homework submission deadline. There will be classes set aside for demo sessions.

* * *

Example input 1: [here](hw03input). Example output 1: [here](hw03output).  

Example input 2: [here](hw03input2). Example output 2: [here](hw03output2).  

Example input 3: [here](hw03input3). Example output 3: [here](hw03output3).  

Example input 4: [here](hw03input4). Example output 4: [here](hw03output4).
