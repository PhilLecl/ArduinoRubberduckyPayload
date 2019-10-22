#! /usr/bin/env python3

from sys import argv

def main():
    filename = argv[1] # The first parameter is the name of the binary file.

    chunksize = 20 # Print 20 bytes per line by default.
    # If a second parameter is given, use that as the number of bytes per line.
    if len(argv) > 2:
        chunksize = int(argv[2])

    # Open the file in binary read mode.
    with open(filename, "rb") as file:
        data = file.read() # Read the binary data.
        datasize = len(data) # Save the length of the file.

        print("const unsigned int duckraw_size = ", datasize, " ;")
        print("const PROGMEM uint8_t duckraw [duckraw_size] = {")

        s = ""
        for i in range(datasize): # Iterate through the bytes.
            s += hex(data[i]) # Add the hex data to the string.

            # Append ',' when it's not the last byte.
            if i < datasize-1:
                s += ","

                # Put a newline after every x bytes.
                if i%chunksize == chunksize-1:
                    s += "\n"

        print(s)
        print("};")

if __name__ == '__main__':
    main()
