#!/usr/bin/env python3
# (c) 2018 Frans Schippers (f.h.schippers@hva.nl) for MSP

# SMPpy_12_fibonacci

def fibonacci(n):
    if n <= 2:
        return 1
    return fibonacci(n - 1) + fibonacci(n - 2)

if __name__ == '__main__':

    for i in range(1, 11):
        print(fibonacci(i), "\n")
    print()
    print(fibonacci(35))    # Could take a while
