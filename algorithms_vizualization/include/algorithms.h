#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

#include "./controlls.h"

void bubbleSort(sf::RectangleShape* rects, const int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size - i - 1; j++) {
            rects[j + 1].setFillColor(sf::Color::Red);
            if (rects[j].getSize().y > rects[j + 1].getSize().y) {
                swapHeights(rects[j], rects[j + 1]);
            }
            dispSort();
            rects[j + 1].setFillColor(sf::Color::White);
        }
    }
}