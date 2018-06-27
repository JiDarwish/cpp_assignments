#!/usr/bin/env python3
import re

# SMPpy_14_palindroom.


def isPalindoom(s):
    allChars = "".join(re.findall("[a-zA-Z]+", s)).lower()
    reversedStr = allChars[::-1]

    return allChars == reversedStr


if __name__ == '__main__':
    for s in ['', 'neen', 'negen', 'geen', 'Kook ik ook?']:
        print(s, isPalindoom(s))
