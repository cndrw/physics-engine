#ifndef UI_HANDLER_HPP
#define UI_HANDLER_HPP

#include <vector>
#include <functional>
#include "raylib.h"
#include "transform.hpp"

namespace pe {

    struct Button
    {
        Vec2 pos;
        int width, height;
        Color color;
        std::function<void()> on_press;
    };

    class UIHandler
    {
    public:
        void add_button(Vec2 pos, int width, int height, Color color, std::function<void()> on_press);
        void update() const;

    private:
        void draw_ui() const;
        bool clicked_button(const Button& button, Vector2 mpos) const;

    private:
        std::vector<Button> m_buttons;
    };

}
#endif //UI_HANDLER_HPP
