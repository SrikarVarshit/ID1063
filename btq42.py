import os
import subprocess
import matplotlib.pyplot as plt
import numpy as np

# System parameters from Q.42
tau = 40.0  # Time constant in seconds
t_target = -tau * np.log(1 - 0.95)  # Exact: 119.83 s -> rounds to 120 s
y_target = 95.0  # 95% of steady state

# Time domain vector (0 to 240 seconds)
t = np.linspace(0, 240, 600)
y = 100 * (1 - np.exp(-t / tau))  # Percentage output

# Create figure
fig, ax = plt.subplots(figsize=(9, 5.5))
ax.plot(
    t,
    y,
    color="#0055ff",
    linewidth=2.2,
    label=r"Response: $y(t) = 100(1 - e^{-t/40})$",
)

# Reference guidelines
ax.axhline(95, color="gray", linestyle="--", linewidth=1, alpha=0.7)
ax.axvline(120, color="gray", linestyle="--", linewidth=1, alpha=0.7)

# Circle the target answer point
ax.scatter(
    120,
    95,
    s=350,
    facecolors="none",
    edgecolors="#e60000",
    linewidth=2.5,
    label="Answer: (120 s, 95%)",
    zorder=5,
)
ax.scatter(120, 95, color="#e60000", s=30, zorder=6)

# Arrow annotation
ax.annotate(
    "t ≈ 120 s",
    xy=(120, 95),
    xytext=(145, 75),
    arrowprops=dict(
        facecolor="#e60000",
        edgecolor="#e60000",
        arrowstyle="->",
        lw=1.8,
        shrinkA=10,
        shrinkB=12,
    ),
    fontsize=11,
    fontweight="bold",
    color="#e60000",
    bbox=dict(boxstyle="round,pad=0.4", fc="#fff2f2", ec="#e60000", lw=1),
)

# Labels and styling
ax.set_title(
    "First-Order Thermometer Response (τ = 40 s)",
    fontsize=13,
    fontweight="bold",
    pad=12,
)
ax.set_xlabel("Time, t (seconds)", fontsize=11)
ax.set_ylabel("Response, y(t) (% of Steady State)", fontsize=11)
ax.set_xlim(0, 240)
ax.set_ylim(0, 105)
ax.grid(True, linestyle=":", alpha=0.6)
ax.legend(loc="lower right", fontsize=10)

plt.tight_layout()

# Save image file
image_path = "q42_response_graph.png"
plt.savefig(image_path, dpi=300)
plt.close()

# Direct to Android default image viewer via Termux
print(f"Plot saved to '{image_path}'. Opening image...")
try:
    subprocess.run(["termux-open", image_path], check=True)
except Exception:
    os.system(f"termux-open {image_path} || am start -a android.intent.action.VIEW -d file://$(pwd)/{image_path} -t image/png")

