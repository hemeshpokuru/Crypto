import random
from sympy import nextprime, isprime, mod_inverse

def get_next_prime(start):
    return nextprime(start)

def find_q(n):
    start = 2
    while not isprime(n):
        while n % start != 0:
            start += 1
        n //= start
    return n

def get_gen(p, q):
    while True:
        h = random.randint(1, p - 1)
        g = pow(h, (p - 1) // q, p)
        if g > 1:  # Ensure g is greater than 1
            return g

def main():
    print("\nSimulation of Digital Signature Algorithm\n")

    p = get_next_prime(10600)  # approximate prime
    q = find_q(p - 1)
    g = get_gen(p, q)

    print("\nGlobal public key components are:")
    print(f"\np is: {p}")
    print(f"\nq is: {q}")
    print(f"\ng is: {g}")

    x = random.randint(1, q - 1)  # Private key
    y = pow(g, x, p)  # Public key
    k = random.randint(1, q - 1)  # Secret random number
    r = pow(g, k, p) % q

    hash_val = random.randint(1, p - 1)  # Simulated hash value
    k_inv = mod_inverse(k, q)
    s = (k_inv * (hash_val + x * r)) % q

    print("\nSecret information are:")
    print(f"x (private) is: {x}")
    print(f"k (secret) is: {k}")
    print(f"y (public) is: {y}")
    print(f"h (rndhash) is: {hash_val}")

    print("\nGenerating digital signature:")
    print(f"r is: {r}")
    print(f"s is: {s}")

    w = mod_inverse(s, q)
    u1 = (hash_val * w) % q
    u2 = (r * w) % q
    v = (pow(g, u1, p) * pow(y, u2, p)) % p % q

    print("\nVerifying digital signature (checkpoints):")
    print(f"w is: {w}")
    print(f"u1 is: {u1}")
    print(f"u2 is: {u2}")
    print(f"v is: {v}")

    if v == r:
        print("\nVerification successful: Signature is valid.")
    else:
        print("\nVerification failed: Signature is invalid.")

if __name__ == "__main__":
    main()
