#include <iostream>
#include <SDL3/SDL.h>
#include <cmath>

constexpr unsigned int WIDTH = 800;
constexpr unsigned int HEIGHT = 600;

bool bDone = true;
bool bFullscreen = false;
uint32_t frameBuffer[WIDTH*HEIGHT] = {};

// SDL related globla variables
SDL_Window* window;
SDL_Renderer* renderer;
SDL_Texture* texture;

int main() {

    // function declarations
    void handleEvent(SDL_Event&);
    void clearFrameBuffer(uint32_t);
    void drawLine(int, int, int, int);

    // 1. Init
    SDL_Init(SDL_INIT_VIDEO);

    // 2. Window
    window = SDL_CreateWindow("06-Line", WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);

    // 3. Renderer
    renderer = SDL_CreateRenderer(window, nullptr);

    // 4. Texture
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_XRGB8888, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);

    clearFrameBuffer(0x0000ff);/* Blue */

    // 5. Game Loop
    SDL_Event event;
    while (bDone) {
        // poll event
        if(SDL_PollEvent(&event)) {
            handleEvent(event);
        }

        // draw
        SDL_UpdateTexture(texture, nullptr, frameBuffer, sizeof(uint32_t)*WIDTH);
        SDL_RenderTexture(renderer, texture, nullptr, nullptr);
        SDL_RenderPresent(renderer);

        drawLine(0, 0, 300, 300);
    }

    // 6. Destroy REsources
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // 7. Un-Initcls
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
                case SDLK_F:
                    {
                        // check current state is fullscreen or not
                        //bFullscreen = (SDL_GetWindowFlags(window) & SDL_WINDOW_FULLSCREEN) == 0;

                        // OR
                        bFullscreen = !bFullscreen;
                        SDL_SetWindowFullscreen(window, bFullscreen);
                    }
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

void clearFrameBuffer(uint32_t color) {
    for(uint32_t i = 0; i < WIDTH*HEIGHT; i++) {
        frameBuffer[i] = color;
    }
}

/**
 * Draw line using DDA Algorithm (Digital Differential Analyzer)
 */
void drawLine(int x1, int y1, int x2, int y2) {
    // function declarations
    void setPixel(int, int, uint32_t);

    int dx = abs(x2) - abs(x1);
    int dy = abs(y2) - abs(y1);

    int step = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    float x = x1;
    float y = y1;
    float xIncr = dx / static_cast<float>(step);
    float yIncr = dy / static_cast<float>(step);
    for(int i = 0; i <= step; i++) {
        setPixel(round(x), round(y), 0xff0000);
        x += xIncr;
        y += yIncr;
    }
}

void setPixel(int x, int y, uint32_t color) {
    if(x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT) {
        frameBuffer[(y*WIDTH) + x] = color;
    }
}
