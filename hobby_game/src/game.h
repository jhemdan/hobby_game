#pragma once

#include "keyboard.h"
#include "level.h"
#include "lua.h"
#include "asset_bank.h"

namespace hg
{
    class GameImpl;

    class Game
    {
    public:
        Game();
        ~Game();

        /*
            Throws.
        */
        void init();

        void clean();

        /*
            Throws.
        */
        void run();

        void quit();

        const AssetBank& get_assets() const { return m_assets; }
        const Keyboard& get_keyboard() const { return m_keyboard; }

    protected:
        friend class GameImpl;

        void on_key_event(Keycode code, bool state);

    private:
        /*
            Steps one frame.
        */
        void tick(float dt);

        /*
            Renders one frame.
        */
        void render();

    private:
        GameImpl* m_impl;
        bool m_should_quit;

        Lua m_lua;
        AssetBank m_assets;

        Keyboard m_keyboard;

        struct
        {
            int start;
            int end;
            int diff;
            float dt;
        } m_frame_time;

        Level m_level;
    };
}