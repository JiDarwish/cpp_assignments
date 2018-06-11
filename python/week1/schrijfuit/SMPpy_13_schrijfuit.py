#!/usr/bin/env python3
# (c) 2018 Frans Schippers (f.h.schippers@hva.nl) for MSP

# SMPpy_13_schrijfuit

gEental = {
    0: 'nul',
    1: 'een',
    2: 'twee',
    3: 'drie',
    4: 'vier',
    5: 'vijf',
    6: 'zes',
    7: 'zeven',
    8: 'acht',
    9: 'negen',
}
gTiental = {
    10: 'tien',
    20: 'twintig',
    30: 'dertig',
    40: 'veertig',
    50: 'vijftig',
    60: 'zestig',
    70: 'zeventig',
    80: 'achtig',
    90: 'negentig',
}
gTieners = {
    11: 'elf',
    12: 'twaalf',
    13: 'dertien',
    14: 'veertien',
    15: 'vijftien',
    16: 'zestien',
    17: 'zeventien',
    18: 'achttien',
    19: 'negentien',
}


def schrijfUit(n):
    if n > 99 or n < 0:
        return "???"
    elif n < 10:  # tussen 1 en 9
        return gEental[n]
    elif n < 20 and n != 10:  # tussen 11 en 19
        return gTieners[n]

    out = ""
    eenheid = n % 10

    if eenheid == 0:  # is het een tiental?
        return gTiental[n]
    else:  # boven 20 en heeft een eenheid
        out += gEental[eenheid] + "en"
        n -= eenheid
        out += gTiental[n]
        return out


if __name__ == '__main__':

    for getal in range(0, 40):
        print(getal, schrijfUit(getal))
