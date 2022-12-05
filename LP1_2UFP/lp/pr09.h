#ifndef pr09_h
#define pr09_h

#include <stdio.h>
#include <stdlib.h>
#include "pr08.h"

typedef struct circle {
	POINT p;
	float radius;
} CIRCLE;

typedef struct circle_dynarray {
	CIRCLE *pfirst;
	int size;
} CIRCLE_DYNARRAY;



typedef struct rectangle {
    struct point downpt, uppt;
}RECTANGLE;

typedef struct rect_queue_node {
	RECTANGLE r;
	struct rect_queue_node * pnext;
}RECT_QUEUE_NODE;

typedef struct rect_queue {
	RECT_QUEUE_NODE * phead, * ptail;
}RECT_QUEUE;



/**
* Allocates memory for an array of circles and reads circles data from the stdin.
* @param size - number of circles to read from the stdin
* @return - a CIRCLE_DYNARRAY
*/
CIRCLE_DYNARRAY read_dyn_array_circles (int size);

/**
* Finds the circle with the greatest perimeter in a given array of circles
* @param pcdy - pointer to circle dyn array
* @return - circle with the greatest perimiter
*/
CIRCLE find_circle_greatest_perimiter (const CIRCLE_DYNARRAY *pcdy);




/**
* Allocates memory and inits a rectangle queue node
* @param rect - rectangle info
* @return pointer to the created queue node
*/
RECT_QUEUE_NODE * create_rect_queue_node (RECTANGLE rect);

/**
* Adds a rectangle node to the rectangles queue tail (FIFO).
* Enqueue at tail
* @param prq - pointer to queue of rectangles
* @* @param rect - rectangle info
*/
void enqueue_rectangle (RECT_QUEUE * prq, RECTANGLE rect);

/**
* Removes a rectangle node from the rectangles queue head (FIFO)
* Dequeue at head
* @param prq - pointer to queue of rectangles
* @return removed rectangle queue node
*/
RECT_QUEUE_NODE * dequeue_rectangle (RECT_QUEUE *prq);

/**
* Looks for a given rectangle position (starting 0 - first) within a rectangle queue.
* @param prq - pointer to rectangle queue
* @return rectangle in given pos (or empty data RECTANGLE if pos does not exist)
*/
RECTANGLE peep_rect_queue_node (const RECT_QUEUE *prq, int pos);

/**
* prints a given rectangle queue
* @param prq - pointer to rectangle queue to be printed
*/
void print_rect_queue (const RECT_QUEUE *prq);

/**
* Dequeus and prints the area of each rectangle node in a given rectangle queue
* @param prq - pointer to rectangle queue
*/
void dequeue_print_rect_queue_nodes_area (RECT_QUEUE * prq);


int main_pr09(int argc, const char * argv[]);

#endif /* pr09_h */