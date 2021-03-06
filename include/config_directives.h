/*
 * vim:ts=4:sw=4:expandtab
 *
 * i3 - an improved dynamic tiling window manager
 * © 2009-2012 Michael Stapelberg and contributors (see also: LICENSE)
 *
 * config_directives.h: all config storing functions (see config_parser.c)
 *
 */
#ifndef I3_CONFIG_DIRECTIVES_H
#define I3_CONFIG_DIRECTIVES_H

#include "config_parser.h"

/** The beginning of the prototype for every cfg_ function. */
#define I3_CFG Match *current_match, struct ConfigResult *result

/* Defines a configuration function, that is, anything that can be called by
 * using 'call cfg_foo()' in parser-specs/.*.spec. Useful so that we don’t need
 * to repeat the definition all the time. */
#define CFGFUN(name, ...) \
    void cfg_ ## name (I3_CFG, ## __VA_ARGS__ )

/* The following functions are called by the config parser, see
 * parser-specs/config.spec. They get the parsed parameters and store them in
 * our data structures, e.g. cfg_font gets a font name and stores it in
 * config.font.
 *
 * Since they are so similar, individual comments were omitted. */

CFGFUN(criteria_init, int _state);
CFGFUN(criteria_add, const char *ctype, const char *cvalue);
CFGFUN(criteria_pop_state);

CFGFUN(font, const char *font);
CFGFUN(exec, const char *exectype, const char *no_startup_id, const char *command);
CFGFUN(for_window, const char *command);
CFGFUN(floating_minimum_size, const long width, const long height);
CFGFUN(floating_maximum_size, const long width, const long height);
CFGFUN(default_orientation, const char *orientation);
CFGFUN(workspace_layout, const char *layout);
CFGFUN(workspace_back_and_forth, const char *value);
CFGFUN(focus_follows_mouse, const char *value);
CFGFUN(force_focus_wrapping, const char *value);
CFGFUN(force_xinerama, const char *value);
CFGFUN(fake_outputs, const char *outputs);
CFGFUN(force_display_urgency_hint, const long duration_ms);
CFGFUN(hide_edge_borders, const char *borders);
CFGFUN(assign, const char *workspace);
CFGFUN(ipc_socket, const char *path);
CFGFUN(restart_state, const char *path);
CFGFUN(popup_during_fullscreen, const char *value);
CFGFUN(color, const char *colorclass, const char *border, const char *background, const char *text, const char *indicator);
CFGFUN(color_single, const char *colorclass, const char *color);
CFGFUN(floating_modifier, const char *modifiers);
CFGFUN(new_window, const char *windowtype, const char *border, const long width);
CFGFUN(workspace, const char *workspace, const char *output);
CFGFUN(binding, const char *bindtype, const char *modifiers, const char *key, const char *release, const char *command);

CFGFUN(enter_mode, const char *mode);
CFGFUN(mode_binding, const char *bindtype, const char *modifiers, const char *key, const char *release, const char *command);

CFGFUN(bar_font, const char *font);
CFGFUN(bar_mode, const char *mode);
CFGFUN(bar_output, const char *output);
CFGFUN(bar_verbose, const char *verbose);
CFGFUN(bar_modifier, const char *modifier);
CFGFUN(bar_position, const char *position);
CFGFUN(bar_i3bar_command, const char *i3bar_command);
CFGFUN(bar_color, const char *colorclass, const char *border, const char *background, const char *text);
CFGFUN(bar_socket_path, const char *socket_path);
CFGFUN(bar_tray_output, const char *output);
CFGFUN(bar_color_single, const char *colorclass, const char *color);
CFGFUN(bar_status_command, const char *command);
CFGFUN(bar_workspace_buttons, const char *value);
CFGFUN(bar_finish);

#endif
