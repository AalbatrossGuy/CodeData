import numpy, re, math
import matplotlib.pyplot as plot

plot.style.use('classic')

prompt = """
Enter your equation in this form: 2x^2 + 4x + 8
"""


def main() -> None:
    x_axis = numpy.linspace(-10, 10, 1000)
    raw_input = input(prompt)
    match_string = re.findall(r'\d+', raw_input)
    num = list(map(int, match_string))
    num.pop(1)
    a, b, c = num
    y_axis = a * x_axis ** 2 + b * x_axis + c
    discriminant = b ** 2 - 4 * a * c
    fig, ax = plot.subplots()
    ax.set_title("Visualizing Quadratic Equations")
    ax.plot(x_axis, y_axis)
    ax.hlines(y=0, xmin=min(x_axis), xmax=max(x_axis), colors='r', linestyles='--', lw=1)
    plot.show()
    if discriminant < 0:
        print('No Real Solutions is/are possible.')
    elif discriminant == 0:
        result = (-b + math.sqrt(b ** 2 - 4 * a * c)) / (2 * a)
        print(f"The result of this equation is/are: {result}")
    else:
        result = (-b + math.sqrt(b ** 2 - 4 * a * c)) / (2 * a)
        result2 = (-b - math.sqrt(b ** 2 - 4 * a * c)) / (2 * a)
        print(f"The result of this equation is/are: {result}, {result2}")


if __name__ == "__main__":
    main()
    # print(matplotlib.style.available)
