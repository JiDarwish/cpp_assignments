#!/usr/bin/env python3
# (c) 2018 Frans Schippers (f.h.schippers@hva.nl) for MSP

# SMPpy_22_hex
import struct


def charToHex(s):
    return hex(ord(s))


def intToHex(s):
    return hex(s)


def floatToHex(s):
    return hex(struct.unpack('<I', struct.pack('<f', s))[0])


if __name__ == '__main__':
    for c in [u'a', b'b', '\t', 'Z']:
        print('charToHex:  {:12s}: {}'.format(repr(c), charToHex(c)))
    for i in [42, 2**31-1, -(2**31), -1]:
        print('intToHex:   {:12s}: {}'.format(repr(i), intToHex(i)))
    for f in [1, 2.0, -2.0, 4.0, 4.125, 32.7581]:
        print('floatToHex: {:12s}: {}'.format(repr(f), floatToHex(f)))
