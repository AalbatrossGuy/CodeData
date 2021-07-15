import time
import os


def rebar(items, total=None):
    total = total or len(items)
    for i, item in enumerate(iter(items), 1):
        width = os.get_terminal_size().columns - 22
        print('\rProgress: |\x1b[42m' + (' ' * int((i / total) * width)) + '\x1b[0m' + (' ' * (width - int((i / total) * width))) + f'| ({i / total:6.1%})', end='' if i < total else '\n')
        yield item


def example():
    x = 0
    # Since we are asking it to provide a progress bar for an iterable/range, we must explicitly give it the total.
    for i in rebar(range(200), total=200):
        x += i
        # Simulate some execution time.
        time.sleep(.05)
    print(f"And the final value of `x`: {x:,}")

    x = 0
    # Double check our results.
    for i in range(200):
        x += i
    print(f"Sanity-check results: {x:,}")

    x = 0
    # Alternatively, if we don't care about memory (or don't have huge lists/tuples/sets/dicts/etc)...
    for i in rebar(list(range(200))):
        x += i
    print(f"Sanity-check results: {x:,}")


if __name__ == '__main__':
    example()
