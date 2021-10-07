def fibonacci_number(n):
    assert 0 <= n <= 45
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        a = [0, 1]
        for i in range(2, n+1):
            a.append(a[i - 1] + a[i - 2])
        return a
