<h1 align="center">
Get Next Line
</h1>

<p align="center">
This project is about programming a function that returns a line
read from a file descriptor.
</p>

## Bonus

- Develop get_next_line() using only one static variable.
- Your get_next_line() can manage multiple file descriptors at the same time.
For example, if you can read from the file descriptors 3, 4 and 5, you should be
able to read from a different fd per call without losing the reading thread of each
file descriptor or returning a line from another fd.
It means that you should be able to call get_next_line() to read from fd 3, then
fd 4, then 5, then once again 3, once again 4, and so forth.
