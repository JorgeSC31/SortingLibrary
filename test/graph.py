import matplotlib.pyplot as plt
import matplotlib.patches as mpatches

xs1 = [100, 1000, 10000, 100000]
xs2 = [100, 1000, 10000, 100000, 1000000, 5000000, 10000000]

name = "Random order"
ys4 = [0.0, 0.0, 4.33, 57.33, 725.33, 4250.67, 9015.0]
ys5 = [0.0, 0.0, 5.0, 66.33, 889.0, 4887.33, 10366.67]
ys6 = [0.0, 0.0, 4.0, 58.0, 852.0, 5909.0, 13176.67]
ys7 = [0.0, 0.0, 2.0, 32.33, 432.33, 2221.33, 4507.0]


fig = plt.figure()
fig.suptitle(name, fontsize=14, fontweight='bold')

# plt.plot(xs1, ys1, 'red')
# plt.plot(xs1, ys2, 'blue')
# plt.plot(xs1, ys3, 'orange')
# plt.plot(xs1, ys4, 'purple')
# plt.plot(xs1, ys5, 'yellow')
# plt.plot(xs1, ys6, 'green')
# plt.plot(xs1, ys7, 'black')

plt.plot(xs2, ys4, 'purple')
plt.plot(xs2, ys5, 'yellow')
plt.plot(xs2, ys6, 'green')
plt.plot(xs2, ys7, 'black')
# plt.axis([0, 10000000, 0, 12000])


red_patch = mpatches.Patch(color='red')
blue_patch = mpatches.Patch(color='blue')
orange_patch = mpatches.Patch(color='orange')
purple_patch = mpatches.Patch(color='purple')
yellow_patch = mpatches.Patch(color='yellow')
green_patch = mpatches.Patch(color='green')
black_patch = mpatches.Patch(color='black')

# plt.legend([red_patch, blue_patch, orange_patch, purple_patch, yellow_patch, green_patch, black_patch],
#            ["bubbleSort", "insertionSort", "selectionSort", "mergeSort", "quickSort", "heapSort", "std::sort"])
plt.legend([purple_patch, yellow_patch, green_patch, black_patch],
           ["mergeSort", "quickSort", "heapSort", "std::sort"])

plt.xlabel("input size")
plt.ylabel("Average time (in milliseconds)")
plt.yscale("log")
plt.show()
