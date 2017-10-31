import sys

def usage():
    print("Usage: %s filename start end width")


def hexdump( chars, sep, width ):
    while chars:
        line = chars[:width]
        chars = chars[width:]
        line = line.ljust( width, '\000' )
        print("%s%s%s" % ( sep.join( "%02x" % ord(c) for c in line ), sep, quotechars( line )))


def quotechars( chars ):
    return ''.join( ['.', c][c.isalnum()] for c in chars )


def file_section( name, start, end ):
    contents = open( name, "rb" ).read()
    return contents[start:end]


if __name__ == '__main__':
    hexdump( file_section( sys.argv[1], int( sys.argv[2] ), int( sys.argv[3] )), ' ', int( sys.argv[4] ) )

