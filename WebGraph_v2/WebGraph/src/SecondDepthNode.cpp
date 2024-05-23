//
//  SecondDepthNode.cpp
//  WebGraph
//
//  Created by Глеб on 23/05/2024.
//

#include "SecondDepthNode.h"

SecondDepthNode::SecondDepthNode(const std::string& url)
    : PageNode(url, 2) {}

void SecondDepthNode::draw(sf::RenderWindow& window, sf::Font& font, const sf::Vector2f& mousePosition, float zoom) const {
    sf::CircleShape shape(4 * zoom);
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(position);
    window.draw(shape);

    sf::Text text;
    text.setFont(font);
    text.setString(url);
    text.setCharacterSize(12);
    text.setFillColor(sf::Color::Black);
    text.setPosition(position.x + 5 * zoom, position.y);
    window.draw(text);
}
