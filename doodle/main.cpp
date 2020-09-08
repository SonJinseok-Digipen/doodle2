// Name       : TODO
// Assignment : TODO
// Course     : TODO
// Term & Year: TODO

#include <doodle/doodle.hpp>

using namespace doodle;

double angle{0.0};
double grey{0};
double x{0.0};
double y{0.0};

int main(void)
{
    create_window(480, 360);
    set_rectangle_mode(RectMode::Center);
    while (!is_window_closed())
    {
        update_window();
        clear_background(220);
        set_fill_color(grey);
        draw_rectangle(x, y, Width * 0.4, Height * 0.4);
    }
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
