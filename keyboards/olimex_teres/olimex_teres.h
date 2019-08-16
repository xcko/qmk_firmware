/* Copyright 2019 xcko
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
    k110, k112, k113, k114, k115, k116, k117, k118, k119, k120, k121, k122, k123, k124, k076, \
    k001, k002, k003, k004, k005, k006, k007, k008, k009, k010, k011, k012, k013,    k015,    \
       k016,    k017, k018, k019, k020, k021, k022, k023, k024, k025, k026, k027, k028, k029, \
       k030,    k031, k032, k033, k034, k035, k036, k037, k038, k039, k040, k041,    k043,    \
       k044,       k046, k047, k048, k049, k050, k051, k052, k053, k054, k055,       k057,    \
    k058, k059, k127, k060,             k061,             k062, k129, k064,        k083,      \
                                                                             k079, k084, k089 \
) \
{ \
    { KC_NO,  k017,  k018,  k019,  k020,  k023,  k024,  k025,  k026, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO,  k016,  k030,  k114,  k021,  k022,  k028,  k118,  k027, KC_NO,  k015, KC_NO,  k127,  k044 }, \
    { KC_NO,  k031,  k032,  k033,  k034,  k037,  k038,  k039,  k040, KC_NO,  k029, KC_NO, KC_NO,  k057 }, \
    { KC_NO,  k110, KC_NO,  k115,  k035,  k036,  k117, KC_NO,  k041,  k060,  k122,  k061, KC_NO,  k083 }, \
    {  k064,  k046,  k047,  k048,  k049,  k052,  k053,  k054, KC_NO, KC_NO,  k043, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,  k050,  k051, KC_NO,  k129, k055,  k062,  k123,  k084,  k089,  k079 }, \
    {  k058,  k001,  k112,  k113,  k006,  k007,  k013,  k119, k012, KC_NO,  k120,  k076, KC_NO,  k059 }, \
    {  k116,  k002,  k003,  k004,  k005,  k008,  k009,  k010, k011,  k124,  k121, KC_NO, KC_NO, KC_NO }, \
}
	/* Col 12 and 16, and col 14 and 15 are combined (see pcb diagram). k042, k044 are not used */
