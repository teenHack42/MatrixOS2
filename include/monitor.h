/*  MatrixOS2 - monitor.h
//  basic monitor commands
*/
#ifndef MONITOR_H
#define MONITOR_H

// Write a single character out to the screen.
void monitor_put(char c);

// Clear the screen to all black.
void monitor_clear();

// Output a null-terminated ASCII string to the monitor.
void monitor_write(char *c);

#endif//MONITOR_H
