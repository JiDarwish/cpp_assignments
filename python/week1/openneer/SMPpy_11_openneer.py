#!/usr/bin/env python3

# SMPpy_11_openneer

def produceerReeks(x):
	out = str(x)
	while(x != 1):
	    if x % 2 == 0:
	       x //= 2
	    else:
	       x = x * 3 + 1
	    out += ", " + str(x)
	return out

if __name__ == '__main__':
        for i in [ 7, 1 ]:
            print("{} {}".format(i,  produceerReeks(i)))
