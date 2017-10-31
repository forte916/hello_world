import sys

def usage():
    print("Usage: %s filename start end width")


def hexdump(fname, start, end, width):
   for line in get_lines(fname, int(start), int(end), int(width)):
       nums = ["%02x" % ord(c) for c in line]
       txt = [fixchar(c) for c in line]
       print " ".join(nums), "".join(txt)


def fixchar(char):
   from string import printable
   if char not in printable[:-5]:
       return "."
   return char


def get_lines(fname, start, end, width):
   f = open(fname, "rb")
   f.seek(start)
   chunk = f.read(end-start)
   gap = width - (len(chunk) % width)
   chunk += gap * '\000'
   while chunk:
       yield chunk[:width]
       chunk = chunk[width:]


if __name__ == '__main__':
   try:
       hexdump(*sys.argv[1:5])
   except TypeError:
       hexdump("hexdump.py", 0, 100, 16)

