/* Standard C Library */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

/* Project Headers */
#include "log_utils.h"
#include "map.h"

/**
 * Map representation:
 * 0 = Empty space (corridor)
 * 1-0 = Different wall textures
 */

/* maybe change, to map is only in map.json files */ 
int map[MAP_HEIGHT][MAP_WIDTH] = {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int is_valid_position(float x, float y) 
{
        int mapX = (int)x;
        int mapY = (int)y;

        if (mapX < 0 || mapX >= MAP_WIDTH || mapY < 0 || mapY >= MAP_HEIGHT)
                return 0;

        return map[mapY][mapX] == 0;
}

void find_nearest_empty_space(float* x, float* y) 
{
        int currentX = (int)*x;
        int currentY = (int)*y;
        float minDistance = INFINITY;
        float bestX = *x;
        float bestY = *y;

        /* Search in increasing spiral pattern */
        for(int radius = 1; radius < MAP_WIDTH && radius < MAP_HEIGHT; radius++) {
                for(int dx = -radius; dx <= radius; dx++) {
                        for(int dy = -radius; dy <= radius; dy++) {
                                int testX = currentX + dx;
                                int testY = currentY + dy;

                                if (testX >= 0 && testX < MAP_WIDTH && 
                                    testY >= 0 && testY < MAP_HEIGHT && 
                                    map[testY][testX] == 0) {

                                        float distance = sqrtf((float)(dx * dx + dy * dy));
                                        if (distance < minDistance) {
                                                minDistance = distance;
                                                bestX = testX + 0.5f; /* Center of the cell */
                                                bestY = testY + 0.5f;
                                        }
                                }
                        }
                }
                /* when found a valid position, stop searching */
                if (minDistance != INFINITY) break;
        }

        *x = bestX;
        *y = bestY;
}