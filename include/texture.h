/* begin of file texture.h */
#ifndef TEXTURE_H
#define TEXTURE_H

/* SDL2 headers */
#include <SDL2/SDL.h>

/* update texture definitions for clarity */
#define NUM_WALL_TEXTURES 4
#define NUM_TEXTURES NUM_WALL_TEXTURES  /* for backwards compatibility */
#define TEX_WIDTH 64
#define TEX_HEIGHT 64

typedef struct {
        SDL_Texture* texture;
        Uint32* pixels;
        int width;
        int height;
} TextureInfo;

/**
 * array to store wall texture pointers, accessible from other source files,
 * SDL_Texture is SDL's structure for storing texture data
 */
extern TextureInfo wall_textures[NUM_WALL_TEXTURES];
extern TextureInfo floor_texture;
extern TextureInfo ceiling_texture;

/**
 * function to load and initialize all wall textures,
 * takes an SDL_Renderer pointer as parameter to create textures,
 * returns 0 on success, non-zero on failure,
 */ 
int init_textures(SDL_Renderer* renderer);

/**
 * function to properly free all allocated texture memory,
 * should be called before program termination
 */
void destroy_textures(void);

/* add texture validation function */
int validate_texture(const TextureInfo* tex);

/* add function to create empty texture */
int create_empty_texture(SDL_Renderer* renderer, TextureInfo* tex, int width, int height);

/* Add function to update texture pixels */
void update_texture_pixels(TextureInfo* tex);

#endif
/* end of file texture.h */