from muralla import altura_maxima

def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    columnas = list(map(int, input().split()))
    
    Q = int(input())
    ataques = []
    for _ in range(Q):
        l, r, w = map(int, input().split())
        ataques.append((l, r, w))

    res = altura_maxima(N, columnas, Q, ataques)

    for h in res:
        print(h)

if __name__ == "__main__":
    main()
