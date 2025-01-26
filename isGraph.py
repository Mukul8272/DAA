import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("isAnalysis.csv")

plt.figure(figsize=(10, 6))
plt.plot(data["size"], data["bestcase"], label="BestCase", marker='o')
plt.plot(data["size"], data["worstcase"], label="WorstCase", marker='o')
plt.plot(data["size"], data["averagecase"], label="AverageCase", marker='o')

plt.title("Linear Search Comparisons")
plt.xlabel("Array Size (n)")
plt.ylabel("Number of Comparisons")
plt.legend()
plt.grid(True)

plt.savefig("linear_search_plot.png")

plt.show()
