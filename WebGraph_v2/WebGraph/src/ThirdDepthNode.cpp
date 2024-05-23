//
//  ThirdDepthNode.cpp
//  WebGraph
//
//  Created by Глеб on 23/05/2024.
//

#include "ThirdDepthNode.h"

ThirdDepthNode::ThirdDepthNode(const std::string& url)
    : PageNode(url, 3) {}

void ThirdDepthNode::draw(sf::RenderWindow& window, sf::Font& font, const sf::Vector2f& mousePosition, float zoom) const {
    sf::CircleShape shape(2 * zoom);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(position);
    window.draw(shape);

    sf::Text text;
    text.setFont(font);
    text.setString(url);
    text.setCharacterSize(12);
    text.setFillColor(sf::Color::Black);
    text.setPosition(position.x + 3 * zoom, position.y);
    window.draw(text);
}
