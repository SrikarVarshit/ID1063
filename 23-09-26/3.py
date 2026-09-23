def run_length(a: list, n: int, i: int) -> int:
    """Returns the number of consecutive 1s starting at position i."""
    count = 0
    while i < n and a[i] == 1:
        count += 1
        i += 1
    return count

def main():
    # Read n and k
    n, k = map(int, input().split())
    # Read the activity log array
    a = list(map(int, input().split()))

    violation_session = 0

    # Search for the first streak that exceeds k
    for i in range(n):
        if run_length(a, n, i) > k:
            # First violation occurs at (i + k + 1) in 1-based session numbering
            violation_session = i + k + 1
            break

    print(violation_session)

if __name__ == "__main__":
    main()

