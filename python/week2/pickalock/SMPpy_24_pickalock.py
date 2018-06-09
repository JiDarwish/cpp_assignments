#!/usr/bin/env python3
# (c) 2018 Frans Schippers (f.h.schippers@hva.nl) for SMP

import SMPpy_24_lock as lock


def lockPickeer(l):
    return ""  # The key


if __name__ == '__main__':
    import datetime

    code = '123'
    l = lock.Lock(len(code), code)

    td = datetime.datetime.now()
    res = lockPicker(l)
    td = datetime.datetime.now()-td
    print('Picker: {0} {1}', res, td)
