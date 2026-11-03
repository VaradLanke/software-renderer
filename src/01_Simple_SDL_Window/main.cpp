/*
    Title: 01_Simple_SDL_Window | SDL : Simple Direct-Media Layer
    
    Compilation (Windows): 
    `cl /EHsc main.cpp /I"C:\Program Files\SDL3\SDL3-3.4.16\include" /Fe:renderer.exe /link /LIBPATH:"C:\Program Files\SDL3\SDL3-3.4.16\lib\x64" SDL3.li`

    run:
    `renderer.exe`
*/

#include <iostream>
#include <SDL3/SDL.h>

int main() {

    // 1.Init
    SDL_Init(SDL_INIT_VIDEO);

    // 2. Create Window
    SDL_Window* window = SDL_CreateWindow("SIMPLE SDL WINDOW", 800, 600, 0);

    // 3. Game Loop
    SDL_Event event;
    bool bDone = true;
    while(bDone) {
        // handle event
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_EVENT_QUIT) { // close button handler
                bDone = false;
            }
        }
    }

    // 4. Destroy Resources
    SDL_DestroyWindow(window);

    // 5. Un-Init
    SDL_Quit();

    std::cout << "[INFO] Application sucessfully closed" << std::endl;

    return 0;
}
