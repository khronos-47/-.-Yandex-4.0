def count_palindromes(s):
    modified_s = '#'.join('^{}$'.format(s))
    p = [0] * len(modified_s)
    c = r = 0
    for i in range(1, len(modified_s) - 1):
        mirror = 2 * c - i
        if r > i:
            p[i] = min(r - i, p[mirror])
        while modified_s[i + 1 + p[i]] == modified_s[i - 1 - p[i]]:
            p[i] += 1

        if i + p[i] > r:
            c, r = i, i + p[i]
    count = sum((v + 1) // 2 for v in p)
    return count

s = input()
palindrome_count = count_palindromes(s)
print(palindrome_count)