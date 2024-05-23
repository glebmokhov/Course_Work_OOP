//
//  SecondDepthNode.h
//  WebGraph
//
//  Created by Глеб on 23/05/2024.
//

#ifndef SecondDepthNode_h
#define SecondDepthNode_h


#include "PageNode.h"

class SecondDepthNode : public PageNode {
public:
    SecondDepthNode(const std::string& url);

    void draw(sf::RenderWindow& window, sf::Font& font, const sf::Vector2f& mousePosition, float zoom) const override;
};



#endif /* SecondDepthNode_h */
