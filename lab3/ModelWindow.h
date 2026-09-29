#pragma once
#include <iostream>
#include <string>

using namespace std;

class ModelWindow
{
private:
    string title;
    int x;
    int y;
    int width;
    int height;
    string color;
    bool visible;
    bool border;

    static const int SCREEN_WIDTH = 120;
    static const int SCREEN_HEIGHT = 30;

    bool CheckBounds(int newX, int newY, int newWidth, int newHeight);

public:
    ModelWindow();

    ModelWindow(string newTitle, int newX, int newY,
        int newWidth, int newHeight,
        string newColor, bool newVisible, bool newBorder);

    ModelWindow(const ModelWindow& other);

    void Init(string newTitle, int newX, int newY,
        int newWidth, int newHeight,
        string newColor, bool newVisible, bool newBorder);

    void Read();
    void Display() const;
    string toString() const;

    bool MoveHorizontal(int dx);
    bool MoveVertical(int dy);

    bool ChangeWidth(int newWidth);
    bool ChangeHeight(int newHeight);
    bool ChangeSize(int newWidth, int newHeight);

    void ChangeColor(string newColor);

    void SetVisible(bool state);
    void SetBorder(bool state);

    bool IsVisible() const;
    bool HasBorder() const;
};