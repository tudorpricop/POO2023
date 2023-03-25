#include "Canvas.h"
#include <iostream>
#include <cmath>

Canvas::Canvas(int width, int height)
    : width_(width), height_(height)
{
    pixels_ = new char* [height_];
    for (int i = 0; i < height_; ++i)
    {
        pixels_[i] = new char[width_];
        for (int j = 0; j < width_; ++j)
        {
            pixels_[i][j] = ' ';
        }
    }
}

Canvas::~Canvas()
{
    for (int i = 0; i < height_; ++i)
    {
        delete[] pixels_[i];
    }
    delete[] pixels_;
}

void Canvas::DrawCircle(int x, int y, int radius, char ch)
{
    int cx = 0;
    int cy = radius;
    int d = 3 - 2 * radius;

    while (cx <= cy)
    {
        SetPoint(x + cx, y + cy, ch);
        SetPoint(x + cy, y + cx, ch);
        SetPoint(x - cy, y + cx, ch);
        SetPoint(x - cx, y + cy, ch);
        SetPoint(x - cx, y - cy, ch);
        SetPoint(x - cy, y - cx, ch);
        SetPoint(x + cy, y - cx, ch);
        SetPoint(x + cx, y - cy, ch);

        if (d < 0)
        {
            d = d + 4 * cx + 6;
        }
        else
        {
            d = d + 4 * (cx - cy) + 10;
            cy--;
        }
        cx++;
    }
}

void Canvas::FillCircle(int x, int y, int radius, char ch)
{
    int cx = radius;
    int cy = 0;
    int error = 0;

    while (cx >= cy)
    {
        for (int i = x - cx; i <= x + cx; ++i)
        {
            SetPoint(i, y + cy, ch);
            SetPoint(i, y - cy, ch);
        }

        for (int i = x - cy; i <= x + cy; ++i)
        {
            SetPoint(i, y + cx, ch);
            SetPoint(i, y - cx, ch);
        }

        if (error <= 0)
        {
            cy++;
            error += 2 * cy + 1;
        }
        if (error > 0)
        {
            cx--;
            error -= 2 * cx + 1;
        }
    }
}

void Canvas::Print()
{
    for (int i = 0; i < height_; i++)
    {
        for (int j = 0; j < width_; j++)
        {
            std::cout << pixels_[i][j];
        }
        std::cout << std::endl;
    }
}

void Canvas::Clear()
{
    for (int i = 0; i < height_; i++)
    {
        for (int j = 0; j < width_; j++)
        {
            pixels_[i][j] = ' ';
        }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    for (int x = left; x <= right; ++x)
    {
        pixels_[top][x] = ch;
        pixels_[bottom][x] = ch;
    }

    for (int y = top; y <= bottom; ++y)
    {
        pixels_[y][left] = ch;
        pixels_[y][right] = ch;
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int y = top; y <= bottom; ++y)
    {
        for (int x = left; x <= right; ++x)
        {
            pixels_[y][x] = ch;
        }
    }
}

void Canvas::SetPoint(int x, int y, char ch)
{
    pixels_[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int dx = std::abs(x2 - x1);
    int dy = std::abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int error = dx - dy;

    while (true)
    {
        pixels_[y1][x1] = ch;

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * error;
        if (e2 > -dy)
        {
            error -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            error += dx;
            y1 += sy;
        }
    }
}
