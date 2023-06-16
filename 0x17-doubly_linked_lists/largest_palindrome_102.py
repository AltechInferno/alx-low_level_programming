#!/usr/bin/env python3

largest_palindrome = 0

for i in range(100, 1000):
    for j in range(i, 1000):  # Start the inner loop from i to avoid duplicate combinations
        product = i * j
        if str(product) == str(product)[::-1] and product > largest_palindrome:
            largest_palindrome = product

# Save the result to the file
with open("102-result", "w") as file:
    file.write(str(largest_palindrome))


