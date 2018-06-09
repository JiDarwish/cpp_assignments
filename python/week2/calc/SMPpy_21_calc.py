#!/usr/bin/env python3
# (c) 2018 Frans Schippers (f.h.schippers@hva.nl) for SMP

# SMPpy_21_calc.py

def processOperation(num1, num2, operator):
  if operator == '+':
    return int(num2) + int(num1)
  elif operator == '*':
    return int(num2) * int(num1)
  elif operator == '/':
    return int(num2) / int(num1)
  else:
    return int(num2) - int(num1)


def calc(formula):
  stack = []
  for c in formula:
    if c.isdigit():
      stack.append(c)
    elif c in '*+-/':
      if len(stack) < 2:
        raise Exception("Error: Trying to perform operation with no enough numbers")
      num1 = stack.pop()
      num2 = stack.pop()
      stack.append(processOperation(num1, num2, c))
    elif c == '^':
      if len(stack) < 1:
        raise Exception("Error ^ needs at least 1 operand")
      num = stack.pop()
      stack.append(int(num) ** 2)
    else:
      raise Exception("Unexpecte token", c)
    
    
  if len(stack) != 1:
    raise Exception("There was more than 1 number at the end")
  return stack.pop()
    

if __name__ == '__main__':
    # Some standard test
    for f, e in [
                ('11+',  2), ('13-',  2), ('31-', -2), ('22*',  4), ('52/', 2), ('4^',   8),
                ('13-15++^', 5),
                ('1+', ''), ('111+', '') ]:
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

