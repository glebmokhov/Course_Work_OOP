//
//  PageNode.cpp
//  WebGraph
//
//  Created by Глеб on 23/05/2024.
//

#include "PageNode.h"

PageNode::PageNode(const std::string& url, int depth)
    : url(url), position(0, 0), depth(depth) {}

PageNode::~PageNode() {
    for (auto child : children) {
        delete child;
    }
}

void PageNode::addChild(PageNode* child) {
    children.push_back(child);
}

const std::vector<PageNode*>& PageNode::getChildren() const {
    return children;
}

void PageNode::setPosition(const sf::Vector2f& pos) {
    position = pos;
}

sf::Vector2f PageNode::getPosition() const {
    return position;
}

int PageNode::getDepth() const {
    return depth;
}

std::string PageNode::getUrl() const {
    return url;
}
