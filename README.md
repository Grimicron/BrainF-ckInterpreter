# Brain F*ck Interpreter
This is a lightweight runtime for the popular esolang BrainF*ck.
It is written in C and it has some implementation quirks:
- Each cell holds 1 int of data (4 bytes).
- The tape holds 30k cells.
- The loop stack can only support a loop nesting level of 1000.
- EOF is inputed with Ctrl+D and sets the cell to -1.
- Printing values outside 0-127 outputs nothing.
- A newline is represented by a 10 both in input and output.
- When the pointer overflows or underflows, it wraps around the tape.

I hope you enjoy this program! 
