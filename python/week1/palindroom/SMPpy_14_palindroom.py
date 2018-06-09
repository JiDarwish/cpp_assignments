#!/usr/bin/env python3
import re

# SMPpy_14_palindroom.

def isPalindoom(s):
    allChars = "".join(re.findall("[a-zA-Z]+", s))
    reversedStr = allChars[::-1]

    return allChars.lower() == reversedStr.lower()

if __name__ == '__main__':
    for s in [ '', 'neen', 'negen', 'geen', 'Kook ik ook?' ]:
        print(s, isPalindoom(s))
