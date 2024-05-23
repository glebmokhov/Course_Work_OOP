//
//  RootNode.cpp
//  WebGraph
//
//  Created by Глеб on 23/05/2024.
//

#include "RootNode.h"

RootNode::RootNode(const std::string& url)
    : PageNode(url, 0) {}

void RootNode::draw(sf::RenderWindow& window, sf::Font& font, const sf::Vector2f& mousePosition, float zoom) const {
    sf::CircleShape shape(10 * zoom);
    shape.setFillColor(sf::Color::Black);
    shape.setPosition(position);
    window.draw(shape);

    sf::Text text;
    text.setFont(font);
    text.setString(url);
    text.setCharacterSize(12);
    text.setFillColor(sf::Color::Black);
    text.setPosition(position.x + 15 * zoom, position.y);
    window.draw(text);
}
