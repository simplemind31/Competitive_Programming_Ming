
class Solution:
    def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
        MAXT = 100000
        know = [0]*n
        usado = [0]*n
        ord = [[set(), set()] for _ in range(MAXT + 1)]
        unecon = [[] for _ in range(n)]
        for a, b, t in meetings:
            if a > b:
                a, b = b, a
            if a == 0 and b == firstPerson:
                continue
            ord[t][0].add((a, b))
            unecon[a].append((b, t))
            unecon[b].append((a, t))
        ord[0][1].add((0, firstPerson))
        unecon[0].append((firstPerson, 0))
        for i in range(MAXT + 1):
            while ord[i][1]:
                a, b = next(iter(ord[i][1]))
                ord[i][1].remove((a, b))
                know[a] = know[b] = 1
                for temp in (a, b):
                    if usado[temp]:
                        continue
                    usado[temp]=1
                    for nxt,t in unecon[temp]:
                        if t < i:
                            continue
                        edge = (min(temp, nxt), max(temp, nxt))
                        if edge in ord[t][0]:
                            ord[t][0].remove(edge)
                            ord[t][1].add(edge)

        return [i for i in range(n) if know[i]]