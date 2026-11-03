/*
    Title: 02_Renderer
    
    Compilation (Windows): 
    `cl /EHsc main.cpp /I"C:\Program Files\SDL3\SDL3-3.4.16\include" /Fe:renderer.exe /link /LIBPATH:"C:\Program Files\SDL3\SDL3-3.4.16\lib\x64" SDL3.li`

    run:
    `renderer.exe`
*/

#include <iostream>
#include <SDL3/SDL.h>

int main(int argc, int* argv[]) {
    // 1. Init SDL
    SDL_Init(SDL_INIT_VIDEO);

    // 2. Create Window
    SDL_Window* window = SDL_CreateWindow("02_Renderer", 800, 600, SDL_WINDOW_RESIZABLE);

    // 3. Create Renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);

    // 4. Game Loop -> Poll Event and Display
    SDL_Event event;
    bool bDone = true;
    while(bDone) {
        // poll event
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_EVENT_QUIT) {
                bDone = false;
            }
        }

        // render
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    // 5. Destroy Resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // 6. Un-init
    SDL_Quit();

    std::cout << "[INFO] Application closed successfully" << std::endl;

    return 0;
}
