// Name       : jinseok Son
// Assignment : Generate Points Image
// Course     : cs120
// Term & Year: Digipen2020-fall &2020

#include <doodle/doodle.hpp>
#include <iostream>

using namespace doodle;

double angle{0.0};
double grey{0};
double x{0.0};
double y{0.0};

int main(void)
{
    int Window_width  = {0};
    int Window_height = {0};
    std::cout << "Enter in desired width: ";
    std::cin >> Window_width;
    std::cout << "Enter in desired height: ";
    std::cin >> Window_height;
    create_window(Window_width, Window_height);
    clear_background(120);
    int Pointx = {0};
    int Pointy = {0};
    while (std::cin >> Pointx >> Pointy)
    {
        no_outline();
        draw_ellipse(Pointx, Pointy, 4, 4);
    }
    Image image = capture_screenshot_to_image();
    image.SaveToFile("points.png");

    return 0;
}

void on_mouse_moved(int mouse_x, int mouse_y)
{
    angle += to_radians(3.0);
    grey = 255 * (std::sin(angle) * 0.5 + 0.5);
    x    = mouse_x;
    y    = mouse_y;
}

void on_key_released(KeyboardButtons button)
{
    if (button == KeyboardButtons::Escape)
        close_window();
}
