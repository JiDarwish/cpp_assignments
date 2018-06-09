import sys
from getopt import getopt

args = getopt(sys.argv[1:], 'vf?', ['name=', 'flag'])
print(args)
