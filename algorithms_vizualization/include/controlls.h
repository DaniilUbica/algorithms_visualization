#pragma once

#include <SFML/Graphics.hpp>
#include <Windows.h>

#define SIZE 50
#define RECT_HEIGHT 495.f
#define RECT_WIDTH 10.f

bool startBubble = false, startShaker = false;

sf::RenderWindow window(sf::VideoMode(555, 705), "Algorithms");

sf::RectangleShape rects[SIZE];

void setRects(sf::RectangleShape* rects, const int size) {
    srand(time(NULL));

    rects[0].setSize(sf::Vector2f(RECT_WIDTH, RECT_HEIGHT));
    rects[0].setPosition(5.f, 5.f);
    rects[0].setFillColor(sf::Color::White);
    rects[0].setOutlineThickness(1);
    rects[0].setOutlineColor(sf::Color::Black);

    for (int i = 1; i < size; i++) {

        float height = float(rand() % 490 + 10);
        rects[i].setSize(sf::Vector2f(RECT_WIDTH, height));
        rects[i].setPosition(sf::Vector2f(rects[i - 1].getPosition().x + RECT_WIDTH + 1, 5.f));
        rects[i].setFillColor(sf::Color::White);
        rects[i].setOutlineThickness(1);
        rects[i].setOutlineColor(sf::Color::Black);
    }
}

void dispSort() {
 
    sf::Font font;
    font.loadFromFile("./fonts/font.TTF");

    sf::Text b("Press 'B' to choose bubble sort", font);
    sf::Text s("Press 'S' to choose shaker sort", font);
    sf::Text space("Press 'Space' to start", font);
    sf::Text choosen("Choosen: ", font);
    sf::Text bubble("Bubble", font);
    sf::Text shaker("Shaker", font);

    b.setCharacterSize(20);
    s.setCharacterSize(20);
    space.setCharacterSize(20);
    choosen.setCharacterSize(20);
    bubble.setCharacterSize(20);
    shaker.setCharacterSize(20);

    b.setPosition(sf::Vector2f(35.f, 550.f));
    s.setPosition(sf::Vector2f(35.f, 580.f));
    space.setPosition(sf::Vector2f(35.f, 610.f));
    choosen.setPosition(sf::Vector2f(35.f, 640.f));
    bubble.setPosition(sf::Vector2f(170.f, 640.f));
    shaker.setPosition(sf::Vector2f(170.f, 640.f));

    window.clear(sf::Color(23, 173, 126, 68));
    for (int i = 0; i < SIZE; i++) {
        window.draw(rects[i]);
    }

    window.draw(b);
    window.draw(s);
    window.draw(space);
    window.draw(choosen);

    if (startBubble) {
        window.draw(bubble);
    }

    if (startShaker) {
        window.draw(shaker);
    }

    window.display();
    Sleep(50);
}

void swapHeights(sf::RectangleShape& r1, sf::RectangleShape& r2) {
    sf::Vector2f temp = r1.getSize();
    r1.setSize(r2.getSize());
    r2.setSize(temp);
}