import os
import shutil
import subprocess
import numpy as np

# Force a non-GUI backend (Agg) so it runs cleanly without an X11 display server
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt

# -------------------------------------------------------------
# 1. Mathematical Setup for Question 46
# -------------------------------------------------------------
# Piecewise domains
x_neg = np.linspace(-1.5, 0, 300)
x_pos = np.linspace(0, 2.0, 300)

# With continuity (a = 0) and differentiability (b = 2):
# Left:  f(x) = a + bx = 2x
# Right: f(x) = sin(2x)
y_neg = 2 * x_neg
y_pos = np.sin(2 * x_pos)

# -------------------------------------------------------------
# 2. Plotting
# -------------------------------------------------------------
fig, ax = plt.subplots(figsize=(8, 5), dpi=150)

ax.plot(
    x_neg,
    y_neg,
    color="#d9534f",
    linewidth=2.2,
    label=r"$f(x) = 2x \quad (x \le 0, \ a=0, b=2)$",
)
ax.plot(
    x_pos,
    y_pos,
    color="#0275d8",
    linewidth=2.2,
    label=r"$f(x) = \sin(2x) \quad (x > 0)$",
)

# Reference axes
ax.axhline(0, color="gray", linestyle="--", linewidth=0.8, alpha=0.6)
ax.axvline(0, color="gray", linestyle="--", linewidth=0.8, alpha=0.6)

# Highlight and circle the junction point (0, 0)
ax.scatter(
    0,
    0,
    s=350,
    facecolors="none",
    edgecolors="#28a745",
    linewidth=2.5,
    zorder=5,
    label="Point of Differentiability (0, 0)",
)
ax.scatter(0, 0, color="#28a745", s=40, zorder=6)

# Result callout
ax.annotate(
    "Differentiable at x = 0:\n"
    r"• Continuity: $a = 0$" "\n"
    r"• Smooth slope: $b = 2$" "\n"
    r"$\mathbf{a + b = 2}$ (Option C)",
    xy=(0, 0),
    xytext=(0.25, -1.8),
    arrowprops=dict(
        facecolor="#28a745",
        edgecolor="#28a745",
        arrowstyle="->",
        lw=1.8,
        shrinkA=10,
        shrinkB=10,
    ),
    fontsize=10,
    bbox=dict(boxstyle="round,pad=0.4", fc="#f4fbf4", ec="#28a745", lw=1.2),
)

# Formatting
ax.set_title(
    "GATE Q.46: Differentiability at x = 0",
    fontsize=12,
    fontweight="bold",
    pad=10,
)
ax.set_xlabel("x", fontsize=10)
ax.set_ylabel("f(x)", fontsize=10)
ax.set_xlim(-1.5, 2.0)
ax.set_ylim(-3.0, 1.5)
ax.grid(True, linestyle=":", alpha=0.6)
ax.legend(loc="upper left", fontsize=9)

plt.tight_layout()

# -------------------------------------------------------------
# 3. Save & Launch via Android Image Viewer
# -------------------------------------------------------------
output_file = os.path.abspath("q46_plot.png")
plt.savefig(output_file, bbox_inches="tight")
plt.close(fig)

print(f"Graph generated at: {output_file}")

# Check for termux-open to view immediately on Android
if shutil.which("termux-open"):
    subprocess.run(["termux-open", output_file])
else:
    # Fallback using Android intent manager
    os.system(f"am start -a android.intent.action.VIEW -d file://{output_file} -t image/png")

