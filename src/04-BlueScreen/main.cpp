/*
    Title: 04-BlueScreen (Using Texture)
*/

#include <iostream>
#include <SDL3/SDL.h>

// global variables
bool bDone = true;
constexpr int WIDTH = 800;
constexpr int HEIGHT = 600;
uint32_t framebuffer[WIDTH*HEIGHT] = {};

int main(int argc, int* argv[]) {

    // function declarations
    void handleEvent(SDL_Event&);

    // 1. Init
    SDL_Init(SDL_INIT_VIDEO);

    // 2. Create Window
    SDL_Window* window = SDL_CreateWindow("04-BlueScreen", WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);

    // 3. Create Renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);

    // 4. Create Texture
    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_XRGB8888,SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);

    SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);

    // 5. Game loop
    SDL_Event event;
    while(bDone) {
        // events
        while(SDL_PollEvent(&event)) {
            handleEvent(event);
        }

        // update framebuffer : fill all with blue color
        for(size_t i = 0; i < static_cast<size_t>(WIDTH*HEIGHT); ++i) {
            framebuffer[i] = 0x0000ff;
        }

        // update texture
        SDL_UpdateTexture(texture, nullptr, framebuffer, WIDTH * sizeof(uint32_t));

        //render
        SDL_RenderClear(renderer);
        SDL_RenderTexture(renderer, texture, nullptr, nullptr);
        SDL_RenderPresent(renderer);
    }

    // 6. Destroy Resources
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // 7. Un-Init
    SDL_Quit();

    return 0;
}

void handleEvent(SDL_Event& event) {
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
