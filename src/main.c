#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>
#include <stdbool.h>
#include <stdio.h>

bool is_running = false;
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

bool initialize_window(void) {
  if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
    fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
    return false;
  }

  window = SDL_CreateWindow("Island", 800, 600,
                            SDL_WINDOW_RESIZABLE | SDL_WINDOW_BORDERLESS);
  if (!window) {
    fprintf(stderr, "Error creating SDL window: %s\n", SDL_GetError());
    return false;
  }

  renderer = SDL_CreateRenderer(window, NULL);
  if (!renderer) {
    fprintf(stderr, "Error creating SDL renderer: %s\n", SDL_GetError());
    return false;
  }

  return true;
}

int main(void) {
  /* Create a SDL window */
  is_running = initialize_window();

  return 0;
}