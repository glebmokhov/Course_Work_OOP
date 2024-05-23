//
//  PageNode.h
//  WebGraph
//
//  Created by Глеб on 23/05/2024.
//

#ifndef PageNode_h
#define PageNode_h

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>




class PageNode {
public:
    PageNode(const std::string& url, int depth);
    virtual ~PageNode();

    void addChild(PageNode* child);
    const std::vector<PageNode*>& getChildren() const;

    virtual void draw(sf::RenderWindow& window, sf::Font& font, const sf::Vector2f& mousePosition, float zoom) const = 0;

    void setPosition(const sf::Vector2f& pos);
    sf::Vector2f getPosition() const;

    int getDepth() const;
    std::string getUrl() const;

protected:
    std::string url;
    std::vector<PageNode*> children;
    sf::Vector2f position;
    int depth;
};





#endif /* PageNode_h */
