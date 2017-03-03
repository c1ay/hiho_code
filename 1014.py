"""
Word tree:
Input:
    5
    babaab
    babbbaaaa
    abba
    aaaaabaa
    babaababb
    5
    babb
    baabaaa
    bab
    bb
    bbabbaab
Output:
    1
    0
    3
    0
    0
"""


def add_cond(word, cond):
    if not word:
        return
    if word[0] in cond.children:
        c = cond.children[word[0]]
        c.count += 1
        return add_cond(word[1:], c)
    else:
        c = Cond(word[0], 1)
        cond.children[word[0]] = c
        return add_cond(word[1:], c)


def dfs(word, cond):
    if not word:
        return cond.count
    if word[0] in cond.children:
        return dfs(word[1:], cond.children[word[0]])
    else:
        return 0


class Cond:

    def __init__(self, v, c=0):
        self.value = v
        self.count = c
        self.children = {}


def run():
    c = input()
    root = Cond('')
    for _ in xrange(int(c)):
        input_str = input()
        add_cond(input_str, root)
    c = input()
    for _ in xrange(int(c)):
        input_str = input()
        print(dfs(input_str, root))


if __name__ == '__main__':
    run()
