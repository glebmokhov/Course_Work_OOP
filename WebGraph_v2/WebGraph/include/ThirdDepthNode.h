//
//  ThirdDepthNode.h
//  WebGraph
//
//  Created by Глеб on 23/05/2024.
//

#ifndef ThirdDepthNode_h
#define ThirdDepthNode_h


#include "PageNode.h"

class ThirdDepthNode : public PageNode {
public:
    ThirdDepthNode(const std::string& url);

    void draw(sf::RenderWindow& window, sf::Font& font, const sf::Vector2f& mousePosition, float zoom) const override;
};




#endif /* ThirdDepthNode_h */
