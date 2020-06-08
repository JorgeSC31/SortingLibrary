def get_line():
    _line = lines[0]
    del lines[0]
    return _line


# Limites bajos - Todos los algoritmos
for CURRENT_GRAPH in range(7):

    f = open('results_read.txt')
    lines = []

    for line in f:
        lines.append(line)

    # print(CURRENT_GRAPH)

    ys_1 = []
    ys_2 = []
    ys_3 = []
    ys_4 = []
    ys_5 = []
    ys_6 = []
    ys_7 = []

    for data in range(4):
        # get_line()
        # N, V = map(int, get_line().split(" "))

        for test in range(7):
            a1, a2, a3, a4, a5, a6, a7 = map(float, get_line().split(" "))
            # print(a, b)

            if test == CURRENT_GRAPH:
                ys_1.append(a1)
                ys_2.append(a2)
                ys_3.append(a3)
                ys_4.append(a4)
                ys_5.append(a5)
                ys_6.append(a6)
                ys_7.append(a7)
        get_line()

    print("ys1 = ", ys_1)
    print("ys2 = ", ys_2)
    print("ys3 = ", ys_3)
    print("ys4 = ", ys_4)
    print("ys5 = ", ys_5)
    print("ys6 = ", ys_6)
    print("ys7 = ", ys_7)
    print()

# Limites Altos - Algoritmos rapidos
for CURRENT_GRAPH in range(7):

    f = open('results_read.txt')
    lines = []

    for line in f:
        lines.append(line)

    # def get_line():
    #     _line = lines[0]
    #     del lines[0]
    #     return _line

    # print(CURRENT_GRAPH)

    ys_4 = []
    ys_5 = []
    ys_6 = []
    ys_7 = []

    for data in range(7):
        # get_line()
        # N, V = map(int, get_line().split(" "))

        for test in range(7):
            a1, a2, a3, a4, a5, a6, a7 = map(float, get_line().split(" "))
            # print(a, b)

            if test == CURRENT_GRAPH:
                ys_4.append(a4)
                ys_5.append(a5)
                ys_6.append(a6)
                ys_7.append(a7)
        get_line()

    print("ys4 = ", ys_4)
    print("ys5 = ", ys_5)
    print("ys6 = ", ys_6)
    print("ys7 = ", ys_7)
    print()
