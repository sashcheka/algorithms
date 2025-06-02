def calculate(s):
    n = len(s)
    res = 0
    unary_sign = 1
    stack_sign = [1]
    prev = "_"

    i = 0
    while i < n:
        if s[i].isdigit():
            num = 0
            while i < n and s[i].isdigit():
                num = num * 10 + int(s[i])
                i += 1
            res += stack_sign[-1] * unary_sign * num
            prev = "not sign"
            continue

        elif s[i] == '(':
            stack_sign.append(stack_sign[-1] * unary_sign)
            unary_sign = 1
            prev = "not sign"

        elif s[i] == ')':
            stack_sign.pop()
            prev = "not sign"

        elif s[i] in ['+', '-']:
            if prev == 'sign':
                unary_sign *= 1 if s[i] == '+' else -1
            else:
                unary_sign = 1 if s[i] == '+' else -1
            prev = 'sign'

        i += 1

    return res

tests = {
    "1 + 1": 2,
    "1 - 1": 0,
    "-1 + 2": 1,
    "-(1 + 2)": -3,
    "-(-1)": 1,
    "1 + (2 + 3)": 6,
    "1 + (2 - 3)": 0,
    "1 + (-2)": -1,
    "1 - (-2)": 3,
    "1 - -2": 3,
    "- (3 + (2 - 1))": -4,
    "((2))": 2,
    "-+--+3": -3,
    "1 + 2 - 3 + 4 - 5 + 6": 5,
    "0": 0,
    "123": 123,
    "-123 + (456 - 789)": -456,
    "1 + (2 + (3 + (4 + 5)))": 15,
    "- ( - ( - (1) ) )": -1,
    "   1 + 2    - 3": 0,
    "+1": 1,
    "-(+1)": -1,
    "(1 + 2) - (3 - 4)": 4,
    "(1 + (2 - (3 + 4)) + 5)": 1,
}

RED = "\033[31m"
GREEN = "\033[32m"
RESET = "\033[0m"

for expr, expected in tests.items():
    try:
        result = calculate(expr)
        assert result == expected
        print(GREEN + f"PASSED: {expr} = {result}" + RESET)
    except AssertionError:
        print(RED + f"FAILED: {expr} = {result}, expected {expected}" + RESET)