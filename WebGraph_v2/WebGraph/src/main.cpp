//
//  main.cpp
//  WebGraph
//
//  Created by Глеб on 19/05/2024.
//



#include <string>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "HTML_FETCHER.h"
#include "PageNode.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const float ZOOM_FACTOR = 1.1f;

void drawPageLinks(sf::RenderWindow& window, const PageNode* node, sf::Font& font, const sf::Vector2f& mousePosition, float zoom) {
    node->draw(window, font, mousePosition, zoom);
    for (const auto& child : node->getChildren()) {
        sf::Vertex line[] = {
            sf::Vertex(node->getPosition(), sf::Color::Black),
            sf::Vertex(child->getPosition(), sf::Color::Black)
        };
        window.draw(line, 2, sf::Lines);
        drawPageLinks(window, child, font, mousePosition, zoom);
    }
}

void setPositionForNodes(PageNode* node, sf::Vector2f& startPos, float verticalSpacing, int depth) {
    static const float angleIncrement = 30.0f;
    float angle = 0.0f;

    for (auto& child : node->getChildren()) {
        float xOffset = cos(angle) * verticalSpacing;
        float yOffset = sin(angle) * verticalSpacing;
        sf::Vector2f childPos = startPos + sf::Vector2f(xOffset, yOffset);
        child->setPosition(childPos);
        setPositionForNodes(child, childPos, verticalSpacing / 1.5f, depth + 1);
        angle += angleIncrement;
    }
}

int main() {
    std::string initialUrl;
    std::cout << "Enter website address: ";
    std::cin >> initialUrl;
    std::vector<std::string> initialUrls = {initialUrl};

    std::vector<PageNode*> nestedLinks = fetchNestedLinks(initialUrls, 3);
    if (nestedLinks.empty()) {
        std::cerr << "No links found. Exiting..." << std::endl;
        return -1;
    }

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Graph Visualization");
    sf::Font font;
    std::vector<std::string> fontPaths = {
        "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf",
        "/Library/Fonts/Arial Unicode.ttf",
        "C:\\Windows\\Fonts\\arial.ttf"
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

    sf::Vector2f startPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    float verticalSpacing = 150.0f;
    setPositionForNodes(nestedLinks[0], startPosition, verticalSpacing, 0);

    sf::Vector2f mousePosition;
    float zoom = 1.0f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseMoved) {
                mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
            } else if (event.type == sf::Event::MouseWheelScrolled) {
                if (event.mouseWheelScroll.delta > 0) {
                    zoom *= ZOOM_FACTOR;
                } else {
                    zoom /= ZOOM_FACTOR;
                }
            }
        }

        window.clear(sf::Color::White);

        for (const auto& node : nestedLinks) {
            drawPageLinks(window, node, font, mousePosition, zoom);
        }

        window.display();
    }

    for (auto node : nestedLinks) {
        delete node;
    }

    return 0;
}
