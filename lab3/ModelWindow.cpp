#include "ModelWindow.h"

using namespace std;

ModelWindow::ModelWindow()
{
    title = "New window";
    x = 0;
    y = 0;
    width = 20;
    height = 10;
    color = "white";
    visible = true;
    border = true;
}

ModelWindow::ModelWindow(string newTitle, int newX, int newY,
    int newWidth, int newHeight,
    string newColor, bool newVisible,
    bool newBorder)
{
    if (CheckBounds(newX, newY, newWidth, newHeight))
    {
        title = newTitle;
        x = newX;
        y = newY;
        width = newWidth;
        height = newHeight;
        color = newColor;
        visible = newVisible;
        border = newBorder;
    }
    else
    {
        cout << "Error: window is off-screen! Standard bounds applied." << endl;
        title = newTitle;
        x = 0;
        y = 0;
        width = 20;
        height = 10;
        color = newColor;
        visible = newVisible;
        border = newBorder;
    }
}

ModelWindow::ModelWindow(const ModelWindow& other)
{
    title = other.title + " (Copy)";
    x = other.x;
    y = other.y;
    width = other.width;
    height = other.height;
    color = other.color;
    visible = other.visible;
    border = other.border;
}

bool ModelWindow::CheckBounds(int newX, int newY,
    int newWidth, int newHeight)
{
    if (newX < 0 || newY < 0)
        return false;

    if (newWidth <= 0 || newHeight <= 0)
        return false;

    if (newX + newWidth > SCREEN_WIDTH)
        return false;

    if (newY + newHeight > SCREEN_HEIGHT)
        return false;

    return true;
}

void ModelWindow::Init(string newTitle, int newX, int newY,
    int newWidth, int newHeight,
    string newColor, bool newVisible,
    bool newBorder)
{
    if (CheckBounds(newX, newY, newWidth, newHeight))
    {
        title = newTitle;
        x = newX;
        y = newY;
        width = newWidth;
        height = newHeight;
        color = newColor;
        visible = newVisible;
        border = newBorder;
    }
    else
    {
        cout << "Error: window is off-screen!" << endl;
    }
}

void ModelWindow::Read()
{
    cout << "Enter the window title: ";
    cin.ignore();
    getline(cin, title);

    cout << "Enter the X coordinate: ";
    cin >> x;

    cout << "Enter the Y coordinate: ";
    cin >> y;

    cout << "Enter width: ";
    cin >> width;

    cout << "Enter height: ";
    cin >> height;

    cout << "Enter color: ";
    cin >> color;

    cout << "Is the window visible? (1 - yes, 0 - no): ";
    cin >> visible;

    cout << "Is the window bordered? (1 - yes, 0 - no): ";
    cin >> border;

    if (!CheckBounds(x, y, width, height))
    {
        cout << "Error: window is off-screen!" << endl;

        x = 0;
        y = 0;
        width = 20;
        height = 10;
    }
}

void ModelWindow::Display() const
{
    cout << "\n===== Window status =====" << endl;

    cout << "Title: " << title << endl;
    cout << "X coordinate: " << x << endl;
    cout << "Y coordinate: " << y << endl;
    cout << "Width: " << width << endl;
    cout << "Height: " << height << endl;
    cout << "Color: " << color << endl;

    cout << "Visible: ";
    if (visible)
        cout << "yes";
    else
        cout << "no";
    cout << endl;

    cout << "Border: ";
    if (border)
        cout << "exists";
    else
        cout << "no exists";
    cout << endl;

    cout << "======================" << endl;
}

string ModelWindow::toString() const
{
    string result;

    result += "Title: " + title;
    result += "\nX coordinate: " + to_string(x);
    result += "\nY coordinate: " + to_string(y);
    result += "\nWidht: " + to_string(width);
    result += "\nHeight: " + to_string(height);
    result += "\nColor: " + color;
    result += "\nVisible: ";

    if (visible)
        result += "yes";
    else
        result += "no";

    result += "\nBorder: ";

    if (border)
        result += "exists";
    else
        result += "no exists";

    return result;
}

bool ModelWindow::MoveHorizontal(int dx)
{
    if (CheckBounds(x + dx, y, width, height))
    {
        x += dx;
        return true;
    }

    return false;
}

bool ModelWindow::MoveVertical(int dy)
{
    if (CheckBounds(x, y + dy, width, height))
    {
        y += dy;
        return true;
    }

    return false;
}

bool ModelWindow::ChangeWidth(int newWidth)
{
    if (CheckBounds(x, y, newWidth, height))
    {
        width = newWidth;
        return true;
    }

    return false;
}

bool ModelWindow::ChangeHeight(int newHeight)
{
    if (CheckBounds(x, y, width, newHeight))
    {
        height = newHeight;
        return true;
    }

    return false;
}

bool ModelWindow::ChangeSize(int newWidth, int newHeight)
{
    if (CheckBounds(x, y, newWidth, newHeight))
    {
        width = newWidth;
        height = newHeight;
        return true;
    }

    return false;
}

void ModelWindow::ChangeColor(string newColor)
{
    color = newColor;
}

void ModelWindow::SetVisible(bool state)
{
    visible = state;
}

void ModelWindow::SetBorder(bool state)
{
    border = state;
}
bool ModelWindow::IsVisible() const
{
    return visible;
}

bool ModelWindow::HasBorder() const
{
    return border;
}