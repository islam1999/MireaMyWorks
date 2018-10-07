def is_prime(n):
    if n == 2:
        return True
    if n % 2 == 0 or n <= 1:
        return False

    for i in range(3, int(n**0.5) + 1):
        if n % i == 0:
            return False

    return True


def main():
    n = int(input('n: '))
    a = [int(number.strip()) for number in input('a: ').split()[:n]]
    print(list(e for e in a if is_prime(e)))


if __name__ == '__main__':
    main()
