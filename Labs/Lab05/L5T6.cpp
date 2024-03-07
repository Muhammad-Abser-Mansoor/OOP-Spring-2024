/* Programmer:Muhammad Abser Mansoor
 * Date: 01/03/2024
 * Descrption: Game Engine using composition
 */

#include <iostream>
#include <vector>

class GraphicsRenderingEngine {
public:
    void render() {
        std::cout << "Graphicing\n";
    }
};

class InputHandler {
public:
    void handleInput() {
        std::cout << "Handling\n";
    }
};

class PhysicsEngine {
public:
    void simulatePhysics() {
        std::cout << "Physicsing\n";
    }
};

// Game Engine composed of GraphicsRenderingEngine, InputHandler, and PhysicsEngine
class GameEngine {
private:
    GraphicsRenderingEngine graphicsEngine;
    InputHandler inputHandler;
    PhysicsEngine physicsEngine;

public:
    void run() {
        graphicsEngine.render();
        inputHandler.handleInput();
        physicsEngine.simulatePhysics();
        std::cout << "Game is running\n";
    }
};

int main() {
    // Creating a game engine
    GameEngine myGameEngine;

    // Run the game
    myGameEngine.run();

    return 0;
}
