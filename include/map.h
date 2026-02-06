/* begin of file map.h */
#ifndef MAP_H
#define MAP_H

/**
 * define the dimensions of the game map,
 * these are preprocessor constants that will be replaced at compile time,
 * MAP_WIDTH: Number of cells across (X direction),
 * MAP_HEIGHT: Number of cells down (Y direction),
 * values must be integers as they're used for array dimensions
 */
#define MAP_WIDTH 32
#define MAP_HEIGHT 16

/**
 * declare an external 2D array that will hold the map data,
 * 'extern' keyword indicates this array is defined in another source file,
 * each cell in the array represents a wall (1) or empty space (0),
 * the array is fixed size: MAP_HEIGHT rows by MAP_WIDTH columns
 */
extern int map[MAP_HEIGHT][MAP_WIDTH];

/* function to find nearest empty space to a given position */
void find_nearest_empty_space(float* x, float* y);

/* function to validate spawn position */
int is_valid_position(float x, float y);

#endif
/* end of file map.h */