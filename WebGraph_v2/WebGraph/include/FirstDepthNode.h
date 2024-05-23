//
//  FirstDepthNode.h
//  WebGraph
//
//  Created by Глеб on 23/05/2024.
//

#ifndef FirstDepthNode_h
#define FirstDepthNode_h



#include "PageNode.h"

class FirstDepthNode : public PageNode {
public:
    FirstDepthNode(const std::string& url);

    void draw(sf::RenderWindow& window, sf::Font& font, const sf::Vector2f& mousePosition, float zoom) const override;
};




#endif /* FirstDepthNode_h */
