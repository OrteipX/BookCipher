# OrteipX

Program Interfaces

The encoder should have the following command-line interface:
./bce bookfile messagefile codedfile

The decoder should have the following command-line interface:
./bcd bookfile codedfile messagefile

Where:
• bookfile is the name of the ASCII text file containing the book used to encode/decode the message
encode/decode the message.
• message file is the name of the ASCII text file containing the message to be encoded
• codedfile is the name of the ASCII text file containing the offset numbers

Encoding rules

Encode each character of the source file by replacing it with three numbers, the first representing the page in the book (zero-based), the second representing the line in the book (zero-based), and the third representing the column to that character in that line (also zero-based). Any method of choosing which location to use is acceptable so long as the same location isn’t used repeatedly.
At the end of running bce, a codedfile is created with locations.
At the end of running bcd, a messagefile is created with the codedfile.
The encoded file must be a file of the exact offsets of the message file. Book file:

    Now is the winter of our discontent\n
    Made glorious summer by this sun of York;\n \fAnd all the clouds that lour’d upon our house\n
    In the deep bosom of the ocean buried\n

Message file:

    Make me noodles

Possible coded file:

    0,1,0 1,0,4 1,2,15 1,1,35 1,1,30 1,1,16 1,0,10 1,0,39 0,0,30 1,1,15 0,1,10 1,0,2 0,1,6 1,2,22 1,0,17

Note:
Lines are delimited by the newline character ‘\n’ Pages are delimited by the form-feed character ‘\f’

Encoding background

To read more about encoding messages using the book cipher see:

    https://en.wikipedia.org/wiki/Book_cipher

In this program, you are encoding letters, not the words. The encoded file will store the
number in text.
