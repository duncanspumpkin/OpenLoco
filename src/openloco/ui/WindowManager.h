#pragma once

#include "../graphics/gfx.h"
#include "../localisation/stringmgr.h"
#include "../map/tile.h"
#include "../window.h"
#include <cstddef>

namespace openloco::ui::WindowManager
{
    void init();
    void registerHooks();
    WindowType getCurrentModalType();
    void setCurrentModalType(WindowType type);
    window* get(size_t index);
    size_t count();

    void update();
    window* getMainWindow();
    window* find(WindowType type);
    window* find(WindowType type, window_number number);
    window* findAt(int16_t x, int16_t y);
    window* findAtAlt(int16_t x, int16_t y);
    window* bringToFront(window* window);
    window* bringToFront(WindowType type, uint16_t id);
    void invalidate(WindowType type);
    void invalidate(WindowType type, window_number number);
    void invalidateWidget(WindowType type, window_number number, uint8_t widget_index);
    void invalidateAllWindowsAfterInput();
    void close(WindowType type);
    void close(WindowType type, uint16_t id);
    void close(window* window);
    window* createWindow(WindowType type, gfx::ui_size_t size, uint32_t flags, window_event_list* events);
    window* createWindow(WindowType type, gfx::point_t origin, gfx::ui_size_t size, uint32_t flags, window_event_list* events);
    window* createWindowCentred(WindowType type, gfx::ui_size_t size, uint32_t flags, window_event_list* events);
    void drawSingle(gfx::drawpixelinfo_t* dpi, window* w, int32_t left, int32_t top, int32_t right, int32_t bottom);
    void dispatchUpdateAll();
    void callViewportRotateEventOnAllWindows();
    void relocateWindows();
    void sub_4CEE0B(window* self);
    void sub_4B93A5(window_number number);
    void closeTopmost();
    void allWheelInput();
    bool isInFront(ui::window* w);
    bool isInFrontAlt(ui::window* w);
    ui::window* findWindowShowing(map::map_pos position);
}

namespace openloco::ui::windows
{
    void station_2_scroll_paint(window& w, gfx::drawpixelinfo_t& dpi);
    window* open_town_window(uint16_t townId);
    window* open_title_version();
    window* open_title_exit();
    window* open_title_menu();
    window* open_title_logo();
    void open_about_window();
    void sub_498E9B(window* w);

    bool prompt_ok_cancel(string_id okButtonStringId);

    void show_error(string_id title, string_id message);
}

namespace openloco::ui::about
{
    void open();
}

namespace openloco::ui::about_music
{
    void open();
}

namespace openloco::ui::windows::construction
{
    window* open_with_flags(uint32_t flags);
    void on_mouse_up(window& w, uint16_t widgetIndex);
}

namespace openloco::ui::windows::industry_list
{
    window* open();
}

namespace openloco::ui::windows::map
{
    void open();
    void center_on_view_point();
}

namespace openloco::ui::windows::music_selection
{
    window* open();
}

namespace openloco::ui::options
{
    window* open();
    window* open_music_settings();
    constexpr uint8_t tab_offset_music = 2;
}

namespace openloco::ui::prompt_browse
{
    enum class browse_type
    {
        load = 1,
        save = 2
    };
    bool open(browse_type type, char* path, const char* filter, const char* title);
    void register_hooks();
}

namespace openloco::ui::windows::station_list
{
    window* open(uint16_t companyId, uint8_t type);
}

namespace openloco::ui::windows::terraform
{
    window* open();
    void open_clear_area();
    void open_adjust_land();
    void open_adjust_water();
    void open_plant_trees();
    void open_build_walls();
}

namespace openloco::ui::textinput
{
    void register_hooks();

    void open_textinput(ui::window* w, string_id title, string_id message, string_id value, int callingWidget, void* valueArgs);
    void sub_4CE6C9(WindowType type, window_number number);
    void cancel();
    void sub_4CE910(int eax, int ebx);
    void sub_4CE6FF();
}

namespace openloco::ui::title_options
{
    window* open();
}

namespace openloco::ui::windows::toolbar_top
{
    void open();
}

namespace openloco::ui::tooltip
{
    void register_hooks();
    void open(ui::window* window, int32_t widgetIndex, int16_t x, int16_t y);
    void update(ui::window* window, int32_t widgetIndex, string_id stringId, int16_t x, int16_t y);
}

namespace openloco::ui::windows::town_list
{
    window* open();
}

namespace openloco::ui::vehicle
{
    void registerHooks();
}

namespace openloco::ui::windows::vehicle_list
{
    window* open(uint16_t companyId, uint8_t type);
}

namespace openloco::ui::build_vehicle
{
    window* open(uint32_t vehicle, uint32_t flags);
    void registerHooks();
}
