#! /usr/bin/env python3

# bin2array.py: Convert an encoded Rubberducky payload into an Arduino array
# Copyright (C) 2020-2021  Philipp Leclercq
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

from sys import argv


def print_array():
    try:
        filename = argv[1]
        chunk_size = int(argv[2]) if (len(argv) > 2) else 20
        with open(filename, 'rb') as file:
            data = file.read()
            print(f'const unsigned int duckraw_size = {len(data)};\nconst PROGMEM uint8_t duckraw [duckraw_size] = {{')
            s = '\t'
            for index, value in enumerate(data):
                s += hex(value)
                # Append ', ' when it's not the last byte.
                if index < (len(data) - 1):
                    s += ', '
                    # Put a newline after every x bytes.
                    if (index % chunk_size) == (chunk_size - 1):
                        s += '\n\t'
            print(f'{s}\n}};')
    except (IndexError, ValueError, FileNotFoundError):
        print('USAGE: ./bin2array.py BIN_FILE [CHUNK_SIZE]')


if __name__ == '__main__':
    print_array()
