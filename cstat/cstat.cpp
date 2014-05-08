/* showdecl: GCC plugin to show each declaration.
 *
 * Copyright (C) 2014  David Lee (live4thee@gmail.com)
 *
 * Derived from:
 *   $GCC_REPO/gcc/testsuite/g++.dg/plugin/decl_plugin.c
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <gcc-plugin.h>
#include <plugin-version.h>
#include <diagnostic.h>

int plugin_is_GPL_compatible;

static void
finish_unit(void *, void *)
{
    const char *s = LOCATION_FILE(global_dc->last_location);
    printf("%s: warnings: %d\n", s, warningcount);
    printf("%s is main file? %d\n", s, MAIN_FILE_P(global_dc->last_module));
}

int plugin_init(
    struct plugin_name_args *plugin_info,
    struct plugin_gcc_version *version)
{
    if (!plugin_default_version_check (version, &gcc_version))
        return 1;

    register_callback(plugin_info->base_name,
                      PLUGIN_FINISH_UNIT,
                      finish_unit,
                      NULL);

    return 0;
}

/* vim: set et cin ts=4 sw=4: */
