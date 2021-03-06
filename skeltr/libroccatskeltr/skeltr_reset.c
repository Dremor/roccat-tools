/*
 * This file is part of roccat-tools.
 *
 * roccat-tools is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * roccat-tools is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with roccat-tools. If not, see <http://www.gnu.org/licenses/>.
 */

#include "skeltr_reset.h"
#include "skeltr.h"

static void skeltr_reset_finalize(SkeltrReset *reset) {
	reset->report_id = SKELTR_REPORT_ID_RESET;
	reset->size = sizeof(SkeltrReset);
}

static gboolean skeltr_reset_write(RoccatDevice *skeltr, SkeltrReset *reset, GError **error) {
	skeltr_reset_finalize(reset);
	return skeltr_device_write(skeltr, (gchar const *)reset, sizeof(SkeltrReset), error);
}

gboolean skeltr_reset(RoccatDevice *skeltr, guint function, GError **error) {
	SkeltrReset reset;

	reset.function = function;
	return skeltr_reset_write(skeltr, &reset, error);
}
