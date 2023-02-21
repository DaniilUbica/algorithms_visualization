#pragma once

#include <SFML/Graphics.hpp>
#include <Windows.h>

#define SIZE 50

sf::RenderWindow window(sf::VideoMode(505, 505), "Algorithms");

sf::RectangleShape rects[SIZE];

void setRects(sf::RectangleShape* rects, const int size) {
    srand(time(NULL));

    rects[0].setSize(sf::Vector2f(10.f, 495.f));
    rects[0].setPosition(5.f, 5.f);
    rects[0].setFillColor(sf::Color::White);

    for (int i = 1; i < size; i++) {

        float height = float(rand() % 490 + 10);
        rects[i].setSize(sf::Vector2f(10.f, height));
        rects[i].setPosition(sf::Vector2f(rects[i - 1].getPosition().x + 10, 5.f));
        rects[i].setFillColor(sf::Color::White);
        rects[i].setOutlineThickness(1);
        rects[i].setOutlineColor(sf::Color::Black);
    }
}

void dispSort() {
    window.clear();
    for (int i = 0; i < SIZE; i++) {
        window.draw(rects[i]);
    }
    window.display();
    Sleep(1);
}

void swapHeights(sf::RectangleShape& r1, sf::RectangleShape& r2) {
    sf::Vector2f temp = r1.getSize();
    r1.setSize(r2.getSize());
    r2.setSize(temp);
}