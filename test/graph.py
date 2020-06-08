import matplotlib.pyplot as plt
import matplotlib.patches as mpatches

xs1 = [100, 1000, 10000, 100000]
xs2 = [100, 1000, 10000, 100000, 1000000, 5000000, 10000000]


name = "Sorted asc with 20% adj swaps"
ys1 = [0.0, 3.0, 297.8, 59400.8]
ys2 = [0.0, 0.0, 0.0, 6.8]
ys3 = [0.0, 7.0, 755.6, 74738.4]
ys4 = [0.0, 0.0, 3.0, 33.8]
ys5 = [0.0, 0.0, 4.2, 62.6]
ys6 = [0.0, 0.0, 4.0, 51.0]
ys7 = [0.0, 0.0, 1.0, 18.4]

fig = plt.figure()
fig.suptitle(name, fontsize=14, fontweight='bold')

plt.plot(xs1, ys1, 'red')
plt.plot(xs1, ys2, 'blue')
plt.plot(xs1, ys3, 'orange')
plt.plot(xs1, ys4, 'purple')
plt.plot(xs1, ys5, 'yellow')
plt.plot(xs1, ys6, 'green')
plt.plot(xs1, ys7, 'black')

# plt.plot(xs2, ys4, 'purple')
# plt.plot(xs2, ys5, 'yellow')
# plt.plot(xs2, ys6, 'green')
# plt.plot(xs2, ys7, 'black')
# plt.axis([0, 10000000, 0, 12000])


red_patch = mpatches.Patch(color='red')
blue_patch = mpatches.Patch(color='blue')
orange_patch = mpatches.Patch(color='orange')
purple_patch = mpatches.Patch(color='purple')
yellow_patch = mpatches.Patch(color='yellow')
green_patch = mpatches.Patch(color='green')
black_patch = mpatches.Patch(color='black')

plt.legend([red_patch, blue_patch, orange_patch, purple_patch, yellow_patch, green_patch, black_patch],
           ["bubbleSort", "insertionSort", "selectionSort", "mergeSort", "quickSort", "heapSort", "std::sort"])
# plt.legend([purple_patch, yellow_patch, green_patch, black_patch],
#            ["mergeSort", "quickSort", "heapSort", "std::sort"])

plt.xlabel("input size")
plt.ylabel("Average time (in milliseconds)")
plt.yscale("log")
plt.show()
