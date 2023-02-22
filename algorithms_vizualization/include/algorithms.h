#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

#include "./controlls.h"

void bubbleSort(sf::RectangleShape* rects, const int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size - i - 1; j++) {
            rects[j + 1].setFillColor(sf::Color(100, 33, 25, 255));
            if (rects[j].getSize().y > rects[j + 1].getSize().y) {
                swapHeights(rects[j], rects[j + 1]);
            }
            dispSort();
            rects[j + 1].setFillColor(sf::Color::White);
        }
        rects[j].setFillColor(sf::Color(30, 97, 227, 89));
    }
}

void shakerSort(sf::RectangleShape* rects, const int size) {
    int left = 0;
    int right = size - 1;
    int i;

    while (left <= right) {
        for (i = right; i > left; i--) {
            if (rects[i - 1].getSize().y > rects[i].getSize().y) {
                swapHeights(rects[i - 1], rects[i]);
            }
            rects[i - 1].setFillColor(sf::Color(100, 33, 25, 255));
            dispSort();
            rects[i - 1].setFillColor(sf::Color::White);
        }
        left++;

        rects[i - 1].setFillColor(sf::Color(30, 97, 227, 89));

        for (i = left; i < right; i++) {
            if (rects[i].getSize().y > rects[i + 1].getSize().y) {
                swapHeights(rects[i], rects[i + 1]);
            }
            rects[i + 1].setFillColor(sf::Color(100, 33, 25, 255));
            dispSort();
            rects[i + 1].setFillColor(sf::Color::White);
        }
        right--;

        rects[i].setFillColor(sf::Color(30, 97, 227, 89));
    }
}