# Shapes-in-2D

There are given two planar shapes in the input. A shape may be any of:

triangle - the input consists of letter T followed by three decimal numbers (sides),
rectangle - the input consists of letter R followed by two decimal numbers (sides), or
square - the input consists of letter S followed by one decimal number (side).
The program computes the area and the perimeter of both input shapes and compares them. The result of the comparison is then printed to the standard output, the format is clear from the example runs below.

The program must validate input data. If the input is invalid, the program must detect it, it shall output an error message (see below), and terminate. If displayed, the error message must be sent to the standard output (do not send it to the error output) and the error message must be terminated by a newline (\n). The input is considered invalid, if:

the input shape is invalid (only Triangle/Rectangle/Square is valid),
there was not enough decimal numbers to describe the dimensions of the input shape,
a dimension is invalid, is not well-formatted, is negative, or zero,
the three decimal numbers do not form a valid triangle (triangle inequality),
both sides of a rectangle are the same (i.e., the shape is indeed a square).
