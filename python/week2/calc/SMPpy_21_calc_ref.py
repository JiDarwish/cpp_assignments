#!/usr/bin/env python3
# (c) 2018 Frans Schippers (f.h.schippers@hva.nl) for SMP

# SMPpy_21_calc.py

def calc(formula):
    stack = []
    for x in formula:
        if x.isdigit():
            stack.append(int(x))
        elif x in "+-*/":
            if len(stack) < 2: return 'Error: stack hasn\'t enough values opr=%s, %s'%(x, stack[-2:])
            b = stack.pop(); a =stack.pop()
            if x == '+':   c = a + b
            elif x == '-': c = a - b
            elif x == '*': c = a * b
            elif x == '/': c = a // b
            stack.append(c)
        elif x in "^":
            if len(stack) < 1: return 'Error: stack hasn\'t enough values opr=%s, %s'%(x, stack[-1:])
            a = stack.pop()
            if x == '^':
                c = a ** 2
            stack.append(c)
        else:
            raise Exception('Error: Unkown token: %s'%(x,))
    r = stack.pop()
    if len(stack) != 0: return 'Error: stack not empty: %s %s'%(len(stack), stack,)
    return r

if __name__ == '__main__':
    # Some standard test
    for f, e in [
            ('11+',  2), ('13-',  2), ('31-', -2), ('22*',  4), ('52/', 2), ('4^',   8),
            ('13-15++^', 5),
            ('1+', ''), ('111+', ''), ('=', '') ]:
        try:
            r = calc(f)
            print('{}: {}'.format(f, r))
        except Exception as e:
            print('Exception: {}'.format(e))

    # Interactive testing
    while True:
        try:
            f = input('Give formula: ')
            if not f: break # Empty line will break the loop
            r = calc(f)
            print('{}: {}'.format(f, r))
        except EOFError:
            print
            break
        except Exception as e:
            print('Exception: {}'.format(e))

