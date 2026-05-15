import matplotlib
matplotlib.use('TkAgg')
import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import numpy as np
import os

# 1. Paths
script_dir = os.path.dirname(os.path.abspath(__file__))
csv_path = os.path.join(script_dir, '..', 'output', 'data.csv')

if not os.path.exists(csv_path):
    print(f"Error: {csv_path} not found.")
    exit()

data = pd.read_csv(csv_path)

def ackley_function(x, y):
    return -20.0 * np.exp(-0.2 * np.sqrt(0.5 * (x**2 + y**2))) - \
        np.exp(0.5 * (np.cos(2 * np.pi * x) + np.cos(2 * np.pi * y))) + np.e + 20

x_range = np.linspace(-5, 5, 100)
y_range = np.linspace(-5, 5, 100)
X, Y = np.meshgrid(x_range, y_range)
Z = ackley_function(X, Y)

fig, ax = plt.subplots(figsize=(9, 8))

terrain = ax.contourf(X, Y, Z, levels=50, cmap='viridis', alpha=0.8)

scatter = ax.scatter([], [], c='white', edgecolors='black', s=30, label='Particles')
ax.legend()

def update(frame):
    current_step = data[data['iteration'] == frame]
    if not current_step.empty:
        scatter.set_offsets(current_step[['x', 'y']])

    return scatter,

total_frames = int(data['iteration'].max()) + 1
ani = animation.FuncAnimation(fig, update, frames=total_frames, interval=100, blit=True)

plt.show()