//
//  main.cpp
//  WebGraph
//
//  Created by Глеб on 19/05/2024.
//




#include <iostream>
#include <vector>
#include "gumbo.h"
#include "first_depth.h"
#include "second_depth.h"
#include "third_depth.h"
#include "HTML_FETCHER.h"
#include "link_tracker.h"
#include <SFML/Graphics.hpp>
#include "vertex.h"
#include "null_depth.h"
#include <cmath>

// Constants for window dimensions
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const float ZOOM_FACTOR = 1.1f;

// Helper function to draw vertices, edges, and labels recursively
void drawPageLinks(sf::RenderWindow& window, const PageLinks& page, int depth, float parentX, float parentY, float parentRadius, sf::Font& font, const sf::Vector2f& mousePosition, float zoom) {


    float angleIncrement = 2 * 3.14 / page.links.size();
    float radius = (depth == 1) ? 175 : (depth == 2) ? 80 : 40;
    int i = 0;

    for (const auto& link : page.links) {
        float angle = i * angleIncrement;
        float x = parentX + radius * cos(angle) * zoom;
        float y = parentY + radius * sin(angle) * zoom;

        sf::CircleShape vertexShape;
        if (depth == 1) {
            vertexShape.setRadius(10 * zoom);
            vertexShape.setFillColor(sf::Color::Red);
        } else if (depth == 2) {
            vertexShape.setRadius(6 * zoom);
            vertexShape.setFillColor(sf::Color::Green);
        } else {
            vertexShape.setRadius(3 * zoom);
            vertexShape.setFillColor(sf::Color::Blue);
        }

        vertexShape.setPosition(x - vertexShape.getRadius(), y - vertexShape.getRadius());
        window.draw(vertexShape);

        // Draw the edge between the parent vertex and the current vertex
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(parentX, parentY), sf::Color::Black),
            sf::Vertex(sf::Vector2f(x, y), sf::Color::Black)
        };
        window.draw(line, 2, sf::Lines);

        // Check if the mouse is hovering over the current vertex
        if (vertexShape.getGlobalBounds().contains(mousePosition)) {
            // Draw the URL label
            sf::Text text;
            text.setFont(font);
            text.setString(link);
            text.setCharacterSize(12);
            text.setFillColor(sf::Color::Black);
            text.setPosition(x + vertexShape.getRadius(), y + vertexShape.getRadius());
            window.draw(text);
        }

        // Draw nested links
        for (const auto& subPage : page.nestedLinks) {
            drawPageLinks(window, subPage, depth + 1, x, y, vertexShape.getRadius(), font, mousePosition, zoom);
        }

        ++i;
    }
}

int main() {
    std::string initialUrl;
    std::cout << "Enter website address: ";
    std::cin >> initialUrl;
    std::vector<std::string> initialUrls = {initialUrl};

    // Fetch nested links up to 3 levels
    std::vector<PageLinks> nestedLinks = fetchNestedLinks(initialUrls, 3);

    // Create the window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Graph Visualization");

    // Load a default font
    sf::Font font;
    std::vector<std::string> fontPaths = {
        "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf",  // Common on Linux
        "/Library/Fonts/Arial Unicode.ttf",                        // Common on macOS
        "C:\\Windows\\Fonts\\arial.ttf"                    // Common on Windows
    };

    bool fontLoaded = false;
    for (const auto& fontPath : fontPaths) {
        if (font.loadFromFile(fontPath)) {
            fontLoaded = true;
            break;
        }
    }

    if (!fontLoaded) {
        std::cerr << "Failed to load any of the default fonts" << std::endl;
        return -1;
    }

    

    // Constants for panning speed and zoom
    const float PAN_SPEED = 10.0f;

    // Variables for tracking panning offsets
    float offsetX = 0.0f;
    float offsetY = 0.0f;

    // Variable for zoom level
    sf::Vector2f mousePosition; // Placeholder for mouse position
    float zoom = 1.0f;
    // Main loop
    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // Handle key presses for panning and zooming
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Key::Equal) { // Zoom in
                    zoom *= 1.1;
                } else if (event.key.code == sf::Keyboard::Key::Hyphen) { // Zoom out
                    zoom *= 0.9;
                } else if (event.key.code == sf::Keyboard::Key::Left) { // Move left
                    offsetX -= PAN_SPEED;
                } else if (event.key.code == sf::Keyboard::Key::Right) { // Move right
                    offsetX += PAN_SPEED;
                } else if (event.key.code == sf::Keyboard::Key::Up) { // Move up
                    offsetY -= PAN_SPEED;
                } else if (event.key.code == sf::Keyboard::Key::Down) { // Move down
                    offsetY += PAN_SPEED;
                }
            }
            // Handle mouse movement for updating mouse position
            else if (event.type == sf::Event::MouseMoved) {
                mousePosition = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);
            }
        }

        window.clear(sf::Color::White);

        if (!nestedLinks.empty()) {
            sf::CircleShape centerShape(20);
            centerShape.setFillColor(sf::Color::Black);
            centerShape.setPosition(WINDOW_WIDTH / 2 - centerShape.getRadius() + offsetX, WINDOW_HEIGHT / 2 - centerShape.getRadius() + offsetY);
            window.draw(centerShape);

            // Draw the central URL label
            sf::Text centerText;
            centerText.setFont(font);
            centerText.setString(initialUrl);
            centerText.setCharacterSize(12);
            centerText.setFillColor(sf::Color::Black);
            centerText.setPosition(WINDOW_WIDTH / 2 + centerShape.getRadius() + offsetX, WINDOW_HEIGHT / 2 + centerShape.getRadius() + offsetY);
            window.draw(centerText);

            for (const auto& page : nestedLinks) {
                drawPageLinks(window, page, 1, WINDOW_WIDTH / 2 + offsetX, WINDOW_HEIGHT / 2 + offsetY, centerShape.getRadius(), font, mousePosition, zoom);
            }
        }

        window.display();
    }

    return 0;

}
