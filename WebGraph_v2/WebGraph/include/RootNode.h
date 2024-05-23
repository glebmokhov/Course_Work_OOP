//
//  RootNode.h
//  WebGraph
//
//  Created by Глеб on 23/05/2024.
//

#ifndef RootNode_h
#define RootNode_h


#include "PageNode.h"

class RootNode : public PageNode {
public:
    RootNode(const std::string& url);

    void draw(sf::RenderWindow& window, sf::Font& font, const sf::Vector2f& mousePosition, float zoom) const override;
};



#endif /* RootNode_h */
