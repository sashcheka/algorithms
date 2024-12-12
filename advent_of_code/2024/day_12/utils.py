from pathlib import Path


def get_day_and_input(f):
    day = Path(f).stem.replace("day", "")
    inputs = Path(f"input_1.txt")
    with open(inputs) as file:
        string = file.read()

    return day, string


def get_day_and_input_by_line(f):
    day, string = get_day_and_input(f)
    return day, [s for s in string.split("\n") if s]


def by_line(s):
    return s.strip().split("\n")


def by_double_line(s):
    return s.strip().split("\n\n")


def log_part_1(answer):
    print(f"Part 1: {answer}")


def log_part_2(answer):
    print(f"Part 2: {answer}")


def log_start(d):
    print(f"Starting Day {d}")