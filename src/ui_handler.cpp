#include "raylib.h"
#include "ui_handler.hpp"

namespace pe {

    void UIHandler::add_button(const Vec2 pos, const int width, const int height, const Color color, const std::function<void()> on_press)
    {
        m_buttons.push_back(Button{pos, width, height, color, on_press});
    }

    void UIHandler::update() const
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            for (const Button& button : m_buttons)
            {
                if (clicked_button(button, GetMousePosition()))
                {
                    button.on_press();
                }
            }
        }
        draw_ui();
    }

    Vec2 UIHandler::GetMousePos()
    {
        const auto raylib_pos = GetMousePosition();
        return {raylib_pos.x, raylib_pos.y};
    }


    bool UIHandler::clicked_button(const Button &button, const Vector2 mpos) const
    {
        return mpos.x >= button.pos.x && mpos.x <= (button.pos.x + button.width) &&
            mpos.y >= button.pos.y && mpos.y <= (button.pos.y + button.height);
    }

    void UIHandler::draw_ui() const
    {
        for (const Button& button : m_buttons)
        {
            DrawRectangle(button.pos.x, button.pos.y, button.width, button.height, button.color);
        }
    }


}
