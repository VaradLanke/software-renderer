/* 
    Title: 03-EventHandling

    Compilation : 
    cl.exe /EHsc main.cpp /I"C:/Program Files/SDL3/SDL3-3.4.16/include" /Fe:renderer.exe /link /LIBPATH:"C:/Program Files/SDL3/SDL3-3.4.16/lib/x64" SDL3.lib

    Run:
    renderer.exe
*/

#include <iostream>
#include <SDL3/SDL.h>

// global variables
bool bDone = true;

int main(int argc, int* argv[]) {

    //function declarations
    void handle_event(SDL_Event& type);

    // 1. Init
    SDL_Init(SDL_INIT_VIDEO);

    // 2. Create Window
    SDL_Window* window =SDL_CreateWindow("03-EventHandling", 800, 600, SDL_WINDOW_RESIZABLE);

    // 3. Game loop
    SDL_Event event;
    while(bDone) {
        while(SDL_PollEvent(&event)) {
            handle_event(event);
        }
    }

    // 4. Destroy resources
    SDL_DestroyWindow(window);

    // 5. Un-init
    SDL_Quit();

    std::cout << "[INFO] Application closed successfully" << std::endl;

    return 0;
}

void handle_event(SDL_Event& event) {
    switch(event.type) {
        case SDL_EVENT_QUIT:
            std::cout << "[INFO] Event: SDL_EVENT_QUIT" << std::endl;
            bDone = false;
            break;

        // Keyboard
        case SDL_EVENT_KEY_DOWN: /* Key Press */
            switch (event.key.key) {
                case SDLK_Q:
                case SDLK_ESCAPE:
                    std::cout << "[INFO] Terminating the application..." << std::endl;
                    bDone = false;
                    break;
            }
            //std::cout << "[INFO] Event: SDL_EVENT_KEY_DOWN" << std::endl;
            break;

        // Mouse
        case SDL_EVENT_MOUSE_BUTTON_DOWN:
            switch(event.button.button) {
                case SDL_BUTTON_LEFT:
                    std::cout << "[INFO] Event: SDL_BUTTON_LEFT" << std::endl;
                    break;
                case SDL_BUTTON_MIDDLE:
                    std::cout << "[INFO] Event: SDL_BUTTON_MIDDLE" << std::endl;
                    break;
                case SDL_BUTTON_RIGHT:
                    std::cout << "[INFO] Event: SDL_BUTTON_RIGHT" << std::endl;
                    break;
            }
            //std::cout << "[INFO] Event: SDL_EVENT_MOUSE_BUTTON_DOWN" << std::endl;
            break;

        case SDL_EVENT_MOUSE_WHEEL:
            std::cout << "[INFO] Event: SDL_EVENT_MOUSE_WHEEL" << std::endl;
            break;
        default:
            break;
    }
}
