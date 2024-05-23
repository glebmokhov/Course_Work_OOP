//
//  FirstDepthNode.cpp
//  WebGraph
//
//  Created by Глеб on 23/05/2024.
//

#include "FirstDepthNode.h"

FirstDepthNode::FirstDepthNode(const std::string& url)
    : PageNode(url, 1) {}

void FirstDepthNode::draw(sf::RenderWindow& window, sf::Font& font, const sf::Vector2f& mousePosition, float zoom) const {
    sf::CircleShape shape(6 * zoom);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(position);
    window.draw(shape);

    sf::Text text;
    text.setFont(font);
    text.setString(url);
    text.setCharacterSize(12);
    text.setFillColor(sf::Color::Black);
    text.setPosition(position.x + 10 * zoom, position.y);
    window.draw(text);
}
